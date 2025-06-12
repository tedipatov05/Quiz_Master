// Quiz_Master.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <sstream>

#include "headers/quizes/Quiz.h"
#include "headers/quizes/QuizAttempt.h"
#include "headers/Time.h"
#include "headers/helpers/MyString.h"
#include "headers/helpers/Pair.hpp"
#include "headers/helpers/Utils.h"
#include "headers/questions/MatchingPairsQuestions.h"
#include "headers/questions/MultipleChoiceQuestion.h"
#include "headers/questions/Question.h"
#include "headers/questions/ShortAnswerQuestion.h"
#include "headers/questions/SingleChoiceQuestion.h"
#include "headers/questions/TrueOrFlaseQuestion.h"
#include "headers/users/Player.h"
#include "headers/users/User.h"
#include "headers/Context.h"
#include "headers/commands/LoginCommand.h"
#include "headers/commands/SignUpCommand.h"
#include "headers/helpers/Validate.h"

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

	/*Time time;

	std::cout << time.getTime();

	User* user = new Player();*/


	//std::ofstream ofs("test.txt");
	//if (!ofs.is_open()) {
	//	std::cerr << "Failed to open file\n";
	//	return 1;
	//}



	//const int lineWidth = 200; // Adjust to your preferred width
	//std::string quizTitle = "Test Quiz - <Number of Questions> Questions";
	//std::string author = "By Teodor Patov @patlaka";

	//// Center header
	//ofs << std::setw((lineWidth + quizTitle.length()) / 2) << quizTitle << "\n\n";
	//ofs << std::setw((lineWidth + author.length()) / 2) << author << "\n\n\n";

	//// Question 1 - True/False
	//ofs << "1) TrueOrFalseQuestion description\n\n";
	//ofs << "   True/False\n\n\n";

	//// Question 2 - Single Choice
	//ofs << "2) SingleChoiceQuestion description\n";
	//ofs << "   a) Option A\n";
	//ofs << "   b) Option B\n";
	//ofs << "   c) Option C\n";
	//ofs << "   d) Option D\n";

	//ofs.close();
	//std::cout << "Quiz saved successfully.\n";

	/*int a = 14;
	MyString str = toString(a);
	std::cout << str;*/


	//std::ofstream ofs("question.dat", std::ios::binary);

	//Question* question1 = new TrueOrFalseQuestion("true of false", 10, "true");

	//question1->writeToBinaryFile(ofs);


	//Vector<MyString> answers = Vector<MyString>();
	//answers.push_back("Answer1");
	//answers.push_back("Answer2");
	//answers.push_back("Answer3");
	//answers.push_back("Answer4");
	//answers.push_back("Answer5");


	//Vector<MyString> correct = Vector<MyString>();
	//correct.push_back("A");
	//correct.push_back("B");

	//Question* question2 = new MultipleChoiceQuestion("Question", 20, answers, correct);

	//question2->writeToBinaryFile(ofs);

	//ofs.close();

	//User* creator = new Player("Test", "Testov", "testov", "1234", 1);

	//Quiz quiz = Quiz(1, 2);

	//quiz.readQuiz();

	//std::ofstream ofs("quiz.dat", std::ios::binary);

	//quiz.saveInBinaryFile(ofs);

	//ofs.close();
	//
	//Vector<Quiz> quizzes;

	//readFromBinaryFile("quiz.dat", quizzes);

	//std::cout << quizzes.size();


	//MyString str = "             Patlaka     Patov               ";
	//Validate::removeUnnecessarySpaces(str);
	//MyString res("Patlaka Patov");
	//std::cout << std::boolalpha << (str == res);


	Context* ctx = Context::getInstance();

	LoginCommand* sign_up_command = new LoginCommand("login testov 12345", *ctx);

	sign_up_command->execute();

	delete sign_up_command;


}
