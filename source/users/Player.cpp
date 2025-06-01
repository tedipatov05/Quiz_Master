#include "../../headers/users/Player.h"

#include <iostream>

Player::Player(const MyString& first_name, const MyString& last_name, const MyString& username, const MyString& password, int id)
	: User(first_name, last_name, username, password, id){
	
}

void Player::likeQuiz(int quizId){
	if (this->likedQuizes.contains(quizId)){
		std::cout << "This quiz is already liked" << std::endl;
		return;
	}

	this->likedQuizes.push_back(quizId);
}

void Player::addToFavs(int quizId){
	if (this->favouriteQuizes.contains(quizId)){
		std::cout << "This quiz is already to favourites" << std::endl;
		return;
	}

	this->favouriteQuizes.push_back(quizId);
}

void Player::removeFromFavs(int quizId){
	if (!this->favouriteQuizes.contains(quizId)){
		std::cout << "This quiz is not in favourites" << std::endl;
		return;
	}

	this->favouriteQuizes.remove(quizId);
}

void Player::unlikeQuiz(int quizId){
	if (!this->likedQuizes.contains(quizId)){
		std::cout << "This quiz is not liked" << std::endl;
		return;
	}

	this->likedQuizes.remove(quizId);
}

User* Player::clone() const{
	return new Player(*this);
}

UserType Player::role() const{
	return UserType::Player;
}

void Player::print(std::ostream& os) const{
	os << this->first_name << " " << this->last_name << " @" << this->username;
	os << "Level: " << this->level;

	os << "Created quizes: " << std::endl;
	for (size_t i = 0; i < this->myQuizes.size(); i++){
		os << "[" << this->myQuizes[i].getFirst() << "] " << this->myQuizes[i].getSecond();
	}
	os << "Liked quizes:";
	for (size_t i = 0; i < this->likedQuizes.size(); i++){
		os << " [" << this->likedQuizes[i] << "]";
	}

	os << "Favourite quizes:";
	for (size_t i = 0; i < this->favouriteQuizes.size(); i++) {
		os << " [" << this->favouriteQuizes[i] << "]";
	}

}

void Player::writeToBinaryFile(std::ofstream& ofs) const{
	UserType role = this->role();
	ofs.write((const char*)&role, sizeof(role));

	User::writeToBinaryFile(ofs);
}











