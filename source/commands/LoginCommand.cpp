#include "../../headers/commands/LoginCommand.h"

#include "../../headers/helpers/Validate.h"

LoginCommand::LoginCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void LoginCommand::execute(){
	if (ctx.currentUserId != -1){
		std::cout << AlreadyLoggedIn << std::endl;
		return;
	}

	Vector<MyString> data = split(buffer, " ");

	User* user = ctx.users.findByUsername(data[1]);

	try{
		Validate::isUserNotExists(user);
		Validate::isBanned(user);
		Validate::areEqual(user->getPassword(), data[2], InvalidPassword);
	}
	catch (std::invalid_argument& ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	ctx.currentUserId = user->getUserId();
	ctx.currentUserType = user->role();

	std::cout << SuccessfulLogIn << std::endl;

}

