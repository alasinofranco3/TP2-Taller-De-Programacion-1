#ifndef MAPPARSER_H
#define MAPPARSER_H 

#include <string>
#include <iostream>
#include <fstream>
#include "CharBlockingQueue.h"

#define ERROR 1

class MapParser {
	private:
		std::ifstream fileMap;
		CharBlockingQueue* trigo;
		CharBlockingQueue* madera;
		CharBlockingQueue* minerales;

	public:
		MapParser();
		MapParser(const std::string file, CharBlockingQueue* madera, 
			CharBlockingQueue* trigo, CharBlockingQueue* minerales);
		~MapParser();
		//Se ocupa de parsear el mapa e ir llenando las colas de recursos
		//Una vez finalizado el archivo ,cierra las colas.
		int parse();
};
#endif
