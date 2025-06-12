#pragma once
#include "Command.h"
class RejectQuizCommand : public Command{

public:
	RejectQuizCommand(const MyString& buffer, Context& ctx);
	void execute() override;


private:

	MyString getReasonFromBuffer(const Vector<MyString>& data) const;
};

