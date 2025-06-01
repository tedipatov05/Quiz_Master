#include "../headers/Report.h"

Report::Report(const MyString& reporter, const MyString& quizCreator, int quizId, const MyString& reason)
	: reporter(reporter), quizCreator(quizCreator), quizId(quizId), reason(reason){
	
}

void Report::print(std::ostream& os) const{
	os << this->time.getTime() << " | sent by " << this->reporter
		<< " | quiz ID " << quizId << " by " << this->quizCreator << " | reason: " << reason;
	
}

void Report::writeToBinaryFile(std::ofstream& ofs) const{
	ofs.write((const char*)&this->quizId, sizeof(this->quizId));
	this->reporter.writeToBinaryFile(ofs);
	this->quizCreator.writeToBinaryFile(ofs);
	this->reason.writeToBinaryFile(ofs);
}

void Report::readFromBinaryFile(std::ifstream& ifs){
	ifs.read((char*)&this->quizId, sizeof(this->quizId));
	this->reporter.readFromBinaryFile(ifs);
	this->quizCreator.readFromBinaryFile(ifs);
	this->reason.readFromBinaryFile(ifs);
}





