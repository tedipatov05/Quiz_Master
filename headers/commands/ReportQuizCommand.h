#pragma once
#include "Command.h"

class ReportQuizCommand : public Command{

public:

	ReportQuizCommand(const MyString& buffer, Context& ctx);

	void execute() override;

private:

	MyString getReason(const Vector<MyString>& data);
};

