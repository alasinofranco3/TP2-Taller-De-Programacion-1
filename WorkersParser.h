#ifndef WORKERSPARSER_H
#define WORKERSPARSER_H 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Thread.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"

#define ERROR 1

class WorkersParser {
	private:
		std::ifstream file;
		CharBlockingQueue* trigo;
		CharBlockingQueue* madera;
		CharBlockingQueue* minerales;
		BlockingInventory* inventory;
		ProtectedCounter* counter;
		std::vector<Thread*> *threads;

		Thread* createWorker(const std::string type);
		int runThreads(const std::string type, const int amount);

	public:
		WorkersParser();
		
		WorkersParser(std::string fileName, CharBlockingQueue* tri, 
		CharBlockingQueue* mad, CharBlockingQueue* min, BlockingInventory* i, 
		ProtectedCounter* c, std::vector<Thread*> *threads);
		//Se ocupa de ir leyendo el archivo de trabajadores y a su vez va 
		//creandolos y lanzando los threads
		int parse();
		~WorkersParser();	
};

#endif
