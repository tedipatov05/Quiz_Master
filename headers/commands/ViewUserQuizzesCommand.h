#pragma once
#include "Command.h"

class ViewUserQuizzesCommand : public Command{
public:

	ViewUserQuizzesCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

