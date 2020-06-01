#include "WorkersParser.h"
#include "MapParser.h"
#include <vector>

int main(int argc, char const *argv[]) {
	CharBlockingQueue mad, min, tri;
	BlockingInventory inv;
	ProtectedCounter counter;
	std::vector<Thread*> threads;

	try {
		WorkersParser wParser(argv[1], &tri, &mad, &min, &inv, &counter, &threads);
		MapParser mParser(argv[2], &mad, &tri, &min); 
		
		if (wParser.parse() == ERROR) {
			return ERROR;
		}

		if (mParser.parse() == ERROR) {
			return ERROR;
		}

		for (unsigned int i = 0; i < threads.size(); ++i) {
	        threads[i]->join();
	    }

		inv.print();
		counter.print();
	} catch(const std::exception &e) {
		return ERROR;
	}

	return 0;
}
