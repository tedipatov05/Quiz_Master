#include "../../headers/challenges/Challenge.h"

Challenge::Challenge(int id, int count, ChallengeType type) :_id(id),  _count(count), _type(type){
	
}

int Challenge::calcPoints() const{
	if (this->_type == ChallengeType::CreatedQuizes){
		return (this->_count * 10) / 2;
	}
	else if (this->_type == ChallengeType::SolvingInNormalMode){
		return 2 * (this->_count * 10) / 3;
	}
	else if (this->_type == ChallengeType::SolvingInTestMode){
		return (this->_count * 10) / 3;
	}
	else{
		return 0;
	}
}

int Challenge::id() const{
	return this->_id;
}



void Challenge::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->_id, sizeof(this->_id));
	ofs.write((const char*)&this->_count, sizeof(this->_count));
	ofs.write((const char*)&this->_type, sizeof(this->_type));
}

void Challenge::readFromBinaryFile(std::ifstream& ifs){
	ifs.read((char*)&this->_id, sizeof(this->_id));
	ifs.read((char*)&this->_count, sizeof(this->_count));
	ifs.read((char*)&this->_type, sizeof(this->_type));
}




