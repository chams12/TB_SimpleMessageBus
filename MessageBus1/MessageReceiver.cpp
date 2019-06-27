#include "MessageReceiver.h"
#include "SafeBus.h"


MessageReceiver::MessageReceiver(SafeBus * bus)
{
	_receiverId = bus->GenerateUniqueGUID();

	mpSafeBus = bus;
	mpSafeBus->AddReceiver(this);
}