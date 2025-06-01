#include "../headers/Time.h"
#pragma warning(disable:4996)

void Time::setCurrentTime(){
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", ltm);

    char* temp = new char[strlen(buffer) + 1];
    std::strcpy(temp, buffer);

    this->data = MyString(temp);
	
}

const MyString Time::getTime() const{
    return this->data;
}

Time::Time(){
    setCurrentTime();
}

void Time::readFromBinaryFile(std::ifstream& ifs){
    this->data.readFromBinaryFile(ifs);
}

void Time::writeToBinaryFile(std::ofstream& ofs) const{
    this->data.writeToBinaryFile(ofs);
	
}





