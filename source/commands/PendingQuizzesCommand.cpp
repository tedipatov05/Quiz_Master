#include "../../headers/commands/PendingQuizzesCommand.h"

#include "../../headers/helpers/Validate.h"

PendingQuizzesCommand::PendingQuizzesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void PendingQuizzesCommand::execute(){

	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Admin);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

}


