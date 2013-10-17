/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This is just the header file for the functions implemented in dijkstra.cpp
*/

#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "map.h"

class dijkstra
{
private:
public:
	map *mapOfAssignment;
	//constructor
	dijkstra(map *m);
	~dijkstra();

	//judge the destination is know or unknow
	bool isKnown(int *knownArr, int arrayLength);
	//update the distance between the destination
	void updateDistance(int destination,int* distanceArr,int* knownArr);
	//return the nearest destination
	int getNearest(int start,int* distanceArr,int* knownArr);
	//return the shortest path
	int* getPath(int start);
};

#endif 