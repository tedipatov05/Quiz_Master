#pragma once
#include "helpers/Vector.hpp"
#include "questions/QuestionsRepository.h"
#include "users/User.h"



class Quiz{
public:
	Quiz() = default;
	Quiz(int creatorId, int quizId);

	void saveInTextFile(std::ofstream& ofs, const User* creator) const;
	int start(MyString mode1, bool isShuffle);
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

