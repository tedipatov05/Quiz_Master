#pragma once
#include "../helpers/MyString.h"
#include "../helpers/Vector.hpp"
#include "../Context.h"


class UserService{
public:
	static Vector<MyString> getCreatedQuizzes(const Context& ctx, int userId);
	static Vector<MyString> getLikedQuizzes(const Context& ctx, int userId);
	static Vector<MyString> getFavouriteQuizzes(const Context& ctx, int userId);
	static void printUserInfo(const User* user);
	static int calculatePointsToNextLevel(const User* user);
	static int nextLevelPoints(int level);
	static int getCreatedQuizzesCount(const Context& ctx, int userId);
	static int getAttemptsCountInMode(const Context& ctx, int userId, QuizMode mode);
	static Vector<Quiz> getUserQuizzes(const Context& ctx, int userId);
	static void printAvailableCommands(const Context& ctx);
};

