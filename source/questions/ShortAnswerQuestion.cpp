#include <iostream>

#include "../../headers/questions/ShortAnswerQuestion.h"

#include "../../headers/helpers/SystemMessages.h"

ShortAnswerQuestion::ShortAnswerQuestion(const MyString& description, int points, const MyString& answer)
	: Question(description, points), _correctAnswer(answer) {

}

void ShortAnswerQuestion::readFromBinaryFile(std::ifstream& ifs) {
	ifs.read((char*)&this->_points, sizeof(this->_points));
	this->_desription.readFromBinaryFile(ifs);
	this->_correctAnswer.readFromBinaryFile(ifs);
}

void ShortAnswerQuestion::writeToBinaryFile(std::ofstream& ofs) const {
	QuestionType questionType = this->type();
	ofs.write((const char*)&questionType, sizeof(questionType));

	ofs.write((const char*)&this->_points, sizeof(this->_points));
	this->_desription.writeToBinaryFile(ofs);
	this->_correctAnswer.writeToBinaryFile(ofs);
}

QuestionType ShortAnswerQuestion::type() const {
	return QuestionType::ShortAnswer;
}

Question* ShortAnswerQuestion::clone() const {
	return new ShortAnswerQuestion(*this);
}

void ShortAnswerQuestion::printCorrectAnswer(std::ostream& os) const{
	os << InputCorrectAnswer << this->_correctAnswer << std::endl;
}
//
//int ShortAnswerQuestion::start() const{
//
//	this->print(std::cout);
//	MyString answer;
//	std::cin >> answer;
//
//	return isCorrectAnswer(answer) ? this->_points : 0;
//}
//


void ShortAnswerQuestion::print(std::ostream& os) const {
	int words = _correctAnswer.countCharacter(' ') + 1;
	os << this->_desription << " (" << words << " words) " << "(" << _points << " points)" << std::endl;
	os << "Enter your answer here : ";
}

int ShortAnswerQuestion::checkAnswer(const MyString& userAnswer) const {

	return this->_correctAnswer.toLower() == userAnswer.toLower() ? this->_points : 0;
}


void ShortAnswerQuestion::read() {
	std::cout << EnterDescription;
	std::cin >> this->_desription;

	std::cout << ShACorrectAnswer;
	std::cin >> this->_correctAnswer;

	std::cout << EnterPoints;
	std::cin >> this->_points;
}












