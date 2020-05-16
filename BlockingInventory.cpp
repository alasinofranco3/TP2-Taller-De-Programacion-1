#include "BlockingInventory.h"
#include <string>
#include <map>

BlockingInventory::BlockingInventory() {
	isClosed = false;
	inventory["Madera"] = 0;
	inventory["Trigo"] = 0;
	inventory["Carbon"] = 0;
	inventory["Hierro"] = 0;
	//gatherers = 0;
}

bool BlockingInventory::has(std::map<std::string, int> *resources) const {
	bool has = true;
	std::map<std::string, int>::iterator it = resources->begin();
	while (it != resources->end() && has == true) {
		if (inventory.at(it->first) < it->second) {
			has = false;
		} 
		it ++;
	}

	return has;
}

int BlockingInventory::take(std::map<std::string, int> *neededResources) {
	std::unique_lock<std::mutex> lk(mutex);

	while (this->has(neededResources) == false) {
		this->shouldClose();
		if (isClosed) {	
			return CLOSED;
		}

		notEmpty.wait(lk);
	}

	std::map<std::string, int>::iterator it = neededResources->begin();
	while (it != neededResources->end()) {
		inventory.at(it->first) -= it->second;
		it ++;
	}

	return 0;
}


void BlockingInventory::shouldClose() {
	
	bool b = true;
	unsigned int i = 0;

    while (i < gatherersStates.size() && b == true) {
    	if (*(gatherersStates.at(i)) == false) b = false;
    	i ++;
    }

  	if (b == true) {
  		this->close();	
 	}
	notEmpty.notify_all();		
 	
 	/*
 	if (gatherers == 0) {
 		this->close();
 	}
 	*/
}


void BlockingInventory::close() {	
	isClosed = true;
}

void BlockingInventory::add(const std::string resource) {
	std::unique_lock<std::mutex> lk(mutex);	
	inventory.at(resource) ++;
	notEmpty.notify_all();
}

void BlockingInventory::print() {
	std::cout << "Recursos restantes:" << std::endl;
	std::cout << "  -Trigo: " << inventory.at("Trigo") << std::endl;
	std::cout << "  -Madera: " << inventory.at("Madera") << std::endl;
	std::cout << "  -Carbon: " << inventory.at("Carbon") << std::endl;
	std::cout << "  -Hierro: " << inventory.at("Hierro") << std::endl;
	std::cout << std::endl;
}

void BlockingInventory::saveState(const bool* state) {
	//bool* b = (bool*)malloc(sizeof(bool*));
	//*b = state;
	gatherersStates.push_back(state);
}

/*
void BlockingInventory::addGatherer() {
	gatherers ++;
}

void BlockingInventory::destroyGatherer() {
	gatherers --;
}
*/
BlockingInventory::~BlockingInventory() {}
