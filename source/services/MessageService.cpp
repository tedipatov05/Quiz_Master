#include "../../headers/services/MessageService.h"
#include "../../headers/commands/Command.h"

void MessageService::sendMessage(Context& ctx, int receiverId, const MyString& messageData){

	User* quizCreator = ctx.users.findUser(receiverId);
	User* user = ctx.users.findUser(ctx.currentUserId);

	Message message(messageData, quizCreator->getUsername(), user->getUsername());

	ctx.messages.push_back(message);
	writeObjectToBinaryFile(messagesFile, message);

}

