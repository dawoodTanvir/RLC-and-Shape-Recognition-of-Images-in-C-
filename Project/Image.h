#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"
#include "Stack.h"
using namespace std;
class Image
{
	int row;
	int column;
	int** array;
	int** array2;
	int* Harray;
	int* Varray;
	int* HVarray;
	int row2;
	int column2;
	string file;
	string file2;
	int c;
	
public:
	void read(string);
	void save();
	int getPixel(int, int);
	void setPixel(int, int, int);
	void getSize();
	void convertToNeg();
	void calcPix();
	void Menu();
	void neighbour(int , int );
	void stNeighbour(int, int);
	void RLC();
	void RLCread();
	void conRLCtoNeg(int**, int, int);
	int read2andProject(string);
	
	//int search(string);
};

