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

Plane::Plane(string ID = "000000", int r = 0, int c = 0, int a = 0) {
	planeID = ID;
	rows = r;
	columns = c;
	aisles = a;
}

Flight::Flight(string flightNumber, Plane planeInfo, string departure, string arrival) {
	flightID = flightNumber;
	planeDetails = planeInfo;
	departureTime = departure;
	arrivalTime = arrival;
	rows = planeDetails.getRows();
	columns = planeDetails.getColumns();
	aisles = planeDetails.getAisles();
}