#pragma once
#include "Command.h"

class MessagesCommand : public Command{

public:

	MessagesCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

