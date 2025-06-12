#pragma once
#include <fstream>

#include "../helpers/MyString.h"
#include "../Context.h"

class Command{

public:

	Command(const MyString& buffer, Context& ctx);
	virtual void execute() = 0;
	virtual ~Command() = default;

	static Vector<MyString> split(const MyString& str, const MyString& delimiter);
protected:

	MyString buffer;
	Context& ctx;

	//void sendMessage(int receiverId, const MyString& message);
};

template <typename T>
void writeObjectToBinaryFile(const MyString& filename, const T& object){

	std::ofstream ofs(filename.data(), std::ios::binary | std::ios::app);

	if (!ofs.is_open()){
		std::cout << CouldNotOpen << std::endl;
		return;
	}

	object.writeToBinaryFile(ofs);


	ofs.close();

}


template <typename T>
int findPositionInFile(const MyString& filename, const T& oldObject){

	std::ifstream ifs(filename.data(), std::ios::binary);

	if (!ifs.is_open()){
		std::cout << CouldNotOpen << std::endl;
		return -1;
	}

	ifs.seekg(std::ios::beg);

	int pos = -1;

	while (!ifs.eof()){
		size_t startPos = ifs.tellg();

		T obj;
		obj.readFromBinaryFile(ifs);

		if (obj == oldObject){
			pos = startPos;
			break;
		}
	}

	ifs.close();
	return pos;
	
}

template <typename T>
void updateObjectInBinaryFile(const MyString& filename, const T& oldObject, const T& newObject) {

	int position = findPositionInFile<T>(filename, oldObject);

	std::ofstream ofs(filename.data(), std::ios::binary | std::ios::in);

	if (!ofs.is_open()){
		std::cout << CouldNotOpen << std::endl;
		return;
	}


	ofs.seekp(position, std::ios::beg);
	newObject.writeToBinaryFile(ofs);


}

