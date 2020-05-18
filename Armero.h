#ifndef ARMERO_H
#define ARMERO_H 

#include "Productor.h"

class Armero : public Productor {
	public:
		Armero();
		Armero(ProtectedCounter* p, BlockingInventory* i);
		virtual int run() override;
		~Armero();	
};

#endif
