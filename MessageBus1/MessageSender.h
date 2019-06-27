#pragma once

#include "Common.h"

/**
- Send to designated component
- Send to all except sender
- Send to all including sender
*/

class SafeBus;

class MessageSender
{
public:
	MessageSender(SafeBus * bus) : mpSafeBus(bus) {}
	~MessageSender() {}

public:
	virtual void Send(const uint& from, const uint& to, const string& type, const string& msg);

private:
	SafeBus *mpSafeBus = nullptr;
};

