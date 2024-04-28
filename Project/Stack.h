#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>

class Stack {
	Node<T>* head;
	Node<T>* tail;
public:
	Stack() {
		head = NULL;
		tail = NULL;
	}
	void push(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		tail->setNext(newNode);
		tail = newNode;
	}

	T pop() {

		Node<T>* iterator = head;
		head = head->getNext();
		return iterator->getData();
		delete iterator;

	}

	bool Empty() {
		if (head == NULL) {
			return 1;
		}
		return 0;
	}
};
