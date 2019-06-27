#include "ComponentA.h"
#include "SafeBus.h"


ComponentA::ComponentA(SafeBus * bus) : MessageReceiver(bus), MessageSender(bus)
{
}

void ComponentA::onReceive(const uint& from, const uint& to, const string& type, const string& msg)
{
	cout<<"[ComponentA::onReceive] from: "<< from << ", to: " << to << ", type: " << type << ", msg: " << msg << endl;
}

void ComponentA::Send(const uint& from, const uint& to, const string& type, const string& msg)
{
	cout << "[ComponentA::Send] from: " << from << ", to: " << to << ", type: " << type << ", msg: " << msg << endl;
	MessageSender::Send(from, to, type, msg);
}