#include "Recolector.h"

Recolector::Recolector() {}

Recolector::Recolector(CharBlockingQueue* q, BlockingInventory* i) {
	queue = q;
	inventory = i;
	finished = false;
}

const bool& Recolector::getState() const{
	return finished;
}

Recolector::~Recolector() {}
