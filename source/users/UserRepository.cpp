#include "../../headers/users/UserRepository.h"

#include <iostream>

#include "../../headers/helpers/Constants.h"


UserRepository::UserRepository() {
	this->_capacity = INITIAL_CAPACITY;
	this->_size = 0;
	this->_users = new User * [this->_capacity];
}

UserRepository::UserRepository(const UserRepository& other) {
	this->copyDynamicMemory(other);
}

UserRepository::UserRepository(const MyString& filename) {
	this->_capacity = INITIAL_CAPACITY;
	this->_size = 0;
	this->_users = new User * [this->_capacity];
	this->readFromBinaryFile(filename);
}

UserRepository& UserRepository::operator=(const UserRepository& other) {
	if (this != &other) {
		free();
		copyDynamicMemory(other);
		this->_size = other.size();
		this->_capacity = other._capacity;
	}

	return *this;
}

UserRepository::~UserRepository() {
	free();
}

void UserRepository::addUser(const User* user) {
	if (this->_size == this->_capacity) {
		this->resize(this->_capacity * 2);
	}

	this->_users[this->_size] = user->clone();
	this->_size++;
}

User* UserRepository::findUser(int userId) const {
	for (size_t i = 0; i < this->size(); i++) {
		if (this->_users[i]->getUserId() == userId) {
			return this->_users[i];
		}
	}

	return nullptr;
}

User& UserRepository::operator[](size_t index) {
	return *this->_users[index];
}

const User& UserRepository::operator[](size_t index) const {
	return *this->_users[index];
}

void UserRepository::free() {
	for (size_t i = 0; i < this->_size; i++) {
		delete this->_users[i];
	}
	delete[] this->_users;
	this->_users = nullptr;
	this->_size = 0;
	this->_capacity = 0;

}

void UserRepository::copyDynamicMemory(const UserRepository& other) {
	this->_capacity = other._capacity;
	this->_size = other._size;
	this->_users = new User * [this->_capacity];
	for (size_t i = 0; i < this->_size; i++) {
		this->_users[i] = other._users[i]->clone();
	}
}

void UserRepository::readFromBinaryFile(const MyString& filename) {
	std::ifstream ifs(filename.data(), std::ios::binary);
	if (!ifs) {
		std::cout << "Error opening file: " << filename << std::endl;
		return;
	}

	free();
	this->_users = new User * [INITIAL_SIZE];
	this->_capacity = INITIAL_SIZE;

	while (!ifs.eof()) {
		UserType type;
		ifs.read((char*)&type, sizeof(type));

		User* user = UserFactory::createUser(type);

		if (!user) {
			std::cout << "Error creating a user" << std::endl;
			break;
		}

		user->readFromBinaryFile(ifs);
		this->addUser(user);
	}

	ifs.close();
}

void UserRepository::writeToBinaryFile(const MyString& filename) const {
	std::ofstream ofs(filename.data(), std::ios::binary);
	if (!ofs) {
		std::cout << "Error opening file: " << filename << std::endl;
		return;
	}

	for (size_t i = 0; i < this->_size; i++) {
		this->_users[i]->writeToBinaryFile(ofs);
	}

	ofs.close();
}

size_t UserRepository::size() const {
	return this->_size;
}

void UserRepository::resize(size_t newCap) {

	User** newUsers = new User * [newCap];
	for (size_t i = 0; i < this->_size; i++) {
		newUsers[i] = this->_users[i]->clone();
	}
	delete[] this->_users;
	this->_users = newUsers;
}

User* UserRepository::findByUsername(const MyString& username) const{
	for (size_t i = 0; i < this->size(); i++){
		if (this->_users[i]->getUsername() == username){
			return this->_users[i];
		}
	}


	return nullptr;
}









