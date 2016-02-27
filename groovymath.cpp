#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include <math.h>

using namespace std;

int globalcarry = 0;
bool expgreat = false;

struct node// original node
{
	int data;
	//int count = 0;
	node* next;
	node* prev;
};

struct node *newNode(int data)// add new node with int data input
{
	struct node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
};

void push(struct node** head_ref, int new_data)// insert at the beginning of the list
{
	/* allocate node */
	struct node* temp = newNode(new_data);
	/* if list is empty */
	if ((*head_ref) == NULL)
	{
		(*head_ref) = temp;
		return;
	}
	/* link the new node off the old list */
	(*head_ref)->prev = temp;
	/* link the old list off the new node */
	temp->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = temp;
}
// A utility function to get size of linked list 
int getSize(struct node *node)
{
	int size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return size;
}

// This function is called after the smaller list is added to the bigger
// lists's sublist of same size.  Once the right sublist is added, the carry
// must be added to the left side of larger list to get the final result.
void addCarryToRemaining(node* head1, node* cur, int* carry, node** result)
{
	int sum;

	// If diff number of nodes are not traversed, add carry
	if (head1 != cur)
	{
		addCarryToRemaining(head1->next, cur, carry, result);

		sum = head1->data + *carry;
		*carry = sum / 10;
		sum %= 10;

		// add this node to the front of the result
		push(result, sum);
	}
}

void swapPointer(node** a, node** b)
{
	node* t = *a;
	*a = *b;
	*b = t;
}

void AddAtTail(struct node** head_ref, int new_data)
{
	struct node* temp = (*head_ref);

	while (temp->next != NULL) {

		temp = temp->next;
	}
	temp->data++;
	//(*head_ref) = temp;
	/*return (*head_ref);*/
}

void InsertAtTail(struct node** head_ref, int new_data)// insert at the beginning of the list
{
	// allocate node 
	struct node* temp = (*head_ref);
	struct node* cur = newNode(new_data);
	// if list is empty
	if ((*head_ref) == NULL)
	{
		(*head_ref) = cur;
		return;
	}
	// traverse the list up to the last node 
	while (temp->next != NULL) {

		temp = temp->next;
	}
	// link the temp off the new node 
	temp->next = cur;
	// link the new node off the temp 
	cur->prev = temp;
}

// Function to merge two linked lists
struct node *merge(struct node *first, struct node *second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	//if (first->data < second->data)
	//{
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	//}
	/*else
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}*/
}

void deleteList(struct node **head_ref)
{
	struct node* temp;
	while ((*head_ref != NULL)) {
		temp = (*head_ref)->next;
		(*head_ref) = NULL;
		(*head_ref) = temp;
	}
}

// Adds two linked lists of same size represented by head1 and head2 and returns
// head of the resultant linked list. Carry is propagated while returning from
// the recursion
node* addSameSize(node* head1, node* head2, int* carry)
{
	// Since the function assumes linked lists are of same size,
	// check any of the two head pointers
	if (head1 == NULL)
		return NULL;

	int sum;

	// Allocate memory for sum node of current two nodes
	node* result = new node;

	// Recursively add remaining nodes and get the carry
	result->next = addSameSize(head1->next, head2->next, carry);

	// add digits of current nodes and propagated carry
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	sum = sum % 10;

	// Assigne the sum to current node of resultant list
	result->data = sum;

	return result;
}

// The main function that adds two linked lists represented by head1 and head2.
// The sum of two lists is stored in a list referred by result instead of giving a return value
void addList(node* head1, node* head2, node** result)
{
	node *cur;

	// first list is empty
	if (head1 == NULL)
	{
		*result = head2;
		return;
	}

	// second list is empty
	else if (head2 == NULL)
	{
		*result = head1;
		return;
	}

	int size1 = getSize(head1);
	int size2 = getSize(head2);

	int carry = 0;

	// Add same size lists
	if (size1 == size2)
		*result = addSameSize(head1, head2, &carry);

	else
	{
		int diff = abs(size1 - size2);

		// First list should always be larger than second list.
		// If not, swap pointers
		if (size1 < size2)
			swapPointer(&head1, &head2);

		// move diff. number of nodes in first list
		for (cur = head1; diff--; cur = cur->next);

		// get addition of same size lists
		*result = addSameSize(cur, head2, &carry);

		// get addition of remaining first list and carry
		addCarryToRemaining(head1, cur, &carry, result);
	}

	// if some carry is still there, add a new node to the front of the result list. 
	if (carry)
		push(result, carry);
}

//Adds two decimal lists
struct node* addTwoFloats(struct node* first, struct node* second)
{
	struct node* res = NULL; // res is head node of the resultant list
	struct node *temp = NULL;
	struct node *prev = NULL;
	int carry = 0, sum;

