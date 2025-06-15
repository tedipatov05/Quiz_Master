#include "../../headers/commands/ReportQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"

ReportQuizCommand::ReportQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx) {

}

void ReportQuizCommand::execute() {

	Vector<MyString> data = split(buffer, " ");
	if (data.size() < 3 || !isNumber(data[1])) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	User* user = ctx.users.findUser(ctx.currentUserId);
	Quiz* quiz = QuizService::getQuizById(ctx, toInt(data[1]));
	MyString reason = getReason(data);

	try {
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);
		Validate::isAlreadyDeleted(quiz);
		Validate::isQuizExists(quiz);
		Validate::isApproved(quiz);
	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	User* creator = ctx.users.findUser(quiz->creator());

	QuizService::reportQuiz(ctx, quiz, reason, creator->getUsername(), user->getUsername());

}

MyString ReportQuizCommand::getReason(const Vector<MyString>& data) {
	MyString reason;

	for (size_t i = 2; i < data.size(); i++) {
		reason += data[i];
		reason += " ";
	}

	return reason;

}



