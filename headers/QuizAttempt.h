#pragma once
#include "Quiz.h"

class QuizAttempt{
public:

	QuizAttempt() = default;
	QuizAttempt(QuizMode mode, int userId, int quizId, int points);

	int getPoints() const;
	QuizMode getMode() const;
	int getQuizId() const;
	int getUserId() const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);


private:

	QuizMode mode;
	int _userId;
	int _quizId;
	int points;

};

