#ifndef MINERO_H
#define MINERO_H 

#include "Recolector.h"

class Minero : public Recolector {
	private:

	public:
		Minero();
		Minero(CharBlockingQueue* q, BlockingInventory* i);
		virtual int work() override;
		~Minero();
	
};

#endif
