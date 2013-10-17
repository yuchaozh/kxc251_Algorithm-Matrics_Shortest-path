/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the connection class.
*/

#include<iostream>
#include<string>
#include "connection.h"

//constructor
connection::connection()
{
	destination=0;
	roadDistance=0;
	next=NULL;
}

//constructor
connection::connection(int end,int distance)
{
	destination=end;
	roadDistance=distance;
	next=NULL;
}

//destructor
connection::~connection()
{
}

//set the destination
void connection::setDestination(int end)
{
	destination=end;
}

//set the distance to the destination
void connection::setDistance(int distance)
{
	roadDistance=distance;
}

//return the destination
int connection::getDestination()
{
	return destination;
}

//return the distance to the destination
int connection::getDistance()
{

	return roadDistance;
}
