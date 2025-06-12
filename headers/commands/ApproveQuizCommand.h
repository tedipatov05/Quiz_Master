#pragma once
#include "Command.h"

class ApproveQuizCommand : public Command{

public:

	ApproveQuizCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

