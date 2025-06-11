#pragma once

class User;

enum class UserType{
	Admin,
	Player,
	None
};

class UserFactory{
public:
	static User* createUser(UserType user_type);
};

