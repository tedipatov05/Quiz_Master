#pragma once
#include "Command.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "PendingQuizzesCommand.h"
#include "ApproveQuizCommand.h"
#include "RejectQuizCommand.h"
#include "ViewReportsCommand.h"
#include "RemoveQuizCommand.h"
#include "BanUserCommand.h"
#include "SignUpCommand.h"
#include "ViewProfileCommand.h"
#include "ChallengesCommand.h"
#include "ViewUserCommand.h"
#include "MessagesCommand.h"
#include "CreateQuizCommand.h"
#include "ViewQuizzesCommand.h"
#include "ViewUserQuizzesCommand.h"
#include "LikeQuizCommand.h"
#include "UnlikeQuizCommand.h"
#include "AddToFavouriteCommand.h"
#include "RemoveFromFavouriteCommand.h"
#include "StartQuizCommand.h"
#include "SaveQuizCommand.h"
#include "ViewFinishedChallengesCommand.h"
#include "ReportQuizCommand.h"



class CommandFactory{

public:

	static Command* generateCommand(const MyString& buffer, Context& ctx);
};

