#pragma once
#include "Command.h"

class LogoutCommand : public Command{

public:

	LogoutCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

