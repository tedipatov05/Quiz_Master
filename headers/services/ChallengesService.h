#pragma once
#include "../../headers/helpers/Vector.hpp"
#include "../../headers/Context.h"

class ChallengesService{

public:

	static Vector<int> getFinishedChallenges(const Context& ctx, int userId);
	static Vector<int> getUnfinishedChallenges(const Context& ctx, int userId);
	static void printUnfinishedChallenges(const Context& ctx, int progressTestMode, int progressNormalMode, int createdQuizzes);
	static void printFinishedChallenges(const Context& ctx);
	static void checkChallenge(Context& ctx, User* user, int value, ChallengeType type);
};

