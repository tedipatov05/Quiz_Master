#include "../../headers/commands/ViewFinishedChallengesCommand.h"
#include "../../headers/helpers/Validate.h"
#include "../../headers/services/ChallengesService.h"

ViewFinishedChallengesCommand::ViewFinishedChallengesCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void ViewFinishedChallengesCommand::execute(){

	User* user = ctx.users.findUser(ctx.currentUserId);
	try {
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Player);
		Validate::isUserNotExists(user);

	}
	catch (std::invalid_argument ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	ChallengesService::printFinishedChallenges(ctx);
}


