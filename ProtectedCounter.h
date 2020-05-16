#ifndef PROTECTEDCOUNTER_H
#define PROTECTEDCOUNTER_H 

#include <mutex>
#include <iostream>

class ProtectedCounter {
	private:
		std::mutex mutex;
		int counter;
	public:
		ProtectedCounter();
		~ProtectedCounter();
		void add(const int value);
		void print() const;
};

#endif
