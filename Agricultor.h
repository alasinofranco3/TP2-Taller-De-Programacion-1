#ifndef AGRICULTOR_H
#define AGRICULTOR_H 

#include "Recolector.h"

class Agricultor : public Recolector {
	public:
		Agricultor();
		Agricultor(CharBlockingQueue* q, BlockingInventory* i);
		virtual int run() override;
		~Agricultor();
};

#endif
