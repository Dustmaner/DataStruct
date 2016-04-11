#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
//#include <math.h>
#include <sstream>
//#include <algorithm>
//#include <cctype>
//#include <stdlib.h>
//#include <stack>
//#include <queue>

using namespace std;

const int MAX= 250;
int csize = 0;
int cquantum = 0;
int linenumber = 0;
int timeq = 0;
int relax = 0;
int elementsNB = -1;
int tempDuration = 0;

template <class Type>
class queueADT
{
public:
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	virtual bool isEmptyQueue() const = 0;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	// otherwise returns false.
	virtual bool isFullQueue() const = 0;
	//Function to initialize the queue to an empty state.
	//Postcondition: The queue is empty.
	virtual void initializeQueue() = 0;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first element of the queue
	// is returned.
	virtual Type front() const = 0;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the last element of the queue
	// is returned.
	virtual Type back() const = 0;
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	// added to the queue.
	virtual void addQueue(const Type& queueElement) = 0;
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	// is removed from the queue.
	virtual void deleteQueue() = 0;
	
};

template <class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	//Overload the assignment operator.
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.bool 
	bool getCount() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	// otherwise returns false.
	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: The queue is empty.
	Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first element of the
	// queue is returned.
	Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the last element of the queue
	// is returned.
	void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	// added to the queue.
	void deleteQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	// is removed from the queue.
	queueType(int queueSize = 100);
	//Constructor
	queueType(const queueType<Type>& otherQueue);
	//Copy constructor
	~queueType();
	//Destructor
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
			   //elements in the queue
	int queueFront; //variable to point to the first
					//element of the queue
	int queueRear; //variable to point to the last
				   //element of the queue
	Type *list; //pointer to the array that holds
				//the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
} //end isEmptyQueue
template <class Type>
bool queueType<Type>::getCount() const
{
	return count;
} //end count
template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
} //end isFullQueue
template <class Type>
Type queueType<Type>::front() const
{
	//assert(!isEmptyQueue());
	return list[queueFront];
} //end front
template <class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queueRear];
} //end back
template <class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
} //end initializeQueue
template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize; //use the
													//mod operator to advance queueRear
													//because the array is circular
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
} //end addQueue
template <class Type>
void queueType<Type>::deleteQueue()
{
	if (!isEmptyQueue())
	{
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; //use the
													  //mod operator to advance queueFront
													  //because the array is circular
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue
template <class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize; //set maxQueueSize to
								  //queueSize
	queueFront = 0; //initialize queueFront
	queueRear = maxQueueSize - 1; //initialize queueRear
	count = 0;
	list = new Type[maxQueueSize]; //create the array to
								   //hold the queue elements
} //end constructor
template <class Type>
queueType<Type>::~queueType()
{
	delete[] list;
}

struct actor
{
	string name;
	int arrival;
	int duration;
	int durationStatic;
};

ostream& operator<< (ostream& osObject,
	const actor& rectangle)
{
	osObject << linenumber++ << "\t" << rectangle.name
		<< "\t" << rectangle.durationStatic << "\t";
	return osObject;
}

class cqueue
{
public:
	actor a[MAX];
	int front, rear;

//public:
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
									if (i != elementsNB)// check if it is not the last element
									{
										cout << linenumber++ << "\t" << "relax\n";
										relax = 0;
									}
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
			//cout << endl;
		}
	}
}

