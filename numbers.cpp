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
	if (start == NULL)
	{
		start = new node;
		start->data = num;
		start->next = NULL;
		start->prev = NULL;
	}
	if (start->data == -1337 && 0 == start->word.compare(""))
	{
		start->data = num;
		start->next = NULL;
		start->prev = NULL;
		return;
	}
	struct node *temp, *p;
	
	temp = newNode(num);
	temp->data = num;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	temp->next = NULL;
	temp->prev = p;
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
	temp->data = -1337;
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
		if (temp->data != -1337)
		{
			cout << temp->data << "";
		}
		/*if (temp->word.compare("") == 0)
		{
			cout << temp->word << "";
		}
		if (temp->word.compare("") == 1)
		{
			cout << temp->word << "";
		}*/
		cout << temp->word;
		cout << "\t";
		temp = temp->next;
	}
	//if (temp != NULL && temp->data != NULL)
	cout << endl;
}

void printAll(nodeColumn* list)
{
	nodeColumn* temp = list;
	while (temp != NULL)
	{
		printList(temp->firstelement);
		temp = temp->next;
	}
}

void deleteList(struct nodeColumn **head_ref, int line)
{
	if (line == 0)
	{
		return;
	}
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (line == 1)
	{
		int num = (*head_ref)->data;
		if (temp->prev == NULL && temp->next == NULL)
		{
			(*head_ref)->firstelement = NULL;
			return;
		}
		if (temp->prev == NULL)
		{
			//(*head_ref)->firstelement = NULL;
			//(*head_ref)->next->prev = (*head_ref);
			//(*head_ref)
			temp->next->prev = NULL;
			temp = temp->next;
			while (((*head_ref)->next != NULL) && temp->next !=NULL)
			{
				temp->data = temp->data - 1;
				temp = temp->next;
				
			}
			temp->data = temp->data - 1;
			while (temp->prev != NULL)
			{
				temp = temp->prev;
			}
			(*head_ref) = temp;
			return;
		}
		if (temp->next == NULL)
		{
			temp = temp->prev;
			temp->next = NULL;
			//(*head_ref) = NULL;
			(head_ref) = &temp;
			return;
		}
		(*head_ref)->firstelement = NULL;
		(*head_ref)->next->prev = (*head_ref)->prev;
		(*head_ref)->prev->next = (*head_ref)->next;
		(*head_ref)->data = num;
		temp = (*head_ref);
		while ((temp->next != NULL))
		{
			temp->next->data = ++num;
			temp = temp->next;
		}
		cout << "";
	}
	
	else
	{
		deleteList((&temp->next), line - 1);
	}
	/*while ((*head_ref != NULL)) {
		temp = (*head_ref)->next;
		(*head_ref) = NULL;
		(*head_ref) = temp;
	}*/
}

void insertList(struct nodeColumn **head_ref, int line)
{
	if (line == 0)
	{
		return;
	}
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (temp->prev == NULL && temp->next == NULL && temp->firstelement == NULL)
	{
		(*head_ref)->firstelement = newNode(-1337);
		return;
	}
	if (temp->prev == NULL && temp->next == NULL)
	{
		nodeColumn* tempo = new nodeColumn;
		tempo->data = 1;
		tempo->firstelement = newNode(-1337);
		tempo->next = (*head_ref);
		tempo->prev = NULL;
		(*head_ref)->data = 2;
		(*head_ref)->prev = tempo;
		(*head_ref) = (*head_ref)->prev;
		return;
	}
	if (temp->prev == NULL && temp->next != NULL)
	{
		nodeColumn* tempo = new nodeColumn;
		tempo->data = 1;
		tempo->firstelement = newNode(-1337);
		tempo->next = (*head_ref);
		tempo->prev = NULL;
		//(*head_ref)->data = 2;
		(*head_ref)->prev = tempo;
		(*head_ref) = (*head_ref)->prev;
		temp = (*head_ref)->next;
		while (temp != NULL)
		{
			
			temp->data += 1;
			temp = temp->next;
		}
		return;
	}
	if (line == 1)
	{
		int num = (*head_ref)->data;
		//int num = 69;
		temp = new nodeColumn;// create an empty new line
		temp->data = num;// set new line to the new position
		temp->firstelement = newNode(-1337);//empty list
		temp->next = (*head_ref);// new line points next to it predecessor
		temp->prev = (*head_ref)->prev;// new line points back to the line previous
		(*head_ref)->prev->next = temp;
		(*head_ref)->next->prev = (*head_ref);
		temp = (*head_ref);
		while ((temp->next != NULL)) {
			temp->next->data = ++num;
			temp = temp->next;
		}
		//cout << "INSERT THIS " << num<<endl;
		cout << "";
	}

	else
	{
		insertList((&temp->next), line - 1);
	}
}

void countList(nodeColumn** head_ref, int line)
{
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (line == 1)
	{
		double count = 0;
		int num = (*head_ref)->data;
		//cout << "COUNT THIS " << num << endl;
		node* templine = (*head_ref)->firstelement;
		while (templine != NULL)
		{
			if (templine->data > -1)
			{
				count++;
			}
			templine = templine->next;

		}
		templine = (*head_ref)->firstelement;
		if (templine == NULL)
		{
			templine = newNode(0);
			(*head_ref)->firstelement = templine;
			return;
		}
		addatend(templine, count);
		cout << "";
	}

	else
	{
		countList((&temp->next), line - 1);
	}
}

