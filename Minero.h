#ifndef MINERO_H
#define MINERO_H 

#include "Recolector.h"

class Minero : public Recolector {
	public:
		Minero();
		Minero(CharBlockingQueue* q, BlockingInventory* i);
		virtual int run() override;
		~Minero();	
};
#endif
