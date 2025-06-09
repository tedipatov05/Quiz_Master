#include <iomanip>
#include <iostream>
#include "../../headers/questions/MatchingPairsQuestions.h"
#include <sstream>

MatchingPairsQuestion::MatchingPairsQuestion(const MyString& description, int points, const Vector<MyString>& leftColumn, const Vector<MyString>& rightColumn,
	const Vector<Pair<MyString, MyString>>& correctAnswer) : Question(description, points) {

	this->_leftColumn = leftColumn;
	this->_rightColumn = rightColumn;
	this->_correctAnswer = correctAnswer;

}

QuestionType MatchingPairsQuestion::type() const {
	return QuestionType::MatchingPairs;
}

void MatchingPairsQuestion::read() {
	std::cout << "Enter description: ";
	std::cin >> this->_desription;

	this->readColumn('A', _leftColumn, "left column");
	this->readColumn('a', _rightColumn, "right column");
	this->readCorrectAnswers();

	std::cout << "Enter points: ";
	std::cin >> this->_points;
	std::cout << std::endl;

}

void MatchingPairsQuestion::printCorrectAnswer(std::ostream& os) const {
	os << "Correct answer: ";
	for (size_t i = 0; i < _correctAnswer.size() - 1; i++) {
		os << this->_correctAnswer[i] << ", ";
	}

	os << this->_correctAnswer[_correctAnswer.size() - 1];
}


void MatchingPairsQuestion::readColumn(char ch, Vector<MyString>& column, const MyString& columnType) {
	size_t cout;
	std::cout << "Enter " << columnType << " column values count: ";
	std::cin >> cout;

	std::cin.ignore();

	for (size_t i = 0; i < cout; i++) {
		std::cout << "Enter value " << ch << ": ";
		MyString str;
		std::cin >> str;
		column.push_back(str);
		ch++;
	}

}

void MatchingPairsQuestion::splitAnswer(const MyString& input, Vector<Pair<MyString, MyString>>& answer) const {

	if (!this->isInValidFormat(input)){
		throw std::invalid_argument("Invalid format of the input");
	}

	std::stringstream ss(input.data());
	char ch;
	char first, second;
	while (ss >> ch) {
		if (ch == '(') {
			ss >> first >> ch >> second;

			Pair<MyString, MyString> pair(first, second);

			answer.push_back(pair);
		}
	}
}

bool MatchingPairsQuestion::isInValidFormat(const MyString& input) const {
	std::stringstream ss(input.data());
	char ch;
	char first, second;

	while (ss >> ch) {
		if (ch != '(') {
			return false;
		}

		ss >> first >> ch;
		if (ch != ',') {
			return false;
		}

		ss >> second >> ch;
		if (ch != ')') {
			return false;
		}

		ss >> ch;
		if (ch != ',' && !ss.eof()) {
			return false;
		}
	}

	return true;
}



void MatchingPairsQuestion::readCorrectAnswers() {

	MyString answer;

	while (true){
		try{
			std::cout << "Enter correct answers: ";
			std::cin >> answer;

			splitAnswer(answer, this->_correctAnswer);
			break;
		}
		catch (std::invalid_argument e){
			std::cout << e.what() << std::endl;
		}
	}
	

}

int MatchingPairsQuestion::checkAnswer(const MyString& input) const {


	Vector<Pair<MyString, MyString>> answers;

	splitAnswer(input, answers);

	int res = countCorrectAnswers(answers);

	if (res >= this->_correctAnswer.size() / 2 && res < this->_correctAnswer.size()) {
		return this->_points / 2;
	}
	else if (res == this->_correctAnswer.size()) {
		return this->_points;
	}
	else {
		return 0;
	}
}


void MatchingPairsQuestion::readFromBinaryFile(std::ifstream& ifs) {
	this->_desription.readFromBinaryFile(ifs);

	this->readColumnFromBinary(ifs, this->_leftColumn);
	this->readColumnFromBinary(ifs, this->_rightColumn);
	this->readCorrectAnswersFromBinary(ifs, this->_correctAnswer);

	ifs.read((char*)&this->_points, sizeof(this->_points));

}

void MatchingPairsQuestion::writeToBinaryFile(std::ofstream& ofs) const {
	QuestionType questionType = this->type();
	ofs.write((const char*)&questionType, sizeof(questionType));

	this->_desription.writeToBinaryFile(ofs);

	writeColumnToBinary(ofs, this->_leftColumn);
	writeColumnToBinary(ofs, this->_rightColumn);
	writeCorrectAnswersToBinary(ofs, this->_correctAnswer);

	ofs.write((const char*)&this->_points, sizeof(this->_points));
}

int MatchingPairsQuestion::countCorrectAnswers(const Vector<Pair<MyString, MyString>>& userAnswer) const {
	int count = 0;
	for (size_t i = 0; i < userAnswer.size(); i++) {
		if (this->_correctAnswer.contains(userAnswer[i])) {
			count++;
		}
	}

	return count;
}

void MatchingPairsQuestion::print(std::ostream& os) const {
	os << this->_desription << std::endl;

	size_t leftSize = this->_leftColumn.size();
	size_t rightSize = this->_rightColumn.size();
	size_t count = std::max(leftSize, rightSize);

	char left = 'A';
	char right = 'a';


	for (size_t i = 0; i < count; i++) {
		MyString leftStr = i < leftSize ? MyString(left) + ". " + this->_leftColumn[i] : "";
		MyString rightStr = i < rightSize ? MyString(right) + ". " + this->_rightColumn[i] : "";
		os << std::left << std::setw(20) << leftStr << rightStr << "\n";
		left++;
		right++;
	}

	std::cout << "Enter your answer here: ";


}

Question* MatchingPairsQuestion::clone() const {
	return new MatchingPairsQuestion(*this);
}

void MatchingPairsQuestion::writeColumnToBinary(std::ofstream& ofs, const Vector<MyString>& column) const {
	size_t size = column.size();
	ofs.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++) {
		column[i].writeToBinaryFile(ofs);
	}
}

void MatchingPairsQuestion::writeCorrectAnswersToBinary(std::ofstream& ofs, const Vector<Pair<MyString, MyString>>& answers) const {

	size_t size = answers.size();
	ofs.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++) {
		answers[i].getFirst().writeToBinaryFile(ofs);
		answers[i].getSecond().writeToBinaryFile(ofs);
	}
}

void MatchingPairsQuestion::readColumnFromBinary(std::ifstream& ifs, Vector<MyString>& column) {
	column.clear();

	size_t size;
	ifs.read((char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++) {
		MyString str;
		str.readFromBinaryFile(ifs);
		column.push_back(str);
	}

}

void MatchingPairsQuestion::readCorrectAnswersFromBinary(std::ifstream& ifs, Vector<Pair<MyString, MyString>>& answers) {
	size_t size;
	ifs.read((char*)&size, sizeof(size));

	answers.clear();

	for (size_t i = 0; i < size; i++) {
		MyString first;
		first.readFromBinaryFile(ifs);
		MyString second;
		second.readFromBinaryFile(ifs);
		Pair<MyString, MyString> pair(first, second);

		answers.push_back(pair);
	}

}


















