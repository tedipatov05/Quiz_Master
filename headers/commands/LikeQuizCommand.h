#pragma once
#include "Command.h"

class LikeQuizCommand : public Command{
public:

	LikeQuizCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

