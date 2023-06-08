#include <iostream>
#include <exception>
#include "PriorityQueue.h"
#include "IntegerPriorityQueue.h"
#include "Dog.h" 

using std::cout; 
using std::endl;

using std::exception;

int main()
{
	std::cout << "Hello PriorityQueue.h" << std::endl;
	
	{
		
		PriorityQueue<Dog> pq;

		pq.push(Dog(1, 13, "Dog03"));
		pq.push(Dog(2, 11, "Dog05"));
		pq.push(Dog(3, 14, "Dog02"));
		pq.push(Dog(4, 15, "Dog01"));
		pq.push(Dog(5, 12, "Dog04"));
		try
		{
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
	

	cout << endl << endl; 
	{
		PriorityQueue<float> pq;

		pq.push(2.3);
		pq.push(1.4);
		pq.push(2.2);
		pq.push(6.1);
		pq.push(2.5);
		try
		{
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
	


	/*
	IntegerPriorityQueue queue1;

	// Test for push function
	queue1.push(5);
	queue1.push(10);
	queue1.push(15);
	std::cout << "Test 1: " << (queue1.size() == 3 ? "Passed" : "Failed") << std::endl;

	// Test for remove function
	queue1.remove(10);
	std::cout << "Test 2: " << (queue1.size() == 2 ? "Passed" : "Failed") << std::endl;

	// Test for contains function
	std::cout << "Test 3: " << (queue1.contains(5) ? "Passed" : "Failed") << std::endl;
	std::cout << "Test 4: " << (!queue1.contains(10) ? "Passed" : "Failed") << std::endl;


	// Test for equals function
	IntegerPriorityQueue queue2;
	queue2.push(5);
	queue2.push(15);
	std::cout << "Test 5: " << (queue1.equals(queue2) ? "Passed" : "Failed") << std::endl;

	// Test for operator overloads
	std::cout << "Test 6: " << (queue1 == queue2 ? "Passed" : "Failed") << std::endl;
	std::cout << "Test 7: " << (!(queue1 != queue2) ? "Passed" : "Failed") << std::endl;
	*/

	return 0;
}