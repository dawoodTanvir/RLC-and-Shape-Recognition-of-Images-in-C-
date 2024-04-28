#include <iostream>
#include "Image.h"
#include <string>
#include <fstream>
#include "Stack.h"
#include "Queue.h"
#include "Hash.h"
#include <ctime>
#include <time.h>
#include <Windows.h>
using namespace std;
int main() {

	Image i1;
	i1.read("beetle-6.pgm") ;
	//i1.save() ;
	//i1.Menu() ;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Month = 1 + newtime.tm_mon;
	int year = 1900 + newtime.tm_year;
	int day = newtime.tm_mday;
	int h = newtime.tm_hour;
	int min = newtime.tm_min;
	int sec = newtime.tm_sec;

	string s1 = "log_" + to_string(year) + to_string(Month) + to_string(day) + to_string(h) + to_string(min) + to_string(sec) + ".txt";
	ofstream obj3;
	obj3.open(s1);
	int ch;
	do {
		cout << "1.Q4\n2.Q5\n3.Q6\n4.End.\n";
		cin >> ch;

		if (ch == 1) {
			obj3 << "User chose to run Q4." << endl;
			obj3 << "RLC function called and data is written in a text file." << endl;
			obj3 << "RLC read function called and image in created from RLC format.";
			obj3 << "No of black pixels displayed." << endl;
			obj3 << "Q4 ends." << endl;
			obj3 << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			i1.RLC();
			i1.RLCread();
			cout << "Done." << endl;
			
		}
		else if (ch == 2) {

			break;
		}
		else if (ch == 3) {
			Hash<string> h1;
			string n = "image";
			string p = ".pgm";
			string names;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {

						names = n + to_string(i) + to_string(j) + to_string(k) + p;
						if (names != "image000.pgm") {
							h1.fill(i1.read2andProject(names), names);
							cout << names << endl;
						}
					}
				}
			}
			h1.fill(i1.read2andProject("image500.pgm"), "image500.pgm");

			obj3 << "User chose to run Q6." << endl;
			obj3 << "500 pgm files loaded in a hash table." << endl;
			obj3 << "User send file name in the function to check if it exits in the hash table." << endl;
			if (h1.search(i1.read2andProject(names), names) == 1) {
				cout << "File Found.";
				obj3 << "File Found"<<endl;
			}
			else {
				cout << "File not Found."<<endl;
				obj3 << "File not Found." << endl;
			}
			obj3 << "Q6 ends." << endl;
			obj3 << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		else if (ch == 4) {
			break;
		}
		else {
			cout << "Wrong Input.";
			obj3 << "User entered wrong choice." << endl;
			obj3 << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	} while (true);

	

	
	
	
}