#include "../../headers/commands/ViewUserCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/UserService.h"
#include "../../headers/services/QuizService.h"

ViewUserCommand::ViewUserCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ViewUserCommand::execute(){
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
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
	}

	UserService::printUserInfo(user);
	Vector<MyString> userCreatedQuizzes = UserService::getCreatedQuizzes(ctx, user->getUserId());
	Vector<MyString> userLikedQuizzes = UserService::getLikedQuizzes(ctx, user->getUserId());
	Vector<MyString> userFavouriteQuizzes = UserService::getFavouriteQuizzes(ctx, user->getUserId());

	UserService::printUserInfo(user);
	QuizService::printUserQuizzes(userCreatedQuizzes, CreatedQuizzes, true);
	QuizService::printUserQuizzes(userLikedQuizzes, LikedQuizzes, false);
	QuizService::printUserQuizzes(userFavouriteQuizzes, FavouriteQuizzes, false);

}

