#include "Leniador.h"

Leniador::Leniador(CharBlockingQueue* q, 
	BlockingInventory* i) : Recolector(q, i) {}

int Leniador::run() {
	char result = 0;
	char poppedElement;
	while (result != CLOSED) {
		result = queue->pop(&poppedElement);
		if (result == CLOSED) {
			finished = true;
			return CLOSED;
		} 

		usleep(50000);
		inventory->add("Madera");
	}	
	return 0;
}

Leniador::~Leniador(){}
