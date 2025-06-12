#pragma once
#include "../../headers/Context.h"

class MessageService{

public:

	static void sendMessage(Context& ctx, int receiverID, const MyString& message);
};

