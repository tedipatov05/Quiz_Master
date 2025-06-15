#pragma once
#include "Command.h"

class HelpCommand : public Command{

public:
	HelpCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

