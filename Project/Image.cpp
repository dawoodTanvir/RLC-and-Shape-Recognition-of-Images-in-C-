#include "Image.h"
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Hash.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <Windows.h>

using namespace std;

void Image::read(string file)
{

	this->file = file;
	fstream op;
	op.open(file, ios::in);
	string size;
	string s;
	getline(op, size);
	getline(op, size);
	getline(op, size);
	getline(op, size);

	
	int a[2];
	int i = 0;
	stringstream str_strm;
	str_strm << size;
	string temp_str;
	int temp_int;
	while (!str_strm.eof()) {
		str_strm >> temp_str;
		if (stringstream(temp_str) >> temp_int) {
			a[i] = temp_int;
			i++;

		}
		temp_str = "";
	}

	
	row = a[1];
	column = a[0];

	

	array = new int* [row];
	for (int i = 0; i < row; i++) {
		array[i] = new int[column];
	}
	
	fstream obj;
	char num;

	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			obj >> num;
			array[i][j] = int(num);   //writing vakues in array 
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == -1)
			{
				array[i][j] = 255;   //converting -1 to 255
			}
			else
				array[i][j] = 0;   //else to 0
		}
	}

//	for (int i = 0; i < row; i++) {
	//	for (int j = 0; j < column; j++) {
		//	cout << array[i][j]<<" ";    //print array
		//}
	//}

	
	
	
}

void Image::save()
{
	fstream obj1, obj;

	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);

	obj1.open("newsaves--.pgm", ios::out);

	obj1 << skip1 << endl;
	obj1 << skip2 << endl;
	obj1 << skip3 << endl;
	obj1 << skip4 << endl;
	obj1 << skip5 << endl;


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			obj1 << char(array[i][j]);     //writing in new file
		}
	}
}

int Image::getPixel(int r , int c)
{
	if (r > row || c > column || r<0 || c<0) {
		return -1;
	}
	else {
		return array[r][c];
	}
}

void Image::setPixel(int r, int c, int data)
{
	if (r > row || c > column || r < 0 || c < 0) {
		cout << "Index out of range.";
	}
	else if (data != 0 && data != 255) {
		cout << "Value must be 0 and 255.";
	}
	else {
		array[r][c] = data;
	}

}

void Image::getSize()
{
	cout << "The size of image is " << row * column<<" pixels.";
}

void Image::convertToNeg()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == 0) {
				array[i][j] = 255;
			}
			else if (array[i][j] == 255) {
				array[i][j] = 0;
			}
		}
	}
	fstream obj;


	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);
	ofstream myFile;
	myFile.open("NewFile.pgm");
	myFile << skip1 << endl;
	myFile << skip2 << endl;
	myFile << skip3 << endl;
	myFile << skip4 << endl;
	myFile << skip5 << endl;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			myFile<< char(array[i][j]);
		}
	}
}

void Image::calcPix()
{
	float sum = 0;
	int count = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			sum = sum + array[i][j];
			count++;
			if (array[i][j] == 0) {
				count1++;
				
			}
			else if(array[i][j]==255) {
				count2++;
			}
		}
		
		}
	
	cout << "The mean pixel value is: " << sum / count << endl;
	cout << "The number of black pixels in the image are: " << count1 << endl;
	cout << "The number of white pixels in the image are: " << count2 << endl;
	cout << "The number of black pixels in each row are: " << count1 / row << endl;

	
	
}

