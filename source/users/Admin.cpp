#include "../../headers/users/Admin.h"

Admin::Admin(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id)
	: User(first_name, last_name, username, password, id){
	
}

User* Admin::clone() const{
	return new Admin(*this);
}


UserType Admin::role() const{
	return UserType::Admin;
}

void Admin::print(std::ostream& os) const{
	os << this->first_name << " " << this->last_name << " @" << this->username;
}

void Admin::writeToBinaryFile(std::ofstream& ofs) const{
	UserType type = this->role();
	ofs.write((const char*)&type, sizeof(type));

	User::writeToBinaryFile(ofs);
}





