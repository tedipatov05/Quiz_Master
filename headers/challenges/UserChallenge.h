#pragma once
#include "../Time.h"


class UserChallenge{

public:
	UserChallenge() = default;
	UserChallenge(int challengeId, int _userId, MyString message);

	int getChallengeId() const;
	int getUserId() const;

	const MyString& getMessage() const;
	const MyString& getTime() const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs) ;

private:
	MyString message;
	int _challengeId;
	int _userId;
	Time time;


};

