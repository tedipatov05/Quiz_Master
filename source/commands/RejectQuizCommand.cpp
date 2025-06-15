#include "../../headers/commands/RejectQuizCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/MessageService.h"

RejectQuizCommand::RejectQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void RejectQuizCommand::execute(){

	Vector<MyString> data = split(buffer, " ");
	if (data.size() < 3 || !isNumber(data[1])){
		std::cout << InvalidFormat << std::endl;
		return;
	}

	Quiz* quiz = QuizService::getQuizById(ctx, toInt(data[1]));

	try{
		Validate::checkPermission(ctx, UserType::Admin);
		Validate::isQuizExists(quiz);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	QuizService::rejectQuiz(ctx, quiz, getReasonFromBuffer(data));

	std::cout << SuccessfullyRejected << std::endl;
}

MyString RejectQuizCommand::getReasonFromBuffer(const Vector<MyString>& data) const{

	MyString reason;

	for (size_t i = 2; i < data.size(); i++){
		reason += data[i];
		reason += " ";
	}


	return reason;
}


