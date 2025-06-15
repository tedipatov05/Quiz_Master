#include "../../headers/commands/HelpCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/services/UserService.h"

HelpCommand::HelpCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void HelpCommand::execute(){
	try{

		Validate::isLoggedIn(ctx);
		
	}
	catch (std::invalid_argument& ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	UserService::printAvailableCommands(ctx);
}


