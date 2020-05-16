#include "Armero.h"

Armero::Armero(ProtectedCounter* p, BlockingInventory* i) : Productor(p, i) {
	neededResources["Carbon"] = 2;
	neededResources["Hierro"] = 2;
}

int Armero::work() {
	int result = 0;
	while (result != CLOSED) {
		result = inventory->take(&neededResources);
		if (result == CLOSED) {
			return CLOSED;
			//VER COMO CERRAR EL CONTADOR DE PUNTOS
			//ver que hacer
		}
		
		usleep(60000);
		std::cout << "";

		points->add(3);
	}
	return 0;
}

Armero::~Armero(){}
