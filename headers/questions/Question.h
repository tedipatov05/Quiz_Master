#pragma once
#include "QuestionFactory.h"
#include "../helpers/MyString.h"

class Question{
public:
	Question() = default;
	Question(const MyString& description, int points);

	virtual Question* clone() const = 0;
	virtual QuestionType type() const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs) = 0;
	virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void read() = 0;
	virtual void print(std::ostream& os) const = 0;
	virtual ~Question() = default;

protected:
	MyString _desription;
	int _points;
	
};
