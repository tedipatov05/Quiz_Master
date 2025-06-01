#pragma once
#include "Question.h"
#include "../helpers/MyString.h"
#include "../helpers/Vector.hpp"
#include "../helpers/Pair.hpp"

class MatchingPairsQuestion : public Question {

public:

	MatchingPairsQuestion() = default;
	MatchingPairsQuestion(const MyString& description, int points, const Vector<MyString>& leftColumn, const Vector<MyString>& rightColumn, const Vector<Pair<MyString, MyString>>& correctAnswer);

	void print(std::ostream& os) const override;
	void read() override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	Question* clone() const override;
	QuestionType type() const override;

	int countCorrectAnswers(const Vector<Pair<MyString, MyString>>& userAnswer);

private:
	Vector<Pair<MyString, MyString>> _correctAnswer;
	Vector<MyString> _leftColumn;
	Vector<MyString> _rightColumn;

	void readColumn(char ch, Vector<MyString>& column, const MyString& columnType);
	void readCorrectAnswers();

	void writeColumnToBinary(std::ofstream& ofs, const Vector<MyString>& column) const;
	void writeCorrectAnswersToBinary(std::ofstream& ofs, const Vector<Pair<MyString, MyString>>& answers) const;

	void readColumnFromBinary(std::ifstream& ifs, Vector<MyString>& column);
	void readCorrectAnswersFromBinary(std::ifstream& ifs, Vector<Pair<MyString, MyString>>& answers);
};