void Image::Menu()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Month = 1 + newtime.tm_mon;
	int year = 1900 + newtime.tm_year;
	int day =  newtime.tm_mday;
	int h=  newtime.tm_hour;
	int min= newtime.tm_min;
	int sec= newtime.tm_sec;

	string s1 = "log_" + to_string(year) + to_string(Month) + to_string(day) + to_string(h) + to_string(min) + to_string(sec) + ".txt";
	ofstream obj3;
	obj3.open(s1);

	do {
		int choice;
		cout << endl;
		cout << "1.Run Q1.\n2.Run Q2.\n3.Run Q3.\n4.To End.\n\n";
		cout << "Enter your choice: ";
		cin >> choice;


		if (choice == 1) {
			
			calcPix();
			convertToNeg();

			obj3 << "User selected to choose 1 now Q1 will run." << endl;
			obj3 << "Mean pixel function is called." << endl;
			obj3 << "Number of black and white pixels function is called." << endl;
			obj3 << "The vaerage numbers of black pixels in a row functions is called." << endl;
			obj3 << "The function that converts the image to negative function is called." << endl;
			obj3 << "Q1 ends." << endl;
			obj3 << "____________________________________________________________________________________" << endl;
		}
		if (choice == 2) {
			int r, c;
			cout << "Enter coordinates for row: ";
			cin >> r;
			cout << "Enter coordinates for column: ";
			cin >> c;
			neighbour(r, c);

			obj3 << "The user selected question 2." << endl;
			string str = to_string(r);
			string str1 = to_string(c);

			obj3 << "The user enters Row= " << str << " and Column= " << str1 << " ." << endl;
			obj3 << "File is saved as newFile123.pgm" << endl;
			obj3 << "Q2 ends." << endl;
			obj3 << "____________________________________________________________________________________" << endl;
		}
		if (choice == 3) {
			int r, c;
			cout << "Enter coordinates for row: ";
			cin >> r;
			cout << "Enter coordinates for column: ";
			cin >> c;

			stNeighbour(r, c);

			obj3 << "The user selected question 3." << endl;
			string str = to_string(r);
			string str1 = to_string(c);

			obj3 << "The user enters Row= " << str << " and Column= " << str1 << " ." << endl;
			obj3 << "File is saved as newFileStack123.pgm" << endl;
			obj3 << "Q3 ends." << endl;
			obj3 << "____________________________________________________________________________________" << endl;
		}
		if (choice == 4) {
			obj3 << "User terminated the program." << endl;
			obj3 << "_________________________________________________________________________________________" << endl;
			break;
		}
		if (choice<=0 || choice>4) {
			
			cout << "Wrong choice.";

			obj3 << "User made a wrong choice." << endl;
			obj3 << "________________________________________________________________________________________________" << endl;
		}
	} 
	while (true);
	
}

void Image::neighbour(int r, int c)
{
	if (r > row || c > column || r < 0 || c < 0) {
		cout << "Index out of range.";
		return;
	}

	ofstream fileee;
	fileee.open("NewFile123.pgm");
	int** tempArr = new int*[row];
	for (int i = 0; i < row; i++) {
		tempArr[i] = new int[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			tempArr[i][j] = 255;
		}
	}
	Queue<int>q1;
	
	q1.enqueue(r);
	q1.enqueue(c);

	int s = r;
	int m = c;

	while (!q1.Empty()) {

		 s = q1.dequeue();
		 m = q1.dequeue();
		
		

		if (tempArr[s][m] == 255) {
			tempArr[s][m] = 0;
			
			
			if (m > 0) {
				if (array[s][m] == array[s][m - 1]) {
					q1.enqueue(s);
					q1.enqueue(m - 1);
				}
			}
			if (m < column - 1) {
				if (array[s][m] == array[s][m + 1]) {
					q1.enqueue(s);
					q1.enqueue(m + 1);
				}
			}

			if (s < row - 1) {
				if (array[s][m] == array[s + 1][m]) {
					q1.enqueue(s + 1);
					q1.enqueue(m);
				}
			}
			if (s > 0) {
				if (array[s][m] == array[s - 1][m]) {
					q1.enqueue(s - 1);
					q1.enqueue(m);
				}
			}

			if (s < row - 1 && m>0) {
				if (array[s][m] == array[s + 1][m - 1]) {
					q1.enqueue(s + 1);
					q1.enqueue(m - 1);
				}
			}

			if (s < row - 1 && m < column - 1) {
				if (array[s][m] == array[s + 1][m + 1]) {
					q1.enqueue(s + 1);
					q1.enqueue(m + 1);
				}
			}
			if (s > 0 && m > 0) {
				if (array[s][m] == array[s - 1][m - 1]) {
					q1.enqueue(s - 1);
					q1.enqueue(m - 1);
				}
			}

			if (s > 0 && m < column - 1) {
				if (array[s][m] == array[s - 1][m + 1]) {
					q1.enqueue(s - 1);
					q1.enqueue(m + 1);
				}
			}
		}
		
	}
	
	fstream obj;
	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);

	fileee << skip1 << endl;
	fileee << skip2 << endl;
	fileee << skip3 << endl;
	fileee << skip4 << endl;
	fileee << skip5 << endl;
	for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				fileee << char(tempArr[i][j]);
			}
		}
	cout << "Done." << endl;
}

