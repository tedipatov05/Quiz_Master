#pragma once
#include "helpers/MyString.h"

class Time{

public:

	Time();
	const MyString getTime() const;
	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

private:

	MyString data;

	void setCurrentTime();
};

