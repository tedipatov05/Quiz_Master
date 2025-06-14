#include "../../headers/services/ChallengesService.h"

#include "../../headers/commands/Command.h"
#include "../../headers/services/UserService.h"

Vector<int> ChallengesService::getFinishedChallenges(const Context& ctx, int userId) {

	Vector<int> finishedChallenges;

	for (size_t i = 0; i < ctx.userChallenges.size(); i++) {
		if (ctx.userChallenges[i].getUserId() == userId) {
			finishedChallenges.push_back(ctx.userChallenges[i].getChallengeId());
		}
	}

	return finishedChallenges;
}

Vector<int> ChallengesService::getUnfinishedChallenges(const Context& ctx, int userId) {
	Vector<int> finishedChallenges;

	for (size_t i = 0; i < ctx.userChallenges.size(); i++) {
		if (ctx.userChallenges[i].getUserId() != userId) {
			finishedChallenges.push_back(ctx.userChallenges[i].getChallengeId());
		}
	}

	return finishedChallenges;
}

void ChallengesService::printUnfinishedChallenges(const Context& ctx, int progressTestMode, int progressNormalMode, int createdQuizzes) {

	Vector<int> finishedChallenges = getFinishedChallenges(ctx, ctx.currentUserId);

	for (size_t i = 0; i < ctx.challeges.size(); i++) {
		if (!finishedChallenges.contains(ctx.challeges[i].id())) {
			if (ctx.challeges[i].type() == ChallengeType::CreatedQuizes) {
				std::cout << ctx.challeges[i].getChallenge() << " (" << createdQuizzes << "/" << ctx.challeges[i].count() << ")" << std::endl;
			}
			else if (ctx.challeges[i].type() == ChallengeType::SolvingInNormalMode) {
				std::cout << ctx.challeges[i].getChallenge() << " (" << progressNormalMode << "/" << ctx.challeges[i].count() << ")" << std::endl;
			}
			else {
				std::cout << ctx.challeges[i].getChallenge() << " (" << progressTestMode << "/" << ctx.challeges[i].count() << ")" << std::endl;
			}
		}
	}

}

void ChallengesService::printFinishedChallenges(const Context& ctx) {
	Vector<int> finishedChallenges = getFinishedChallenges(ctx, ctx.currentUserId);

	if (finishedChallenges.size() == 0) {
		std::cout << NoDataToDisplay << std::endl;
		return;
	}

	for (size_t i = 0; i < ctx.userChallenges.size(); i++) {
		if (finishedChallenges.contains(ctx.userChallenges[i].getChallengeId())) {
			std::cout << ctx.userChallenges[i].getTime() << " | " << ctx.userChallenges[i].getMessage() << std::endl;
		}
	}
}

void ChallengesService::checkChallenge(Context& ctx, User* user, int value, ChallengeType type) {
	Vector<int> finishedChallenges = getFinishedChallenges(ctx, user->getUserId());
	UserChallenge* challenge = nullptr;

	for (size_t i = 0; i < ctx.challeges.size(); i++) {
		if (ctx.challeges[i].count() == value && !finishedChallenges.contains(ctx.challeges[i].id()) && ctx.challeges[i].type() == type) {
			challenge = new UserChallenge(ctx.challeges[i].id(), user->getUserId(), ctx.challeges[i].getChallenge());
			user->increasePoints(ctx.challeges[i].calcPoints());
			ctx.areUsersChanged = true;
			break;
		}
	}

	// TODO: Check whether it updates level
	int pointsToNextLevel = UserService::calculatePointsToNextLevel(user);
	int nexLevelPoints = UserService::nextLevelPoints(user->getLevel());

	if (pointsToNextLevel >= nexLevelPoints){
		user->updateLevel();
	}

	if (challenge != nullptr){
		
		ctx.userChallenges.push_back(*challenge);
		writeObjectToBinaryFile(userChallengesFile, *challenge);
	}
}



