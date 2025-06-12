#include "../../headers/users/User.h"

User::User(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id)
	: first_name(first_name), last_name(last_name), username(username), password(password), id(id), level(0), points(0), isBanned(false) {
	
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

MyString User::getFirstName() const{
	return this->first_name;
}

MyString User::getLastName() const{
	return this->last_name;
}

MyString User::getUsername() const{
	return this->username;
}

MyString User::getPassword() const{
	return this->password;
}


int User::getLevel() const{
	return this->level;
}

int User::getPoints() const{
	return this->points;
}

void User::increasePoints(int points){
	this->points += points;
}

int User::getUserId() const{
	return this->id;
}

void User::ban(){
	this->isBanned = true;
}











