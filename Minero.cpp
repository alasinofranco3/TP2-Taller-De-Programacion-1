#include "Minero.h"

Minero::Minero(CharBlockingQueue* q, 
	BlockingInventory* i) : Recolector(q, i) {}

int Minero::run() {
	char result = 0;
	while (result != CLOSED) {	
		result = queue->pop();
		if (result == CLOSED) {
			finished = true;
			return CLOSED;
		} 
		usleep(50000);
		if (result == 'H') {
			inventory->add("Hierro");
		} else {
			inventory->add("Carbon");
		}
	}	
	return 0;
}

Minero::~Minero(){}
