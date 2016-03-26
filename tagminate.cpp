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

class stacke
{
	char stk[8000], top;
	public:
		stacke()
		{
			top = -1;
		}

		void push(char x)
		{
			if (top > 500)
			{
				//cout << "The stack is full"<<endl;
				return;
			}
			stk[++top] = x;
			//cout << "Successfully inserted: " << x<<endl;
		}
		void pop()
		{
			if (top < 0)
			{
				//cout << "The stack is empty" << endl;
				return;
			}
			//cout << "the deleted element is: " << stk[top--]<<endl;
		}

		void display()
		{
			if (top < 0)
			{
				//cout << "The stack is empty" << endl;
			}

			for (int i = top; i >= 0; i--)
			{
				cout << stk[i] << " \n";
			}
		}

		void tope()
		{
			cout << stk[top];
			return;
		}
};

struct node {
	char data;
	node *next;
	node *prev;
};

struct node *newNode(char data)// add new node with int data input
{
	struct node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
};

void addatend(struct node *start, char num)
{
	if (start == NULL)
	{
		start = new node;
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
	//cout << p->data << endl;
	//cout << temp->data << endl;


	p->next = temp;
	temp->next = NULL;
	temp->prev = p;
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
		//cout << "\t";
		temp = temp->next;
	}
	//if (temp != NULL && temp->data != NULL)
	cout << endl;
}

int main(int argc, char* argv[])
{
	int ch;
	stacke st;


	stack<char> myStack;
	//Set input
	std::string filename = "abc.html";
	int linecount = 1;
	//string filename = argv[1];
	/*filename.erase(0, 6);

	std::string s = filename;
	std::string delimiter = "=";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}

	string operations = s;

	std::string f = filename;//get correct filename
	std::string cutoff = ";";
	std::string file = f.substr(0, f.find(cutoff)); */

	ifstream instream(filename);//Obtain Input Stream
	//ifstream opstream(s);// Obtain Operation Stream

	node *head = NULL;
	//head = newNode(NULL);
	string steiner;// reading string line
	string element;
	char stackerino[256]; // stack for storing characters
	int charpoint = 1; // index of the stack

	/*while (!instream.eof())
	{
		getline(instream, steiner);
		istringstream some(steiner);
		while (!some.eof()) {// loop for each element
			linecount++;
			getstring(some, element);
			cout << element << endl;
		}
		//cout << steiner << endl;
	}*/

	while (!instream.eof())
	{
		//cout << "Line Number: " << linecount<<endl;
		getline(instream, steiner);
		//cout << steiner;
		
		istringstream some(steiner);
		while (!some.eof())
		{
			//some.get();
			element = some.get();

			if (element == "<")
			{
				st.push('<');
				myStack.push('<');
			}
			if (element == ">")
			{
				if (myStack.size() != 0 && myStack.top() == '<')
				{
					//cout << "pop <" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					cout << "Error in line " << linecount << ", top of stack=";
					if (myStack.size() != 0)
					{
						st.tope();
						//cout << myStack.top();
					}

					cout << " current=" << ">" << endl;
					system("pause");
					return 0;
				}
				//myStack.push('>');
			}

			if (element == "{")
			{
				st.push('{');
				myStack.push('{');
			}
			if (element == "}")
			{
				if (myStack.size() != 0 && myStack.top() == '{')
				{
					//cout << "pop <" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					cout << "Error in line " << linecount << ", top of stack=";
					if (myStack.size() != 0)
					{
						st.tope();
						//cout << myStack.top();
					}

					cout << " current=" << "}" << endl;
					system("pause");
					return 0;
				}
				//myStack.push('>');
			}

			if (element == "(")
			{
				st.push('(');
				myStack.push('(');
			}
			if (element == ")")
			{
				if (myStack.size() != 0 && myStack.top() == '(')
				{
					//cout << "pop <" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					cout << "Error in line " << linecount << ", top of stack=";
					if (myStack.size() != 0)
					{
						st.tope();
						//cout << myStack.top();
					}

					cout << " current=" << ")" << endl;
					system("pause");
					return 0;
				}
				//myStack.push('>');
			}

			if (element == "[")
			{
				st.push('[');
				myStack.push('[');
			}
			if (element == "]")
			{
				if (myStack.size() != 0 && myStack.top() == '[')
				{
					//cout << "pop [" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					cout << "Error in line " << linecount << ", top of stack=";
					if (myStack.size() != 0)
					{
						st.tope();
						//cout << myStack.top();
					}
					
					cout << " current=" << "]" << endl;
					system("pause");
					return 0;
				}
				//myStack.push(']');
			}
			

			if (element == "\"")
			{
				
				if (myStack.size() != 0 && myStack.top() == '"')
				{
					//cout << "pop <" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					st.push('"');
					myStack.push('"');
				}

			}

			if (element == "'")
			{

				if (myStack.size() != 0 && myStack.top() == '\'')
				{
					//cout << "pop <" << endl;
					st.pop();
					myStack.pop();
				}
				else
				{
					st.push('\'');
					myStack.push('\'');
				}

			}

			//cout << "Element: " << element<< endl;
		}
		linecount++;
	}

	//cout << "Filename: " << filename << endl;
	//cout << "First Line: " << faf << endl;
	
	/*cout << "Number of elements on hte stack " << myStack.size() << endl;
	while (!myStack.empty())
	{
		cout << "popping " << myStack.top() << endl;
		myStack.pop();
	}
	cout << "Number of elements on hte stack " << myStack.size() << endl;*/


	if (myStack.size() > 0)
	{
		cout << "Error in line " << linecount << ", top of stack=";
		if (myStack.size() != 0)
		{
			st.tope();
			//cout << myStack.top();
		}

		cout << " current=" << "$" << endl;
		system("pause");
		return 0;
	}

	cout << "ok" << endl;
	

	//st.display();
	system("pause");
	return 0;
}
