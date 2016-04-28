#pragma once
#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator=(const linkedListType<Type>&);

	void initialiseList();

	bool isEmptyList() const;

	void print() const;

	int length() const;

	void destroyList();

	Type front() ;

	Type back() ;

	bool search(const Type& searchItem) const;

	void insertFirst(const Type& newItem);

	void insertLast(const Type& newItem);

	void deleteNode(const Type& deleteItem);

	linkedListType();

	linkedListType( linkedListType<Type>& otherList);

	//~linkedListType();

protected:
	int count;

	nodeType<Type> *first;
	nodeType<Type> *last;

private:
	void copyList(const linkedListType<Type>& otherList);

};

template<class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return(first == NULL);
}

template<class Type>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;

	while (first != NULL)
	{
		cout << first << endl;
		temp = first;
		first = first->link;
		delete temp;
	}

	last = NULL;

	count = 0;
}

template<class Type>
void linkedListType<Type>::initialiseList()
{
	destroyList();
}

template<class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current;

	current = first;

	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template<class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template<class Type>
Type linkedListType<Type>::front()
{
	assert(last != NULL);
	return first->info;
}

template<class Type>
Type linkedListType<Type>::back()
{
	assert(last != NULL);
	return last->info;
}

template<class Type>
bool linkedListType<Type>::search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse list
	bool found = false;

	current = first;

	while (current != NULL && !found)
	{
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	}

	return found;
}

template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;

	assert(newNode != NULL);    //if unable to allocate memory,
								//terminate the program
	newNode->info = newItem;
	newNode->link = first;
	first = newNode;

	count++;

	if (last == NULL)    //if the list is empty, newNode is the last node
		last = newNode;
}

template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> * newNode;

	newNode = new nodeType<Type>;

	assert(newNode != NULL);

	newNode->info = newItem;
	newNode->link = NULL;

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		last->link = newNode;
		last = newNode;
		count++;
	}
}

template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	bool found;

	if (first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (first->info == deleteItem)
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL:
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = first;

			current = first->link;

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}

			if (found)
			{
				trailCurrent->link = current->link;
				count--;

				if (last == current)
					last = trailCurrent;

				delete current;
			}
			else
				cout << "The item to be deleted is not in the list" << endl;
		}
	}
}

template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode;
	nodeType<Type> *current;

	if (first != NULL)
		destroyList();

	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;

		count = otherList.count;

		first = new nodeType<Type>;

		assert(first != NULL);

		first->info = current->info;
		first->link = NULL;

		last = first;

		current = current->link;

		while (current != NULL)
		{
			newNode = new nodeType<Type>;

			assert(newNode != NULL);

			newNode->info = current->info;
			newNode->link = NULL;

			last->link = newNode;
			last = newNode;

			curent = current->link;
		}
	}
}
#endif
