#include "../../headers/questions/MultipleChoiceQuestion.h"

#include <iostream>
#include <sstream>

#include "../../headers/helpers/SystemMessages.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const Vector<MyString>& correctAnswers)
	: Question(description, points), _answers(answers), _correctAnswer(correctAnswers) {

}

void MultipleChoiceQuestion::read() {
	_answers.clear();
	_correctAnswer.clear();

	std::cout << EnterDescription;
	std::cin >> this->_desription;

	size_t answersCount = 0;
	std::cout << MultipleChoicePossibleAnswers;
	std::cin >> answersCount;
	std::cin.ignore();

	char ch = 'A';

	for (size_t i = 0; i < answersCount; i++) {
		std::cout << "Enter answer " << ch << ": ";
		MyString answer;
		std::cin >> answer;
		_answers.push_back(answer);
		ch++;
	}

	MyString input;

	while (true) {
		std::cout << MultipleChoiceCorrectAnswers;
		std::cin >> input;

		try {
			splitAnswers(input, this->_correctAnswer);
			break; 
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Error: " << e.what() << ". Please try again." << std::endl;
		}
	}

	std::cout << EnterPoints;
	std::cin >> this->_points;

}

void MultipleChoiceQuestion::splitAnswers(const MyString& input, Vector<MyString>& answers) const {
	int start = 0;
	int end = input.find(", ");

	if (!isInValidFormat(input)) {
		throw std::invalid_argument(InvalidFormat.data());
	}

	while (end != -1) {
		MyString answer(input.substr(start, end - start));
		answers.push_back(answer);
		start = end + 2; // Move past ", "
		end = input.find(", ", start);
	}

	MyString lastAnswer(input.substr(start, 1));
	answers.push_back(lastAnswer);
}

bool MultipleChoiceQuestion::isInValidFormat(const MyString& input) const {
	std::stringstream ss(input.data());
	char ch;

	while (ss >> ch) {
		if (!std::isalpha(ch)) {
			return false; 
		}

		ss >> ch;
		if (ch != ',' && !ss.eof()) {
			return false; 
		}
	}

	return true; 
}



void MultipleChoiceQuestion::print(std::ostream& os) const {
	os << this->_desription << " (" << this->_points << " points)" << std::endl;

	char ch = 'A';
	for (size_t i = 0; i < this->_answers.size(); i++) {
		os << "  ";
		os << ch << ".  " << this->_answers[i] << std::endl;
		ch++;
	}

	std::cout << "Enter your answer here [ A, ..]: ";

}

void MultipleChoiceQuestion::readCollection(std::ifstream& ifs, Vector<MyString>& collection) {
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++) {
		MyString answer;
		answer.readFromBinaryFile(ifs);
		collection.push_back(answer);
	}
}

void MultipleChoiceQuestion::writeCollection(std::ofstream& ofs, const Vector<MyString>& collection) const {
	size_t size = collection.size();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++) {
		collection[i].writeToBinaryFile(ofs);
	}
}



void MultipleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs) {

	_answers.clear();
	_correctAnswer.clear();
	this->_desription.readFromBinaryFile(ifs);

	readCollection(ifs, this->_answers);
	readCollection(ifs, this->_correctAnswer);

	ifs.read((char*)&this->_points, sizeof(this->_points));
}


void MultipleChoiceQuestion::printCorrectAnswer(std::ostream& os) const {
	os << InputCorrectAnswer;
	for (size_t i = 0; i < _correctAnswer.size() - 1; i++) {
		os << _correctAnswer[i] << ", ";
	}

	os << this->_correctAnswer[_correctAnswer.size() - 1];
}



void MultipleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const {
	QuestionType questionType = this->type();
	ofs.write((const char*)&questionType, sizeof(questionType));
	this->_desription.writeToBinaryFile(ofs);

	writeCollection(ofs, this->_answers);
	writeCollection(ofs, this->_correctAnswer);

	ofs.write((const char*)&this->_points, sizeof(this->_points));

}

int MultipleChoiceQuestion::checkAnswer(const MyString& answer) const {

	Vector<MyString> userAnswer;

	splitAnswers(answer, userAnswer);

	if (userAnswer.size() == 0) {
		return 0;
	}

	int counter = 0;

	for (size_t i = 0; i < userAnswer.size(); i++) {
		if (this->_correctAnswer.contains(userAnswer[i])) {
			counter++;
		}
	}

	if (counter >= this->_correctAnswer.size() / 2 && counter < this->_correctAnswer.size()) {
		return this->_points / 2;
	}
	else if (counter == this->_correctAnswer.size()) {
		return this->_points;
	}
	else {
		return 0;
	}

}

Question* MultipleChoiceQuestion::clone() const {
	return new MultipleChoiceQuestion(*this);
}

QuestionType MultipleChoiceQuestion::type() const {
	return QuestionType::MultipleChoice;

}










