#include "stdafx.h"
#include "flight.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//-----------------------------------------------------------------------------
// Name: generateSeatingChart
// Desc: Generate a new seating chart file
//-----------------------------------------------------------------------------

void generateSeatingChart(flight flight) {
	ofstream flightFile;
	flightFile.open(flight.flightID + ".txt");
	for (int i = 0; i < (flight.rows * flight.columns) + 1; i++) {
		flightFile << "O" << endl;
	}
	flightFile.close();
}

//-----------------------------------------------------------------------------
// Name: printSeatingChart
// Desc: Print an existing seating chart
//-----------------------------------------------------------------------------

void printSeatingChart(flight flight) {
	string emptyCheck;
	string tempString;
	string seatingChart;

	ifstream flightFile;
	flightFile.open(flight.flightID + ".txt");

	getline(flightFile, emptyCheck);

	if (emptyCheck == "") {
		generateSeatingChart(flight);
	}

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
// Name: checkSeat
// Desc: Checks to see if a seat is already booked
//-----------------------------------------------------------------------------

bool checkSeat(flight flight, int row, int column) {
	string seatValue;
	int seatID = ((((column - 1) * flight.rows) + row));

	ifstream flightFile;
	flightFile.open(flight.flightID + ".txt");
	for (int i = 0; i < seatID + 1; i++) {
		getline(flightFile, seatValue);
		if (i == seatID && seatValue == "X") {
			return false;
		}
	}
	return true;
}


//-----------------------------------------------------------------------------
// Name: addBooking
// Desc: Adds a booked seat to the booking chart of a flight
//-----------------------------------------------------------------------------

void addBooking(flight flight, int row, int column) {
	int seatID = ((((column - 1) * flight.rows) + row));
	string seatValue;
	ifstream inputFlightFile;
	ofstream outputFlightFile;
	inputFlightFile.open(flight.flightID + ".txt");
	outputFlightFile.open(flight.flightID + "-temp.txt");

	while (inputFlightFile.is_open()) {
		for (int i = 0; i < (flight.rows * flight.columns) + 1; i++) {
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
				outputFlightFile << "X\n";
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


int main() {

	//CREATE TEST PLANES
	plane A02ERP("A02ERP", 60, 10, 3);
	plane R73OQL("R73OQL", 60, 10, 3);
	plane J51CLS("J51CLS", 50, 4, 2);
	plane H78VFS("H78VFS", 50, 6, 2);

	//CREATE TEST FLIGHTS
	flight A00001("A00001", J51CLS, "12:02", "16:43");
	flight A00002("A00002", A02ERP, "06:49", "09:19");
	flight A00003("A00003", R73OQL, "14:23", "16:22");
	flight A00004("A00004", H78VFS, "18:21", "19:14");

	//RESET SEATING CHARTS
	//generateSeatingChart(A00001);
	//generateSeatingChart(A00002);
	//generateSeatingChart(A00003);
	//generateSeatingChart(A00004);

	vector<flight> availableFlights;
	availableFlights.push_back(A00001);
	availableFlights.push_back(A00002);
	availableFlights.push_back(A00003);
	availableFlights.push_back(A00004);

	string userFlightSelection;
	int userRow;
	int userColumn;
	bool searchingForFlight = true;
	bool selectingSeat = true;
	int i = 0;

	while (searchingForFlight) {
		cout << "What is the ID of the flight you would like to book?" << endl;
		cin >> userFlightSelection;
		for (i = 0; i < availableFlights.size(); i++) {
			if (userFlightSelection == availableFlights[i].flightID) {
				searchingForFlight = false;
				break;
			}
		}
		if (searchingForFlight) {
			cout << "That flight does not exist." << endl;
		}
	}

	while (selectingSeat) {
		cout << "Which seat would you like?" << endl;
		cout << "" << endl;
		printSeatingChart(availableFlights[i]);
		cout << string("Row number (1 - ") + to_string(availableFlights[i].rows) + "): ";
		cin >> userRow;
		cout << string("Column number (1 - ") + to_string(availableFlights[i].columns) + "): ";
		cin >> userColumn;
		if (userRow >= 1 && userRow <= availableFlights[i].rows && userColumn >= 1 && userColumn <= availableFlights[i].columns && checkSeat(availableFlights[i], userRow, userColumn)) {
			break;
		}
		else if (userRow > availableFlights[i].rows || userRow < 1) {
			cout << "Row does not exist." << endl;
		}
		else if (userRow > availableFlights[i].columns || userColumn < 1) {
			cout << "Column does not exist." << endl;
		}
		else if (!checkSeat(availableFlights[i], userRow, userColumn)) {
			cout << "Seat is already booked." << endl;
		}
	}

	addBooking(availableFlights[i], userRow, userColumn);
	printSeatingChart(availableFlights[i]);
}