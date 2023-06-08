#pragma once

#include <iostream>
#include <list>
#include <exception>
#include "Dog.h"
using namespace std;


template <typename T>
struct MyComparator {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

// Specialization for Dog class (compare by weight)
template <>
struct MyComparator<Dog> {
    bool operator()(const Dog& a, const Dog& b) const {
        return a.getWeight() < b.getWeight();
    }
};


template <typename T>
class PriorityQueue {
private:
    std::list<T> _priorityQueue;
    MyComparator<T> Compare;

public:

    // C-tors
    PriorityQueue();
    PriorityQueue(const PriorityQueue& queue);
    PriorityQueue(const T& element);
    PriorityQueue(const T* arr, const size_t size);

    // D-tor
    ~PriorityQueue();

    //===================================
    //============ Methods ==============
    //===================================

    // Add element to the queue
    void push(const T& newElement);

    // Remove the smallest element from the queue and return it
    T poll();

    // Return the size of the queue
    size_t size() const;

    // Return true if the queue is empty
    bool isEmpty() const;

    // Return the smallest element from the queue without removing it
    T peek() const;

    // Return the biggest element from the queue without removing it
    T back() const;

    // Print the queue
    void print() const;

    // Return true if the queue contains the element
    bool contains(const T& element) const;

    // Remove all elements from the queue
    void clear();

    // Remove the element from the queue
    void remove(const T& element);

    // Return the index of the element
    int indexOf(const T& element) const;

    // Return true if the queue is equals to other
    bool equals(const PriorityQueue& other) const;

    //===================================
    //========== Operators ==============
    //===================================
    bool operator==(const PriorityQueue& other) const;
    bool operator!=(const PriorityQueue& other) const;
    
};


template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    this->_priorityQueue = list<T>();
}
    

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& queue)
{
    this->_priorityQueue(queue._priorityQueue);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const T& element) {
    _priorityQueue.push_back(element);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const T* arr, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        _priorityQueue.push_back(arr[i]);
    }
    _priorityQueue.sort(Compare); // sort the queue
}


template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    _priorityQueue.clear();
}

template <typename T>
void PriorityQueue<T>::push(const T& newElement) {
    auto it = _priorityQueue.begin();
    while (it != _priorityQueue.end() && !Compare(newElement, *it)) {
        it++;
    }
    _priorityQueue.insert(it, newElement);
}

template <typename T>
T PriorityQueue<T>::poll() {
    if (_priorityQueue.empty()) {
        throw exception("The queue is empty");
    }
    T smallestElement = _priorityQueue.front();
    _priorityQueue.pop_front();
    return smallestElement;
}

template <typename T>
size_t PriorityQueue<T>::size() const {
    return _priorityQueue.size();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return _priorityQueue.empty();
}

template <typename T>
T PriorityQueue<T>::peek() const {
    if (_priorityQueue.empty()) {
        throw exception("The queue is empty");
    }
    return _priorityQueue.front();
}

template <typename T>
T PriorityQueue<T>::back() const {
    if (_priorityQueue.empty()) {
        throw exception("The queue is empty");
    }
    return _priorityQueue.back();
}


template <typename T>
void PriorityQueue<T>::print() const {
    for (const T& element : _priorityQueue) {
        cout << element << " ";
    }
    cout << endl;
}

template <typename T>
bool PriorityQueue<T>::contains(const T& element) const {
    for (const T& val : _priorityQueue) {
        if (val == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
void PriorityQueue<T>::clear() {
    _priorityQueue.clear();
}

template <typename T>
void PriorityQueue<T>::remove(const T& element) {
    _priorityQueue.remove(element);
}

template <typename T>
int PriorityQueue<T>::indexOf(const T& element) const {
    int index = 0;
    for (const T& val : _priorityQueue) {
        if (val == element) {
            return index;
        }
        index++;
    }
    return -1;
}

template <typename T>
bool PriorityQueue<T>::equals(const PriorityQueue& other) const {
    return _priorityQueue == other._priorityQueue;
}

template <typename T>
bool PriorityQueue<T>::operator==(const PriorityQueue& other) const {
    return _priorityQueue == other._priorityQueue;
}

template <typename T>
bool PriorityQueue<T>::operator!=(const PriorityQueue& other) const {
    return _priorityQueue != other._priorityQueue;
}
