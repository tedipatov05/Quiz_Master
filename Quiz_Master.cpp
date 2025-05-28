// Quiz_Master.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers/helpers/MyString.h"
#include "headers/helpers/Utils.h"

int main()
{
	MyString question("What is the capital of France?");
	Vector<MyString> questions = split(question, " ");
	for (size_t i = 0; i < questions.size(); i++){
		std::cout << "Question " << i + 1 << ": " << questions[i].data() << std::endl;
	}
   
}
