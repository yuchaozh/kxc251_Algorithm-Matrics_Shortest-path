/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the list class.
(based upon Mike Cameron-Jones' C implementation for KXA251)
Adapted by: Zhou Yuchao
*/

#include<iostream>
using namespace std;
#include<string.h>
#include"list.h"


//constructor
list::list(){
	first = new connection();
	first->next=NULL; 
}

//destructor
list::~list()
{
    connection *current = first;
    while(current)
    {
		connection *toFree = current->next;
		delete toFree;
		current = current->next;
    }
}

//insert the node at front of the list
void list::insert_at_front(int e,int d)
{
	connection *newRoad = new connection(e,d);
		newRoad->next = first->next;
		first->next = newRoad;
}

//print out the list
void list::print()
{
	connection *current = first->next;
    while(current)
    {
		cout<<current->getDestination()<<" "
		<<current->getDistance()<<endl;
		current = current->next;
    }
    cout<<endl;
}