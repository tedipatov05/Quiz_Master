#include "../../headers/commands/SaveQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"

SaveQuizCommand::SaveQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx) {

}

void SaveQuizCommand::execute() {

	User* user = ctx.users.findUser(ctx.currentUserId);

	Vector<MyString> data = split(buffer, " ");
	if (data.size() != 3 || !isNumber(data[1])) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	Quiz* quiz = QuizService::getQuizById(ctx, toInt(data[1]));

	User* creator = ctx.users.findUser(quiz->creator());


	try {
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);
		Validate::isQuizExists(quiz);
		QuizService::saveQuizInTextFile(quiz, creator, data[2]);
	}
	catch (std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	std::cout << SuccessfullySaveInTextFile << std::endl;


}


