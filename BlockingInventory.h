#ifndef BLOCKINGINVENTORY_H
#define BLOCKINGINVENTORY_H 

#include <iostream>
#include <map>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <string>


#define CLOSED 2


class BlockingInventory {
	private:
		bool isClosed;
		std::map<std::string, int> inventory;
		std::mutex mutex;
		std::condition_variable notEmpty;
		std::vector<const bool*> gatherersStates;
		
		/*Indica si la cantidad de recursos del mapa pasado por parametro
		esta disponible en el inventario*/
		bool has(std::map<std::string, int> *resources) const;
		//void close();
	public:
		BlockingInventory();
		~BlockingInventory();
		void add(const std::string resource);
		int take(std::map<std::string, int> *neededResources);
		//Imprime los recursos del inventario
		void print();
		/*Guarda en gatherersStates el bool* recibido, que representa 
		si un recolector termino o no su trabajo*/
		void saveState(const bool* state);
		/*Verifica si se debe cerrar el inventario.En caso afirmativo
		lo cierra*/
		void shouldClose();
};

#endif
