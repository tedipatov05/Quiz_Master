#pragma once
#include "Command.h"

class SignUpCommand : public Command{

public:
	SignUpCommand(const MyString& buffer, Context& ctx);

	void execute() override;

};

