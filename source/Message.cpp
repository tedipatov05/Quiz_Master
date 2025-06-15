#include "../headers/Message.h"

Message::Message(const MyString& content, const MyString& receiver, const MyString& sender)
	: _content(content), _receiver(receiver), _sender(sender){
	
}

const MyString& Message::receiver() const{
	return this->_receiver;
}

const MyString& Message::content() const{
	return this->_content;
}

const MyString& Message::getTime() const{
	return this->time.getTime();
}


void Message::print(std::ostream& os) const{
	os << "	  ";
	os << this->_content << std::endl;
}

void Message::writeToBinaryFile(std::ofstream& ofs) const{
	this->_content.writeToBinaryFile(ofs);
	this->_receiver.writeToBinaryFile(ofs);
	this->_sender.writeToBinaryFile(ofs);
	this->time.writeToBinaryFile(ofs);
}

void Message::readFromBinaryFile(std::ifstream& ifs){
	this->_content.readFromBinaryFile(ifs);
	this->_receiver.readFromBinaryFile(ifs);
	this->_sender.readFromBinaryFile(ifs);
	this->time.readFromBinaryFile(ifs);
}




