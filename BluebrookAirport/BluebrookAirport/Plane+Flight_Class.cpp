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
	plane(string, int, int, int);
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

plane::plane(string ID = "000000", int r = 0, int c = 0, int a = 0) {
	planeID = ID;
	rows = r;
	columns = c;
	aisles = a;
}

class flight {
	plane planeDetails;
	string departureTime, arrivalTime;
public:
	flight(string, plane, string, string);
	string flightID;
	int rows;
	int columns;
	int aisles;
};

flight::flight(string flightNumber, plane planeInfo, string departure, string arrival) {
	flightID = flightNumber;
	planeDetails = planeInfo;
	departureTime = departure;
	arrivalTime = arrival;
	rows = planeDetails.getRows();
	columns = planeDetails.getColumns();
	aisles = planeDetails.getAisles();
}

//-----------------------------------------------------------------------------
// Name: generateSeatingChart
// Desc: Generate a new seating chart file
//-----------------------------------------------------------------------------

void generateSeatingChart(flight flight) {
	ofstream flightFile;
	flightFile.open(flight.flightID + ".txt");
	for (int i = 0; i < flight.rows * flight.columns; i++) {
		flightFile << "O" << endl;
	}
	flightFile.close();
}

//-----------------------------------------------------------------------------
// Name: printSeatingChart
// Desc: Print an existing seating chart
//-----------------------------------------------------------------------------

void printSeatingChart(flight flight) {
	string tempString;
	string seatingChart;

	ifstream flightFile;
	flightFile.open(flight.flightID + ".txt");

	while (flightFile.is_open()) {
		for (int i = 0; i < flight.columns; i++) {
			for (int j = 0; j < flight.rows; j++) {
				getline(flightFile, tempString);
				seatingChart += tempString;
			}
			seatingChart += "\n";
			if (i == flight.aisles - 1 || i == flight.columns - flight.aisles - 1) {
				seatingChart += "\n";
			}
		}
		flightFile.close();
	}
	cout << seatingChart << endl;
}

//-----------------------------------------------------------------------------
// Name: addBooking
// Desc: Adds a booked seat to the booking chart of a flight if it is available
//-----------------------------------------------------------------------------

void addBooking(flight flight, int row, int column) {
	int seatID = ((((row - 1) * 5) + column - 1));
	string seatValue;
	ifstream inputFlightFile;
	ofstream outputFlightFile;
	inputFlightFile.open(flight.flightID + ".txt");
	outputFlightFile.open(flight.flightID + "-temp.txt");

	while (inputFlightFile.is_open()) {
		for (int i = 0; i < flight.rows * flight.columns; i++) {
			getline(inputFlightFile, seatValue);
			if (i != seatID) {
				if (seatValue == "O") {
					outputFlightFile << "O\n";
				}
				else if (seatValue == "X") {
					outputFlightFile << "X\n";
				}
			}
			else {
				if (seatValue == "O") {
					outputFlightFile << "X\n";
				}
			}
		}
		inputFlightFile.close();
		outputFlightFile.close();

		ifstream  newFile(flight.flightID + "-temp.txt", ios::binary);
		ofstream  oldFile(flight.flightID + ".txt", ios::binary);

		oldFile << newFile.rdbuf();

		oldFile.close();
		newFile.close();
		remove((flight.flightID + "-temp.txt").c_str());
	}
}


/*int main() {
	plane testPlane("AAA001", 5, 5, 2);
	flight testFlight("FFF999", testPlane, "12:00", "2:30");
	//generateSeatingChart(testFlight);
	//addBooking(testFlight, 1, 1);
	//printSeatingChart(testFlight);
}*/