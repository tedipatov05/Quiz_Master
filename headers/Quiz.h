#pragma once
#include "helpers/Vector.hpp"
#include "questions/QuestionsRepository.h"
#include "users/User.h"


class QuizAttempt;

enum class QuizMode{
	Test,
	Normal
};

class Quiz{
public:
	Quiz() = default;
	Quiz(int creatorId, int quizId);

	void saveInTextFile(std::ofstream& ofs, const User* creator) const;
	QuizAttempt start(QuizMode mode, bool isShuffle, int userId);
	void print(std::ostream& ofs) const;
	void saveInBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
	void readQuiz();

	void approveQuiz();


private:

	
	QuestionsRepository _questionsRepo;
	int creatorId;
	int quizId;
	MyString quizName;
	bool isApproved;
	bool isActive;
	int maxPoints;


	void writeCenteredRow(std::ostream& ofs, const MyString& line) const;
	void shuffle(Vector<int>& numbers);
};

