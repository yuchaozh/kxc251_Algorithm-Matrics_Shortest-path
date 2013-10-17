/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This is just the header file for the functions implemented in town.cpp
*/

#ifndef _TOWN_H
#define _TOWN_H

#include<iostream>
#include<string>
#include "list.h"
#include "connection.h"
using namespace std;

class town
{
public:
	list *edges;

	//constructor
	town();
	~town();
	//set the name of the destination
	void setDestinationName(string name);
	//set the information of the destination into the list
	void setList(int end,int distance);
	//return the name of the destination
	string getDestinationName();
	//return the list
	list* getList();

private:
	//store the name of the destination
	string destinationName;
};
#endif 