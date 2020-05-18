#ifndef RECOLECTOR_H
#define RECOLECTOR_H 

#include "CharBlockingQueue.h"
#include "BlockingInventory.h"
#include "Thread.h"

class Recolector : public Thread {
	protected:
		CharBlockingQueue* queue;
		BlockingInventory* inventory;
		bool finished;
	public:
		Recolector();
		Recolector(CharBlockingQueue* q, BlockingInventory* i);
	
		//Devuelve una referencia al atributo finished del recolector
		const bool* getState() const;
		virtual ~Recolector();
};

#endif
