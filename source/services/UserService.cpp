#include "../../headers/services/UserService.h"

#include <iomanip>


Vector<MyString> UserService::getCreatedQuizzes(const Context& ctx, int userId) {

	Vector<MyString> createdQuizzes;

	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].creator() == userId) {
			MyString str = "[" + toString(ctx.quizzes[i].id()) + "] " + ctx.quizzes[i].name();
			createdQuizzes.push_back(str);
		}
	}


	return createdQuizzes;
}

Vector<MyString> UserService::getLikedQuizzes(const Context& ctx, int userId) {
	Vector<MyString> likedQuizzes;

	for (size_t i = 0; i < ctx.likedQuizzes.size(); i++) {
		if (ctx.likedQuizzes[i].getUserId() == userId && ctx.likedQuizzes[i].isActive()) {
			MyString str = "[" + toString(ctx.likedQuizzes[i].getQuizId()) + "] ";
			likedQuizzes.push_back(str);
		}
	}

	return likedQuizzes;

}

Vector<MyString> UserService::getFavouriteQuizzes(const Context& ctx, int userId) {
	Vector<MyString> favouriteQuizzes;

	for (size_t i = 0; i < ctx.favouriteQuizzes.size(); i++) {
		if (ctx.favouriteQuizzes[i].getUserId() == userId && ctx.favouriteQuizzes[i].isActive()) {
			MyString str = "[" + toString(ctx.likedQuizzes[i].getQuizId()) + "] ";
			favouriteQuizzes.push_back(str);
		}
	}

	return favouriteQuizzes;
}

void UserService::printUserInfo(const User* user) {

	MyString levelInfo = "Level: " + toString(user->getLevel()) + " ";
	MyString pointsInfo = toString(calculatePointsToNextLevel(user)) + "/" + toString(nextLevelPoints(user->getLevel())) + " points to next level.";

	std::cout << user->getFirstName() << " " << user->getLastName() << " @" << user->getUsername() << std::endl;
	std::cout << std::left << std::setw(20) << levelInfo << pointsInfo << std::endl;

}

int UserService::calculatePointsToNextLevel(const User* user) {
	int level = user->getLevel();
	int points = 0;

	while (level > 0) {
		if (level > 30) {
			points += 4000;
		}
		else if (level > 20) {
			points += 3000;
		}
		else if (level > 10) {
			points += 2000;
		}
		else {
			points += 1000;
		}

		level--;
	}

	return user->getPoints() - points;

}

int UserService::nextLevelPoints(int level) {
	int points = 0;
	if (level > 30) {
		points = 4000;
	}
	else if (level > 20) {
		points = 3000;
	}
	else if (level > 10) {
		points = 2000;
	}
	else {
		points = 1000;
	}


	return points;
}

int UserService::getCreatedQuizzesCount(const Context& ctx, int userId) {
	return (int)getCreatedQuizzes(ctx, userId).size();
}

int UserService::getAttemptsCountInMode(const Context& ctx, int userId, QuizMode mode) {
	int count = 0;

	for (size_t i = 0; i < ctx.quizAttempts.size(); i++) {
		if (ctx.quizAttempts[i].getUserId() == userId && ctx.quizAttempts[i].getMode() == mode) {
			count++;
		}
	}

	return count;
}

Vector<Quiz> UserService::getUserQuizzes(const Context& ctx, int userId) {

	Vector<Quiz> quizzes;
	for (size_t i = 0; i < ctx.quizzes.size(); i++) {
		if (ctx.quizzes[i].creator() == userId) {
			quizzes.push_back(ctx.quizzes[i]);
		}
	}


	return quizzes;

}










