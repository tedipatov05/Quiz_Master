#pragma once
#include "Command.h"

class BanUserCommand : public Command{

public:

	BanUserCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

