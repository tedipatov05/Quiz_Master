#pragma once
#include "Command.h"

class UnlikeQuizCommand : public Command{

public:

	UnlikeQuizCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

