#ifndef WORKERSPARSER_H
#define WORKERSPARSER_H 

#include <iostream>
#include <fstream>
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

		Thread* createWorker(std::string type);
		int runThreads(std::string type, int amount);

	public:
		WorkersParser();
		
		WorkersParser(std::string fileName, CharBlockingQueue* tri, 
		CharBlockingQueue* mad, CharBlockingQueue* min, BlockingInventory* i, 
		ProtectedCounter* c, std::vector<Thread*> *threads);

		int parse();
		~WorkersParser();
	
};

#endif