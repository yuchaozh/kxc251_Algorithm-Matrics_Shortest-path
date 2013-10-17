/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the map class.
*/

#include<string>
#include <iostream>
#include "map.h"
using namespace std;

//constructor
map::map()
{
	mapSize=0;
	roadSize=0;
	maps=NULL;
}

map::map(int townSize,int roadSize)
{
	this->mapSize=townSize;
	this->roadSize=roadSize;
	maps=new town[townSize];
}

map::~map()
{
	delete[] maps;
}

//add destination
void map::addDestination(string name[])
{
	for (int i=0;i<mapSize;i++)
	{
		maps[i].setDestinationName(name[i]);
	}
}

//add edge to the conjective list
void map::addEdge(int start[],int end[],int distance[])
{

	for (int j=0;j<roadSize;j++)
	{
		if(distance[j]!=0)
		{
			maps[start[j]].setList(end[j],distance[j]);
			maps[end[j]].setList(start[j],distance[j]);
		}
		else
		{
		}
	}
}

//return the number of the destination
int map::getNumberOfDestination()
{
	return mapSize;
}

