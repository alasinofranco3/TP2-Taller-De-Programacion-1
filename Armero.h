#ifndef ARMERO_H
#define ARMERO_H 

#include "Productor.h"

class Armero : public Productor {
	private:
	public:
		Armero();
		Armero(ProtectedCounter* p, BlockingInventory* i);
		virtual int work() override;
		~Armero();	
};

#endif
