#pragma once
#include "Time.h"
#include "helpers/MyString.h"
class Message {

public:

	Message() = default;
	Message(const MyString& content, const MyString& receiver, const MyString& sender);

	//const char* content() const;

	void print(std::ostream& os) const;

	const MyString& receiver() const;

	void readFromFile(std::ifstream& ifs);
	void writeToFile(std::ofstream& ofs) const;

private:

	MyString _content;
	MyString _sender;
	MyString _receiver;
	Time time;
};

