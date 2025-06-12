#pragma once
#include "UserFactory.h"
#include "../helpers/MyString.h"

class User{
public:
	User() = default;
	User(const MyString& first_name, const MyString& last_name, const MyString& username,
		const MyString& password, int id);

	virtual ~User() = default;


	// TODO: Add getters if needed
	MyString getFirstName() const;
	MyString getLastName() const;
	MyString getUsername() const;
	MyString getPassword() const;
	int getLevel() const;
	int getPoints() const;
	int getUserId() const;
	bool banned() const;

	void ban();

	void increasePoints(int points);

	virtual UserType role() const = 0;
	virtual User* clone() const = 0;
	virtual void writeToBinaryFile(std::ofstream& ofs) const;
	virtual void readFromBinaryFile(std::ifstream& ifs);
	virtual void print(std::ostream& os) const = 0;




protected:
	int id;
	MyString first_name;
	MyString last_name;
	MyString username;
	MyString password;
	int level;
	int points;
	bool isBanned;
};

