#ifndef COCINERO_H
#define COCINERO_H 

#include "Productor.h"

class Cocinero : public Productor {
	private:

	public:
		Cocinero();
		Cocinero(ProtectedCounter* p, BlockingInventory* i);
		virtual int work() override;
		~Cocinero();
	
};

#endif
