#include "Cocinero.h"

Cocinero::Cocinero(ProtectedCounter* p, 
	BlockingInventory* i) : Productor(p, i) {
	neededResources["Trigo"] = 2;
	neededResources["Carbon"] = 1;
}

int Cocinero::run() {
	int result = 0;
	while (result != CLOSED) {
		result = inventory->take(&neededResources);
		if (result == CLOSED) {
			return CLOSED;
		}
		usleep(60000);
		points->add(5);
	}	
	return 0;
}

Cocinero::~Cocinero(){}
