#pragma once
#include "MyString.h"
#include "../Context.h"

class Validate{

public:

	static void removeUnnecessarySpaces(MyString& data);
	static void areEqual(const MyString& str1, const MyString& str2, const MyString& errorMessage);
	static void isUserAlreadyExists(const MyString& username, const Context& ctx);
	static void isUserNotExists(const User* user);


	static void isAlreadyApproved(const Quiz* quiz);
	static void isAlreadyDeleted(const Quiz* quiz);
	static void isQuizExists(const Quiz* quiz);
	static void isApproved(const Quiz* quiz);

};

