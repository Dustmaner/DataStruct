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
#include "graphType.h"
#include "weightedGraph.h"


using namespace std;


struct student
{
	string name = "";
	double gpa = 0;
	double qat = 0;
	string gender = "";
	string note = "";
	double score = 0;
	//student *link;
};

bool operator==(const student& lhs, const student& rhs)
{
	if (lhs.gpa == rhs.gpa && lhs.qat == rhs.qat)
	{
		//cout << "LUL\n";
		return 1;/* your comparison code goes here */
	}
	else
		return 0;
}
bool operator!=(const student& lhs, const student& rhs)
{
	if (lhs.gpa == rhs.gpa && lhs.qat == rhs.qat)
	{
		//cout << "LUL\n";
		return 0;/* your comparison code goes here */
	}
	else
		return 1;
}
bool operator <(const student& lhs, const student& rhs)
{
	if (lhs.score < rhs.score)
	{
		//cout << "LUL\n";
		return 1;/* your comparison code goes here */
	}
	else
		return 0;
}
bool operator >(const student& lhs, const student& rhs)
{
	if (lhs.score > rhs.score)
	{
		//cout << "LUL\n";
		return 1;/* your comparison code goes here */
	}
	else
		return 0;
}

/*student operator++(const student& lhs)
{

{
//cout << "LUL\n";
return lhs;/* your comparison code goes here
}


}*/

/*template <class Type>
struct nodeType
{
	Type info;

	nodeType<Type> *link;
};*/


template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator=
		(const arrayListType<elemType>&);
	//Overloads the assignment operator
	bool isEmpty() const;
	//Function to determine whether the list is empty
	//Postcondition: Returns true if the list is empty;
	// otherwise, returns false.
	bool isFull() const;
	//Function to determine whether the list is full.
	//Postcondition: Returns true if the list is full;
	// otherwise, returns false.
	int listSize() const;
	//Function to determine the number of elements in the list
	//Postcondition: Returns the value of length.
	int maxListSize() const;
	//Function to determine the size of the list.
	//Postcondition: Returns the value of maxSize.
	void print() const;
	//Function to output the elements of the list
	//Postcondition: Elements of the list are output on the
	// standard output device.
	bool isItemAtEqual(int location, const elemType& item) const;
	//Function to determine whether the item is the same
	//as the item in the list at the position specified by
	//Postcondition: Returns true if list[location]
	// is the same as the item; otherwise,
	// returns false.
	void insertAt(int location, const elemType& insertItem);
	//Function to insert an item in the list at the
	//position specified by location. The item to be inserted
	//is passed as a parameter to the function.
	//Postcondition: Starting at location, the elements of the
	// list are shifted down, list[location] = insertItem;,
	// and length++;. If the list is full or location is
	// out of range, an appropriate message is displayed.

	int minLocation(int first, int last);
	void swap(int first, int second);
	void selectionSort();
	void insertionSort();
	void shellSort();
	int partition(int first, int last);
	void recQuickSort(int first, int last);
	void quickSort();

	void insertEnd(const elemType& insertItem);
	//Function to insert an item at the end of the list.
	//The parameter insertItem specifies the item to be inserted.
	//Postcondition: list[length] = insertItem; and length++;
	// If the list is full, an appropriate message is
	// displayed.
	void removeAt(int location);
	//Function to remove the item from the list at the
	//position specified by location
	//Postcondition: The list element at list[location] is removed
	// and length is decremented by 1. If location is out of
	// range, an appropriate message is displayed.
	void retrieveAt(int location, elemType& retItem) const;
	//Function to retrieve the element from the list at the
	//position specified by location.
	//Postcondition: retItem = list[location]
	// If location is out of range, an appropriate message is
	// displayed.
	void replaceAt(int location, const elemType& repItem);
	//Function to replace the elements in the list at the
	//position specified by location. The item to be replaced
	//is specified by the parameter repItem.
	//Postcondition: list[location] = repItem
	// If location is out of range, an appropriate message is
	// displayed.
	void clearList();
	//Function to remove all the elements from the list.
	//After this operation, the size of the list is zero.
	//Postcondition: length = 0;
	int seqSearch(const elemType& item) const;
	//Function to search the list for a given item.
	//Postcondition: If the item is found, returns the location
	// in the array where the item is found; otherwise,
	// returns -1.
	void insert(const elemType& insertItem);
	//Function to insert the item specified by the parameter
	//insertItem at the end of the list. However, first the
	//list is searched to see whether the item to be inserted
	//is already in the list.
	//Postcondition: list[length] = insertItem and length++
	// If the item is already in the list or the list
	// is full, an appropriate message is displayed.
	void remove(const elemType& removeItem);
	//Function to remove an item from the list. The parameter
	//removeItem specifies the item to be removed.
	//Postcondition: If removeItem is found in the list,
	// it is removed from the list and length is
	// decremented by one.
	arrayListType(int size = 100);
	//constructor
	//Creates an array of the size specified by the
	//parameter size. The default array size is 100.
	//Postcondition: The list points to the array, length = 0,
	// and maxSize = size
	arrayListType(const arrayListType<elemType>& otherList);
	//copy constructor
	~arrayListType();
	//destructor
	//Deallocates the memory occupied by the array.


