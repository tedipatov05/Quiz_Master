#pragma once
#include "Command.h"

class ViewUserCommand : public Command{
public:

	ViewUserCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

