#include "../../headers/commands/LogoutCommand.h"

LogoutCommand::LogoutCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}


void LogoutCommand::execute(){
	if (ctx.currentUserId == -1){
		std::cout << AlreadyLoggedOut << std::endl;
		return;
	}

	ctx.currentUserId = -1;
	ctx.currentUserType = UserType::None;

	std::cout << std::endl << std::endl << std::endl;
	
}