protected:
	elemType *list; //array to hold the list elements
	int length; //to store the length of the list
	int maxSize; //to store the maximum size of the list
};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}
template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}
template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}
template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}
template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}
template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
	return(list[location] == item);
}
template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "
		<< "is out of range" << endl;
	else
		if (length >= maxSize) //list is full
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1]; //move the elements down
			list[location] = insertItem; //insert the item at the
										 //specified position
			length++; //increment the length
		}
} //end insertAt
template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize) //the list is full
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem; //insert the item at the end
		length++; //increment the length
	}
} //end insertEnd



template <class elemType>
int arrayListType<elemType>::minLocation(int first, int last)
{
	int minIndex;
	minIndex = first;
	for (int loc = first + 1; loc <= last; loc++)
		if (list[loc] < list[minIndex])
			minIndex = loc;
	return minIndex;
} //end minLocation

template <class elemType>
void arrayListType<elemType>::swap(int first, int second)
{
	elemType temp;
	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}//end swap

template <class elemType>
void arrayListType<elemType>::selectionSort()
{
	int minIndex;
	for (int loc = 0; loc < length - 1; loc++)
	{
		minIndex = minLocation(loc, length - 1);
		swap(loc, minIndex);
	}
}

template <class elemType>
void arrayListType<elemType>::insertionSort()
{
	int firstOutOfOrder, location;
	elemType temp;
	for (firstOutOfOrder = 1; firstOutOfOrder < length;
	firstOutOfOrder++)
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			temp = list[firstOutOfOrder];
			location = firstOutOfOrder;
			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);
			list[location] = temp;
		}
} //end insertionSort

  /*template <class elemType>
  void arrayListType<elemType>::shellSort()
  {
  int inc;
  for (inc = 1; inc < (length - 1) / 9; inc = 3 * inc + 1);
  do
  {
  for (int begin = 0; begin < inc; begin++)
  intervalInsertionSort(begin, inc);
  inc = inc / 3;
  } while (inc > 0);
  } //end shellSort*/

template <class elemType>
int arrayListType<elemType>::partition(int first, int last)
{
	elemType pivot;
	int index, smallIndex;
	swap(first, (first + last) / 2);
	pivot = list[first];
	smallIndex = first;
	for (index = first + 1; index <= last; index++)
		if (list[index] < pivot)
		{
			smallIndex++;
			swap(smallIndex, index);
		}
	swap(first, smallIndex);
	return smallIndex;
}

template <class elemType>
void arrayListType<elemType>::recQuickSort(int first, int last)
{
	int pivotLocation;
	if (first < last)
	{
		pivotLocation = partition(first, last);
		recQuickSort(first, pivotLocation - 1);
		recQuickSort(pivotLocation + 1, last);
	}
}