void Image::stNeighbour(int r, int c)
{
	if (r > row || c > column || r < 0 || c < 0) {
		cout << "Index out of range.";
		return;
	}

	ofstream fileee;
	fileee.open("NewFileStack123.pgm");
	int** tempArr = new int* [row];
	for (int i = 0; i < row; i++) {
		tempArr[i] = new int[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			tempArr[i][j] = 255;
		}
	}

	Stack<int> s1;
	s1.push(r);
	s1.push(c);

	int s = r;
	int m = c;

	while (!s1.Empty()) {

		s = s1.pop();
		m = s1.pop();



		if (tempArr[s][m] == 255) {
			tempArr[s][m] = 0;
			

			if (m > 0) {
				if (array[s][m] == array[s][m - 1]) {
					s1.push(s);
					s1.push(m - 1);
				}
			}
			if (m < column - 1) {
				if (array[s][m] == array[s][m + 1]) {
					s1.push(s);
					s1.push(m + 1);
				}
			}

			if (s < row - 1) {
				if (array[s][m] == array[s + 1][m]) {
					s1.push(s + 1);
					s1.push(m);
				}
			}
			if (s > 0) {
				if (array[s][m] == array[s - 1][m]) {
					s1.push(s - 1);
					s1.push(m);
				}
			}

			if (s < row - 1 && m>0) {
				if (array[s][m] == array[s + 1][m - 1]) {
					s1.push(s + 1);
					s1.push(m - 1);
				}
			}

			if (s < row - 1 && m < column - 1) {
				if (array[s][m] == array[s + 1][m + 1]) {
					s1.push(s + 1);
					s1.push(m + 1);
				}
			}
			if (s > 0 && m > 0) {
				if (array[s][m] == array[s - 1][m - 1]) {
					s1.push(s - 1);
					s1.push(m - 1);
				}
			}

			if (s > 0 && m < column - 1) {
				if (array[s][m] == array[s - 1][m + 1]) {
					s1.push(s - 1);
					s1.push(m + 1);
				}
			}
		}

	}
	fstream obj;
	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);

	fileee << skip1 << endl;
	fileee << skip2 << endl;
	fileee << skip3 << endl;
	fileee << skip4 << endl;
	fileee << skip5 << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			fileee << char(tempArr[i][j]);
		}
	}
	
	cout << "Done." << endl;
}

void Image::RLC()
{
	List<int> l1;
	int count;
	 c = 0;
	l1.insert(row);
	l1.insert(column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == 0) {
				count = j;
				
				l1.insert(j);
				
				int k = count;
				while (array[i][j] == 0) {
					
					count++;
						
					j++;

				}
				if (count != k) {
				
					l1.insert(count);
					
				}
			}
		}
		
	l1.insert(-1);
		
	}
	l1.write("RLC.txt"); 
}

