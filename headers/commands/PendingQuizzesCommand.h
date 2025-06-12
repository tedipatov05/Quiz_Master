#pragma once
#include "Command.h"

class PendingQuizzesCommand : public Command{

public:

	PendingQuizzesCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

