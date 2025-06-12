#include "../../headers/commands/Command.h"
#include "../../headers/helpers/Validate.h"

Command::Command(const MyString& buffer, Context& ctx) : buffer(buffer), ctx(ctx){

	Validate::removeUnnecessarySpaces(this->buffer);
}

Vector<MyString> Command::split(const MyString& str, const MyString& delimiter) {
	Vector<MyString> result;
	size_t start = 0;
	size_t end = str.find(delimiter.data(), start);

	while (end != std::string::npos) {
		result.push_back(str.substr(start, end - start));
		start = end + delimiter.size();
		end = str.find(delimiter.data(), start);
	}

	result.push_back(str.substr(start, end));
	return result;
}

//void Command::sendMessage(int receiverId, const MyString& messageData){
//
//	User* quizCreator = ctx.users.findUser(receiverId);
//	User* user = ctx.users.findUser(ctx.currentUserId);
//	
//
//	Message message(messageData, quizCreator->getUsername(), user->getUsername());
//
//	ctx.messages.push_back(message);
//	writeObjectToBinaryFile(messagesFile, message);
//
//	std::cout << SuccessfullyRejected << std::endl;
//}



