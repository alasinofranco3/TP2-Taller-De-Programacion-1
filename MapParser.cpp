#include "MapParser.h"

MapParser::MapParser(std::string file, CharBlockingQueue* madera, 
		CharBlockingQueue* trigo, CharBlockingQueue* minerales) {
	fileMap.open(file);
	this->madera = madera;
	this->trigo = trigo;
	this->minerales = minerales;
}

int MapParser::parse() {
	char c;

	if (!(this->fileMap.good())) {
		std::cout << "Error al abrir el archivo del mapa\n";
		return ERROR;
	}

	while (fileMap.get(c)) {
		if (c == 'T') {
			trigo->push(c);
		} else if (c == 'M') {
			madera->push(c);
		} else if (c == 'H' || c == 'C') {
			minerales->push(c);
		} 
	}

	this->madera->close();
	this->trigo->close();
	this->minerales->close();	
	return 0;
}

MapParser::~MapParser() {
	fileMap.close();
}
