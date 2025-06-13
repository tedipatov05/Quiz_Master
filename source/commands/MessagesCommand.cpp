#include "../../headers/commands/MessagesCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/MessageService.h"
#include "../../headers/services/UserService.h"

MessagesCommand::MessagesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void MessagesCommand::execute(){

	User* user = ctx.users.findUser(ctx.currentUserId);

	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);

	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
	}

	Vector<Message> userMessages = MessageService::getUserMessages(ctx, user->getUsername());
	MessageService::printMessages(userMessages);
}

