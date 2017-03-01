#include "stdafx.h"
#include "flight.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

plane::plane(string ID = "000000", int r = 0, int c = 0, int a = 0) {
	planeID = ID;
	rows = r;
	columns = c;
	aisles = a;
}

flight::flight(string flightNumber, plane planeInfo, string departure, string arrival) {
	flightID = flightNumber;
	planeDetails = planeInfo;
	departureTime = departure;
	arrivalTime = arrival;
	rows = planeDetails.getRows();
	columns = planeDetails.getColumns();
	aisles = planeDetails.getAisles();
}