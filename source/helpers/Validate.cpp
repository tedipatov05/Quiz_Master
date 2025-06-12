#include "../../headers/helpers/Validate.h"

void Validate::removeUnnecessarySpaces(MyString& input){
	const char* raw = input.data();  
	size_t len = input.size();      

	MyString result;
	bool inSpace = true;

	for (size_t i = 0; i < len; i++) {
		char c = raw[i];

		if (c == ' ') {
			if (!inSpace) {
				result += ' ';
				inSpace = true;
			}
		}
		else {
			result += c;
			inSpace = false;
		}
	}

	
	if (!result.isEmpty() && result[result.size() - 1] == ' ')
		result.pop_back();

	input = result;
}

void Validate::areEqual(const MyString& str1, const MyString& str2, const MyString& errorMessage){
	if (str1 != str2){
		throw std::invalid_argument(errorMessage.data());
	}
}

void Validate::isUserAlreadyExists(const MyString& username, const Context& ctx){
	User* user = ctx.users.findByUsername(username);

	if (user != nullptr){
		throw std::invalid_argument(AlreadyExists.data());
	}
	
}

void Validate::isUserNotExists(const User* user){

	if (user == nullptr){
		throw std::invalid_argument(UserNotExists.data());
	}

}

void Validate::isAlreadyApproved(const Quiz* quiz){
	if (quiz->approved()){
		throw std::invalid_argument(QuizAlreadyApproved.data());
	}
}

void Validate::isAlreadyDeleted(const Quiz* quiz){
	if (!quiz->active()){
		throw std::invalid_argument(QuizDeleted.data());
	}
}

void Validate::isQuizExists(const Quiz* quiz){
	if (!quiz){
		throw std::invalid_argument(QuizNoExists.data());
	}
}

void Validate::isApproved(const Quiz* quiz){
	if (!quiz->approved()){
		throw std::invalid_argument(QuizNotApproved.data());
	}
}



void Validate::checkPermission(const Context& ctx, UserType type){
	if (ctx.currentUserType != type){
		throw std::invalid_argument(NotAllowed.data());
	}
}

void Validate::isLoggedIn(const Context& ctx){
	if (ctx.currentUserId == -1){
		throw std::invalid_argument(NotLoggedIn.data());
	}
}

void Validate::isBanned(const User* user){
	if (user->banned()){
		throw std::invalid_argument(Banned.data());
	}
}







