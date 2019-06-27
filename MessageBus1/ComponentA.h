#pragma once

#include "MessageReceiver.h"
#include "MessageSender.h"

class SafeBus;

class ComponentA : public MessageReceiver, public MessageSender
{
public:
	ComponentA(SafeBus * bus);
	~ComponentA() {}

public:
	void onReceive(const uint& from, const uint& to, const string& type, const string& msg) override;
	void Send(const uint& from, const uint& to, const string& type, const string& msg) override;

};

