#include <iostream>

#include "../../headers/questions/TrueOrFlaseQuestion.h"

TrueOrFalseQuestion::TrueOrFalseQuestion(const MyString& description, int points, const MyString& correctAnswer)
	: Question(description, points), _correctAnswer(correctAnswer) {}

void TrueOrFalseQuestion::readFromBinaryFile(std::ifstream& ifs) {
	ifs.read((char*)&this->_points, sizeof(this->_points));
	this->_desription.readFromBinaryFile(ifs);
	this->_correctAnswer.readFromBinaryFile(ifs);
}

void TrueOrFalseQuestion::writeToBinaryFile(std::ofstream& ofs) const {
	ofs.write((const char*)&this->_points, sizeof(this->_points));
	this->_desription.writeToBinaryFile(ofs);
	this->_correctAnswer.writeToBinaryFile(ofs);
}
void TrueOrFalseQuestion::read() {
	std::cout << "Enter question description: ";
	std::cin >> this->_desription;
	std::cout << std::endl;
	std::cout << "Enter correct answer (True/False): ";
	std::cin >> this->_correctAnswer;
	std::cout << std::endl;
	std::cout << "Enter points: ";
	std::cin >> this->_points;
}
void TrueOrFalseQuestion::print() const {
	std::cout << this->_desription << std::endl;
}



