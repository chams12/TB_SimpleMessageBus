#pragma once

#include "Common.h"

class SafeBus;

class MessageReceiver
{
public:
	MessageReceiver(SafeBus * bus);
	~MessageReceiver() {}

public:
	virtual void onReceive(const uint& from, const uint& to, const string& type, const string& msg) {}

public:
	const uint GetReceiverId() { return _receiverId; }

private:
	uint _receiverId;
	SafeBus *mpSafeBus = nullptr;
};

