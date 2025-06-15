#include "../../headers/commands/SignUpCommand.h"

#include "../../headers/helpers/Validate.h"
#include "../../headers/users/Player.h"

SignUpCommand::SignUpCommand(const MyString& buffer, Context& ctx) : Command(buffer, ctx){
	
}

void SignUpCommand::execute(){
	if (ctx.currentUserId != -1){
		std::cout << AlreadyLoggedIn << std::endl;
		return;
	}

	Vector<MyString> data = split(buffer, " ");

	if (data.size() != 6){
		std::cout << InvalidFormat << std::endl;
		return;
	}

	try{
		Validate::areEqual(data[4], data[5], InvalidPassword);
		Validate::isUserAlreadyExists(data[3], ctx);
	}
	catch (std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
		return;
	}

	User* user = new Player(data[1], data[2], data[3], data[4], Context::nextUserId);
	Context::nextUserId++;
	ctx.users.addUser(user);

	writeObjectToBinaryFile(userFile, *user);

	delete user;

	std::cout << SuccessfulSignUp << std::endl;

}


