#include "../../headers/quizes/UserQuiz.h"

UserQuiz::UserQuiz(int userId, int quizId) : _userId(userId), _quizId(quizId), _isActive(true){
	
}

int UserQuiz::getQuizId() const{
	return this->_quizId;
}

int UserQuiz::getUserId() const{
	return this->_userId;
}

bool UserQuiz::isActive() const{
	return this->_isActive;
}

void UserQuiz::changeActive(){
	this->_isActive = !this->_isActive;
}



void UserQuiz::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->_userId, sizeof(this->_userId));
	ofs.write((const char*)&this->_quizId, sizeof(this->_quizId));
	ofs.write((const char*)&this->_isActive, sizeof(this->_isActive));
}

void UserQuiz::readFromBinaryFile(std::ifstream& ifs) const{
	ifs.read((char*)&this->_userId, sizeof(this->_userId));
	ifs.read((char*)&this->_quizId, sizeof(this->_quizId));
	ifs.read((char*)&this->_isActive, sizeof(this->_isActive));
}

bool operator==(const UserQuiz& lhs, const UserQuiz& rhs){
	return lhs.getQuizId() == rhs.getQuizId() && lhs.getUserId() == rhs.getUserId() && lhs.isActive() && rhs.isActive();
}





