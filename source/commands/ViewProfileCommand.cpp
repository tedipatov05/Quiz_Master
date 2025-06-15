#include "../../headers/commands/ViewProfileCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/UserService.h"

ViewProfileCommand::ViewProfileCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ViewProfileCommand::execute(){

	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		
	}
	catch (std::invalid_argument& ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	User* user = ctx.users.findUser(ctx.currentUserId);
	Vector<MyString> userCreatedQuizzes = UserService::getCreatedQuizzes(ctx, user->getUserId());
	Vector<MyString> userLikedQuizzes = UserService::getLikedQuizzes(ctx, user->getUserId());
	Vector<MyString> userFavouriteQuizzes = UserService::getFavouriteQuizzes(ctx, user->getUserId());

	UserService::printUserInfo(user);
	QuizService::printUserQuizzes(userCreatedQuizzes, CreatedQuizzes, true);
	QuizService::printUserQuizzes(userLikedQuizzes, LikedQuizzes, false);
	QuizService::printUserQuizzes(userFavouriteQuizzes, FavouriteQuizzes, false);


}


