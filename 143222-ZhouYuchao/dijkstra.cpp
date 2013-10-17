/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the dijkstra class.
*/

#include<string>
#include "dijkstra.h"

//constructor
dijkstra::dijkstra(map *m)
{
	this->mapOfAssignment=m;
}

dijkstra::~dijkstra()
{

}

//judge the destination is know or unknow
bool dijkstra::isKnown(int* knownArr,int arrayLength)
{
	bool result=0;
	for (int i=0;i<arrayLength;i++)
	{
		if (knownArr[i]==0)
		{
			result=1;
			break;
		}
	}
	return result;
}

//update the distance between the destination
void dijkstra::updateDistance(int destination,int* distanceArr,int* knownArr)
{
	connection *r;
	r=mapOfAssignment->maps[destination].edges->first->next;
	while (r!=0)
	{
		if (knownArr[r->getDestination()]==0)
		{
			if (distanceArr[destination]+r->getDistance()<distanceArr[r->getDestination()])
			{
				distanceArr[r->getDestination()]=distanceArr[destination]+r->getDistance();
			}
		}
		r=r->next;
	}
}

//return the nearest destination
int dijkstra::getNearest(int start,int* distanceArr,int* knownArr)
{
	int min=99999;
	int index = 0;
	for (int i=0;i<mapOfAssignment->getNumberOfDestination();i++)
	{
		if (knownArr[i]==0)
		{
			if (distanceArr[i]<min)
			{
				min=distanceArr[i];
				index=i;
			}
		}
	}
	knownArr[index]=1;
	return index;
}

//return the shortest path
int* dijkstra::getPath(int start)
{
	int *knownArr=new int[mapOfAssignment->getNumberOfDestination()];
	int *distanceArr=new int[mapOfAssignment->getNumberOfDestination()];
	for (int i=0;i<mapOfAssignment->getNumberOfDestination();i++)
	{
		knownArr[i]=0;
		if (i!=start)
		{
			distanceArr[i]=99999;
		}
		else{
			distanceArr[i]=0;
		}
	}
	while(isKnown(knownArr,mapOfAssignment->getNumberOfDestination())==1)
		updateDistance(getNearest(start,distanceArr,knownArr),distanceArr,knownArr);
	return distanceArr;
}
