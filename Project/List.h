#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class List {

	Node<T>* head;
public:
	List() {
		head = nullptr;
	}
	void insert(T data) {

		Node<T>* newNode = new Node<T>(data);
		Node<T>* iterator = head;
		if (head == nullptr) {
			head = newNode;
		}
		else {
			while (iterator->getNext() != nullptr) {
				iterator = iterator->getNext();
			}
			iterator->setNext(newNode);
		}
	}
	void display() {
		Node<T>* iterator = head;
		while (iterator != nullptr) {
			cout << iterator->getData()<<" ";
			iterator = iterator->getNext();
		}
	}
	void write(string name) {
		fstream inp;
		inp.open(name, ios::out);
		Node<T>* it = head;
		inp << it->getData();
		inp << " ";
		it = it->getNext();
		inp << it->getData();
		inp << endl;
		it = it->getNext();
		while (it != nullptr) {
			if (it->getData() == -1 && it->getNext() !=nullptr) {
				inp << it->getData();
				inp << endl;
				it = it->getNext();
			}
			inp << it->getData();
			inp << " ";
			it = it->getNext();

		}
	}
	T getListData() {
		Node<T>* todelete = head;

		head = head->getNext();

		return todelete->getData();
		delete[] todelete;
	}
	bool ListEmpty() {
		if (head == NULL) {
			return 1;
		}
		return 0;
	}

	bool search(T data) {
		Node<T>* iterator = head;
		
		while (iterator != nullptr) {
			if (iterator->getData() == data) {
				
				return 1;

			}
			iterator = iterator->getNext();
		}
		return 0;
	}
};