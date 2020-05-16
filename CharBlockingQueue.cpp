#include "CharBlockingQueue.h"

CharBlockingQueue::CharBlockingQueue() {
	isClosed = false;
}

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

void CharBlockingQueue::push(char c) {
	std::unique_lock<std::mutex> lk(mutex);	
	queue.push(c);
	notEmpty.notify_all();
}

unsigned int CharBlockingQueue::size() const {
	return queue.size();
}

void CharBlockingQueue::close() {
	std::unique_lock<std::mutex> lk(mutex);	
	isClosed = true;
	notEmpty.notify_all();		
}

CharBlockingQueue::~CharBlockingQueue() {}
