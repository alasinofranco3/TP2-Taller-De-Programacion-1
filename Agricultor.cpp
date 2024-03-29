#include "Agricultor.h"

Agricultor::Agricultor(CharBlockingQueue* q, 
	BlockingInventory* i) : Recolector(q, i) {}

int Agricultor::run() {
	char result = 0;
	char poppedElement;
	while (result != CLOSED) {
		result = queue->pop(&poppedElement);
		if (result == CLOSED) {
			finished = true;
			return CLOSED;
		} 
		usleep(50000);
		inventory->add("Trigo");
	}
	return 0;
}

Agricultor::~Agricultor(){}
