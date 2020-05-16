#include "Leniador.h"

Leniador::Leniador(CharBlockingQueue* q, 
	BlockingInventory* i) : Recolector(q, i) {}

int Leniador::work() {
	char result = 0;
	while (result != CLOSED) {
		//std::cout << "Tamanio cola de madera: " << queue->size() << std::endl;	
		result = queue->pop();
		//std::cout << "Leniador obtiene de la cola: " << result << std::endl;
		if (result == CLOSED) {
			finished = true;
			//inventory->destroyGatherer();
			return CLOSED;
			//VER COMO CERRAR EL INVENTARIO
			//ver que hacer
		} 

		usleep(50000);
		inventory->add("Madera");
	}	
	return 0;
}

Leniador::~Leniador(){}
