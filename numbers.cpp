#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <algorithm>

using namespace std;

struct node{
	double data;
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
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
};

void addatend(struct node *start, double num)
{
	if (start == NULL)
	{
		return;
	}
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
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
	if (start == NULL)
	{
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
	temp->next = NULL;
}

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
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
	//node *head = newNode(0);
	headC->data = 0;
	headC->next = NULL;
	//head->data = 0;


	string line;
	string element;

	bool ismathline = 0;
	bool isdelete = 0;
	bool isinsert = 0;

	int lines = 0;

	while (!instream.eof()){// loop for each line
		lines++;

		getline(instream, line, '\n');

		addatendC(headC, lines);// Add new node for Row manager
		

		istringstream some(line);
		while (!some.eof()){// loop for each element
			getline(some, element, '\t');
			if (is_number(element))
			{
				//add element to horizontal node list
			}
			/*cout << "Stuff: " << element << endl;*/
		}

	}

	while (!opstream.eof()){// loop for each line


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
