#include "../../headers/users/UserFactory.h"

#include "../../headers/users/Admin.h"
#include "../../headers/users/Player.h"


User* UserFactory::createUser(UserType user_type){
	switch (user_type){
		case UserType::Player:
			return new Player();
		case UserType::Admin:
			return new Admin();
		default:
			return nullptr;
		
	}
}

