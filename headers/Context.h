#pragma once
#include <iostream>

#include "Message.h"
#include "Report.h"
#include "challenges/Challenge.h"
#include "challenges/UserChallenge.h"
#include "helpers/SystemMessages.h"
#include "helpers/Vector.hpp"
#include "quizes/Quiz.h"
#include "quizes/UserQuiz.h"
#include "users/UserRepository.h"
#include "quizes/QuizAttempt.h"
//#include "helpers/HelperFunctions.hpp"

class Context{


public:
	UserRepository users;
	Vector<Quiz> quizzes;
	Vector<QuizAttempt> quizAttempts;
	Vector<Challenge> challeges;
	Vector<UserChallenge> userChallenges;
	Vector<UserQuiz> likedQuizzes;
	Vector<UserQuiz> favouriteQuizzes;
	Vector<Report> reports;
	Vector<Message> messages;

	int currentUserId;
	UserType currentUserType;

	static int nextUserId;
	static int nextQuizId;
	bool areUsersChanged;

	Context(const Context& context) = delete;
	Context& operator=(const Context& context) = delete;

	static Context* getInstance();

	~Context();
protected:

	static Context* instance;

private:

	Context();

	void readQuizzes(const MyString& filename);
	void readQuizAttempts(const MyString& filename);
	void readChallenges(const MyString& filename);
	void readUserChallenge(const MyString& filename);
	void readLikedQuizzes(const MyString& filename);
	void readFavouriteQuizzes(const MyString& filename);
	void readReports(const MyString& filename);
	void readMessages(const MyString& filename);

	void seedChallenges(ChallengeType type, int step, int end, int& id);
	void seedAdmin();

	void setNextUserId();
	void setNextQuizId();

};

template <typename T>
void readFromBinaryFile(const MyString& filename, Vector<T>& objects) {
	std::ifstream ifs(filename.data(), std::ios::binary);

	createFileIfNotExists(ifs, filename);


	if (!ifs.is_open()) {
		std::cout << FileNotOpened << std::endl;
		return;
	}

	ifs.seekg(std::ios::beg);

	objects.clear();

	while (!ifs.eof()) {

		T object;
		object.readFromBinaryFile(ifs);

		if (!ifs){
			break;
		}

		objects.push_back(object);
	}

	ifs.close();
}



