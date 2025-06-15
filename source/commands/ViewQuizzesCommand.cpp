#include "../../headers/commands/ViewQuizzesCommand.h"
#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"

ViewQuizzesCommand::ViewQuizzesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}


void ViewQuizzesCommand::execute(){
	User* user = ctx.users.findUser(ctx.currentUserId);

	try {
		Validate::isLoggedIn(ctx);
		//Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);
	}
	catch (std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	QuizService::printQuizzesInfo(ctx, ctx.quizzes);
}
