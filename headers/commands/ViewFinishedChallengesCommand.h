#pragma once
#include "Command.h"

class ViewFinishedChallengesCommand : public Command{
public:

	ViewFinishedChallengesCommand(const MyString& buffer, Context& ctx);

	void execute() override;

};

