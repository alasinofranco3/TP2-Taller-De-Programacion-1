#include "CharBlockingQueue.h"

CharBlockingQueue::CharBlockingQueue() {
	isClosed = false;
}
/*
char CharBlockingQueue::pop() {
	std::unique_lock<std::mutex> lk(mutex);
	while (queue.empty()) {
		if (isClosed) {
			return CLOSED;
		}

		notEmpty.wait(lk);
	}
	char result = queue.front();
	queue.pop();
	return result;
}
*/

int CharBlockingQueue::pop(char* result) {
	std::unique_lock<std::mutex> lk(mutex);
	while (queue.empty()) {
		if (isClosed) {
			return CLOSED;
		}

		notEmpty.wait(lk);
	}
	*result = queue.front();
	queue.pop();
	return 0;
}

void CharBlockingQueue::push(const char c) {
	std::unique_lock<std::mutex> lk(mutex);	
	queue.push(c);
	notEmpty.notify_all();
}

void CharBlockingQueue::close() {
	std::unique_lock<std::mutex> lk(mutex);	
	isClosed = true;
	notEmpty.notify_all();		
}

CharBlockingQueue::~CharBlockingQueue() {}
