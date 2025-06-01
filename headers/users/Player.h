#pragma once
#include "../../headers/users/User.h"
#include "../../headers/helpers/Vector.hpp"
#include "../helpers/Pair.hpp"

class Player : public User{
public:
	Player() = default;
	Player(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id);

	void likeQuiz(int quizId);
	void addToFavs(int quizId);
	void removeFromFavs(int quizId);
	void unlikeQuiz(int quizId);

	User* clone() const override;
	UserType role() const override;
	void print(std::ostream& os) const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	//void readFromBinaryFile(std::ifstream& ifs) override;

private:

	Vector<int> likedQuizes;
	Vector<int> favouriteQuizes;
	Vector<Pair<int, MyString>> myQuizes; 
	Vector<int> finishedChallenges;
	int quizesInTestMode;
	int quizesInNormalMode;
	int points;
	int level;

};

