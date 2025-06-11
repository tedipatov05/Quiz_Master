#include <iomanip>
#include <iostream>

#include "../../headers/helpers/SystemMessages.h"
#include "../../headers/questions/TrueOrFlaseQuestion.h"

TrueOrFalseQuestion::TrueOrFalseQuestion(const MyString& description, int points, const MyString& correctAnswer)
	: Question(description, points), _correctAnswer(correctAnswer) {}

void TrueOrFalseQuestion::readFromBinaryFile(std::ifstream& ifs) {
	ifs.read((char*)&this->_points, sizeof(this->_points));
	this->_desription.readFromBinaryFile(ifs);
	this->_correctAnswer.readFromBinaryFile(ifs);
}


void TrueOrFalseQuestion::writeToBinaryFile(std::ofstream& ofs) const {

	QuestionType type = this->type();
	ofs.write((const char*)&type, sizeof(type));

	ofs.write((const char*)&this->_points, sizeof(this->_points));
	this->_desription.writeToBinaryFile(ofs);
	this->_correctAnswer.writeToBinaryFile(ofs);
}
void TrueOrFalseQuestion::read() {
	std::cout << EnterDescription;
	std::cin >> this->_desription;
	std::cout << TrueOrFalseCorrectAnswer;
	std::cin >> this->_correctAnswer;
	std::cout << EnterPoints;
	std::cin >> this->_points;
}
void TrueOrFalseQuestion::print(std::ostream& os) const {
	os << this->_desription << " (" << _points << " points) " << std::endl;
	os << TrueOrFalseUserAnswer;
}

QuestionType TrueOrFalseQuestion::type() const{
	return QuestionType::TrueOrFalse;
}

Question* TrueOrFalseQuestion::clone() const{
	return new TrueOrFalseQuestion(*this);
}

void TrueOrFalseQuestion::printCorrectAnswer(std::ostream& os) const{
	os << InputCorrectAnswer << this->_correctAnswer << std::endl;
}


//int TrueOrFalseQuestion::start() const{
//	this->print(std::cout);
//
//	MyString answer = 
//
//}


int TrueOrFalseQuestion::checkAnswer(const MyString& userAnswer) const{
	return this->_correctAnswer.toLower() == userAnswer.toLower() ? this->_points : 0;
}





