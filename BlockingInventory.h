#ifndef BLOCKINGINVENTORY_H
#define BLOCKINGINVENTORY_H 

#include <iostream>
#include <map>
#include <mutex>
#include <condition_variable>
#include <vector>


#define CLOSED 2


class BlockingInventory {
	private:
		bool isClosed;
		std::map<std::string, int> inventory;
		std::mutex mutex;
		std::condition_variable notEmpty;
		bool has(std::map<std::string, int> *resources) const;
		
		std::vector<const bool*> gatherersStates;
		//int gatherers;
	public:
		BlockingInventory();
		~BlockingInventory();
		void add(const std::string resource);
		int take(std::map<std::string, int> *neededResources);
		void close();
		void print();

		void saveState(const bool* state);
		//void addGatherer();
		//void destroyGatherer();
		void shouldClose();
};

#endif