	while (first != NULL || second != NULL) //while both lists exist
	{
		carry = 0;
		// Calculate value of next digit in resultant list. 
		// The next digit is sum of following things
		// (i)  Carry
		// (ii) Next digit of first list (if there is a next digit)
		// (ii) Next digit of second list (if there is a next digit)
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);



		// update carry for next calulation
		carry = (sum >= 10) ? 1 : 0;

		// update sum if it is greater than 10
		sum = sum % 10;

		// Create a new node with sum as data
		temp = newNode(sum);

		// if this is the first node then set it as head of the resultant list
		if (res == NULL)
			res = temp;
		else // If this is not the first node then connect it to the rest.
			prev->next = temp;

		if (carry > 0)
		{
			if (prev == NULL)
			{
				globalcarry++;
				prev = newNode(0);
			}
			prev->data += 1;
		}
		//add 1 to prev

		// Set prev for next insertion
		prev = temp;

		// Move first and second pointers to next nodes
		if (first == NULL) first = newNode(0);
		if (first) first = first->next;
		if (second == NULL) second = newNode(0);
		if (second) second = second->next;
	}
	if (res == NULL)
	{
		res = newNode(0);
	}
	if (res->data >= 10)
	{
		globalcarry = 1;
	}
	// return head of the resultant list
	return res;
}


// global array used to store result and its length
int* buffer = NULL;
int lenBuffer = 0;

void addToBuffer(int value, int index)
{
	assert(value >= 0 && value <= 9);
	while (value > 0 && index >= 0)
	{
		int temp = buffer[index] + value;
		buffer[index] = temp % 10;
		value = temp / 10;
		index--;
	}
}

void multiplyHelper(int value, node* head, int offset)
{
	assert(value >= 0 && value <= 9 && head != NULL);
	if (value == 0) return;

	node* temp = head;
	int pos = 0;
	while (temp)
	{
		int temp1 = value * temp->data;
		int ones = temp1 % 10;
		if (ones != 0) addToBuffer(ones, offset + pos + 1);
		int tens = temp1 / 10;
		if (tens != 0) addToBuffer(tens, offset + pos);

		temp = temp->next;
		pos++;
	}
}

struct node* multiply(node* num1, node* num2)
{
	if (num1 == NULL || num2 == NULL) return NULL;

	int length1 = getSize(num1);
	int length2 = getSize(num2);
	if (length1 > length2) return multiply(num2, num1);

	// initialize buffer
	lenBuffer = length1 + length2;
	buffer = new int[lenBuffer];
	memset(buffer, 0, sizeof(int) * lenBuffer);

	// multiply
	int offset = 0;
	node* temp = num1;
	while (temp)
	{
		multiplyHelper(temp->data, num2, offset);
		temp = temp->next;
		offset++;
	}

	// transfer buffer to a linked list
	node* head = NULL;
	int pos = 0;
	while (pos < lenBuffer && buffer[pos] == 0) pos++;
	if (pos < lenBuffer)
	{
		head = newNode(buffer[pos++]);

		temp = head;
		while (pos < lenBuffer)
		{
			temp->next = newNode(buffer[pos++]);
			temp = temp->next;
		}
	}

	delete buffer;
	lenBuffer = 0;
	buffer = NULL;

	return head;
}

void printList(node* list)
{
	node* temp = list;
	while (temp != NULL)
	{
		cout << temp->data << "";
		temp = temp->next;
	}
	//cout << endl;
}

int ReverseInt(int value)
{
	int resultNumber = 0;
	for (int i = value; i != 0; i /= 10) {
		resultNumber = resultNumber * 10 + i % 10;
	}
	return resultNumber;
}

struct node* deleteWholeZero(struct node* head)
{
	if(head->next !=NULL)
	while (head->data == 0)
	{
		node* temp = head->next;
		delete head;
		head = temp;
	}
	return head;
}

struct node* deleteDecimalZero(struct node* head)
{
	

	node* temp = head;
	node* curr = temp;
	while (curr->next != NULL)
	{
		temp = curr->next;
		curr = temp;

	}
	if (curr->prev == NULL && curr->next == NULL)
	{
		return head;
	}
	while (curr->data == 0)
	{
		temp = curr;
		curr = curr->prev;

		delete temp;
		
	}
	curr->next = 0;

	while (curr->prev != NULL)
	{
		curr = curr->prev;
		head = curr;

	}
	/*return curr;
	temp = NULL;*/

	return head;
}

