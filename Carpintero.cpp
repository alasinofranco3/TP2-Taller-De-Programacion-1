#include "Carpintero.h"

Carpintero::Carpintero(ProtectedCounter* p, BlockingInventory* i) : Productor(p, i) {
	neededResources["Madera"] = 3;
	neededResources["Hierro"] = 1;
}

int Carpintero::work() {
	int result = 0;
	while (result != CLOSED) {
		result = inventory->take(&neededResources);
		if (result == CLOSED) {
			return CLOSED;
			//VER COMO CERRAR EL CONTADOR DE PUNTOS
			//ver que hacer
		}
		
		usleep(60000);
		points->add(2);
	}
	return 0;
}

Carpintero::~Carpintero(){}
