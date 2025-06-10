#include "../../headers/quizes/UserQuiz.h"

UserQuiz::UserQuiz(int userId, int quizId) : _userId(userId), _quizId(quizId){
	
}

int UserQuiz::getQuizId() const{
	return this->_quizId;
}

int UserQuiz::getUserId() const{
	return this->_userId;
}

void UserQuiz::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->_userId, sizeof(this->_userId));
	ofs.write((const char*)&this->_quizId, sizeof(this->_quizId));
}

void UserQuiz::readFromBinaryFile(std::ifstream& ifs) const{
	ifs.read((char*)this->_userId, sizeof(this->_userId));
	ifs.read((char*)&this->_quizId, sizeof(this->_quizId));
}




