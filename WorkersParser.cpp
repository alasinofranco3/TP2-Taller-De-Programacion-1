#include "WorkersParser.h"
#include <vector>
#include <string>

WorkersParser::WorkersParser(std::string fileName, CharBlockingQueue* tri, 
	CharBlockingQueue* mad, CharBlockingQueue* min, BlockingInventory* i, 
	ProtectedCounter* c, std::vector<Thread*> *threads) {
	file.open(fileName);
	madera = mad;
	minerales = min;
	trigo = tri;
	inventory = i;
	counter = c;
	this->threads = threads;
}


int WorkersParser::parse() {
	std::string line, type;
	std::size_t equalsOpPos;
	int amount;

	if (!(this->file.good())) {
		std::cout << "Error al abrir el archivo del mapa\n";
		return ERROR;
	}

	while (std::getline(file, line)) {
		int status;
		equalsOpPos = line.find("=", 0);	  
		if (equalsOpPos == std::string::npos) return ERROR;
		type = line.substr(0, equalsOpPos);  
		amount = std::stoi(line.substr(equalsOpPos + 1));
		
		status = this->runThreads(type, amount);
		if (status == ERROR) return ERROR;
	}

	return 0;
}

int WorkersParser::runThreads(std::string type, int amount) {
	for (int i = 0; i < amount; i++) {
		Thread *t = this->createWorker(type);
		if (t == NULL) {
			std::cout << "Error: Trabajador desconocido" << std::endl;
			return ERROR;
		}
		
		t->start();
		threads->push_back(t);
	}

	return 0;
}

Thread* WorkersParser::createWorker(std::string type) {
	Recolector* r;
	if (type == "Agricultores") {
		r = new Agricultor(trigo, inventory);
		inventory->saveState(r->getState());
		//inventory->addGatherer();
		return r;  			
	} else if (type == "Leniadores") {
		r = new Leniador(madera, inventory);
		inventory->saveState(r->getState());
		//inventory->addGatherer();
		return r;  	
	} else if (type == "Mineros") {
		r = new Minero(minerales, inventory);
		inventory->saveState(r->getState());
		//inventory->addGatherer();
		return r;  
	} else if (type == "Cocineros") {
		return new Cocinero(counter, inventory);
	} else if (type == "Carpinteros") {
		return new Carpintero(counter, inventory);
	} else if (type == "Armeros") {
		return new Armero(counter, inventory);
	} else {
		return NULL;
	}		
}

WorkersParser::~WorkersParser() {
	file.close();
	for (unsigned int i = 0; i < threads->size(); ++i) {
        delete threads->at(i);
    }
}