int main(int argc, char** argv)
{
	int loopi = 1;
	//cout << "A" << loopi++<<"\t";
	
	/*if (argc != 2) {
		cout << "Error, please specify parameter correctly. This program needs a parameter to work." << endl;
		return 0;
	}*/
	// initialize the variable 'parameter' with the argument 1
	string parameter(argv[1]);
	//string parameter("input=grayy.txt;size=3;scheduling=roundrobin;quantum=3");


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
	//cout << "size: " << number << endl;

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
	//cout << "quantum: " << number4 << endl;


	ifstream instream(filename);//Obtain Input Stream
	string line;
	string element;
	int elementn = 0;
	

	cqueue c1;//queue
	actor temp;// actor placeholder

	temp.name = "";//Example
	temp.arrival = 0;
	temp.duration = 0;


	csize = std::stoi(number);// Size
	cquantum = std::stoi(number4);// Quantum

	if (number3 == "fifo" || number3 == "shortfifo")
	{
		while (!instream.eof())
		{
			getline(instream, line, '\n');
			istringstream some(line);
			if(some.peek() != 35)// Check if it is a comment
			while (!some.eof()) {// loop for each element
				getline(some, element, '\t');
			
				{
					temp.name = element;
					//cout << temp.name << endl;
					//cout << element << endl;
					elementn++;
				}
			
				{
					getline(some, element, '\t');
					//cout << "before\n";
					//cout << element << endl;
					temp.arrival = std::stoi(element);
					//cout << "after\n";
					elementn++;
				}
				
				{
					getline(some, element, '\t');
					temp.duration = std::stoi(element);
					elementn = 0;
				}
				elementsNB++;
				c1.enqueue(temp);
			}
			//c1.enqueue(temp);
			
			
		}
		c1.display();
	}
	
	queueType<actor> c2;
	if (number3 == "roundrobin")
	{

		queueType<actor> squeue(csize);
		while (!instream.eof())// This sets up the Big Queue that will contain the whole input file
		{
			//cout << "A" << loopi++ << "\t";
			getline(instream, line, '\n');
			istringstream some(line);
			if (some.peek() != 35 && some.peek() != '\n' && some.peek() != 00 && some.peek() > 64 && some.peek() < 123)// Check if it is a comment
			{

				while (!some.eof()) {// loop for each element
					//cout << "B" << loopi++ << "\t";
					//cout << line << endl;
					getline(some, element, '\t');

					{
						temp.name = element;
						//cout << temp.name << endl;
						//cout << element << endl;
						elementn++;
					}

					{
						getline(some, element, '\t');
						//cout << "before\n";
						//cout << element << endl;
						temp.arrival = std::stoi(element);
						//cout << "after\n";
						elementn++;
					}

					{
						getline(some, element, '\t');
						temp.duration = std::stoi(element);
						temp.durationStatic = std::stoi(element);
						elementn = 0;
					}
					elementsNB++;
					c1.enqueue(temp);
					c2.addQueue(temp);
				}
			}
		}//Finished Big Queue
		instream.close();

		do// This is the quantum working
		{
			if (loopi > 100)//debug limit
				return 0;

			//cout << "G" << loopi++ << "\t";

			if (c2.isEmptyQueue() == 0)// has an actor arrived?
			{

				//Keep putting arrivals into the small working queue as long as it is not full(the small queue size is a parameter of my program) 
				if (squeue.isFullQueue() == 0)
				while (c2.front().arrival <= linenumber  && c2.front().arrival >= 0 && c2.front().durationStatic > 0 && squeue.isFullQueue() == 0)// add from big queue to small queue
				{
					//cout << "C" << loopi++ << "\t";
					if (c2.isEmptyQueue() == 0)// as long as big queue is not empty
					{
						//cout << "A" << loopi++ <<endl;
						
						{


							squeue.addQueue(c2.front()); // add to small queue
							c2.deleteQueue(); // delete from bigqueue
						}
					}
				}
			}


			if (squeue.front().arrival <= linenumber && squeue.isEmptyQueue() == 0)// Arrived: 
			{
				temp = squeue.front();// hold the front of the queue as a modifiable variable
				tempDuration = temp.duration;// Set duration time for working

				for (int i = 0; i < cquantum; i++)//quantum
				{
					//cout << "D" << loopi++ << "\t";
					if (temp.duration == 1)//completed
					{
						cout << squeue.front() << "completed" << endl;// completed
						temp.duration--;
						relax++;

					}
					if (temp.duration > 1)
					{
						cout << squeue.front() << "makeup" <<endl;//makeup work
						temp.duration--;

						
					}
				}
				
				if (c2.getCount() > 0)// has an actor arrived?
				{
					//Keep putting arrivals into the small working queue as long as it is not full(the small queue size is a parameter of my program) 
					while (c2.front().arrival <= linenumber && squeue.isFullQueue() == 0 && c2.front().arrival >= 0 && c2.front().durationStatic > 0)// add from big queue to small queue
					{
						/*cout << "E" << loopi++ << "\t";
						cout << "\nc2.front().arrival == " << c2.front().arrival<<endl;
						
						cout << "linenumber == " << linenumber<<endl;
						cout << "squeue.isFullQueue() == " << squeue.isFullQueue() << endl;
						cout << "c2.isEmptyQueue() == " << c2.isEmptyQueue() << endl;*/
						if (c2.isEmptyQueue() == 0)// as long as big queue is not empty
						{
							//cout << "\nXY\n";
							//cout << "B" << loopi++ << endl;
							squeue.addQueue(c2.front()); // add to small queue
							c2.deleteQueue(); // delete from bigqueue
						}
						if (loopi > 100)//debug limit
							return 0;
						/*cout << "FE" << loopi++ << "\t";
						cout << "\nc2.front().arrival == " << c2.front().arrival << endl;
						cout << "linenumber == " << linenumber << endl;
						cout << "squeue.isFullQueue() == " << squeue.isFullQueue() << endl;
						cout << "c2.isEmptyQueue() == " << c2.isEmptyQueue() << endl;*/
					}
				}


				squeue.deleteQueue();// delete working element (temp variable still holds the information)

				//Relax every four actors that display completed
				if (relax == 4 && (squeue.isEmptyQueue() == 0 || c2.isEmptyQueue() == 0))// relax output
				{
					for (int w = 0; w < 2; w++)
					{
						//cout << "F" << loopi++ << "\t";
						cout << linenumber++ << "\t" << "relax\n";// relax two time units
						relax = 0;
						//timeq++;// timeq is just here for reference it is not actually used
					}
				}


				if (temp.duration != 0)// if temp is still not completed
				{

					//cout << "C" << loopi++ << endl;
					squeue.addQueue(temp);// requeue
				}
			}
			else
			{
				cout << linenumber++ << "\twaiting" << endl;// Wait until there is someone to work on(squeue is empty)
			}
			timeq++;// timeq is just here for reference it is not actually used

		} while (c2.isEmptyQueue() == 0 || squeue.isEmptyQueue() == 0);// check if any queue has actors left to be worked on

	}

	//system("pause");
	return 0;
}
