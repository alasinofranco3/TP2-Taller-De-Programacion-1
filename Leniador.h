#ifndef LENIADOR_H
#define LENIADOR_H 

#include "Recolector.h"

class Leniador : public Recolector {
	private:
	public:
		Leniador();
		Leniador(CharBlockingQueue* q, BlockingInventory* i);
		virtual int work() override;
		~Leniador();
};
#endif
