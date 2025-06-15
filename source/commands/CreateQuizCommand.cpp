#include "../../headers/commands/CreateQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/ChallengesService.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/UserService.h"

CreateQuizCommand::CreateQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void CreateQuizCommand::execute(){
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

	QuizService::addQuiz(ctx);
	int createdQuizzes = UserService::getCreatedQuizzesCount(ctx, user->getUserId());
	ChallengesService::checkChallenge(ctx, user, createdQuizzes, ChallengeType::CreatedQuizes);
}


