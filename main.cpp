#include "WorkersParser.h"
#include "MapParser.h"

int main(int argc, char const *argv[]) {
	CharBlockingQueue mad, min, tri;
	BlockingInventory inv;
	ProtectedCounter counter;
	std::vector<Thread*> threads;

	MapParser mParser(argv[2], &mad, &tri, &min); 
	WorkersParser wParser(argv[1], &tri, &mad, &min, &inv, &counter, &threads);
	
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

	return 0;
}