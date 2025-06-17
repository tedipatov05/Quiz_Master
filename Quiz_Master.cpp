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
#include "headers/commands/CommandFactory.h"
#include "headers/commands/LoginCommand.h"
#include "headers/commands/RemoveQuizCommand.h"
#include "headers/commands/SignUpCommand.h"
#include "headers/helpers/Validate.h"
#include "headers/users/Admin.h"

int main()
{


	std::cout << "Welcome to my Quiz Master App." << std::endl;

	Context* context = Context::getInstance();

	while (true) {
		std::cout << "> ";
		
		MyString command;
		std::cin >> command;

		if (command.isEmpty() || command.toLower() == "quit") {
			std::cout << "Thank you for using my Quiz Master App! " << std::endl;
			delete context;
			break;
		}

		Command* cmd = CommandFactory::generateCommand(command, *context);

		if (cmd) {
			cmd->execute();
			delete cmd;
		}

	}

}
