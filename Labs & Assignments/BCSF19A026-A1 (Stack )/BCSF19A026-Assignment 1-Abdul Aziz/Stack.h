//  Stack.h file header of stack ADT
//  Abdul Aziz
//  BCSF19A026 
//  Add/drop CS-Afternoon
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	/* data */
	T* data;
	int capacity;
	int top;
	void reSize(const int&);

public:
	Stack();
	Stack(const Stack<T>&);
	const Stack<T>& operator=(const Stack<T>&);
	~Stack();
	// Functions
	void push(const T&);
	const T& pop();
	const T& stackTop();
	bool isFull() const;
	bool isEmpty() const;
	const int getCapacity();
	const int getNumberOfElement();
};
#endif