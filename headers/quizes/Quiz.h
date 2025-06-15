#pragma once
#include "../questions/QuestionsRepository.h"
#include "../users/User.h"
#include "QuizMode.h"
#include "QuizAttempt.h"

class Quiz{
public:
	Quiz() = default;
	Quiz(int creatorId, int quizId);

	void saveInTextFile(std::ofstream& ofs, const User* creator) const;
	QuizAttempt start(QuizMode mode, bool isShuffle, int userId);
	void print(std::ostream& ofs) const;
	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
	void read();

	void approveQuiz();
	void reject();

	int id() const;
	bool approved() const;
	bool active() const;
	int creator() const;
	MyString name() const;
	int questionsCount() const;


private:

	
	QuestionsRepository _questionsRepo;
	int creatorId;
	int quizId;
	MyString quizName;
	bool isApproved;
	bool isActive;
	int maxPoints;


	void writeCenteredRow(std::ostream& ofs, const MyString& line) const;

	
};


bool operator==(const Quiz& lhs, const Quiz& rhs);

