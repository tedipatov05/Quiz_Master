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
#include "headers/commands/ApproveQuizCommand.h"
#include "headers/commands/BanUserCommand.h"
#include "headers/commands/ChallengesCommand.h"
#include "headers/commands/LoginCommand.h"
#include "headers/commands/RemoveQuizCommand.h"
#include "headers/commands/SignUpCommand.h"
#include "headers/helpers/Validate.h"
#include "headers/users/Admin.h"

int main()
{

	/*Quiz quiz = Quiz(100, 1);
	quiz.read();
	std::ofstream ofs(quizzesFile.data(), std::ios::binary);

	quiz.writeToBinaryFile(ofs);

	ofs.close();
	*/

	User* admin = new Admin("admin", "adminov", "adminov1", "1234", 101);
	User* player = new Player("test", "testov", "player1", "12345", 100);
	std::ofstream ostream(userFile.data(), std::ios::binary);
	admin->writeToBinaryFile(ostream);
	player->writeToBinaryFile(ostream);

	ostream.close();


	Context* ctx = Context::getInstance();

	LoginCommand* sign_up_command = new LoginCommand("login player1 12345", *ctx);

	sign_up_command->execute();

	//BanUserCommand* ban = new BanUserCommand("ban player1", *ctx);

	//ban->execute();

	ChallengesCommand* cmd = new ChallengesCommand("challenges", *ctx);

	cmd->execute();


	delete sign_up_command;
	//delete ban;
	delete cmd;
	delete ctx;


}
