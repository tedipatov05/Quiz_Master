#include "../headers/Context.h"


int Context::nextUserId = 100;
int Context::nextQuizId = 50;
Context* Context::instance = nullptr;


void Context::seedChallenges(ChallengeType type, int step, int end, int& id){

	for (int i = step; i <= end; i+=step){

		Challenge challenge(id, i, type);
		this->challeges.push_back(challenge);
		id++;
	}
}


void Context::readChallenges(const MyString& filename){
	readFromBinaryFile<Challenge>(filename, this->challeges);

	if (this->challeges.size() == 0){
		int id = 200;

		seedChallenges(ChallengeType::CreatedQuizes, 5, 30, id);
		seedChallenges(ChallengeType::SolvingInNormalMode, 10, 100, id);
		seedChallenges(ChallengeType::SolvingInTestMode, 10, 100, id);
	}
}

void Context::readMessages(const MyString& filename){
	readFromBinaryFile<Message>(filename, this->messages);
}

void Context::readLikedQuizzes(const MyString& filename){
	readFromBinaryFile<UserQuiz>(filename, this->likedQuizzes);
}

void Context::readFavouriteQuizzes(const MyString& filename){
	readFromBinaryFile<UserQuiz>(filename, this->favouriteQuizzes);
}

void Context::readQuizzes(const MyString& filename){
	readFromBinaryFile<Quiz>(filename, this->quizzes);
}

void Context::readQuizAttempts(const MyString& filename){
	readFromBinaryFile<QuizAttempt>(filename, this->quizAttempts);
}

void Context::readReports(const MyString& filename){
	readFromBinaryFile<Report>(filename, this->reports);
}

void Context::readUserChallenge(const MyString& filename){
	readFromBinaryFile<UserChallenge>(filename, this->userChallenges);
}

Context::Context() : currentUserType(UserType::None), currentUserId(-1) {
	this->users.readFromBinaryFile(userFile);
	this->readQuizzes(quizzesFile);
	this->readChallenges(challengesFile);
	this->readFavouriteQuizzes(favouriteQuizzesFile);
	this->readLikedQuizzes(likedQuizzesFile);
	this->readMessages(messagesFile);
	this->readReports(reportsFile);
	this->readUserChallenge(userChallengesFile);

}

Context* Context::getInstance(){
	if (instance == nullptr){
		instance = new Context();
	}

	return instance;
}











