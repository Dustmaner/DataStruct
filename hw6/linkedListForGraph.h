#pragma once
#ifndef H_LinkedListForGraph
#define H_LinkedListForGraph
#include <list>
#include "linkedList.h"

template<class vType>
class linkedListGraph : public linkedListType<vType>
{
public:
	void getAdjacentVertices(vType adjacencyList[],
		int& length);
	//The vertices adjacent to a given vertex from the 
	//linked list are retrieved in the array adjacencyList. 
	//The parameter length specifies the number of vertices
	//adjacent to given vertex.
};


template<class vType>
void linkedListGraph<vType>::getAdjacentVertices(
	vType adjacencyList[], int& length)
{
	nodeType<vType> *current;

	length = 0;
	current = first;

	while (current != NULL)
	{
		adjacencyList[length++] = current->info;
		current = current->link;
	}
}

#endif
