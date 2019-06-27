#include "SafeBus.h"
#include "Message.h"
#include "MessageReceiver.h"
#include "DefineId.h"

SafeBus::SafeBus()
{
	uniqueGuid = EM_DEF_ID::ALLOCATE_START;
}

void SafeBus::AddReceiver(MessageReceiver* receiver)
{
	_mapReceiver.insert( make_pair(receiver->GetReceiverId(), receiver) );
}

void SafeBus::TransferMessage(const shared_ptr<Message>& msg)
{
	_msgQueue.push(msg);
}

void SafeBus::Notify()
{
	while (!_msgQueue.empty())
	{
		cout << "[Message Queue] Count =" << _msgQueue.size() << endl;
		const shared_ptr<Message> msg = _msgQueue.front();

		const uint& toId = msg->getTo();

		if (EM_DEF_ID::BROADCAST == toId)
		{
			for (auto& it : _mapReceiver)
			{
				it.second->onReceive(msg->getFrom(), msg->getTo(), msg->getType(), msg->getMsg());
			}
		}
		else 
		{
			map<uint, MessageReceiver*>::iterator it = _mapReceiver.find(toId);
			
			if (it != _mapReceiver.end())
			{
				it->second->onReceive(msg->getFrom(), msg->getTo(), msg->getType(), msg->getMsg());
			}
		}
			   		
		_msgQueue.pop();
	}
}


