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

using namespace std;

bool isFloat(string myString) {
	std::istringstream iss(myString);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

struct node{
	double data;
	string word;
	node *next;
	node *prev;
};

struct nodeColumn{
	double data;
	node *firstelement;
	nodeColumn *next;
	nodeColumn *prev;
};

struct node *newNode(double data)// add new node with int data input
{
	struct node *temp = new node;
	temp->data = data;
	temp->word = "";
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
};

void addatend(struct node *start, double num)
{
	if (start->data == NULL && 0 == start->word.compare(""))
	{
		start->data = num;
		start->next = NULL;
		start->prev = NULL;
		return;
	}
	struct node *temp, *p;
	//temp = (struct node *)malloc(sizeof(struct node));
	temp = newNode(num);
	temp->data = num;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->next = NULL;
}

void addatendW(struct node *start, string num)
{
	if (0 == start->word.compare(""))
	{
		start->word = num;
		start->next = NULL;
		start->prev = NULL;
		return;
	}
	struct node *temp, *p;
	//temp = (struct node *)malloc(sizeof(struct node));
	temp = new node;
	temp->data = NULL;
	temp->word = num;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->next = NULL;
}

void addatendC(struct nodeColumn *start, double num)
{
	if (start->data == -420)
	{
		start->data = 1;
		start->next = NULL;
		start->prev = NULL;
		start->firstelement = NULL;
		node *first = newNode(0);
		start->firstelement = first;
		return;
	}
	struct nodeColumn *temp, *p;
	temp = (struct nodeColumn *)malloc(sizeof(struct nodeColumn));
	temp->data = num;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->prev = p;
	temp->next = NULL;
	/*temp->firstelement = NULL;
	node *first = newNode(0);
	temp->firstelement = first;*/
}

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

void printList(node* list)
{
	node* temp = list;
	while (temp != NULL)
	{
		if (temp->data != NULL)
		{
			cout << temp->data << "";
		}
		if (temp->word.compare("") == 1)
		{
			cout << temp->word << "";
		}
		cout << "\t";
		temp = temp->next;
	}
	//if (temp != NULL && temp->data != NULL)
	cout << endl;
}

int main(int argc, char* argv[])
{


	//Set input
	std::string filename = "input=textcase.txt;operations=commands.txt";
	//string filename = argv[1];
	filename.erase(0, 6);

	std::string s = filename;
	std::string delimiter = "=";

	size_t pos = 0;// Get Operations.txt per node
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}

	string operations = s;//obtain DigitsPerNode

	std::string f = filename;//get correct filename
	std::string cutoff = ";";
	std::string file = f.substr(0, f.find(cutoff)); //correct filename 

	ifstream instream(file);//Obtain Input Stream
	ifstream opstream(s);// Obtain Operation Stream

	nodeColumn *headC = new nodeColumn;
	nodeColumn *temporalC = new nodeColumn;
	node *head = new node;
	headC->data = -420;
	//headC->next = NULL;
	head->data = NULL;
	//head->word = "\0";


	string line;
	string element;

	bool ismathline = 0;
	bool isdelete = 0;
	bool isinsert = 0;

	int lines = 0;// determines the line number

	while (!instream.eof()){// loop for each line data file
		lines++;

		getline(instream, line, '\n');

		addatendC(headC, lines);// Add new node for Row manager

		//head = newNode(-1337);
		//head->data = -1337;

		istringstream some(line);
		while (!some.eof()){// loop for each element
			getline(some, element, '\t');
			if (isFloat((element)))
			{
				//cout << "number " << element << "\tLine "<<lines << endl;
				addatend(head, stod(element));
				//add element to horizontal node list
			}
			else
			{
				//cout << "word " << element << "\t\tLine " << lines << endl;
				addatendW(head, element);
			}
		}
		printList(head);
		temporalC = headC;
		for (int i = 0; i < lines-1; i++)
		{
			temporalC = temporalC->next;
		}
		temporalC->firstelement = head;
		head = newNode(NULL);

	}

	while (!opstream.eof()){// loop for each line operation file


		getline(opstream, line, '\n');// get a complete line
		/*cout << "Line: " << line << endl;*/

		istringstream some(line);
		while (!some.eof()){// loop for each element
			getline(some, element, ':');//Separate each element by ":"


			//If we detected Mathline we check for the number of the line
			if (ismathline)//check if operation is "mathline"
			{
				int linenumber = stoi(element);// store the line number
				
				getline(some, element, ':');// store the Math Operation
				if (element.compare("count")==0)// If Math operation is Count
				{
					
					//cout << "count Line: " << linenumber << endl;
				}
				else if (element.compare("max")==0)// If Math operation is Max
				{
					
					//cout << "max Line: " << linenumber << endl;
				}
				else if (element.compare("min")==0)// If Math operation is Min
				{
					
					//cout << "min Line: " << linenumber << endl;
				}
				else // If Math operation is Mean
				{

					//cout << "mean Line: "<<linenumber << endl;
				}

				//do stuff

				ismathline = 0;
			}

			//If we detected DeleteLine we store for the number of the line
			if (isdelete)//check if operation is "deleteline"
			{
				int linenumber = stoi(element);// store the line number

				//cout << "Delete Line : " << linenumber << endl;

				//do stuff

				isdelete = 0;//end
			}

			//If we detected InsertLine we store for the number of the line
			if (isinsert)//check if operation is "insertline"
			{
				int linenumber = stoi(element);// store the line number

				//cout << "Insert Line : " << linenumber << endl;

				//do stuff

				isdelete = 0;
			}

			//We have 3 operations
			if (element.compare("mathline") == 0)//check if element is "mathline"
			{
				ismathline = 1;
			}
			if (element.compare("deleteline") == 0)//check if element is "deleteline"
			{
				isdelete = 1;
			}
			if (element.compare("insertline") == 0)//check if element is "insertline"
			{
				isinsert = 1;
			}

			


			/*cout << "Stuff: " << element << endl;//do stuff*/

		}

		isdelete = 0;//set back to zero to prepare for the next line
		isinsert = 0;
		ismathline = 0;
	}



	//cout << "Filename: " << file << endl;
	//cout << "Operations: " << s << endl;

	//cout << "Number of lines: "<<lines << endl;

	system("pause");
	return 0;
}
