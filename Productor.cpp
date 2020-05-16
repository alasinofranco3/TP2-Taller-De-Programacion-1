#include "Productor.h"

Productor::Productor() {}

Productor::Productor(ProtectedCounter* p, BlockingInventory* i) {
	points = p;
	inventory = i;
}


void Productor::run() {
	this->work();
}

Productor::~Productor() {}
