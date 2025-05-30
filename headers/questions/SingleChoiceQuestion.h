#pragma once
#include "Question.h"
#include "../helpers/MyString.h"
#include "../helpers/Vector.hpp"

class SingleChoiceQuestion : public Question{
public:
	SingleChoiceQuestion() = default;
	SingleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const MyString& correctAnswer);

	void readFromBinaryFile(std::ifstream& ifs) override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void print(std::ostream& os) const override;
	void read() override;
	Question* clone() const override;
	bool isCorrectAnswer(const MyString& userAnswer) const;

private:
	Vector<MyString> _answers;
	MyString _correctAnswer;
};
