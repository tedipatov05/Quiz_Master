#pragma once
#include "Command.h"

class ViewQuizzesCommand : public Command{
public:

	ViewQuizzesCommand(const MyString& buffer, Context& ctx);

	void execute() override;

};

