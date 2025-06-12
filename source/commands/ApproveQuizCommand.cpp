#include "../../headers/commands/ApproveQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/quizes/services/QuizService.h"

ApproveQuizCommand::ApproveQuizCommand(const MyString& buffer, Context& ctx) : ApproveQuizCommand(buffer, ctx){
	
}

void ApproveQuizCommand::execute() {

	if (ctx.currentUserType != UserType::Admin) {
		std::cout << NoAllowed << std::endl;
		return;
	}

	Vector<MyString> data = split(buffer, " ");

	if (data.size() != 2) {
		std::cout << InvalidFormat << std::endl;
		return;
	}

	Quiz* quiz = QuizService::getQuizById(ctx, toInt(data[1]));

	try {
		Validate::isQuizExists(quiz);
		Validate::isAlreadyApproved(quiz);
		Validate::isAlreadyDeleted(quiz);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}


	quiz->approveQuiz();

}
