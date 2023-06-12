#include "IntegerPriorityQueue.h"

//=======================================================
//=================  MyComparator  =====================
//=======================================================
template <typename T>
struct MyComparator {
	T operator()(const T& a, const T& b) const {
		return a - b;
	}
};


/*=========================
	  constructors:
=========================*/

// Default c-tor
IntegerPriorityQueue::IntegerPriorityQueue()
{
	this->_priorityQueue = list<int>();
}

// Copy c-tor
IntegerPriorityQueue::IntegerPriorityQueue(const IntegerPriorityQueue& queue)
{
	this->_priorityQueue = list<int>(queue._priorityQueue);
}

// c-tor from a single element
IntegerPriorityQueue::IntegerPriorityQueue(const int& element) {
	this->_priorityQueue.push_back(element);
}

// c-tor from an array
IntegerPriorityQueue::IntegerPriorityQueue(const int* arr, const int& size) {
	for (int i = 0; i < size; ++i) {
		this->_priorityQueue.push_back(arr[i]);
	}
	this->_priorityQueue.sort(); // sort the queue
}

/*=========================
	Destructor:
=========================*/
IntegerPriorityQueue::~IntegerPriorityQueue() {
	this->_priorityQueue.clear();
}

/*=========================
		Methods:
=========================*/

// Add element to the queue
void IntegerPriorityQueue::push(const int& newElement) {
	MyComparator<int> comp;

	// "it" will point to the first element bigger than t
	auto it = this->_priorityQueue.begin();
	while (it != this->_priorityQueue.end() && !comp(*it, newElement)) {
		it++;
	}
	// insert the new element and move right the biggers elements
	this->_priorityQueue.insert(it, newElement);
}


// Remove element from the front of the queue - the smallest element
int IntegerPriorityQueue::poll() {
	if (this->_priorityQueue.empty()) {
		throw exception("The queue is empty");
	}
	int smallestElement = this->_priorityQueue.front();
	this->_priorityQueue.pop_front(); // remove the smallest element
	return smallestElement;
}

size_t IntegerPriorityQueue::size() const {
	return this->_priorityQueue.size();
}

bool IntegerPriorityQueue::isEmpty() const {
	return this->_priorityQueue.empty();
}

// Return the smallest element
int IntegerPriorityQueue::peek() const {
	if (this->_priorityQueue.empty()) {
		throw exception("The queue is empty");
	}
	return this->_priorityQueue.front();
}

// Return the biggest element
int IntegerPriorityQueue::back() const {
	if (this->_priorityQueue.empty()) {
		throw exception("The queue is empty");
	}
	return this->_priorityQueue.back();
}

void IntegerPriorityQueue::print() const {
	for (list<int>::const_iterator it = this->_priorityQueue.begin(); it != this->_priorityQueue.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

// Return true if the queue contains the element 
bool IntegerPriorityQueue::contains(const int& element) const {
	for (list<int>::const_iterator it = this->_priorityQueue.begin(); it != this->_priorityQueue.end(); ++it) {
		if (*it == element) {
			return true;
		}
	}
	return false;
}

void IntegerPriorityQueue::clear() {
	this->_priorityQueue.clear();
}

void IntegerPriorityQueue::remove(const int& element) {
	this->_priorityQueue.remove(element);
}


int IntegerPriorityQueue::indexOf(const int& element) const {
	int index = 0;
	for (list<int>::const_iterator it = this->_priorityQueue.begin(); it != this->_priorityQueue.end(); ++it) {
		if (*it == element) {
			return index;
		}
		index++;
	}
	return -1;
}


bool IntegerPriorityQueue::equals(const IntegerPriorityQueue& other) const {
	return this->_priorityQueue == other._priorityQueue;
}

bool IntegerPriorityQueue::operator==(const IntegerPriorityQueue& other) const {
	return this->_priorityQueue == other._priorityQueue;
}

bool IntegerPriorityQueue::operator!=(const IntegerPriorityQueue& other) const {
	return this->_priorityQueue != other._priorityQueue;
}





		