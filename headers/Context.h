#pragma once
#include "Message.h"
#include "Report.h"
#include "challenges/Challenge.h"
#include "challenges/UserChallenge.h"
#include "helpers/Vector.hpp"
#include "quizes/Quiz.h"
#include "quizes/UserQuiz.h"
#include "users/UserRepository.h"

class Context{


public:
	UserRepository users;
	Vector<Quiz> quizzes;
	Vector<QuizAttempt> quizAttempts;
	Vector<Challenge> challeges;
	Vector<UserChallenge> userChallenge;
	Vector<UserQuiz> likedQuizzes;
	Vector<UserQuiz> favouriteQuizzes;
	Vector<Report> reports;
	Vector<Message> messages;

	static int nextUserId;
	static int nextQuizId;

	Context(const Context& context) = delete;
	Context& operator=(const Context& context) = delete;

	static Context* getInstance();

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



};

