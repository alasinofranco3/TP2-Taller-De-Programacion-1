#include "ProtectedCounter.h"

ProtectedCounter::ProtectedCounter() {
	counter = 0;
}	

void ProtectedCounter::add(const int value) {
	std::unique_lock<std::mutex> lk(mutex);	
	counter += value;
}

void ProtectedCounter::print() const {
	std::cout << "Puntos de Beneficio acumulados: " << counter << std::endl;
}

ProtectedCounter::~ProtectedCounter() {}
