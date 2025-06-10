#include "../../headers/challenges/UserChallenge.h"

UserChallenge::UserChallenge(int challengeId, int userId, MyString message) : _challengeId(challengeId), _userId(userId), message(message), time(){
	
	
}

int UserChallenge::getChallengeId() const{
	return this->_challengeId;
}

int UserChallenge::getUserId() const{
	return this->_userId;
}

MyString UserChallenge::getMessage() const{
	return this->message;
}



void UserChallenge::writeToBinaryFile(std::ofstream& ofs) const{
	this->message.writeToBinaryFile(ofs);
	ofs.write((const char*)&this->_userId, sizeof(this->_userId));
	ofs.write((const char*)&this->_challengeId, sizeof(this->_challengeId));
	this->time.writeToBinaryFile(ofs);

}


void UserChallenge::readFromBinaryFile(std::ifstream& ifs) {
	this->message.readFromBinaryFile(ifs);
	ifs.read((char*)&this->_userId, sizeof(this->_userId));
	ifs.read((char*)&this->_challengeId, sizeof(this->_challengeId));
	this->time.readFromBinaryFile(ifs);
}


