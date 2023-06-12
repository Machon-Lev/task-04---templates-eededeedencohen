#pragma once
#include <iostream>
#include <list>
#include <exception>
using std::list;
using std::cout;
using std::endl;
using std::exception;

class IntegerPriorityQueue {
private:
	std::list<int> _priorityQueue;

public:

	// Constructors
	IntegerPriorityQueue();

	IntegerPriorityQueue(const IntegerPriorityQueue& queue);

	IntegerPriorityQueue(const int& element);

	IntegerPriorityQueue(const int* arr, const int& size);

	// Destructor
	~IntegerPriorityQueue();

	// Methods

	// Add element to the end of the queue
	void push(const int& element);

	// Remove element from the front of the queue
	int poll();

	// Return the size of the queue 
	size_t size() const;

	// Return true if the queue is empty
	bool isEmpty() const;

	// Return the element (without remove it) at the front of the queue - the smallest element
	int peek() const;

	// Return the element (without remove it) at the back of the queue - the biggest element
	int back() const;

	// Print the queue
	void print() const;

	// Return true if the queue contains the element t
	bool contains(const int& element) const;

	// Remove all elements from the queue
	void clear();

	// Remove the element from the queue - t is the element to be removed
	void remove(const int& element);
	
	// Return the index of the element t
	int indexOf(const int& element) const;

	// Return true if the queue is equals to the other queue
	bool equals(const IntegerPriorityQueue& other) const;

	// Return true if the queue is equals to the other queue
	bool operator==(const IntegerPriorityQueue& other) const;

	// Return true if the queue is not equals to the other queue
	bool operator!=(const IntegerPriorityQueue& other) const;
};
