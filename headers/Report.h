#pragma once
#include "Time.h"
#include "helpers/MyString.h"

class Report{

public:
	Report() = default;
	Report(const MyString& reporter, const MyString& quizCreator, int quizId, const MyString& reason);

	void print(std::ostream& os) const;
	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

private:

	MyString reporter;
	MyString quizCreator;
	MyString reason;
	int quizId;
	Time time;


};

