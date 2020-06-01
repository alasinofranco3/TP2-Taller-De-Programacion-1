#ifndef CHARBLOCKINGQUEUE
#define CHARBLOCKINGQUEUE 

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

#define CLOSED 2

class CharBlockingQueue {
	private:
		bool isClosed;
		std::queue<char> queue;
		std::mutex mutex;
		std::condition_variable notEmpty;

	public:
		CharBlockingQueue();
		~CharBlockingQueue();
		//char pop();
		int pop(char* result);
		void push(const char c);
		void close();
};

#endif
