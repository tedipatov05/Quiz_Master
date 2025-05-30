// Quiz_Master.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <sstream>

#include "headers/helpers/MyString.h"
#include "headers/helpers/Pair.hpp"
#include "headers/helpers/Utils.h"

int main()
{
	//MyString question("What is the capital of France?");
	/*Vector<MyString> questions = split(question, " ");
	for (size_t i = 0; i < questions.size(); i++){
		std::cout << "Question " << i + 1 << ": " << questions[i].data() << std::endl;
	}*/

	/*MyString lowered = question.toLower();
	std::cout << lowered;*/

	/*char pairs[1024];
	std::cin.getline(pairs, 1024);
	Vector<Pair<MyString, MyString>> pairsVector;
	std::stringstream ss(pairs);
	char ch;
	char first, second;
	while (ss >> ch){
		if (ch == '('){
			ss >> first >> ch >> second;

			Pair<MyString, MyString> pair(first, second);

			pairsVector.push_back(pair);
		}
	}

	for (size_t i = 0; i < pairsVector.size(); i++){
		std::cout << pairsVector[i] << " ";
	}*/

	/*Pair<MyString, MyString> pair1 = Pair<MyString, MyString>("test", "test");
	Pair<MyString, MyString> pair2;
	pair2 = pair1;

	std::cout << pair2;*/

	/*std::string left[] = { "A. sinx", "B. ln(1+x)", "C. cosx" };
	std::string right[] = {
		"a. 1+x+x^2/2+x^3/6+...",
		"b. x−x^3/6+x^5/120+..",
		"c. x−x^2/2+x^3/3+..."
	};

	for (int i = 0; i < 3; ++i) {
		std::cout << std::left << std::setw(20) << left[i] << right[i] << "\n";
	}*/

	std::string left[] = { "A. sinx", "B. ln(1+x)", "C. cosx", "D. tanx" };
	std::string right[] = { "a. 1+x+x^2/2+x^3/6+...", "b. x−x^3/6+x^5/120+.." };

	int left_len = sizeof(left) / sizeof(left[0]);
	int right_len = sizeof(right) / sizeof(right[0]);
	int max_len = std::max(left_len, right_len);

	for (int i = 0; i < max_len; ++i) {
		std::string l = i < left_len ? left[i] : "";
		std::string r = i < right_len ? right[i] : "";
		std::cout << std::left << std::setw(20) << l << r << "\n";
	}
   
}
