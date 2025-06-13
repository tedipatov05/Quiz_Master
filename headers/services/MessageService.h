#pragma once
#include "../../headers/Context.h"

class MessageService{

public:

	static void sendMessage(Context& ctx, int receiverID, const MyString& message);
	static Vector<Message> getUserMessages(Context& ctx, const MyString& receiver);
	static void printMessages(const Vector<Message>& data);
};

