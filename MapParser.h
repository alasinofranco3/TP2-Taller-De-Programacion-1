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
		MapParser(std::string file, CharBlockingQueue* madera, 
			CharBlockingQueue* trigo, CharBlockingQueue* minerales);
		int parse();
		
		~MapParser();
};
#endif
