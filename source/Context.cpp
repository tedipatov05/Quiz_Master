#include "../headers/Context.h"

#include "../headers/helpers/FIleHelper.hpp"
#include "../headers/users/Admin.h"


int Context::nextUserId = 100;
int Context::nextQuizId = 50;
Context* Context::instance = nullptr;


void Context::seedChallenges(ChallengeType type, int step, int end, int& id) {

	for (int i = step; i <= end; i += step) {
		MyString str;
		if (type == ChallengeType::CreatedQuizes) {
			str = "Create " + toString(i) + " quizzes";
		}
		else if (type == ChallengeType::SolvingInNormalMode) {
			str = "Complete " + toString(i) + " quizzes in normal mode";
		}
		else if (type == ChallengeType::SolvingInTestMode) {
			str = "Complete " + toString(i) + " quizzes in test mode";
		}
		

		Challenge challenge(id, i, type, str);
		this->challeges.push_back(challenge);
		id++;
	}
}

void Context::seedAdmin(){
	User* user = new Admin("Teodor", "Patov", "patlaka", "111111", 1);
	this->users.addUser(user);
	this->areUsersChanged = true;
	delete user;
}



void Context::readChallenges(const MyString& filename) {
	readFromBinaryFile<Challenge>(filename, this->challeges);

	if (this->challeges.size() == 0) {
		int id = 200;

		seedChallenges(ChallengeType::CreatedQuizes, 5, 30, id);
		seedChallenges(ChallengeType::SolvingInNormalMode, 10, 100, id);
		seedChallenges(ChallengeType::SolvingInTestMode, 10, 100, id);

		for (size_t i = 0; i < this->challeges.size(); i++){
			writeObjectToBinaryFile<Challenge>(filename, this->challeges[i]);
		}
	}
}

void Context::readMessages(const MyString& filename) {
	readFromBinaryFile<Message>(filename, this->messages);
}

void Context::readLikedQuizzes(const MyString& filename) {
	readFromBinaryFile<UserQuiz>(filename, this->likedQuizzes);
}

void Context::readFavouriteQuizzes(const MyString& filename) {
	readFromBinaryFile<UserQuiz>(filename, this->favouriteQuizzes);
}

void Context::readQuizzes(const MyString& filename) {
	readFromBinaryFile<Quiz>(filename, this->quizzes);
}

void Context::readQuizAttempts(const MyString& filename) {
	readFromBinaryFile<QuizAttempt>(filename, this->quizAttempts);
}

void Context::readReports(const MyString& filename) {
	readFromBinaryFile<Report>(filename, this->reports);
}

void Context::readUserChallenge(const MyString& filename) {
	readFromBinaryFile<UserChallenge>(filename, this->userChallenges);
}

Context::Context() : currentUserType(UserType::None), currentUserId(-1), areUsersChanged(false) {
	this->users.readFromBinaryFile(userFile);
	if (this->users.size() == 0){
		seedAdmin();
	}

	this->readQuizzes(quizzesFile);
	this->readChallenges(challengesFile);
	this->readFavouriteQuizzes(favouriteQuizzesFile);
	this->readLikedQuizzes(likedQuizzesFile);
	this->readMessages(messagesFile);
	this->readReports(reportsFile);
	this->readUserChallenge(userChallengesFile);
	this->readQuizAttempts(quizAttemptsFile);

	setNextUserId();
	setNextQuizId();
}

void Context::setNextUserId() {
	int maxId = 0;
	for (int i = 0; i < this->users.size(); i++) {
		int userId = this->users[i].getUserId();
		maxId = std::max(maxId, userId);
	}

	Context::nextUserId = maxId + 1;
}

void Context::setNextQuizId(){
	int maxQuizId = 0;
	for (int i = 0; i < this->quizzes.size(); i++) {
		int quizId = this->quizzes[i].id();
		maxQuizId = std::max(maxQuizId, quizId);
	}

	Context::nextQuizId = maxQuizId + 1;
}



Context* Context::getInstance() {
	if (instance == nullptr) {
		instance = new Context();
	}

	return instance;
}

Context::~Context() {
	if (areUsersChanged) {
	}
}












