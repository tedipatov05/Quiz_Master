#pragma once
#include "Command.h"

class RemoveFromFavouriteCommand : public Command{
public:

	RemoveFromFavouriteCommand(const MyString& buffer, Context& ctx);
	void execute() override;
};

