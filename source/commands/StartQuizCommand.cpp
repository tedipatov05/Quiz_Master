#include "../../headers/commands/StartQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/ChallengesService.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/UserService.h"

StartQuizCommand::StartQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx) {

}

void StartQuizCommand::execute() {

	User* user = ctx.users.findUser(ctx.currentUserId);

	Vector<MyString> data = split(buffer, " ");
	if (data.size() < 3 || !isNumber(data[1])) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	bool isShuffle = data.size() == 4 && data[3].toLower() == "shuffle";

	Quiz* quiz = QuizService::getQuizById(ctx, toInt(data[1]));

	try {

		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);
		Validate::isQuizExists(quiz);
		Validate::isAlreadyDeleted(quiz);
		Validate::isApproved(quiz);
		QuizService::startQuiz(ctx, user, toInt(data[1]), fromStringToMode(data[2]), isShuffle);

	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	

	int attempts = UserService::getAttemptsCountInMode(ctx, user->getUserId(), fromStringToMode(data[2]));
	ChallengesService::checkChallenge(ctx, user, attempts, fromStringToChallengeType(data[2]));

}


