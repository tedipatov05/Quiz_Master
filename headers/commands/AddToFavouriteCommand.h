#pragma once
#include "Command.h"

class AddToFavouriteCommand : public Command{
public:

	AddToFavouriteCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