struct node* exponential(node* first, node** decimal, node* power)
{
	int size = getSize(first);
	int sized = getSize(*decimal);
	int exponent = 0;
	string expoS;
	//int last_digit, reversedNum = 0;
	for (int i = 0; power->data != 0 || power->data == 0; i++)
	{
		if (power->next != NULL)
		exponent += (power->data * pow(10,i));
		if (power->next == NULL)
		{
			exponent += (power->data * pow(10,i)) /*/ 10*/;
			break;
		}
		power = power->next;
	}
	
	node* res = first;
	if (exponent < sized)
	{
		//cout << "tuturu\t" ;
		int decimaldistance = sized - exponent;
		node* curr = (*decimal);// curr will carry the numbers extracted from the old decimal
		for (int i = 0; i < exponent; i++)
		{
			 
			InsertAtTail(&first, curr->data);
			curr = curr->next;
		}
		for (int i = 0; i < exponent; i++)
		{
			//Delete  "exponent" nodes from decimal

			node* temp = (*decimal)->next;// temp will carry the new decimal number
			delete (*decimal);
			(*decimal) = temp;


		}
		return first;
	}

	first = merge(first, *decimal);
	
	//insert code for deleting leading zeroes

	exponent = ReverseInt(exponent);
	if (exponent > sized)
	{
		expgreat = true;
		for (sized; sized < exponent  ; sized++)
		{
			InsertAtTail(&first, 0);
			/*printList(first);
				cout << endl;*/
		}
	}

	if (exponent == sized)
	{
		expgreat = true;
	}
	
	return first;
}




int main(int argc, char* argv[])

