#include "../../headers/commands/ApproveQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"

ApproveQuizCommand::ApproveQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ApproveQuizCommand::execute() {

	if (ctx.currentUserType != UserType::Admin) {
		std::cout << NotAllowed << std::endl;
		return;
	}

	Vector<MyString> data = split(buffer, " ");

	if (data.size() != 2 || !isNumber(data[1])) {
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

	Quiz oldQuiz(*quiz);

	quiz->approveQuiz();

	updateObjectInBinaryFile(quizzesFile, oldQuiz, *quiz);

	std::cout << SuccessfullyApproved << std::endl;

}
