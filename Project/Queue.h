#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>

class Queue
{
	Node<T>* front;
	Node<T>* back;

public:

	Queue() {
		front = NULL;
		back = NULL;
	}

	void enqueue(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (front == NULL) {
			front = newNode;
			back = newNode;

		}
		back->setNext(newNode);
		back = newNode;
	}

	T dequeue() {
			Node<T>* todelete = front;

			front = front->getNext();

			return todelete->getData();
			delete[] todelete;
		
	}

	bool Empty() {
		if (front == NULL) {
			return 1;
		}
		return 0;
	}
};

