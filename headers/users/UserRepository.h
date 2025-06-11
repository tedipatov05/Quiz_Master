#pragma once
#include "User.h"

class UserRepository
{
public:

	UserRepository();
	UserRepository(const MyString& filename);
	UserRepository(const UserRepository& other);
	UserRepository& operator=(const UserRepository& other);
	~UserRepository();

	void addUser(const User* user);
	User* findUser(int userId) const;
	User* findByUsername(const MyString& username) const;

	void readFromBinaryFile(const MyString& filename);
	void writeToBinaryFile(const MyString& filename) const;

	const User& operator[](size_t index) const;
	User& operator[](size_t index);
	size_t size() const;

private:

	User** _users;
	size_t _size;
	size_t _capacity;

	void copyDynamicMemory(const UserRepository& other);
	void free();
	void resize(size_t newCap);
};

