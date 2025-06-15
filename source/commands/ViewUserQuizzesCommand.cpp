#include "../../headers/commands/ViewUserQuizzesCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/UserService.h"

ViewUserQuizzesCommand::ViewUserQuizzesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ViewUserQuizzesCommand::execute(){

	Vector<MyString> data = split(buffer, " ");
	if (data.size() != 2){
		std::cout << InvalidFormat << std::endl;
		return;
	}


	User* user = ctx.users.findByUsername(data[1]);
	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);
		Validate::isBanned(user);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	Vector<Quiz> quizzes = UserService::getUserQuizzes(ctx, user->getUserId());
	QuizService::printQuizzesInfo(ctx, quizzes);

}


