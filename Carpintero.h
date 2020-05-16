#ifndef CARPINTERO_H
#define CARPINTERO_H 

#include "Productor.h"

class Carpintero : public Productor {
	private:
	public:
		Carpintero();
		Carpintero(ProtectedCounter* p, BlockingInventory* i);
		virtual int work() override;
		~Carpintero();
};

#endif
