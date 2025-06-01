#include "../../headers/questions/MultipleChoiceQuestion.h"

#include <iostream>

MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const Vector<MyString>& correctAnswers)
	: Question(description, points), _answers(answers), _correctAnswer(correctAnswers){
	
}

void MultipleChoiceQuestion::read(){
	_answers.clear();
	_correctAnswer.clear();

	std::cout << "Enter description: ";
	std::cin >> this->_desription;

	size_t answersCount = 0;
	std::cout << "Enter possible answers count: ";
	std::cin >> answersCount;

	char ch = 'A';

	for (size_t i = 0; i < answersCount; i++) {
		std::cout << "Enter answer " << ch << ": ";
		MyString answer;
		std::cin >> answer;
		_answers.push_back(answer);
		ch++;
	}

	MyString input;

	std::cout << "Enter correct answers: ";
	std::cin >> input;

	std::cout << "Enter points: ";
	std::cin >> this->_points;
	
}

void MultipleChoiceQuestion::print(std::ostream& os) const{
	os << this->_desription << " (" << this->_points << " points)" << std::endl;

	char ch = 'A';
	for (size_t i = 0; i < this->_answers.size(); i++) {
		os << "  ";
		os << ch << ".  " << this->_answers[i] << std::endl;
		ch++;
	}
}

void MultipleChoiceQuestion::readCollection(std::ifstream& ifs, Vector<MyString>& collection){
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++) {
		MyString answer;
		answer.readFromBinaryFile(ifs);
		collection.push_back(answer);
	}
}

void MultipleChoiceQuestion::writeCollection(std::ofstream& ofs, const Vector<MyString>& collection) const{
	size_t size = collection.size();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++) {
		collection[i].writeToBinaryFile(ofs);
	}
}



void MultipleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs){

	_answers.clear();
	_correctAnswer.clear();
	this->_desription.readFromBinaryFile(ifs);

	readCollection(ifs, this->_answers);
	readCollection(ifs, this->_correctAnswer);
	
	ifs.read((char*)&this->_points, sizeof(this->_points));
}



void MultipleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const{
	QuestionType questionType = this->type();
	ofs.write((const char*)&questionType, sizeof(questionType));
	this->_desription.writeToBinaryFile(ofs);

	writeCollection(ofs, this->_answers);
	writeCollection(ofs, this->_correctAnswer);
	
	ofs.write((const char*)&this->_points, sizeof(this->_points));
	
}

int MultipleChoiceQuestion::isCorrectAnswer(const Vector<MyString>& userAnswer) const{
	int counter = 0;

	for (size_t i = 0; i < userAnswer.size(); i++){
		if (this->_correctAnswer.contains(userAnswer[i])){
			counter++;
		}
	}

	return counter;

}

Question* MultipleChoiceQuestion::clone() const{
	return new MultipleChoiceQuestion(*this);
}

QuestionType MultipleChoiceQuestion::type() const{
	return QuestionType::MultipleChoice;
	
}










