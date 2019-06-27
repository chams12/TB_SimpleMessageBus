#pragma once

#include <iostream>
#include "Common.h"

class Message
{
public:
	Message(uint from, uint to, string type, string msg) : _from(from), _to(to), _type(type), _msg(msg) {}
	~Message() {}

private:
	uint _from;
	uint _to;
	string _type;
	string _msg;

public:
	const uint& getFrom() { return _from;  }
	const uint& getTo() { return _to; }
	const string& getType() { return _type;  }
	const string& getMsg() { return _msg; }
};

