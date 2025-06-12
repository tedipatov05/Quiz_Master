#pragma once
#include "Command.h"

class ViewReportsCommand : public Command{

public:

	ViewReportsCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