{
	struct node* res = NULL;
	struct node* resfloat = NULL;
	struct node* first = NULL;
	struct node* firstfloat = NULL;
	struct node* second = NULL;
	struct node* secondfloat = NULL;

	//Set input
	string filename = "textcase.txt";


	std::string s = filename;
	std::string delimiter = "=";
/*
	size_t pos = 0;// Get digits per node
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}

	int digitsPerNode = std::stoi(s);//obtain DigitsPerNode

	std::string f = filename;//get correct filename
	std::string cutoff = ";";
	std::string reducedname = f.substr(0, f.find(cutoff)); // token is "scott"
*/
	ifstream instream(s);//Obtain Input Stream

	string operands;

	char currentchar;
	string group;

	//Char solution
	bool isfloat = false;// Checks if the number is a decimal
	bool isfirstoperation = true;// Checks if it is the first number in the operation
	bool isswap = false; //Checks if the operator is swap
	char operation = 00; // Stores operator
	int exp = 0;

	bool iseof = false;//Checks if it is the end of file
	//avoiding eating or doubling the last output


	//The whole input and computation
	while (!instream.eof())
	{


		instream.get(currentchar);

		//Special case for end of file without 
		if (instream.peek() == -1)
		{
			if (currentchar >= 48 && currentchar <= 57)// Checks if its a number
			{
				//cout << currentchar;
				if (isfirstoperation && operation != '#')//checks if it is the first item in the line
				{
					if (isfloat == false) {//If it is the whole number
						InsertAtTail(&first, currentchar - 48);
					}
					else {//If it is after the decimal point
						InsertAtTail(&firstfloat, currentchar - 48);
					}
				}
				else//checks if it is the second item in the line
				{
					if (isfloat == false) {//If it is the whole number
						InsertAtTail(&second, currentchar - 48);
					}
					else {//If it is after the decimal point
						InsertAtTail(&secondfloat, currentchar - 48);
					}
				}
				/*if (instream.peek() == -1)
				{
				//isfirstoperation = false;
				iseof = true;
				}*/
			}
			iseof = true;
		}

		// Checks for "Enter" key (Output result)
		if (currentchar == 10 || iseof == true /*|| instream.peek() == -1*/)
		{
			
			if (first != NULL)
			{
				isfirstoperation = true;
				first = deleteWholeZero(first);//Delete leading zeroes
				if (isswap == false)//Checks if NOT swap
				printList(first);// Print first item
				if (firstfloat != NULL && isswap == false)// checks if first float number exists
				cout << ".";// puts a "." in the output
				//firstfloat = deleteDecimalZero(firstfloat);//Delete trailing zeroes
				if (isswap == false)//Checks if NOT swap
				printList(firstfloat);// prints first float number
				if (isswap == false)//Checks if NOT swap
				cout << operation;// display operation symbol
				if(second != NULL)
				second = deleteWholeZero(second);//Delete leading zeroes
				printList(second);// Print the Second item
				if (secondfloat != NULL && operation != '#')//check if second float number
				{
					cout << ".";// puts a "." in the output
				}
				//secondfloat = deleteDecimalZero(secondfloat);//Delete trailing zeroes
				printList(secondfloat);//prints second float number
				if (isswap == false)//Checks if NOT swap
				cout << "=";//Display answer
				if (operation == '+')// Check for Addition
				{
					addList(first, second, &res);// Make the computation of the two items
					resfloat= addTwoFloats(firstfloat, secondfloat);//add both float(decimal) numbers
					if (globalcarry == 1)// checks if decimal numbers add up to more than 
					{
						AddAtTail(&res, 1);
					}
					globalcarry = 0;
					
					printList(res);// Print the result
					if (res == NULL)// If no whole number found
					{
						cout << "0";
					}
					cout << ".";
					printList(resfloat);
					if (resfloat == NULL)//If not float number found
					{
						cout << "0";
					}
					cout << "\n";// Print the decimal point and a 0
					deleteList(&first);// Set all listsststst to NULL
					deleteList(&firstfloat);
					deleteList(&second);
					deleteList(&secondfloat);
					isfloat = false;

					//cout <<"\nSize = "<< getSize(first)<< "\t"<<getSize(second) << endl;
				}
				if (operation == '*')// check for Multiplication
				{
					//first = merge(first, firstfloat);
					//second = merge(second, secondfloat);
					res = multiply(first, second);
					//resfloat = multiply(firstfloat, secondfloat);


					if (globalcarry == 1)// checks if decimal numbers have a carryover 
					{
						AddAtTail(&res, 1);
					}
					globalcarry = 0;

					// Print the result
					printList(res);
					if (res == NULL)// If no whole number found
					{
						cout << "0";
					}
					cout << ".";
					printList(resfloat);

					if (resfloat == NULL)//If not float number found
					{
						cout << "0";
					}
					cout << "\n";// Print the decimal point and a 0
					deleteList(&first);// Set all listsststst to NULL
					deleteList(&firstfloat);
					deleteList(&second);
					deleteList(&secondfloat);
					isfloat = false;
				}
				if (operation == '#')// Check for pound
				{
					first = exponential(first, &firstfloat, second);
					res = first;
					// Print the result
					printList(res);
					if (expgreat == false)
					{
						cout << ".";
						printList(firstfloat);
					}
					else
					{
						cout << ".0";
					}

					cout << "\n";// Print the decimal point and a 0
					deleteList(&first);// Set all listsststst to NULL
					deleteList(&firstfloat);
					deleteList(&second);
					deleteList(&secondfloat);
					isfloat = false;
					operation = '0';
					expgreat = false;
				}
				if (isswap == true)
				{
					//code for swap
					cout << "swap(";
					
					
					printList(first);
					
					cout << ".";
					printList(firstfloat);
					cout << ")=";
					firstfloat = deleteWholeZero(firstfloat);
					first = deleteWholeZero(first);
					first = deleteDecimalZero(first);
					printList(firstfloat);
					cout << ".";
					printList(first);

					
					cout << "\n";// Print the decimal point and a 0
					deleteList(&first);// Set all listsststst to NULL
					deleteList(&firstfloat);
					deleteList(&second);
					deleteList(&secondfloat);
					isfloat = false;
					isswap = false;
				}
			}
		}

		
		// Checks for "+" operator
		if (currentchar == 43)
		{
			operation = '+';
			isfirstoperation = false;
			isfloat = false;
		}

		// Checks for "*" operator
		if (currentchar == '*')
		{
			operation = '*';
			isfirstoperation = false;
			isfloat = false;
		}

		// Checks for "." decimal separator
		if (currentchar == '.')
		{
			isfloat = true;
		}

		// Checks for "#" operator
		if (currentchar == '#')
		{
			operation = '#';
			isfirstoperation = false;
			isfloat = false;

		}

		// Checks for swap operator
		if (currentchar == 's') {
			for (int z = 0; z < 4; z++) {
				instream.get(currentchar);
			}
			//get numbers for swap
			operation = 00;
			isswap = true;

			
		}

		// Checks if its a number
		if (currentchar >= 48 && currentchar <= 57)
		{
			//cout << currentchar;
			if (isfirstoperation && operation != '#')//checks if it is the first item in the line
			{
				if (isfloat == false) {//If it is the whole number
					InsertAtTail(&first, currentchar - 48);
				}
				else {//If it is after the decimal point
					InsertAtTail(&firstfloat, currentchar - 48);
				}
			}
			else//checks if it is the second item in the line
			{
				if (isfloat == false) {//If it is the whole number
					InsertAtTail(&second, currentchar - 48);
				}
				else {//If it is after the decimal point
					InsertAtTail(&secondfloat, currentchar - 48);
				}
			}
			/*if (instream.peek() == -1)
			{
				//isfirstoperation = false;
				iseof = true;
			}*/
		}
	}

	//cout << endl;
	//cout << "Filename = "<<reducedname<< endl;
	//cout << "Digits Per Node = " << digitsPerNode << endl;

	system("pause");
	return 0;
}

