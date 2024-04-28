#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>

class Node
{
	T data;
	Node* next;
public:
	Node(T dat) {

		data = dat;
		next = NULL;
	}
	void setData(T dat) {
		data = dat;

	}
	void setNext(Node<T>* next) {
		this->next = next;

	}
	Node* getNext() {
		return this->next;
	}
	T getData() {
		return this->data;
	}

};
