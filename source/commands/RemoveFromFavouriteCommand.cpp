#include "../../headers/commands/RemoveFromFavouriteCommand.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/helpers/Validate.h"

RemoveFromFavouriteCommand::RemoveFromFavouriteCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
}

void RemoveFromFavouriteCommand::execute(){
	Vector<MyString> data = split(buffer, " ");
	if (data.size() != 2) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	int quizId = toInt(data[1]);
	Quiz* quiz = QuizService::getQuizById(ctx, quizId);

	try {

		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isQuizExists(quiz);

	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	if (!QuizService::isQuizAddedToFavourite(ctx, quiz)) {
		std::cout << NotAddedToFavs << std::endl;
		return;
	}

	QuizService::removeFromFavourite(ctx, quiz);
}


