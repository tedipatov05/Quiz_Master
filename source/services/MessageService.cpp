#include "../../headers/services/MessageService.h"
#include "../../headers/helpers/FileHelper.hpp"

void MessageService::sendMessage(Context& ctx, int receiverId, const MyString& messageData){

	User* quizCreator = ctx.users.findUser(receiverId);
	User* user = ctx.users.findUser(ctx.currentUserId);

	Message message(messageData, quizCreator->getUsername(), user->getUsername());

	ctx.messages.push_back(message);
	writeObjectToBinaryFile(messagesFile, message);

}

Vector<Message> MessageService::getUserMessages(Context& ctx, const MyString& receiver){
	Vector<Message> userMessages;

	for (size_t i = 0; i < ctx.messages.size(); i++){
		if (ctx.messages[i].receiver() == receiver){
			userMessages.push_back(ctx.messages[i]);
		}
	}

	return userMessages;
}

void MessageService::printMessages(const Vector<Message>& data){
	if (data.size() == 0){
		std::cout << NoDataToDisplay << std::endl;
		return;
	}

	for (size_t i = 0; i < data.size(); i++){
		data[i].print(std::cout);
	}


}



