#pragma once
#include "User.h"
#include "../Report.h"
#include "../helpers/Vector.hpp"


class Admin : public User{

public:
	Admin() = default;
	Admin(const MyString& first_name, const MyString& last_name, const MyString& username,
		const MyString& password, int id);

	User* clone() const override;
	UserType role() const override;
	void print(std::ostream& os) const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;

};

