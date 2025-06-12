#pragma once
#include "Command.h"
class LoginCommand : public Command{

public:
	LoginCommand(const MyString& buffer, Context& ctx);

	void execute() override;

};

