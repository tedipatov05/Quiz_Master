// Quiz_Master.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <sstream>

#include "headers/Time.h"
#include "headers/helpers/MyString.h"
#include "headers/helpers/Pair.hpp"
#include "headers/helpers/Utils.h"
#include "headers/questions/MatchingPairsQuestions.h"
#include "headers/questions/Question.h"
#include "headers/questions/ShortAnswerQuestion.h"
#include "headers/questions/SingleChoiceQuestion.h"
#include "headers/questions/TrueOrFlaseQuestion.h"

int main()
{
	

	/*MyString left[] = {"A. sinx", "B. ln(1+x)", "C. cosx", "D. tanx"};
	MyString right[] = { "a. 1+x+x^2/2+x^3/6+...", "b. x−x^3/6+x^5/120+.." };

	int left_len = sizeof(left) / sizeof(left[0]);
	int right_len = sizeof(right) / sizeof(right[0]);
	int max_len = std::max(left_len, right_len);

	for (int i = 0; i < max_len; ++i) {
		MyString l = i < left_len ? left[i] : "";
		MyString r = i < right_len ? right[i] : "";
		std::cout << std::left << std::setw(20) << l << r << "\n";
	}*/

	/*Question* question = new TrueOrFalseQuestion();
	question->read();

	std::ofstream ofs("questions.dat", std::ios::binary);
	question->writeToBinaryFile(ofs);
	ofs.close();

	Question* question2 = new TrueOrFalseQuestion();

	std::ifstream ifs("questions.dat", std::ios::binary);
	QuestionType type;
	ifs.read((char*)&type, sizeof(type));

	question2->readFromBinaryFile(ifs);
	ifs.close();

	question2->print(std::cout);*/

	Time time;

	std::cout << time.getTime();

	MyString question("Test split finction");

	Vector<MyString> splitedWords = split(question, " ");


	
   
}
