#include "stdafx.h"
#include "class.h"
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() {

	int userInput = 0;
	string username;
	string password;
	bool finished = false;
	Account userAccount("null", "null", "null", "null", "null");

	userAccount.parseXML();

	cout << "Welcome to the Bluebrook airport booking system." << endl;
	cout << "" << endl;
	cout << "MENU:" << endl;
	cout << "1. Log in" << endl;
	cout << "2. Register" << endl;
	cout << "3. Quit" << endl;
	cout << "" << endl;


	while (finished == false) {

		cin >> userInput;

		if (userInput == 1) {
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;

			userAccount.setForename(username);
			finished = true;
		}
		else if (userInput == 2) {

			string forename, surname, phone, email, password1, password2;
			cout << "Please enter your forename: ";
			cin >> forename;

			cout << "\nPlease enter your surname: ";
			cin >> surname;

			cout << "\nPlease enter your phone number: ";
			cin >> phone;
			while (phone.length() != 11)
			{
				cout << "\nINVALID PHONE NUMBER - NOT  11 digits: ";
				cout << "\nPlease enter your phone number: ";
				cin >> phone;
			}

			cout << "\nPlease enter your email address: ";
			cin >> email;

			cout << "\nPlease enter a password: ";
			cin >> password1;

			cout << "\nPlease re-enter a password: ";
			cin >> password2;

			while (password1 != password2)
			{
				cout << " INVALID - Passwords do not match" << endl;
				cout << "\nPlease enter a password: ";
				cin >> password1;
				cout << "\nPlease re-enter a password: ";
				cin >> password2;
			}

			cout << "\n\nACCOUNT SUCCESSFULLY CREATED!" << endl;

			userAccount.setForename(forename);
			userAccount.setSurname(surname);
			userAccount.setEmail(email);
			userAccount.setPhone(phone);
			userAccount.setPassword(password1);
			userAccount.createXML();
			finished = true;

		}
		else if (userInput == 3) {
			return 0;
		}
		else {
			cout << "Please enter a valid number" << endl;
		}
	}

	cout << "Welcome, " + userAccount.getForename() + "." << endl;
	cout << "" << endl;
	cout << "MENU:" << endl;
	cout << "1. Book flight" << endl;
	cout << "2. Check existing bookings" << endl;
	cout << "3. Change user details" << endl;
	cout << "4. Log out" << endl;
	cout << "" << endl;

	////CREATE TEST PLANES
	//Plane A02ERP("A02ERP", 60, 10, 3);
	//Plane R73OQL("R73OQL", 60, 10, 3);
	//Plane J51CLS("J51CLS", 50, 4, 2);
	//Plane H78VFS("H78VFS", 50, 6, 2);

	////CREATE TEST FLIGHTS
	//Flight A00001("A00001", J51CLS, "12:02", "16:43");
	//Flight A00002("A00002", A02ERP, "06:49", "09:19");
	//Flight A00003("A00003", R73OQL, "14:23", "16:22");
	//Flight A00004("A00004", H78VFS, "18:21", "19:14");

	////RESET SEATING CHARTS
	////A00001.generateSeatingChart();
	////A00002.generateSeatingChart();
	////A00003.generateSeatingChart();
	////A00004.generateSeatingChart();

	//vector<Flight> availableFlights;
	//availableFlights.push_back(A00001);
	//availableFlights.push_back(A00002);
	//availableFlights.push_back(A00003);
	//availableFlights.push_back(A00004);
	//

	//string userFlightSelection;
	//Flight currentFlight = A00001;
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
	//			Flight currentFlight = availableFlights[i];
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
	//
	//Plane J51CLS("J51CLS", 50, 4, 2);
	//Flight A00001("A00001", J51CLS, "12:02", "16:43");
	//A00001.createXML();
}