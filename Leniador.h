#ifndef LENIADOR_H
#define LENIADOR_H 

#include "Recolector.h"

class Leniador : public Recolector {
	public:
		Leniador();
		Leniador(CharBlockingQueue* q, BlockingInventory* i);
		virtual int run() override;
		~Leniador();
};
#endif
