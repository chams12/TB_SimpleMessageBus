#include "ComponentB.h"
#include "SafeBus.h"


ComponentB::ComponentB(SafeBus * bus) : MessageReceiver(bus), MessageSender(bus)
{
}

void ComponentB::onReceive(const uint& from, const uint& to, const string& type, const string& msg)
{
	cout << "[ComponentB::onReceive] from: " << from << ", to: " << to << ", type: " << type << ", msg: " << msg << endl;
}

void ComponentB::Send(const uint& from, const uint& to, const string& type, const string& msg)
{
	cout << "[ComponentB::Send] from: " << from << ", to: " << to << ", type: " << type << ", msg: " << msg << endl;
	MessageSender::Send(from, to, type, msg);
}
