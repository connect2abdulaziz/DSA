//  Stack.cpp file Implementation of stack ADT
//  Abdul Aziz
//  BCSF19A026 
//  Add/drop CS-Afternoon
#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
	capacity = 0;
	top = 0;
	data = NULL;
}
template <typename T>
Stack<T>::~Stack()
{
	if (data)
	{
		delete[] data;
		data = NULL;
		top = 0;
		capacity = 0;
	}
}
template <typename T>
Stack<T>::Stack(const Stack<T> &obj)
{
	capacity = obj.capacity;
	top = obj.top;
	data = new T[capacity]{};
	for (int i = 0; i < top; i++)
		data[i] = obj.data[i];
}
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack<T> &obj)
{
	if (this == &obj)
		return *this;
	if (data)
		this->~Stack();
	capacity = obj.capacity;
	top = obj.top;
	data = new T[capacity]{};
	for (int i = 0; i < top; i++)
		data[i] = obj.data[i];
	return *this;
}

// Functions
template <typename T>
void Stack<T>::reSize(const int &size)
{
	T *data1 = new T[size]{};
	for (int i = 0; i < top; i++)
		data1[i] = data[i];
	delete[] data;
	capacity = size;
	data = data1;
	data1 = NULL;
}
template <typename T>
void Stack<T>::push(const T &val)
{
	if (isFull())
		if (capacity)
			reSize(capacity * 2);
		else
		{
			capacity++;
			data = new T[1]{};
		}

	data[top++] = val;
}
template <typename T>
const T &Stack<T>::pop()
{
	if (top > 0 && top == capacity / 4)
		reSize(capacity / 2);
	return data[--top];
}
template <typename T>
const T &Stack<T>::stackTop()
{
	if (!isEmpty())
		return data[top - 1];
	else
		exit(0);
}
template <typename T>
bool Stack<T>::isFull() const
{
	if (capacity == top)
		return true;
	return false;
}
template <typename T>
bool Stack<T>::isEmpty() const
{
	if (top == 0)
		return true;
	return false;
}
template <typename T>
const int Stack<T>::getCapacity()
{
	return capacity;
}
template <typename T>
const int Stack<T>::getNumberOfElement()
{
	return top;
}