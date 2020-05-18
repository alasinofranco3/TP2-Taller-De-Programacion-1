#include "Productor.h"

Productor::Productor() {}

Productor::Productor(ProtectedCounter* p, BlockingInventory* i) {
	points = p;
	inventory = i;
}

Productor::~Productor() {}
