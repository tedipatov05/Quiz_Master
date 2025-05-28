#pragma once
#include "Question.h"
#include "../helpers/MyString.h"
#include "../helpers/Vector.hpp"

class SingleChoiceQuestion : public Question{
public:
	SingleChoiceQuestion() = default;
	SingleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const MyString& correctAnswer);

	virtual void readFromBinaryFile(std::ifstream& ifs) override;
	virtual void writeToBinaryFile(std::ofstream& ofs) const override;
	virtual void print() const override;
	virtual void read() override;

private:
	Vector<MyString> _answers;
	MyString _correctAnswer;
};
