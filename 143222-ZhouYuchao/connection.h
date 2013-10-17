/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This is just the header file for the functions implemented in connection.cpp
*/

#ifndef _CONNECTION_H
#define _CONNECTION_H

class connection
{
public:
	//store the destination 
	int destination;
	//store the distance to the destination
	int roadDistance;
	connection *next;

	//constrctor
	connection();
	connection(int end,int distance);
	~connection();
	//set the destination
	void setDestination(int end);  
	//set the distance to the destination
	void setDistance(int distance); 
	//return the destination
	int getDestination();  
	//return the distance to the destination
	int getDistance(); 
};

#endif