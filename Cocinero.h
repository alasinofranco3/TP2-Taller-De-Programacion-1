#ifndef COCINERO_H
#define COCINERO_H 

#include "Productor.h"

class Cocinero : public Productor {
	public:
		Cocinero();
		Cocinero(ProtectedCounter* p, BlockingInventory* i);
		virtual int run() override;
		~Cocinero();
};

#endif
