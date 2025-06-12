#include "../../headers/commands/RemoveQuizCommand.h"
#include "../../headers/helpers/Validate.h"
#include "../../headers/services/QuizService.h"
#include "../../headers/services/MessageService.h"

RemoveQuizCommand::RemoveQuizCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void RemoveQuizCommand::execute(){

	Vector<MyString> data = split(buffer, " ");

	if (data.size() < 3){
		std::cout << InvalidFormat << std::endl;
		return;
	}

	int quizID = toInt(data[1]);

	Quiz* quiz = QuizService::getQuizById(ctx, quizID);

	try{
		Validate::isQuizExists(quiz);
		Validate::isAlreadyDeleted(quiz);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
	}

	Quiz old(*quiz);
	quiz->reject();

	updateObjectInBinaryFile(quizzesFile, old, *quiz);

	MyString reason = getReasonFromBuffer(data);

	MessageService::sendMessage(ctx, quiz->creator(), reason);

	std::cout << SuccessfullyRemoved << std::endl;

}


MyString RemoveQuizCommand::getReasonFromBuffer(const Vector<MyString>& data) const{
	MyString reason;

	for (size_t i = 2; i < data.size()-1; i++){
		reason += data[i] + " ";
	}

	reason += data[data.size() - 1];

	return reason;
}




