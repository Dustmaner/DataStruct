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
#include <queue>

using namespace std;

const int MAX= 250;
int csize = 0;
int cquantum = 0;
int linenumber = 0;
int relax = 0;

struct actor
{
	string name;
	int arrival;
	int duration;
};

class cqueue
{
	actor a[MAX];
	int front, rear;

public:
	cqueue()
	{
		front = rear = -1;
	}

	void enqueue(actor);
	actor dequeue();
	void display();
};

void cqueue::enqueue(actor val)
{
	if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
	{
		cout << "Circular Queue is full\n";
	}
	else
	{
		if (rear == MAX - 1)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}
		a[rear] = val;
	}
	if (front == -1)
	{
		front = 0;
	}

}

actor cqueue::dequeue()
{
	actor k;
	if (front == -1)
	{
		cout << "Circular Queue is Empty\n";
	}
	else
	{
		k = a[front];
		if (front == rear)
		{
			front = rear = -1;
		}
		else if (front == MAX - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	return k;
}

void cqueue::display()
{
	int i;
	int j;
	if (front == -1)
	{
		cout << "Circular Queue is Empty\n";
	}
	else
	{
		if (rear < front)
		{
			for (i = front; i <= MAX - 1; i++)//print right side
			{
				cout << linenumber++ << "\t" <<a[i].name <<"\t"<< a[i].arrival << "\t" << a[i].duration;
				relax++;
			}
			for (i = 0; i <= rear; i++)//print first part
			{
				cout << linenumber++ << "\t" << a[i].name << "\t" << a[i].arrival << "\t" << a[i].duration;
				relax++;
			}
			cout << endl;
		}
		else
		{
			for (i = front; i <= rear; i++)// Line loop
			{
				if (a[i].arrival <= linenumber)
				{
					for (j = 0; j < a[i].duration; j++)// each step
					{
						cout << linenumber++ << "\t" << a[i].name << "\t" << a[i].duration << "\t";
						if (j < a[i].duration - 1)//in between
						{
							cout << "makeup" << endl;
						}
						else // last
						{
							cout << "completed" << endl;
							relax++;
							if (relax == 4)// relax output
							{
								for (int w = 0; w < 2; w++)
								{
									cout << linenumber++ << "\t" << "relax\n";
									relax = 0;
								}
							}
						}
					}
				}
				else
				{
					cout << linenumber++ <<  "\twaiting\n";
					i--;
				}
			}
			cout << endl;
		}
	}
}

int main(int argc, char** argv)
{
	
	
	/*if (argc != 2) {
		cout << "Error, please specify parameter correctly. This program needs a parameter to work." << endl;
		return 0;
	}*/
	// initialize the variable 'parameter' with the argument 1
	//string parameter(argv[1]);
	string parameter("input=gray.txt;size=22;scheduling=fifo;quantum=4");


	// find the position of the semicolon
	string::size_type position = parameter.find(';');
	// next line is for display purposes only.
	//cout << "position: " << position << endl;

	// get only the filename via substring. The value of 10 is fixed for hw1 because the parameter always starts with: inputfile=
	string filename = parameter.substr(6, position - 6);
	// next line is for display purposes only.
	//cout << "Filename: " << filename << endl;

	//Size
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position2 = parameter.find('=', position);
	// next line is for display purposes only.
	//cout << "position2: " << position2 << endl;

	string poison = parameter.substr(position+1);
	string::size_type positioner = poison.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number = poison.substr(5, positioner-5);
	// next line is for display purposes only.
	//cout << "number: " << number << endl;

	//Scheduling
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position3 = parameter.find('=', position2+1);
	// next line is for display purposes only.
	//cout << "position3: " << position3 << endl;

	string poison3 = parameter.substr(position3);
	string::size_type positioner3 = poison3.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number3 = poison3.substr(1, positioner3 - 1);
	// next line is for display purposes only.
	//cout << "schedule: " << number3 << endl;


	//Quantum
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position4 = parameter.find('=', position3 + 1);
	// next line is for display purposes only.
	//cout << "position3: " << position4 << endl;

	string poison4 = parameter.substr(position4);
	string::size_type positioner4 = poison4.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number4 = poison4.substr(1, positioner4 - 1);
	// next line is for display purposes only.
	//cout << "schedule: " << number4 << endl;


	ifstream instream(filename);//Obtain Input Stream
	string line;
	string element;
	int elementn = 0;
	

	cqueue c1;//queue
	actor temp;// actor placeholder

	temp.name = "";//Example
	temp.arrival = 0;
	temp.duration = 0;


	csize = stoi(number);// Size
	cquantum = stoi(number4);// Quantum

	if (number3 == "fifo")
	{
		while (!instream.eof())
		{
			getline(instream, line, '\n');
			istringstream some(line);
			while (!some.eof()) {// loop for each element
				getline(some, element, '\t');
			
				{
					temp.name = element;
					elementn++;
				}
			
				{
					getline(some, element, '\t');
					temp.arrival = stoi(element);
					elementn++;
				}
				
				{
					getline(some, element, '\t');
					temp.duration = stoi(element);
					elementn = 0;
				}
				c1.enqueue(temp);
			}
			//c1.enqueue(temp);
			
			
		}
		c1.display();
	}
	
	/*c1.enqueue(2);
	c1.enqueue(3);
	c1.enqueue(4);
	c1.enqueue(5);
	c1.display();
	c1.dequeue();
	c1.enqueue(68);
	c1.display();
	c1.enqueue(420);
	c1.display();*/


	system("pause");
	return 0;
}