void Image::RLCread()
{
	List<int> q1;
	int cou = 0;
	fstream op;
	string num;
	op.open("RLC.txt", ios::in);
	int m = 0;
	int temp;
	while (!op.eof()) {
		op >> temp;
		q1.insert(temp);

	}
	
	int s = q1.getListData();
	int sc = q1.getListData();
	int** apple = new int*[s];
	
	for (int i = 0; i < s; i++) {
		apple[i] = new int[sc];
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < sc; j++) {
			apple[i][j] = 255;
		}
	}
	int i = 0, j = 0;
	while (!q1.ListEmpty()) {
		int t = q1.getListData();
		if (t == -1) {
			i++;
		}
		else {
			m = q1.getListData();
			int k = t;
			while (k <= m) {
				apple[i][k] = 0;
				k++;
				cou++;
			}
		}
	}

	fstream obj;
	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);

	fstream fileee;
	fileee.open("NewRLC.txt", ios::out);

	fileee << skip1 << endl;
	fileee << skip2 << endl;
	fileee << skip3 << endl;
	fileee << skip4 << endl;
	fileee << skip5 << endl;


	for (int i = 0; i < s; i++) {
		for (int j = 0; j < sc; j++) {
			fileee << char(apple[i][j]);
		}
	}

	cout << "The total number of black pixels computed from RLC method are: " << cou;
	conRLCtoNeg(apple, s, sc);
}

void Image::conRLCtoNeg(int**apple, int s, int sc)
{
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < sc; j++) {
			if (apple[i][j] == 0) {
				apple[i][j] = 255;
			}
			else if(apple[i][j]==255) {
				apple[i][j] = 0;
			}
		}
	}
	fstream fileee;
	fileee.open("RLCNeg.txt", ios::out);
	fstream obj;
	obj.open(file, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);
	getline(obj, skip5);


	fileee << skip1 << endl;
	fileee << skip2 << endl;
	fileee << skip3 << endl;
	fileee << skip4 << endl;
	fileee << skip5 << endl;


	for (int i = 0; i < s; i++) {
		for (int j = 0; j < sc; j++) {
			fileee << char(apple[i][j]);
		}
	}
}


int Image::read2andProject(string file2) {

this->file2 = file2;
fstream op;
op.open(file2, ios::in);
string size;
string sp;
getline(op, size);
getline(op, size);
getline(op, size);



int a[2];
int i = 0;
stringstream str_strm;
str_strm << size;
string temp_str;
int temp_int;
while (!str_strm.eof()) {
	str_strm >> temp_str;
	if (stringstream(temp_str) >> temp_int) {
		a[i] = temp_int;
		i++;

	}
	temp_str = "";
}


row2 = a[1];
column2 = a[0];


array2 = new int* [row2];
for (int i = 0; i < row2; i++) {
	array2[i] = new int[column2];
}

fstream obj;
int num;

obj.open(file2, ios::in);
string skip1, skip2, skip3, skip4, skip5;
getline(obj, skip1);
getline(obj, skip2);
getline(obj, skip3);
getline(obj, skip4);

for (int i = 0; i < row2; i++) {
	for (int j = 0; j < column2; j++) {
		obj >> num; 
		
		array2[i][j] = num;   //writing values in array 
	}
}

Harray = new int[row2];
Varray = new int[column2];

int count1 = 0, count2 = 0;
for (int i = 0; i < row2; i++) {
	for (int j = 0; j < column2; j++) {
		if (array2[i][j] == 0) {
			count1++;
		}
	}
	Harray[i] = count1;
	count1 = 0;

}

for (int i = 0; i < column2; i++) {
	for (int j = 0; j < row2; j++) {
		if (array2[j][i] == 0) {
			count2++;
		}
	}
	Varray[i] = count2;
	count2 = 0;
}

int s = row2 + column2;

HVarray = new int[s];

for (int i = 0; i < column2; i++) {
	HVarray[i] = Varray[i];
}
for (int i = column2, j = 0; i < s; i++, j++) {
	HVarray[i] = Harray[j];
}

int sum = 0;
if (s % 4 == 0) {
	int index = 0;
	while (index < s - 3) {
		sum += (HVarray[index] * 1000) + (HVarray[index + 1] * 100) + (HVarray[index + 1 + 1] * 10) + (HVarray[index + 1 + 1 + 1]);
		index += 4;
	}
}
else {
	int index = 0;
	if ((s + 3) % 4 == 0) {
		while (index < s - 3) {
			sum += (HVarray[index] * 1000) + (HVarray[index + 1] * 100) + (HVarray[index + 1 + 1] * 10) + 0;
			index += 4;
		}
	}
	else if ((s + 2) % 4 == 0) {
		while (index < s - 2) {
			sum += (HVarray[index] * 1000) + (HVarray[index + 1] * 100) + 0 + 0;
			index += 4;
		}
	}
	else if ((s + 1) % 4 == 0) {
		while (index < s - 1) {
			sum += (HVarray[index] * 1000) + 0 + 0 + 0;
			index += 4;
		}
	}
}

return sum;
}


