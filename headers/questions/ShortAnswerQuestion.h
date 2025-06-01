#pragma once
#include "Question.h"
#include "../helpers/MyString.h"
#include "../helpers/Vector.hpp"

class ShortAnswerQuestion: public Question{
public:
	ShortAnswerQuestion() = default;
	ShortAnswerQuestion(const MyString& description, int points, const MyString& answer);

	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	void read() override;
	void print(std::ostream& os) const override;
	Question* clone() const override;
	QuestionType type() const override;

	bool isCorrectAnswer(const MyString& userAnswer) const;


private:
	MyString _correctAnswer;
};