template <class elemType>
void arrayListType<elemType>::quickSort()
{
	recQuickSort(0, length - 1);
}
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed "
		<< "is out of range" << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
} //end removeAt
template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem) const
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is "
		<< "out of range." << endl;
	else
		retItem = list[location];
} //end retrieveAt
template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is "
		<< "out of range." << endl;
	else
		list[location] = repItem;
} //end replaceAt
template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
} //end clearList
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}
template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete[] list;
}
template <class elemType>
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize]; //create the array
	assert(list != NULL); //terminate if unable to allocate
						  //memory space
	for (int j = 0; j < length; j++) //copy otherList
		list[j] = otherList.list[j];
} //end copy constructor
template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
	if (this != &otherList) //avoid self-assignment
	{
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new elemType[maxSize]; //create the array
		assert(list != NULL); //if unable to allocate memory
							  //space, terminate the program
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}
template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
} //end seqSearch
template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;
	if (length == 0) //list is empty
		list[length++] = insertItem; //insert the item and
									 //increment the length
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		loc = seqSearch(insertItem);
		if (loc == -1) //the item to be inserted
					   //does not exist in the list
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list. No duplicates are allowed." << endl;
	}
} //end insert
template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;
	if (length == 0)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list."
			<< endl;
	}
} //end remove
template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();
	//Default constructor
	//Postcondition: current = NULL;
	linkedListIterator(nodeType<Type> *ptr);
	//Constructor with a parameter.
	//Postcondition: current = ptr;
	Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.
	linkedListIterator<Type> operator++();
	//Overload the preincrement operator.
	//Postcondition: The iterator is advanced to the next node.
	bool operator==(const linkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to
	// the iterator specified by right, otherwise it returns
	// false.
	bool operator!=(const linkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not equal to
	// the iterator specified by right, otherwise it returns
	// false.
	//private:
	nodeType<Type> *current; //pointer to point to the current
							 //node in the linked list
};
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = NULL;
}
template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type> *ptr)
{
	current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}
