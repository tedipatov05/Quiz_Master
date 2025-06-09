#pragma once
#include "../../headers/users/User.h"
#include "../../headers/helpers/Vector.hpp"
#include "../helpers/Pair.hpp"
#include "../Message.h"

class Player : public User{
public:
	Player() = default;
	Player(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id);

	User* clone() const override;
	UserType role() const override;
	void print(std::ostream& os) const override;
	
	void writeToBinaryFile(std::ofstream& ofs) const override;
	//void receiveMessage(const Message& message);
	//void readFromBinaryFile(std::ifstream& ifs) override;
	//void viewProfile(std::ostream&, const Vector<int>& favouriteQuizes, const Vector<int>& likedQuizes, const Vector<Pair<int, MyString>>& myQuizes) const;

//private:

	/*Vector<int> likedQuizes;
	Vector<int> favouriteQuizes;
	Vector<Pair<int, MyString>> myQuizes; 
	Vector<int> finishedChallenges;
	Vector<Message> messages;
	int quizesInTestMode;
	int quizesInNormalMode;
	int points;
	int level;*/

};

