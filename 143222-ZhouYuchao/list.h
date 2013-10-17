/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This is just the header file for the functions implemented in list.cpp
(based upon Mike Cameron-Jones' C implementation for KXA251)
Adapted by: Zhou Yuchao
*/

#ifndef _LIST_H
#define _LIST_H

#include "connection.h"

class list
{
private:
	
public:
	connection * first;

	//constructor
	list();
	~list();
	//insert the connection at front
	void insert_at_front(int e,int d);
	//print out the list
	void print();
};

#endif