/*template <class Type>
class linkedListType
{
public:
	//Overload the assignment operator.
	const linkedListType<Type>& operator=
		(const linkedListType<Type>&);
	//Initialize the list to an empty state.
	//Postcondition: first = NULL, last = NULL, count = 0;
	void initializeList();
	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty, otherwise
	// it returns false.
	bool isEmptyList() const;
	//Function to output the data contained in each node.
	//Postcondition: none
	void print() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	int length() const;
	//Function to delete all the nodes from the list.
	//Postcondition: first = NULL, last = NULL, count = 0;
	void destroyList();
	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, the program terminates;
	// otherwise, the first element of the list is returned.
	Type front() const;
	void front(double x);//score modifier

						 //Function to return the last element of the list.
						 //Precondition: The list must exist and must not be empty.
						 //Postcondition: If the list is empty, the program
						 // terminates; otherwise, the last
						 // element of the list is returned.
	Type back() const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	// otherwise the value false is returned.
	virtual bool search(const Type& searchItem) const = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list, last points to
	// the last node in the list, and count is incremented by
	// 1.
	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the end of the list, last points to the
	// last node in the list, and count is incremented by 1.
	virtual void insertLast(const Type& newItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem is
	// deleted from the list. first points to the first node,
	// last points to the last node of the updated list, and
	// count is decremented by 1.
	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to return an iterator at the beginning of the
	//linked list.
	//Postcondition: Returns an iterator such that current is set
	// to first.
	linkedListIterator<Type> begin();
	//Function to return an iterator one element past the
	//last element of the linked list.
	//Postcondition: Returns an iterator such that current is set
	// to NULL.
	linkedListIterator<Type> end();
	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = NULL, last = NULL, count = 0;
	linkedListType();
	//copy constructor
	linkedListType(const linkedListType<Type>& otherList);
	//destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed.
	~linkedListType();
	int count;
protected:
	//variable to store the number of list elements
	//
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last; //pointer to the last node of the list
private:
	void copyList(const linkedListType<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and assigned
	// to this list.
};
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == NULL);
}
template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = NULL;
	last = NULL;
	count = 0;
}
template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp; //pointer to deallocate the memory
						  //occupied by the node
	while (first != NULL) //while there are nodes in the list
	{
		temp = first; //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	last = NULL; //initialize last to NULL; first has already
				 //been set to NULL by the while loop
	count = 0;
}
template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

ostream& operator<< (ostream& osObject,
	const student& rectangle)
{
	osObject << rectangle.name
		/*<< "\t" << rectangle.gpa << "\t" << rectangle.qat << "\t" << rectangle.gender << "\t" << rectangle.note << "\t"<< rectangle.score*//* << endl;
	return osObject;
}
template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list
	current = first; //set current point to the first node
	while (current != NULL) //while more data to print
	{
		cout << current->info;
		//cout << current->info
		current = current->link;
	}
}//end print


template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}
template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != NULL);
	return first->info; //return the info of the first node
}
template<class Type>
void linkedListType<Type>::front(double x)
{
	assert(first != NULL);
	first->info.score = x*first->info.gpa + first->info.qat;
	/*while (first != NULL)
	{
	first->info.score = x;
	first->info = first->link;
	}*//*
}
//end front

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != NULL);
	return last->info; //return the info of the last node
}//end back
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(NULL);
	return temp;
}
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list
	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == NULL) //otherList is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the
								   //list to be copied
		count = otherList.count;
		//copy the first node
		first = new nodeType<Type>; //create the node
		first->info = current->info; //copy the info
		first->link = NULL; //set the link field of the node to NULL
		last = first; //make last point to the first node
		current = current->link; //make current point to the next
								 // node
								 //copy the remaining list
		while (current != NULL)
		{
			newNode = new nodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = NULL; //set the link of newNode to NULL
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to the actual last
							//node
			current = current->link; //make current point to the
									 //next node
		}//end while
	}//end else
}//end copyList
template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}
template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}//end copy constructor
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else
	return *this;
}
//
//
//
//
//
template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
	using linkedListType<Type>::first;
	using linkedListType<Type>::last;
	using linkedListType<Type>::count;
	//using int::count;
public:
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	// otherwise the value false is returned.
	bool search(const Type& searchItem) const;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list, last points to
	// the last node, and count is incremented by 1.
	void insertFirst(const Type& newItem);

	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the end of the list, last points to the
	// last node, and count is incremented by 1.
	void insertLast(const Type& newItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem
	// is deleted from the list. first points to the first
	// node, last points to the last node of the updated
	// list, and count is decremented by 1.
	void deleteNode(const Type& deleteItem);

	//function to divide list
	void divideList(nodeType<Type>* first1, nodeType<Type>*& first2);

	nodeType<Type>* mergeList(nodeType<Type>* first1, nodeType<Type>* first2);

	void recMergeSort(nodeType<Type>* &head);

	void mergeSort();
};

template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;
	current = first; //set current to point to the first
					 //node in the list
	while (current != NULL && !found) //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
									 //the next node
	return found;
}//end search
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = first; //insert newNode before first
	first = newNode; //make first point to the actual first node
	count++; //increment count
	if (last == NULL) //if the list was empty, newNode is also
					  //the last node in the list
		last = newNode;
}//end insertFirst
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = NULL; //set the link field of newNode to NULL
	if (first == NULL) //if the list is empty, newNode is
					   //both the first and last node
	{
		first = newNode;
		last = newNode;
		count++; //increment count
	}
	else //the list is not empty, insert newNode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual
						//last node in the list
		count++; //increment count
	}
}//end insertLast
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;
	if (first == NULL) //Case 1; the list is empty.
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (first->info == deleteItem) //Case 2
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL) //the list has only one node
				last = NULL;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first; //set trailCurrent to point
								  //to the first node
			current = first->link; //set current to point to
								   //the second node
			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while
			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				count--;
				if (last == current) //node to be deleted was the
									 //last node
					last = trailCurrent; //update the value of last
				delete current; //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}//end deleteNode



template <class Type>
void unorderedLinkedList<Type>::divideList(nodeType<Type>* first1, nodeType<Type>* &first2)
{
	nodeType<Type>* middle;
	nodeType<Type>* current;
	if (first1 == NULL) //list is empty
		first2 = NULL;
	else if (first1->link == NULL) //list has only one node
		first2 = NULL;
	else
	{
		middle = first1;
		current = first1->link;
		if (current != NULL) //list has more than two nodes
			current = current->link;
		while (current != NULL)
		{
			middle = middle->link;
			current = current->link;
			if (current != NULL)
				current = current->link;
		} //end while
		first2 = middle->link; //first2 points to the first
							   //node of the second sublist
		middle->link = NULL; //set the link of the last node
							 //of the first sublist to NULL
	} //end else
} //end divideList


template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::mergeList(nodeType<Type>* first1, nodeType<Type>* first2)
{

	nodeType<Type> *lastSmall; //pointer to the last node of
							   //the merged list
	nodeType<Type> *newHead; //pointer to the merged list
	if (first1 == NULL) //the first sublist is empty
		return first2;
	else if (first2 == NULL) //the second sublist is empty
		return first1;
	else
	{
		if (first1->info > first2->info) //compare the first nodes
		{
			newHead = first1;
			first1 = first1->link;
			lastSmall = newHead;
		}
		else
		{
			newHead = first2;
			first2 = first2->link;
			lastSmall = newHead;
		}
		while (first1 != NULL && first2 != NULL)
		{
			if (first1->info > first2->info)
			{
				lastSmall->link = first1;
				lastSmall = lastSmall->link;
				first1 = first1->link;
			}
			else
			{
				lastSmall->link = first2;
				lastSmall = lastSmall->link;
				first2 = first2->link;
			}
		} //end while
		if (first1 == NULL) //first sublist is exhausted first
			lastSmall->link = first2;
		else //second sublist is exhausted first
			lastSmall->link = first1;
		return newHead;
	}
}//end mergeList

template <class Type>
void unorderedLinkedList<Type>::recMergeSort(nodeType<Type>* &head)
{

	nodeType<Type> *otherHead;
	if (head != NULL) //if the list is not empty
		if (head->link != NULL) //if the list has more than one node
		{
			divideList(head, otherHead);
			recMergeSort(head);
			recMergeSort(otherHead);
			head = mergeList(head, otherHead);
		}
} //end recMergeSort

template<class Type>
void unorderedLinkedList<Type>::mergeSort()
{
	recMergeSort(first);
	if (first == NULL)
		last = NULL;
	else
	{
		last = first;
		while (last->link != NULL)
			last = last->link;
	}
} //end mergeSort
*/
/*class graphType
{
public:
	bool isEmpty() const;
	//Function to determine whether the graph is empty.
	//Postcondition: Returns true if the graph is empty;
	// otherwise, returns false.
	void createGraph();
	//Function to create a graph.
	//Postcondition: The graph is created using the
	// adjacency list representation.
	void clearGraph();
	//Function to clear graph.
	//Postcondition: The memory occupied by each vertex
	// is deallocated.
	void printGraph() const;
	//Function to print graph.
	//Postcondition: The graph is printed.
	void depthFirstTraversal();
	//Function to perform the depth first traversal of
	//the entire graph.
	//Postcondition: The vertices of the graph are printed
	// using the depth first traversal algorithm.
	void dftAtVertex(int vertex);
	//Function to perform the depth first traversal of
	//the graph at a node specified by the parameter vertex.
	//Postcondition: Starting at vertex, the vertices are
	// printed using the depth first traversal algorithm.
	//void breadthFirstTraversal();
	//Function to perform the breadth first traversal of
	//the entire graph.
	//Postcondition: The vertices of the graph are printed
	// using the breadth first traversal algorithm.
	graphType(int size = 0);
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	// graph is an array of pointers to linked lists.
	~graphType();
	//Destructor
	//The storage occupied by the vertices is deallocated.
//protected:
	int maxSize; //maximum number of vertices
	int gSize; //current number of vertices
	unorderedLinkedList<int> *graph; //array to create
									 //adjacency lists
private:
	void dft(int v, bool visited[]);
	//Function to perform the depth first traversal of
	//the graph at a node specified by the parameter vertex.
	//This function is used by the public member functions
	//depthFirstTraversal and dftAtVertex.
	//Postcondition: Starting at vertex, the vertices are
	// printed using the depth first traversal algorithm.
};

bool graphType::isEmpty() const
{
	return (gSize == 0);
}

void graphType::createGraph()
{
	ifstream infile;
	char fileName[50];
	int vertex;
	int adjacentVertex;
	if (gSize != 0) //if the graph is not empty, make it empty
		clearGraph();
	cout << "Enter input file name: ";
	cin >> fileName;
	cout << endl;
	infile.open(fileName);
	if (!infile)
	{
		cout << "Cannot open input file." << endl;
		return;
	}
	infile >> gSize; //get the number of vertices
	for (int index = 0; index < gSize; index++)
	{
		infile >> vertex;
		infile >> adjacentVertex;
		while (adjacentVertex != -999)
		{
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		} //end while
	} // end for
	infile.close();
} //end createGraph

void graphType::clearGraph()
{
	for (int index = 0; index < gSize; index++)
		graph[index].destroyList();
	gSize = 0;
} //end clearGraph

void graphType::printGraph() const
{
	for (int index = 0; index < gSize; index++)
	{
		cout << index << " ";
		graph[index].print();
		cout << endl;
	}
	cout << endl;
} //end printGraph

  //Constructor
graphType::graphType(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new unorderedLinkedList<int>[size];
}

//Destructor
graphType::~graphType()
{
	clearGraph();
}

void graphType::dft(int v, bool visited[])
{
	visited[v] = true;
	cout << " " << v << " "; //visit the vertex
	linkedListIterator<int> graphIt;
	//for each vertex adjacent to v
	for (graphIt = graph[v].begin(); graphIt != graph[v].end();
	++graphIt)
	{
		int w = *graphIt;
		if (!visited[w])
			dft(w, visited);
	} //end while
} //end dft

void graphType::depthFirstTraversal()
{
	bool *visited; //pointer to create the array to keep
				   //track of the visited vertices
	visited = new bool[gSize];
	for (int index = 0; index < gSize; index++)
		visited[index] = false;
	//For each vertex that is not visited, do a depth
	//first traverssal
	for (int index = 0; index < gSize; index++)
		if (!visited[index])
			dft(index, visited);
	delete[] visited;
} //end depthFirstTraversal

void graphType::dftAtVertex(int vertex)
{
	bool *visited;
	visited = new bool[gSize];
	for (int index = 0; index < gSize; index++)
		visited[index] = false;
	dft(vertex, visited);
	delete[] visited;
} // end dftAtVertex


void graphType::breadthFirstTraversal()
{
	linkedQueueType<int> queue;
	bool *visited;
	visited = new bool[gSize];
	for (int ind = 0; ind < gSize; ind++)
		visited[ind] = false; //initialize the array
							  //visited to false
	linkedListIterator<int> graphIt;
	for (int index = 0; index < gSize; index++)
		if (!visited[index])
		{
			queue.addQueue(index);
			visited[index] = true;
			cout << " " << index << " ";
			while (!queue.isEmptyQueue())
			{
				int u = queue.front();
				queue.deleteQueue();
				for (graphIt = graph[u].begin();
				graphIt != graph[u].end(); ++graphIt)
				{
					int w = *graphIt;
					if (!visited[w])
					{
						queue.addQueue(w);
						visited[w] = true;
						cout << " " << w << " ";
					}
				}
			} //end while
		}
	delete[] visited;
} //end breadthFirstTraversal*/
/*
class weightedGraphType : public graphType
{
public:
	//Function to create the graph and the weight matrix.
	//Postcondition: The graph using adjacency lists and
	// its weight matrix is created.
	void createWeightedGraph();
	//Function to determine the weight of a shortest path
	//from vertex, that is, source, to every other vertex
	//in the graph.
	//Postcondition: The weight of the shortest path from vertex
	// to every other vertex in the graph is determined.
	void shortestPath(int vertex);
	//Function to print the shortest weight from the vertex
	//specified by the parameter vertex to every other vertex in
	//the graph.
	//Postcondition: The weight of the shortest path from vertex
	// to every other vertex in the graph is printed.
	void printShortestDistance(int vertex);
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	// graph is an array of pointers to linked lists.
	// weights is a two-dimensional array to store the weights
	// of the edges.
	// smallestWeight is an array to store the smallest weight
	// from source to vertices.
	weightedGraphType(int size = 0);
	//Destructor
	//The storage occupied by the vertices and the arrays
	//weights and smallestWeight is deallocated.
	~weightedGraphType();
	
//protected:
	double **weights; //pointer to create weight matrix
	double *smallestWeight; //pointer to create the array to store
							//the smallest weight from source to vertices
};

void weightedGraphType::createWeightedGraph()
{
	ifstream infile;
	char fileName[50];

	int vertexNum, weight;
	int adjacentVertex;
	weightedGraphType weightedNode;	//node holds vertex number and edge weight

	if (gSize != 0)	//if the graph is not empty, make it empty
		clearGraph();


	cout << "Enter input file name: ";
	cin >> fileName;
	cout << endl;

	infile.open(fileName);

	if (!infile)
	{
		cout << "Cannot open input file" << endl;
		return;
	}

	infile >> gSize;	//get the number of vertices

	while (infile >> vertexNum >> adjacentVertex >> weight)
	{
		weightedNode.vertexNum = adjacentVertex;
		weightedNode.weight = weight;
		graph[vertexNum - 1].insertLast(weightedNode);
	} //end while

	infile.close();
} //createWeightedGraph

template < class vType, int size>
void weightedGraphType< vType, size> ::createWeightedGraph()
{
	ifstream infile; 
	char fileName[50]; 
	vType vertex; 
	vType adjacentVertex;
	int distance;
	int edges; 
	if (gSize != 0) //if the graph is not empty, make it empty 27 COS211-X/101
		clearGraph(); 
	cout<< "Enter the input file name: ";
	cin>>fileName;
	cout<<endl; 
	infile.open(fileName);
	if(!infile)
	{ 
		cerr<< "Cannot open the input file."<<endl;
		return; 
	}
	infile>>gSize; //get number of vertices 
	infile>>edges; //get number of edges 
	for(int k = 0; k < gSize;k++) 
		for(int j = 0; j &lt;gSize;j++)
			weights[k][j] = infinity;
	for(int l = 0; l < edges; l++)
	{ 
		infile>>vertex;
		infil>>adjacentVertex; 
		infile>>distance;
		weights[vertex][adjacentVertex] = distance; 
	}
	infile.close(); }//createWeightedGraph 
}


void weightedGraphType::shortestPath(int vertex)
{
	for (int j = 0; j < gSize; j++)
		smallestWeight[j] = weights[vertex][j];
	bool *weightFound;
	weightFound = new bool[gSize];
	for (int j = 0; j < gSize; j++)
		weightFound[j] = false;
	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;
	for (int i = 0; i < gSize - 1; i++)
	{
		double minWeight = DBL_MAX;
		int v;
		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (smallestWeight[j] < minWeight)
				{
					v = j;
					minWeight = smallestWeight[v];
				}
		weightFound[v] = true;
		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
					smallestWeight[j] = minWeight + weights[v][j];
	} //end for
} //end shortestPath

void weightedGraphType::printShortestDistance(int vertex)
{
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex."
		<< endl;
	cout << "Vertex Shortest_Distance" << endl;
	for (int j = 0; j < gSize; j++)
		cout << setw(4) << j << setw(12) << smallestWeight[j]
		<< endl;
	cout << endl;
} //end printShortestDistance

  //Constructor
weightedGraphType::weightedGraphType(int size)
	:graphType(size)
{
	weights = new double*[size];
	for (int i = 0; i < size; i++)
		weights[i] = new double[size];
	smallestWeight = new double[size];
}
//Destructor
weightedGraphType::~weightedGraphType()
{
	for (int i = 0; i < gSize; i++)
		delete[] weights[i];
	delete[] weights;
	delete smallestWeight;
}
*/


