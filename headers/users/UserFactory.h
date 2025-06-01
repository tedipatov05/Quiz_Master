#pragma once

class User;

enum class UserType{
	Admin,
	Player
};

class UserFactory{
public:
	static User* createUser(UserType user_type);
};

