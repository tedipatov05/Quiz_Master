#pragma once
#include "Command.h"

class StartQuizCommand : public Command{
public:

	StartQuizCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

