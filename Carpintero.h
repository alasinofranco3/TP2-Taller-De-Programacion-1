#ifndef CARPINTERO_H
#define CARPINTERO_H 

#include "Productor.h"

class Carpintero : public Productor {
	public:
		Carpintero();
		Carpintero(ProtectedCounter* p, BlockingInventory* i);
		virtual int run() override;
		~Carpintero();
};

#endif
