#include "../../headers/commands/LikeQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/UserService.h"

LikeQuizCommand::LikeQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void LikeQuizCommand::execute(){

	Vector<MyString> data = split(buffer, " ");
	if (data.size() != 2 || !isNumber(data[1])){
		std::cout << InvalidFormat << std::endl;
		return;
	}

	int quizId = toInt(data[1]);
	Quiz* quiz = QuizService::getQuizById(ctx, quizId);

	try{

		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isQuizExists(quiz);
		Validate::isApproved(quiz);
		
	}
	catch (std::invalid_argument& ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	if (QuizService::isQuizLiked(ctx, quiz)){
		std::cout << AlreadyLiked << std::endl;
		return;
	}

	QuizService::likeQuiz(ctx, quiz);
}


