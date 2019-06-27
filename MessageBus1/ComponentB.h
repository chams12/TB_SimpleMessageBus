#pragma once

#include "MessageReceiver.h"
#include "MessageSender.h"

class ComponentB : public MessageReceiver, public MessageSender
{
public:
	ComponentB(SafeBus * bus);
	~ComponentB() {}

public:
	void onReceive(const uint& from, const uint& to, const string& type, const string& msg) override;
	void Send(const uint& from, const uint& to, const string& type, const string& msg) override;
};