/*
int Image::search(string check)
{
	
	fstream op;
	op.open(check, ios::in);
	string size;
	string sp;
	getline(op, size);
	getline(op, size);
	getline(op, size);



	int a[2];
	int i = 0;
	stringstream str_strm;
	str_strm << size;
	string temp_str;
	int temp_int;
	while (!str_strm.eof()) {
		str_strm >> temp_str;
		if (stringstream(temp_str) >> temp_int) {
			a[i] = temp_int;
			i++;

		}
		temp_str = "";
	}


	row2 = a[1];
	column2 = a[0];


	array2 = new int* [row2];
	for (int i = 0; i < row2; i++) {
		array2[i] = new int[column2];
	}

	fstream obj;
	int num;

	obj.open(check, ios::in);
	string skip1, skip2, skip3, skip4, skip5;
	getline(obj, skip1);
	getline(obj, skip2);
	getline(obj, skip3);
	getline(obj, skip4);

	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < column2; j++) {
			obj >> num;

			array2[i][j] = num;   //writing values in array 
		}
	}

	Harray = new int[row2];
	Varray = new int[column2];

	int count1 = 0, count2 = 0;
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < column2; j++) {
			if (array2[i][j] == 0) {
				count1++;
			}
		}
		Harray[i] = count1;
		count1 = 0;

	}

	for (int i = 0; i < column2; i++) {
		for (int j = 0; j < row2; j++) {
			if (array2[j][i] == 0) {
				count2++;
			}
		}
		Varray[i] = count2;
		count2 = 0;
	}

	int s = row2 + column2;

	HVarray = new int[s];

	for (int i = 0; i < column2; i++) {
		HVarray[i] = Varray[i];
	}
	for (int i = column2, j = 0; i < s; i++, j++) {
		HVarray[i] = Harray[j];
	}

	int sum = 0;
	if (s % 4==0) {
		int index = 0;
		while (index < s-3) {
	    sum += (HVarray[index]*1000) + (HVarray[index + 1]*100) + (HVarray[index + 1 + 1]*10) + (HVarray[index + 1 + 1 + 1]);
			index += 4;
		}
	}
	else {
		int index = 0;
		if ((s + 3) % 4 == 0) {
			while (index < s - 3) {
				sum += (HVarray[index] * 1000) + (HVarray[index + 1] * 100) + (HVarray[index + 1 + 1] * 10) + 0;
				index += 4;
			}
		}
		else if ((s + 2) % 4 == 0) {
			while (index < s - 2) {
				sum += (HVarray[index] * 1000) + (HVarray[index + 1] * 100) + 0 + 0;
				index += 4;
			}
		}
		else if ((s + 1) % 4 == 0) {
			while (index < s - 1) {
				sum += (HVarray[index] * 1000) + 0 + 0 + 0;
				index += 4;
			}
		}
	}
	
	return sum;

	
}
*/