/*
Author: Zhou Yuchao
Student ID: 143222
Date:12/12/2011
This code is to implement the assignment2 class.
*/

#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>
#include "map.h"
#include "dijkstra.h"
using namespace std;

int main()
{
	//store the name of the destination
	string *destinationName;
	//store the shortest path
	int *shortest;  
	//store the number of destination
	int numberOfDestination=0; 
	//store the number of road
	int numberOfRoad=0;
	//store the origin
	int *roadOfOrigin;  
	//store the destination
	int *roadOfDestination;
	//store the diatance to the destination
	int *roadDistance;
	//sort the order of the array
	int mile;
	string town;

	const char* filename = "D:\\assignment2\\input1.txt";
	//read the text
	ifstream fin(filename);
	fin>>numberOfDestination;
	
	numberOfRoad = numberOfDestination*(numberOfDestination-1)/2;
	destinationName=new string[numberOfDestination];

	for (int i=0;i<numberOfDestination;i++)
	{
		fin>>destinationName[i];
	}
	
	roadOfOrigin=new int[numberOfRoad]; 
	roadOfDestination=new int[numberOfRoad];  
	roadDistance=new int[numberOfRoad];  

	//put the distance into the adjective list
	
	int aa =1;
	for (int j=0;j<7;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 0;
		roadOfDestination[j] = aa;
		aa++;
	}

	aa=2;
	for (int j=7;j<13;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 1;
		roadOfDestination[j] = aa;
		aa++;
	}

	aa=3;
	for (int j=13;j<18;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 2;
		roadOfDestination[j] = aa;
		aa++;
	}

		aa=4;
	for (int j=18;j<22;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 3;
		roadOfDestination[j] = aa;
		aa++;
	}

		aa=5;
	for (int j=22;j<25;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 4;
		roadOfDestination[j] = aa;
		aa++;
	}

		aa=6;
	for (int j=25;j<27;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 5;
		roadOfDestination[j] = aa;
		aa++;
	}

		aa=7;
	for (int j=27;j<28;j++)
	{
		fin>>roadDistance[j];
		roadOfOrigin[j] = 6;
		roadOfDestination[j] = aa;
		aa++;
	}

	//establish the map of this assignment
	map m(numberOfDestination,numberOfRoad);
	m.mapSize = numberOfDestination;
	m.roadSize = numberOfRoad;
	m.addDestination(destinationName);
	m.addEdge(roadOfOrigin,roadOfDestination,roadDistance);

	//use the dijkstra algorithm 
	dijkstra d(&m);
	shortest=new int[m.getNumberOfDestination()];
	for (int k=0;k<m.getNumberOfDestination();k++)
	{
		shortest[k]=0;
	}

	//return the shortest path
	shortest=d.getPath(0);

	//sort the order of the array
	for(int next=0;next<numberOfDestination;next++)
	{
		mile = shortest[next];
		town = m.maps[next].getDestinationName();
		int moveItem = next;
		while((moveItem>0)&&(shortest[moveItem-1]>mile))
		{
			shortest[moveItem] = shortest[moveItem-1];
			m.maps[moveItem] = m.maps[moveItem-1];
			moveItem--;
		}
		shortest[moveItem] = mile;
		m.maps[moveItem].setDestinationName(town);
	}
	cout<<"Shortest path from Burnie to:       "<<endl;
	for (int k=1;k<m.getNumberOfDestination();k++)
	{
		cout<<"  "<<setw(20)<<left<<m.maps[k].getDestinationName()<<shortest[k]<<"Km"<<endl;
	}

	//delete the storage
	delete [] destinationName;
	delete [] roadOfOrigin;
	delete [] roadOfDestination;
	delete [] roadDistance;
	delete [] shortest;

	//the window will not close
	system("pause");
	return 0;
}