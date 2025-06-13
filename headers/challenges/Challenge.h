#pragma once
#include "../helpers/MyString.h"

enum class ChallengeType{
	SolvingInTestMode,
	SolvingInNormalMode,
	CreatedQuizes

};


class Challenge{
public:
	Challenge() = default;
	Challenge(int id, int count, ChallengeType type, const MyString& challenge);

	int calcPoints() const;
	int id() const;
	MyString getChallenge() const;
	ChallengeType type() const;
	int count() const;
	
	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);


private:
	int _id;
	int _count;
	ChallengeType _type;
	MyString challenge;
	
};

