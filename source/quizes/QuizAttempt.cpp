#include "../../headers/quizes/QuizAttempt.h"

QuizAttempt::QuizAttempt(QuizMode mode, int userId, int quizId, int points) : mode(mode), _userId(userId), _quizId(quizId), points(points){
	
}

QuizMode QuizAttempt::getMode() const{
	return this->mode;
}

int QuizAttempt::getPoints() const{
	return this->points;
}

int QuizAttempt::getQuizId() const{
	return this->_quizId;
}

int QuizAttempt::getUserId() const{
	return this->_userId;
}


void QuizAttempt::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->_userId, sizeof(this->_userId));
	ofs.write((const char*)this->_quizId, sizeof(this->_quizId));
	ofs.write((const char*)&this->mode, sizeof(this->mode));
	ofs.write((const char*)&this->points, sizeof(this->points));
}

void QuizAttempt::readFromBinaryFile(std::ifstream& ifs){
	ifs.read((char*)&this->_userId, sizeof(this->_userId));
	ifs.read((char*)&this->_quizId, sizeof(this->_quizId));
	ifs.read((char*)&this->mode, sizeof(this->mode));
	ifs.read((char*)&this->points, sizeof(this->points));
}


