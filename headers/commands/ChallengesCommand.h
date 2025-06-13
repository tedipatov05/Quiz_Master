#pragma once
#include "Command.h"

class ChallengesCommand : public Command{

public:

	ChallengesCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

