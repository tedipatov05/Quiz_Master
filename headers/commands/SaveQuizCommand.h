#pragma once
#include "Command.h"

class SaveQuizCommand : public Command{
public:

	SaveQuizCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