void maxList(nodeColumn** head_ref, int line)
{
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (line == 1)
	{
		double count = -1337;
		int num = (*head_ref)->data;
		//cout << "MAX THIS " << num << endl;
		node* templine = (*head_ref)->firstelement;
		while (templine != NULL)
		{
			if (templine->data > count)
			{
				count = templine->data;
			}
			/*if (templine->data == -1337 && templine->next != NULL)
			{
				count = templine->next->data;
			}*/
			templine = templine->next;

		}
		templine = (*head_ref)->firstelement;
		if (templine == NULL)
		{
			(*head_ref)->firstelement = newNode(-1337);
			addatendW((*head_ref)->firstelement, "undefined");
			//cout << "wowpls" << endl;
			return;
		}
			
		if (count == -1337)
		{

			addatendW(templine, "undefined");
			return;
		}
		addatend(templine, (int)count);
		cout << "";
	}

	else
	{
		maxList((&temp->next), line - 1);
	}
}

void minList(nodeColumn** head_ref, int line)
{
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (line == 1)
	{
		
		int num = (*head_ref)->data;
		double count = -1;
		//cout << "MIN THIS " << num << endl;
		node* templine = (*head_ref)->firstelement;
		//if (templine->data > -1)
		if (templine == NULL)
		{
			(*head_ref)->firstelement = newNode(-1337);
			addatendW((*head_ref)->firstelement, "undefined");
			return;
		}
		count = templine->data;
		

		while (templine != NULL)
		{
			if (templine->data < count && templine->data != -1337)
			{
				count = templine->data;
			}
			if (templine->data == -1337 && templine->next != NULL)
			{
				count = templine->next->data;
			}
			templine = templine->next;
		}	
		templine = (*head_ref)->firstelement;
		
		if (count == -1337)
		{
			addatendW(templine, "undefined");
			return;
		}
		addatend(templine, (int)count);
		cout << "";
	}

	else
	{
		minList((&temp->next), line - 1);
	}
}

void meanList(nodeColumn** head_ref, int line)
{
	struct nodeColumn* temp;
	temp = (*head_ref);
	if (line == 1)
	{

		int num = (*head_ref)->data;
		double count = -1;
		//cout << "MIN THIS " << num << endl;
		node* templine = (*head_ref)->firstelement;
		//if (templine->data > -1)
		count = 0;
		int passable = 0;
		int counts = 0;

		while (templine != NULL)
		{
			if (templine->data != -1337)
			{
				count += templine->data;
				passable = 1;
				counts++;
			}
			if (templine->data == -1337 && templine->next != NULL)
			{
				//count = templine->next->data;
				//passable = 0;
			}
			templine = templine->next;
		}
		templine = (*head_ref)->firstelement;
		if (templine == NULL)
		{
			(*head_ref)->firstelement = newNode(-1337);
			addatendW((*head_ref)->firstelement, "undefined");
			return;
		}
		if (passable == 0)
		{
			addatendW(templine, "undefined");
			return;
		}
		addatend(templine, ((int)count/counts));
		cout << "";
	}

	else
	{
		meanList((&temp->next), line - 1);
	}
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
	head->data = -1337;
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
		//printList(head);
		temporalC = headC;
		for (int i = 0; i < lines-1; i++)
		{
			temporalC = temporalC->next;
		}
		temporalC->firstelement = head;
		head = newNode(-1337);

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
					if (headC->firstelement == NULL)
					{
						lines = 1;
					}
					countList(&headC, linenumber);

					if (headC->firstelement == NULL)
					{
						headC->firstelement = newNode(-1337);
						lines = 1;
						//break;
					}
					//cout << "count Line: " << linenumber << endl;
				}
				else if (element.compare("max")==0)// If Math operation is Max
				{
					if (headC->firstelement == NULL)
					{
						//headC->firstelement = newNode(0);
						//headC->firstelement->word = "undefined";
						lines = 1;
						//break;
					}
					maxList(&headC, linenumber);
					
					//cout << "max Line: " << linenumber << endl;
				}
				else if (element.compare("min")==0)// If Math operation is Min
				{
					if (headC->firstelement == NULL)
					{
						lines = 1;
					}
					minList(&headC, linenumber);
					//cout << "min Line: " << linenumber << endl;
				}
				else // If Math operation is Mean
				{
					if (headC->firstelement == NULL)
					{
						lines = 1;
					}
					meanList(&headC, linenumber);
					//cout << "mean Line: "<<linenumber << endl;
				}

				//do stuff

				ismathline = 0;
			}

			//If we detected DeleteLine we store for the number of the line
			if (isdelete && stoi(element)<=lines)//check if operation is "deleteline"
			{
				int linenumber = stoi(element);// store the line number

				//cout << "Delete Line : " << linenumber << endl;
				if (stoi(element) <= lines)
				deleteList(&headC, linenumber);
				lines--;
				isdelete = 0;//end
			}

			//If we detected InsertLine we store for the number of the line
			if (isinsert && stoi(element)<=lines+1|| headC->firstelement == NULL && isinsert)//check if operation is "insertline"
			{
				/*if (headC->firstelement == NULL)
				{
					lines = 1;
				}*/
				int linenumber = stoi(element);// store the line number

				//cout << "Insert Line : " << linenumber << endl;

				insertList(&headC, linenumber);

				//do stuff
				lines++;
				isinsert = 0;
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
	//cout << "\n\n\n";
	printAll(headC);

	system("pause");
	return 0;
}
