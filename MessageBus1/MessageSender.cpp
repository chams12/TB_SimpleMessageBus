#include "MessageSender.h"
#include "Message.h"
#include "SafeBus.h"

void MessageSender::Send(const uint& from, const uint& to, const string& type, const string& msg)
{
	shared_ptr<Message> message = make_shared<Message>(from, to, type, msg);
	
	if(mpSafeBus)
		mpSafeBus->TransferMessage(message);
}