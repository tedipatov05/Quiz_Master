#include "../../headers/commands/ChallengesCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/ChallengesService.h"
#include "../../headers/services/UserService.h"

ChallengesCommand::ChallengesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ChallengesCommand::execute(){

	User* user = ctx.users.findUser(ctx.currentUserId);
	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);

	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	int progressTestMode = UserService::getAttemptsCountInMode(ctx, user->getUserId(), QuizMode::Test);
	int progressNormalMode = UserService::getAttemptsCountInMode(ctx, user->getUserId(), QuizMode::Normal);
	int createdQuizzes = UserService::getCreatedQuizzesCount(ctx, user->getUserId());


	ChallengesService::printUnfinishedChallenges(ctx, progressTestMode, progressNormalMode, createdQuizzes);


}


