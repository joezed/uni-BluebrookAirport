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

int main() {

	////CREATE TEST PLANES
	//plane A02ERP("A02ERP", 60, 10, 3);
	//plane R73OQL("R73OQL", 60, 10, 3);
	//plane J51CLS("J51CLS", 50, 4, 2);
	//plane H78VFS("H78VFS", 50, 6, 2);

	////CREATE TEST FLIGHTS
	//flight A00001("A00001", J51CLS, "12:02", "16:43");
	//flight A00002("A00002", A02ERP, "06:49", "09:19");
	//flight A00003("A00003", R73OQL, "14:23", "16:22");
	//flight A00004("A00004", H78VFS, "18:21", "19:14");

	////RESET SEATING CHARTS
	////A00001.generateSeatingChart();
	////A00002.generateSeatingChart();
	////A00003.generateSeatingChart();
	////A00004.generateSeatingChart();

	//vector<flight> availableFlights;
	//availableFlights.push_back(A00001);
	//availableFlights.push_back(A00002);
	//availableFlights.push_back(A00003);
	//availableFlights.push_back(A00004);

	//string userFlightSelection;
	//flight currentFlight = A00001;
	//int userRow;
	//int userColumn;
	//bool searchingForFlight = true;
	//bool selectingSeat = true;
	//int i = 0;

	//while (searchingForFlight) {
	//	cout << "What is the ID of the flight you would like to book?" << endl;
	//	cin >> userFlightSelection;
	//	for (i = 0; i < availableFlights.size(); i++) {
	//		if (userFlightSelection == availableFlights[i].flightID) {
	//			flight currentFlight = availableFlights[i];
	//			searchingForFlight = false;
	//			break;
	//		}
	//	}
	//	if (searchingForFlight) {
	//		cout << "That flight does not exist." << endl;
	//	}
	//}

	//while (selectingSeat) {
	//	cout << "Which seat would you like?" << endl;
	//	cout << "" << endl;
	//	currentFlight.printSeatingChart();
	//	cout << string("Row number (1 - ") + to_string(availableFlights[i].rows) + "): ";
	//	cin >> userRow;
	//	cout << string("Column number (1 - ") + to_string(availableFlights[i].columns) + "): ";
	//	cin >> userColumn;
	//	if (userRow >= 1 && userRow <= availableFlights[i].rows && userColumn >= 1 && userColumn <= availableFlights[i].columns && currentFlight.checkSeat(userRow, userColumn)) {
	//		break;
	//	}
	//	else if (userRow > availableFlights[i].rows || userRow < 1) {
	//		cout << "Row does not exist." << endl;
	//	}
	//	else if (userRow > availableFlights[i].columns || userColumn < 1) {
	//		cout << "Column does not exist." << endl;
	//	}
	//	else if (!currentFlight.checkSeat(userRow, userColumn)) {
	//		cout << "Seat is already booked." << endl;
	//	}
	//}

	//currentFlight.addBooking(userRow, userColumn);
	//currentFlight.printSeatingChart();

	plane J51CLS("J51CLS", 50, 4, 2);
	flight A00001("A00001", J51CLS, "12:02", "16:43");
	A00001.createXML();
}