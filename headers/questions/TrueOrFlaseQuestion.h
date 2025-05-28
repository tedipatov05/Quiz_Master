#pragma once
#include "Question.h"
#include "../helpers/MyString.h"

class TrueOrFalseQuestion : public Question
{
public:
	TrueOrFalseQuestion() = default;
	TrueOrFalseQuestion(const MyString& description, int points, const MyString& correctAnswer);

	void readFromBinaryFile(std::ifstream& ifs) override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void read() override;
	void print() const override;
	Question* clone() const override;

private:
	MyString _correctAnswer;
};
