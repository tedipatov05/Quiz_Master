#include "../../headers/questions/SingleChoiceQuestion.h"
#include <iostream>

SingleChoiceQuestion::SingleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const MyString& correctAnswer)
	: Question(description, points), _answers(answers), _correctAnswer(correctAnswer){
	
}


void SingleChoiceQuestion::read(){
	std::cout << "Enter description: ";
	std::cin >> this->_desription;
	std::cout << std::endl;

	char ch = 'A';

	for (size_t i = 0; i < this->_answers.size(); i++){
		std::cout << "Enter answer " << ch << ": ";
		std::cin >> this->_answers[i];
		std::cout << std::endl;
		ch++;
	}

	std::cout << "Enter correct answer (A,B,C,D): ";
	std::cin >> this->_correctAnswer;
	std::cout << std::endl;

	std::cout << "Enter points: ";
	std::cin >> this->_points;
	std::cout << std::endl;
}

void SingleChoiceQuestion::print() const{
	std::cout << this->_desription << "(" << this->_points << " points)" << std::endl;

	char ch = 'A';
	for (size_t i = 0; i < this->_answers.size(); i++){
		std::cout << "	  ";
		std::cout << ch << ".  " << this->_answers[i] << std::endl;
		ch++;
	}
}

void SingleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs){
	ifs.read((char*)&this->_points, sizeof(this->_points));
	this->_desription.readFromBinaryFile(ifs);
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++){
		this->_answers[i].readFromBinaryFile(ifs);
	}

	this->_correctAnswer.readFromBinaryFile(ifs);

}

void SingleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->_points, sizeof(this->_points));
	this->_desription.writeToBinaryFile(ofs);
	size_t size = this->_answers.size();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++){
		this->_answers[i].writeToBinaryFile(ofs);
	}

	this->_correctAnswer.writeToBinaryFile(ofs);

	
}








