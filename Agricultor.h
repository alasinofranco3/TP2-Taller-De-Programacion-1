#ifndef AGRICULTOR_H
#define AGRICULTOR_H 

#include "Recolector.h"

class Agricultor : public Recolector {
	private:

	public:
		Agricultor();
		Agricultor(CharBlockingQueue* q, BlockingInventory* i);
		virtual int work() override;
		~Agricultor();
	
};

#endif
