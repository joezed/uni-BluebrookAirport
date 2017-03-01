#include <stdio.h>
#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class plane {
	string planeID;
	int rows, columns, aisles;
public:
	plane(string, int rows, int columns, int aisles);
	int getRows() {
		return rows;
	}
	int getColumns() {
		return columns;
	}
	int getAisles() {
		return aisles;
	}
};

class flight {
	plane planeDetails;
	string departureTime, arrivalTime;
public:
	flight(string flightID, plane planeDetails, string departureTime, string arrivalTime);
	string flightID;
	int rows;
	int columns;
	int aisles;
};