#pragma once
#include "Question.h"
#include "../helpers/Vector.hpp"

class MultipleChoiceQuestion : public Question{

public:
	MultipleChoiceQuestion() = default;
	MultipleChoiceQuestion(const MyString& description, int points, const Vector<MyString>& answers, const Vector<MyString>& correctAnswers);

	void readFromBinaryFile(std::ifstream& ifs) override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void print(std::ostream& os) const override;
	void read() override;
	Question* clone() const override;
	QuestionType type() const override;
	int isCorrectAnswer(const Vector<MyString>& userAnswer) const;

	void readCollection(std::ifstream& ifs, Vector<MyString>& collection);
	void writeCollection(std::ofstream& ofs, const Vector<MyString>& collection) const;

private:
	Vector<MyString> _answers;
	Vector<MyString> _correctAnswer;
};

