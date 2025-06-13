#pragma once
#include "Command.h"

class ViewProfileCommand : public Command{

public:

	ViewProfileCommand(const MyString& buffer, Context& ctx);

	void execute() override;
};

