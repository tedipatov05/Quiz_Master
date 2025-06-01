#include "../../headers/users/UserFactory.h"


// TODO: Add Player and Admin
User* UserFactory::createUser(UserType user_type){
	switch (user_type){
		case UserType::Player:
			return nullptr;
		case UserType::Admin:
			return nullptr;
		default:
			return nullptr;
		
	}
}

