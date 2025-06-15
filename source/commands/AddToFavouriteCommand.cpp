#include "../../headers/commands/AddToFavouriteCommand.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/helpers/Validate.h"

AddToFavouriteCommand::AddToFavouriteCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void AddToFavouriteCommand::execute(){
	Vector<MyString> data = split(buffer, " ");
	if (data.size() != 2 || !isNumber(data[1])) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	int quizId = toInt(data[1]);
	Quiz* quiz = QuizService::getQuizById(ctx, quizId);

	try {

		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isQuizExists(quiz);
		Validate::isApproved(quiz);

	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	if (QuizService::isQuizAddedToFavourite(ctx, quiz)) {
		std::cout << AlreadyAddedToFavs << std::endl;
		return;
	}

	QuizService::addQuizToFavourite(ctx, quiz);
}


