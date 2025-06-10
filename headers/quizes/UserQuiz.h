#pragma once
#include <fstream>

class UserQuiz{

public:

	UserQuiz() = default;
	UserQuiz(int userId, int quizId);

	int getUserId() const;
	int getQuizId() const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs) const;

private:

	int _userId;
	int _quizId;
};

