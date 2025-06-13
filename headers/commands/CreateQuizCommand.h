#pragma once
#include "Command.h"

class CreateQuizCommand : public Command{
public:

	CreateQuizCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

