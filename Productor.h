#ifndef PRODUCTOR_H
#define PRODUCTOR_H 

#include "BlockingInventory.h"
#include "Thread.h"
#include "ProtectedCounter.h"
#include <string>
#include <map>

class Productor : public Thread {
	protected:
		ProtectedCounter* points;
		BlockingInventory* inventory;
		std::map<std::string, int> neededResources;
	public:
		Productor();
		Productor(ProtectedCounter* p, BlockingInventory* i);
		virtual void run() override;
		virtual int work() = 0;
		virtual ~Productor();	
};

#endif
