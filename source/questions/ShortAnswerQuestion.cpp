#include <iostream>

#include "../../headers/questions/ShortAnswerQuestion.h"

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

void ShortAnswerQuestion::print(std::ostream& os) const {
	int words = _correctAnswer.countCharacter(' ') + 1;
	os << this->_desription << " (" << words << " words) " << "(" << _points << " points)" << std::endl;
}

bool ShortAnswerQuestion::isCorrectAnswer(const MyString& userAnswer) const {
	return this->_correctAnswer.toLower() == userAnswer.toLower();
}


void ShortAnswerQuestion::read() {
	std::cout << "Enter description: ";
	std::cin >> this->_desription;

	std::cout << "Enter correct answer: ";
	std::cin >> this->_correctAnswer;

	std::cout << "Enter points: ";
	std::cin >> this->_points;


}