int main(int argc, char** argv)
{
	//FILENAME
	//string parameter(argv[1]);
	string parameter("city=Icity.txt;people=Ipeople.txt;visit=Ivisit.txt");
	// find the position of the semicolon
	string::size_type position = parameter.find(';');
	// next line is for display purposes only.
	//cout << "position: " << position << endl;
	// get only the filename via substring. The value of 10 is fixed for hw1 because the parameter always starts with: inputfile=
	string Icity = parameter.substr(5, position - 5);
	// next line is for display purposes only.
	//cout << "Filename: " << filename << endl;

	//PEOPLE
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position2 = parameter.find('=', position);
	// next line is for display purposes only.
	//cout << "position2: " << position2 << endl;
	string poison = parameter.substr(position + 1);
	string::size_type positioner = poison.find(';');
	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string Ipeople = poison.substr(7, positioner - 7);
	//int pick = stoi(pickS);
	// next line is for display purposes only.
	//cout << "size: " << number << endl;


	//VISIT
	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position3 = parameter.find('=', position2 + 1);
	// next line is for display purposes only.
	//cout << "position3: " << position3 << endl;

	string poison3 = parameter.substr(position3);
	string::size_type positioner3 = poison3.find(';');

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string Ivisit = poison3.substr(1, positioner3 - 1);
	// next line is for display purposes only.
	//cout << "schedule: " << number3 << endl;


	ifstream instream(Icity);//Obtain Input Stream
	string line;
	string element;

	
	WeightedGraphType<city, 20> fff;

	fff.createWeightedGraph(instream);

	//fff.printGraph();

	//fff.printShortestDistance();


	//fff.graphType();

	//abc.isEmpty();


	/*while (!instream.eof())
	{
		getline(instream, line, '\n');
		istringstream some(line);
		if (some.peek() != 35 && some.peek() != '\n')// Check if it is a comment
			while (!some.eof()) {// loop for each element
				{
					getline(some, element, '\t');

				}
			}
	}*/

	
	//system("pause");
	return 0;
}
