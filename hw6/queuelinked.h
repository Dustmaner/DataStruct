#pragma once
#ifndef H_queueLinked
#define H_queueLinked

#include <iostream>
#include <cassert>

using namespace std;

struct city
{
	int name = 0;
	int vertexNum = 0;
	int weight = 0;
	
};


ostream& operator<< (ostream& osObject,
	const city& rectangle)
{
	osObject << rectangle.name
		<< "\t" << rectangle.weight << "\t" << rectangle.vertexNum /*<< "\t" << rectangle.gender << "\t" << rectangle.note << "\t"<< rectangle.score*/ << endl;
	return osObject;
}

/*template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};*/

template<class Type>
class queueLinkedType
{
public:
	const queueLinkedType<Type>& operator=(const queueLinkedType<Type>&);

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void destroyQueue();

	void initialiseQueue();

	Type front() const;

	Type back() const;

	void addQueue(const Type& queueElement);

	void deleteQueue();

	queueLinkedType();

	queueLinkedType(const queueLinkedType<Type>& otherQueue);

	~queueLinkedType();

private:
	nodeType<Type> *queueFront;

	nodeType<Type> *queueRear;
};

template<class Type>
queueLinkedType<Type>::queueLinkedType()
{
	queueFront = NULL;
	queueRear = NULL;
}



template<class Type>
bool queueLinkedType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template<class Type>
bool queueLinkedType<Type>::isFullQueue() const
{
	return false;
}

template<class Type>
void queueLinkedType<Type>::destroyQueue()
{
	nodeType<Type> *temp;

	while (queueFront != NULL)
	{
		temp = queueFront;

		queueFront = queueFront->link;

		delete temp;
	}

	queueRear = NULL;
}

template<class Type>
void queueLinkedType<Type>::initialiseQueue()
{
	destroyQueue();
}

template<class Type>
void queueLinkedType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;
	assert(newNode != NULL);

	newNode->info = newElement;
	newNode->link = NULL;

	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}

template<class Type>
Type queueLinkedType<Type>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template<class Type>
Type queueLinkedType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template<class Type>
inline queueLinkedType<Type>::~queueLinkedType()
{
}

/*template<class Type>
void queueLinkedType<Type>::~queueLinkedType()
{
	nodeType<Type> *temp;

	while (queueFront != NULL)
	{
		temp = queueFront;

		queueFront = queueFront->link;

		delete temp;
	}

	queueRear = NULL;
	//delete this;
}*/

template<class Type>
const queueLinkedType<Type>& queueLinkedType<Type>::operator=(const queueLinkedType<Type>& otherQueue)
{
	//overload copy function
}
#endif
