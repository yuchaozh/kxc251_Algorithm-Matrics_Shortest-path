/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This is just the header file for the functions implemented in map.cpp
*/

#ifndef _MAP_H
#define _MAP_H
#include "town.h"

class map
{
public:
	//constructor
	map();
	map(int townSize,int roadSize);
	//destructor
    ~map();
	//add destination
	void addDestination(string name[]);
	//add edge to the conjective list
	void addEdge(int start[],int end[],int distance[]);

	//store the number of the destination
	int getNumberOfDestination();
	//store the scope of the map
	int mapSize;
	//store the number of roads
	int roadSize;
	town *maps;
};

#endif 