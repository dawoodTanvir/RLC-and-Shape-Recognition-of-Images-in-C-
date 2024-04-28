#pragma once
#include "Node.h"
#include "List.h"
#include <iostream>
using namespace std;

template <class T>

class Hash {
	List<T>* array;
public:
	Hash() {
		array = new List<T> [401];
	}
	void fill(int sum, T name) {
		int idx = sum % 401;
		array[idx].insert(name);
	}
	bool search(int sum, T name) {
		int idx = sum % 401;
		if (array[idx].search(name) == true) {
			return 1;
		}
		return 0;
	}
};