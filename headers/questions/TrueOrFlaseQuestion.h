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
	void print(std::ostream& os) const override;
	Question* clone() const override;
	QuestionType type() const;
	int checkAnswer(const MyString& userAnswer) const;
	void printCorrectAnswer(std::ostream& os) const override;

	//int start() const override;

private:
	MyString _correctAnswer;
};
