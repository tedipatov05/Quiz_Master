#include "../../headers/questions/SingleChoiceQuestion.h"
#include <iostream>

SingleChoiceQuestion::SingleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const MyString& correctAnswer)
	: Question(description, points), _answers(answers), _correctAnswer(correctAnswer){
	
}


void SingleChoiceQuestion::read(){
	_answers.clear();

	std::cout << "Enter description: ";
	std::cin >> this->_desription;

	char ch = 'A';

	for (size_t i = 0; i < 4; i++){
		std::cout << "Enter answer " << ch << ": ";
		MyString answer;
		std::cin >> answer;
		_answers.push_back(answer);
		ch++;
	}

	std::cout << "Enter correct answer (A,B,C,D): ";
	std::cin >> this->_correctAnswer;

	std::cout << "Enter points: ";
	std::cin >> this->_points;
}

void SingleChoiceQuestion::print(std::ostream& os) const{
	os << this->_desription << " (" << this->_points << " points)" << std::endl;

	char ch = 'A';
	for (size_t i = 0; i < this->_answers.size(); i++){
		os << "  ";
		os << ch << ".  " << this->_answers[i] << std::endl;
		ch++;
	}
}

void SingleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs){
	_answers.clear();

	this->_desription.readFromBinaryFile(ifs);
	size_t size;
	ifs.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++){
		MyString answer;
		answer.readFromBinaryFile(ifs);
		this->_answers.push_back(answer);
	}

	this->_correctAnswer.readFromBinaryFile(ifs);
	ifs.read((char*)&this->_points, sizeof(this->_points));

}

void SingleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const{
	QuestionType questionType = this->type();
	ofs.write((const char*)&questionType, sizeof(questionType));
	
	this->_desription.writeToBinaryFile(ofs);
	size_t size = this->_answers.size();
	ofs.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++){
		this->_answers[i].writeToBinaryFile(ofs);
	}

	this->_correctAnswer.writeToBinaryFile(ofs);
	ofs.write((const char*)&this->_points, sizeof(this->_points));

	
}

Question* SingleChoiceQuestion::clone() const{
	return new SingleChoiceQuestion(*this);
}

QuestionType SingleChoiceQuestion::type() const{
	return QuestionType::SingleChoice;
}

bool SingleChoiceQuestion::isCorrectAnswer(const MyString& userAnswer) const{
	return this->_correctAnswer.toLower() == userAnswer.toLower();
}










