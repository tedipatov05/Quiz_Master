#include "../../headers/users/User.h"

User::User(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id)
	: first_name(first_name), last_name(last_name), username(username), password(password), id(id) {
	
}

void User::readFromBinaryFile(std::ifstream& ifs){
	ifs.read((char*)&id, sizeof(id));
	this->first_name.readFromBinaryFile(ifs);
	this->last_name.readFromBinaryFile(ifs);
	this->username.readFromBinaryFile(ifs);
	this->password.readFromBinaryFile(ifs);

}

void User::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const  char*)&id, sizeof(id));
	this->first_name.writeToBinaryFile(ofs);
	this->last_name.writeToBinaryFile(ofs);
	this->username.writeToBinaryFile(ofs);
	this->password.writeToBinaryFile(ofs);
}



