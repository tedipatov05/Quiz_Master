#include "../../headers/commands/BanUserCommand.h"

#include "../../headers/helpers/Validate.h"

BanUserCommand::BanUserCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void BanUserCommand::execute(){

	Vector<MyString> data = split(buffer, " ");

	if (data.size() != 2){
		std::cout << InvalidFormat << std::endl;
		return;
	}

	User* userForBan = ctx.users.findByUsername(data[1]);


	try{
		Validate::isLoggedIn(ctx);
		Validate::checkPermission(ctx, UserType::Admin);
		Validate::isUserNotExists(userForBan);

	}
	catch (std::invalid_argument& ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	userForBan->ban();
	ctx.areUsersChanged = true;
	
}


