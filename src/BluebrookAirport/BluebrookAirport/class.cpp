#include "stdafx.h"
#include "class.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Account::Account(int id, string fore, string sur, string emailAddress, string number, string pass, string auth) {
	forename = fore;
	surname = sur;
	email = emailAddress;
	phone = number;
	password = pass;
	authority = auth;

}

Destination::Destination(string destinationNumber, string place, int flightTime, int distance) {
	destinationID = destinationNumber;
	destination = place;
	avgFlightTime = flightTime;
	flightDistance = distance;
}

Plane::Plane(string ID = "0", int r = 0, int c = 0, int a = 0, string s ="standby", int range = 0) {
	planeID = ID;
	rows = r;
	columns = c;
	aisles = a;
	status = s;
	milerange = range;
	
}

Flight::Flight(string flightNumber, Plane planeInfo, Destination destinationInfo, int departure, int arrival) {
	flightID = flightNumber;
	planeDetails = planeInfo;
	departureTime = departure;
	arrivalTime = departure + destinationInfo.getFlightTime();
	rows = planeDetails.getRows();
	columns = planeDetails.getColumns();
	aisles = planeDetails.getAisles();
}