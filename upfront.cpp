#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <stack>

using namespace std;

const int MAX= 5;

class cqueue
{
	int a[MAX];
	int front, rear;

	cqueue()
	{
		front = rear = -1;
	}

	void enqueue(int);
	int dequeue();
	void display();
};

int main(int argc, char** argv)
{
	//std::string filename = "input=abc.txt;size=INTEGER;scheduling=SCHEDULE;quantum=NUMBER";
	/*
	//Set input
	std::string filename = "input=abc.txt;size=INTEGER;scheduling=SCHEDULE;quantum=NUMBER";
	//int linecount = 1;
	//string filename = argv[1];
	filename.erase(0, 6);

	std::string s = filename;
	std::string delimiter = "=";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	token = s.substr(0, pos);
	s.erase(0, pos + delimiter.length());
	}

	string quantum = s;

	
	std::string f = filename;//get correct filename
	std::string cutoff = ";";
	std::string file = f.substr(0, f.find(cutoff)); */
	// verify that there was 1 parameter passed.

	
	/*if (argc != 2) {
		cout << "Error, please specify parameter correctly. This program needs a parameter to work." << endl;
		return 0;
	}*/
	// initialize the variable 'parameter' with the argument 1
	//string parameter(argv[1]);
	string parameter("input=gray.txt;size=222222222222222222222;scheduling=fifo;quantum=4");


	// find the position of the semicolon
	string::size_type position = parameter.find(';');
	// next line is for display purposes only.
	cout << "position: " << position << endl;

	// get only the filename via substring. The value of 10 is fixed for hw1 because the parameter always starts with: inputfile=
	string filename = parameter.substr(6, position - 6);
	// next line is for display purposes only.
	cout << "Filename: " << filename << endl;

	//Size
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position2 = parameter.find('=', position);
	// next line is for display purposes only.
	cout << "position2: " << position2 << endl;

	string poison = parameter.substr(position+1);
	string::size_type positioner = poison.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number = poison.substr(5, positioner-5);
	// next line is for display purposes only.
	cout << "number: " << number << endl;

	//Scheduling
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position3 = parameter.find('=', position2+1);
	// next line is for display purposes only.
	cout << "position3: " << position3 << endl;

	string poison3 = parameter.substr(position3);
	string::size_type positioner3 = poison3.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number3 = poison3.substr(1, positioner3 - 1);
	// next line is for display purposes only.
	cout << "schedule: " << number3 << endl;


	//Quantum
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position4 = parameter.find('=', position3 + 1);
	// next line is for display purposes only.
	cout << "position3: " << position4 << endl;

	string poison4 = parameter.substr(position4);
	string::size_type positioner4 = poison4.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number4 = poison4.substr(1, positioner4 - 1);
	// next line is for display purposes only.
	cout << "schedule: " << number4 << endl;


	//ifstream instream(file);//Obtain Input Stream
								

	system("pause");
	return 0;
}
