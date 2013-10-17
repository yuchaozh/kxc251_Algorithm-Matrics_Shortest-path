/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the town class.
*/

#include "town.h"

//constructor
town::town()
{
	edges=new list();
	destinationName="";
}

town::~town()
{
	delete edges;
}

//set the name of the destination
void town::setDestinationName(string name)
{
	destinationName=name;
}

//set the information of the destination into the list
void  town::setList(int end,int distance)
{
	edges->insert_at_front(end,distance);
}

//return the name of the destination
string town::getDestinationName()
{
	return destinationName;
}

//return the list
list* town::getList()
{
	return edges;
}
