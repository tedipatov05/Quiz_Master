#pragma once
#include "Command.h"

class RemoveQuizCommand : public Command{

public:

	RemoveQuizCommand(const MyString& buffer, Context& ctx);

	void execute() override;

private:

	MyString getReasonFromBuffer(const Vector<MyString>& data) const;
};

