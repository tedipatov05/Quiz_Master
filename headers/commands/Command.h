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

};

template <typename T>
void writeObjectToBinaryFile(const MyString& filename, const T& object){

	std::ofstream ofs(filename.data(), std::ios::binary | std::ios::app);

	if (!ofs.is_open()){
		std::cout << CouldNotOpen << std::endl;
		return;
	}

	object->writeToBinaryFile(ofs);


	ofs.close();

}

