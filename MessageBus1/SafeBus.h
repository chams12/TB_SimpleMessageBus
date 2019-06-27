#pragma once

#include <queue>
#include <vector>
#include <map>
#include "Common.h"

class Message;
class MessageReceiver;


class SafeBus
{
private:
	uint uniqueGuid;

public:
	SafeBus();
	~SafeBus() {}

private: 
	queue<shared_ptr<Message>> _msgQueue;
	map<uint, MessageReceiver*> _mapReceiver;

public:
	void AddReceiver(MessageReceiver* receiver);
	void TransferMessage(const shared_ptr<Message>& msg);
	void Notify();

	uint GenerateUniqueGUID() 
	{
		return ++uniqueGuid;
	}


};

