#pragma once
#ifndef WeightedGraph_H
#define WeightedGraph_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "graphType.h"

using namespace std;



template <class vType, int size>
class WeightedGraphType : public graphType<vType, size>
{
public:
	void createWeightedGraph();

	void createWeightedGraph(ifstream& x);

	//void createWeightedGraph(ifstream x);
	//The function to create the graph and the weight matrix.
	void shortestPath(vType vertex);
	//The function to determine the smallest weight from, 
	//vertex, that is, the source to every other vertex 
	//in the graph.
	void printShortestDistance(vType vertex);
	//The function to print the shortest weight from the 
	//source to the other vertices in the graph.

protected:
	int weights[size][size];	//weight matrix
	int smallestWeight[size];	//smallest weight from 
								//source to vertices
};

//store graph as adjacency list
template <class vType, int size>
void WeightedGraphType<vType, size>::createWeightedGraph()
{
	string nope;
	ifstream infile;
	char fileName[50];

	int vertexNum, weight;
	int adjacentVertex;
	vType weightedNode;	//node holds vertex number and edge weight

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

	//infile >> gSize;	//get the number of vertices
	gSize = 99;

	while (!infile.eof())
	{
		//cout << infile.peek()<<" a ";
		if (infile.peek() != -1 && infile.peek() != 35 && infile.peek() != '\n')
		{

			infile >> vertexNum >> adjacentVertex >> weight;
			weightedNode.vertexNum = adjacentVertex;
			weightedNode.weight = weight;
			graph[vertexNum - 1].insertLast(weightedNode);
		}
		else
		{
			//cout << infile.peek()<<" b ";
			getline(infile, nope, '\n');
		}
	} //end while

	infile.close();
} //createWeightedGraph

//store graph as adjacency list
template <class vType, int size>
void WeightedGraphType<vType, size>::createWeightedGraph(ifstream& x)
{
	string nope;
	ifstream infile;
	char fileName[50];

	int vertexNum, weight;
	int adjacentVertex;
	vType weightedNode;	//node holds vertex number and edge weight

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

	//infile >> gSize;	//get the number of vertices
	gSize = 99;

	while (!infile.eof())
	{
		//cout << infile.peek()<<" a ";
		if (infile.peek() != -1 && infile.peek() != 35 && infile.peek() != '\n')
		{
			
			infile >> vertexNum >> adjacentVertex >> weight;
			weightedNode.vertexNum = adjacentVertex;
			weightedNode.weight = weight;
			graph[vertexNum - 1].insertLast(weightedNode);
		}
		else
		{
			//cout << infile.peek()<<" b ";
			getline(infile, nope, '\n');
		}
	} //end while

	infile.close();
} //createWeightedGraph


template <class vType, int size>
void WeightedGraphType<vType, size>::shortestPath(vType vertex)
{
	int i, j;
	int v;
	int minWeight;

	for (j = 0; j < graphSize; j++)
		smallestWeight[j] = weights[vertex][j];

	bool weightFound[size];
	for (j = 0; j < graphSize; j++)
		weightFound[j] = false;

	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;

	for (i = 0; i < graphSize - 1; i++)
	{
		minWeight = INFINITY;

		for (j = 0; j < graphSize; j++)
			if (!weightFound[j])
				if (smallestWeight[j] < minWeight)
				{
					v = j;
					minWeight = smallestWeight[v];
				}

		weightFound[v] = true;

		for (j = 0; j < graphSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
					smallestWeight[j] = minWeight + weights[v][j];
	} //end for
} //end shortestPath

template <class vType, int size>
void WeightedGraphType<vType, size>::printShortestDistance
(vType vertex)
{
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest Distance from Source to each Vertex" << endl;
	cout << "Vertex  Shortest_Distance" << endl;

	for (int j = 0; j < graphSize; j++)
		cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
	cout << endl;

}

#endif
