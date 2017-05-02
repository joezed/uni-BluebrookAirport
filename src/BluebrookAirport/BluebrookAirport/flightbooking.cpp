#include "stdafx.h"
#include "class.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <deque>

#define KEY_UP 72
#define KEY_DOWN 80
#define ESC 27

using namespace std;

void quickSort(vector<int>& A, int p, int q);
int partition(vector<int>& A, int p, int q);
string formatTime(int time);

int main() {

	int userInput = 0;
	string email;
	string password;
	bool finished = false;
	string auth = "user";

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

	//A00001.createXML();
	//A00002.createXML();
	//A00003.createXML();
	//A00004.createXML();

	Account userAccount(0, "null", "null", "null", "null", "null", "null");
	Plane tempPlane("1", 50, 6, 2, "standby", 5000);
	Destination testDestination("1", "Glasgow", 70, 237);
	Flight A00001("0", tempPlane, testDestination, 456, 526);

	cout << "Welcome to the Bluebrook airport booking system." << endl;
	cout << "" << endl;
	cout << "MENU:" << endl;
	cout << "1. Log in" << endl;
	cout << "2. Register" << endl;
	cout << "3. Quit" << endl;
	cout << "" << endl;


	//---------------------------------------------------------------------------------------------------------------------------
	// Name: LOG IN
	// Description: User enters email and password, which is validated if they are found in the XML file
	//              If Successful user proceeds through the system
	//----------------------------------------------------------------------------------------------------------------------------


	while (finished == false) {

		cin >> userInput;

		if (userInput == 1) {
			cout << "Email: ";
			cin >> email;
			cout << "Password: ";
			cin >> password;

			while (userAccount.compareXML("email", email, "password", password) == false) {
				cout << "\nINVALID LOG IN";
				cout << "\nEmail: ";
				cin >> email;
				cout << "Password: ";
				cin >> password;
			}

			if (userAccount.compareXML("email", email, "auth", "admin")) {
				auth = "admin";
			}
			else if (userAccount.compareXML("email", email, "auth", "staff")) {
				auth = "staff";
			}

			finished = true;
		}


		//---------------------------------------------------------------------------------------------------------------------------
		// Name: CREATE ACCOUNT
		// Description: User enters details to be saved in XML file
		//----------------------------------------------------------------------------------------------------------------------------

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
				cout << "\nINVALID PHONE NUMBER - NOT  11 DIGITS";
				cout << "\nPlease enter your phone number: ";
				cin >> phone;
			}

			cout << "\nPlease enter your email address: ";
			cin >> email;
			while (userAccount.searchXML("email", email) == true) {
				cout << "\nINVALID EMAIL - ALREADY IN USE";
				cout << "\nPlease enter your email address: ";
				cin >> email;
			}

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
			userAccount.setAuth("user");
			userAccount.createXML();
			finished = true;

		}

		//---------------------------------------------------------------------------------------------------------------------------
		// Name: EXIT
		// Description: user exits the system when ‘3’ is entered on the main menu
		//----------------------------------------------------------------------------------------------------------------------------

		else if (userInput == 3) {
			return 0;
		}
		else {
			cout << "Please enter a valid number" << endl;
		}
	}

	finished = false;
	string flightNo;

	//---------------------------------------------------------------------------------------------------------------------------
	// Name: ADMIN MENU
	// Description: if user log entered, admin menu appears with additional admin specific features 
	//----------------------------------------------------------------------------------------------------------------------------

	if (auth == "admin") {
		cout << "Welcome, " + email + "." << endl;
		cout << "" << endl;
		cout << "MENU:" << endl;
		cout << "1. View flight" << endl;
		cout << "2. Create flight" << endl;
		cout << "3. Log out" << endl;
		cout << "" << endl;

		while (finished == false)

			//---------------------------------------------------------------------------------------------------------------------------
			// Name: VIEW FLIGHTS
			// Description: User enters flight ID, XML file is searches for flight/displays its data
			//----------------------------------------------------------------------------------------------------------------------------


		{

			cin >> userInput;


			if (userInput == 1) {
				cout << "Enter the flight number of the flight you want to view" << endl;
				cin >> flightNo;

				while (!A00001.searchXML("flightID", flightNo)) {
					cout << "Invalid flight number." << endl;
					cout << "Enter the flight number of the flight you want to view" << endl;
					cin >> flightNo;
				}

				cout << "Flight Number: " + flightNo << endl;
				cout << "Plane Number: " + A00001.getXML("flightID", flightNo, "planeID") << endl;
				cout << "Destination: " + A00001.getXML("flightID", flightNo, "destination") << endl;
				cout << "Departure Time: " + formatTime(stoi(A00001.getXML("flightID", flightNo, "departure"))) << endl;
				cout << "Arrival Time: " + formatTime(stoi(A00001.getXML("flightID", flightNo, "arrival"))) << endl;
			}

			//---------------------------------------------------------------------------------------------------------------------------
			// Name: ADD FLIGHT
			// Description: Admin is able add a new flight to the XML flights file
			//----------------------------------------------------------------------------------------------------------------------------

			else if (userInput == 2) {
				string planeID;
				string destination;
				int departure;
				int departureHour;
				int departureMinute;

				cout << "Enter plane ID: ";
				cin >> planeID;
				while (!tempPlane.searchXML("id", planeID)) {
					cout << "That plane doesn't exist." << endl;
					cout << "Enter plane ID: ";
					cin >> planeID;
				}
				cout << "Enter destination: ";
				cin >> destination;
				while (!testDestination.searchXML("name", destination)) {
					cout << "That destination doesn't exist." << endl;
					cout << "Enter destination: ";
					cin >> destination;
				}
				cout << "Enter departure hour: ";
				cin >> departureHour;
				if (departureHour > 24 || departureHour < 0) {
					cout << "That time doesn't make sense." << endl;
					cout << "Enter departure hour: ";
					cin >> departureHour;
				}

				cout << "Enter departure minute: ";
				cin >> departureMinute;
				if (departureMinute > 59 || departureHour < 0) {
					cout << "That time doesn't make sense." << endl;
					cout << "Enter departure minute: ";
					cin >> departureMinute;
				}

				departure = (departureHour * 60) + departureMinute;
				tuple <string, string, string, string, string, string> planeData = tempPlane.getPlaneInfo("id", planeID);
				tuple <string, string, string> destinationData = testDestination.getDestinationInfo("name", destination);
				Destination tempDestination("a", "a", 1, 1);

				tempPlane.setID(get<0>(planeData));
				tempPlane.setRows(stoi(get<1>(planeData)));
				tempPlane.setColumns(stoi(get<2>(planeData)));
				tempPlane.setAisles(stoi(get<3>(planeData)));
				tempPlane.setStatus(get<4>(planeData));
				tempPlane.setMileRange(stoi(get<5>(planeData)));
				tempDestination.setDestination(get<0>(destinationData));
				tempDestination.setFlightTime(stoi(get<1>(destinationData)));
				tempDestination.setDistance(stoi(get<2>(destinationData)));
				string newFlightID = to_string(A00001.getLastID() + 1);
				Flight createdFlight(newFlightID, tempPlane, tempDestination, departure, departure);
				createdFlight.createFlightXML(get<0>(destinationData));
			}
			else if (userInput == 3) {
				return 0;
			}
			else {
				return 0;
			}
		}
	}

	//---------------------------------------------------------------------------------------------------------------------------
	// Name: STAFF MENU
	// Description: if user log in entered is a staff log in staff specific menus displays
	//----------------------------------------------------------------------------------------------------------------------------



	else if (auth == "staff") {
		//cout << "Welcome, " + userAccount.getForename() + "." << endl;
		//cout << "" << endl;
		//cout << "MENU:" << endl;
		//cout << "1. View flight list" << endl;
		//cout << "2. Book flight" << endl;
		//cout << "3. Check existing bookings" << endl;
		//cout << "4. Change user details" << endl;
		//cout << "5. Log out" << endl;
		//cout << "" << endl;

	}

	else {
		cout << "Welcome, " + userAccount.getEmail() + "." << endl;
		cout << "" << endl;
		cout << "MENU:" << endl;
		cout << "1. View flight list" << endl;
		cout << "2. Book flight" << endl;
		cout << "3. Log out" << endl;
		cout << "" << endl;

		while (finished == false) {

			cin >> userInput;

			if (userInput == 1) {
				int offset = 0;
				int push_front_pos = 0;
				int push_back_pos = 10;
				vector<int> A = A00001.getFlightTimes();
				int p = 0;
				int q = A.size();
				quickSort(A, p, q);
				//vector A is sorted
				deque<int> queue;
				for (int i = 0; i < 10; i++) {
					queue.push_back(A.at(i));
				}
				//deque is filled with first 10 values of A

				int c = 0;


				system("CLS");
				tuple <string, string, string, string, string> flightData;
				cout << "TODAYS FLIGHTS" << endl;
				cout << "FlightID        Destination                     Departure Time          Expected Arrival Time" << endl;
				for (auto e : queue) {
					flightData = A00001.getFlightInfo("departure", to_string(e));
					string tabspacing = "\t\t\t\t";
					if (get<2>(flightData).length() > 8) {
						tabspacing = "\t\t\t";
					}
					cout << get<0>(flightData) + "\t\t" + get<2>(flightData) + tabspacing + formatTime(stoi(get<3>(flightData))) + "\t\t\t" + formatTime(stoi(get<4>(flightData))) << endl;
					cout << "" << flush;
				}
				cout << "USE ARROW KEYS TO MOVE THROUGH BOOKINGS AND PRESS ESCAPE TO EXIT" << endl;

				bool cont = true;
				while (cont == true) {
					switch ((c = _getch())) {
					case KEY_UP:
						if (offset - 1 >= 0) {
							system("CLS");
							push_front_pos -= 1;
							push_back_pos -= 1;
							offset -= 1;
							queue.pop_back();
							queue.push_front(A.at(push_front_pos));

							tuple <string, string, string, string, string> flightData;
							cout << "TODAYS FLIGHTS" << endl;
							cout << "FlightID        Destination                     Departure Time          Expected Arrival Time" << endl;
							for (auto e : queue) {
								flightData = A00001.getFlightInfo("departure", to_string(e));
								string tabspacing = "\t\t\t\t";
								if (get<2>(flightData).length() > 8) {
									tabspacing = "\t\t\t";
								}
								cout << get<0>(flightData) + "\t\t" + get<2>(flightData) + tabspacing + formatTime(stoi(get<3>(flightData))) + "\t\t\t" + formatTime(stoi(get<4>(flightData))) << endl;
								cout << "" << flush;
							}
							cout << "USE ARROW KEYS TO MOVE THROUGH BOOKINGS AND PRESS ESCAPE TO EXIT" << endl;
						}
						break;
					case KEY_DOWN:
						if (offset + 1 < A.size() - 10) {
							system("CLS");
							push_front_pos += 1;
							push_back_pos += 1;
							offset += 1;
							queue.pop_front();
							queue.push_back(A.at(push_back_pos));

							tuple <string, string, string, string, string> flightData;
							cout << "TODAYS FLIGHTS" << endl;
							cout << "FlightID        Destination                     Departure Time          Expected Arrival Time" << endl;
							for (auto e : queue) {
								flightData = A00001.getFlightInfo("departure", to_string(e));
								string tabspacing = "\t\t\t\t";
								if (get<2>(flightData).length() > 8) {
									tabspacing = "\t\t\t";
								}
								cout << get<0>(flightData) + "\t\t" + get<2>(flightData) + tabspacing + formatTime(stoi(get<3>(flightData))) + "\t\t\t" + formatTime(stoi(get<4>(flightData))) << endl;
								cout << "" << flush;
							}
							cout << "USE ARROW KEYS TO MOVE THROUGH BOOKINGS AND PRESS ESCAPE TO EXIT" << endl;
						}
						break;
					case ESC:
						cont = false;
						break;
					}
				}
			}

			//---------------------------------------------------------------------------------------------------------------------------
			// Name: BOOK A FLIGHT
			// Description:
			//----------------------------------------------------------------------------------------------------------------------------


			else if (userInput == 2) {
				string row;
				string column;

				cout << "Enter the flight number of the flight you want to book:" << endl;

				cin >> flightNo;

				while (!A00001.searchXML("flightID", flightNo)) {
					cout << "That flight doesn't exist." << endl;
					cout << "Enter the flight number of the flight you want to book:" << endl;
					cin >> flightNo;
				}

				cout << "Flight Number: " + flightNo << endl;
				cout << "Plane Number: " + A00001.getXML("flightID", flightNo, "planeID") << endl;
				cout << "Destination: " + A00001.getXML("flightID", flightNo, "destination") << endl;
				cout << "Departure Time: " + formatTime(stoi(A00001.getXML("flightID", flightNo, "departure"))) << endl;
				cout << "Arrival Time: " + formatTime(stoi(A00001.getXML("flightID", flightNo, "arrival"))) << endl;
				finished = false;
				while (finished == false) {
					cout << "Enter the row of the seat you want:" << endl;
					cin >> row;
					cout << "Enter the column of the seat you want:" << endl;
					cin >> column;

					while(A00001.isSeatTaken(flightNo, row, column)) {
						cout << "That seat is taken. Choose another?" << endl;
						cout << "1. Yes" << endl;
						cout << "2. No" << endl;
						cin >> userInput;
						if (userInput == 1) {
							cout << "Enter the row of the seat you want:" << endl;
							cin >> row;
							cout << "Enter the column of the seat you want:" << endl;
							cin >> column;
						}
						if (userInput == 2) {
							finished = true;
						}
						finished = true;
					}

					tuple <string, string, string, string, string, string> planeData = tempPlane.getPlaneInfo("id", A00001.getXML("flightID", flightNo, "planeID"));
					tuple <string, string, string> destinationData = testDestination.getDestinationInfo("name", A00001.getXML("flightID", flightNo, "destination"));
					tempPlane.setID(get<0>(planeData));
					tempPlane.setRows(stoi(get<1>(planeData)));
					tempPlane.setColumns(stoi(get<2>(planeData)));
					tempPlane.setAisles(stoi(get<3>(planeData)));
					tempPlane.setStatus(get<4>(planeData));
					tempPlane.setMileRange(stoi(get<5>(planeData)));
					testDestination.setDestination(get<0>(destinationData));
					testDestination.setFlightTime(stoi(get<1>(destinationData)));
					testDestination.setDistance(stoi(get<2>(destinationData)));
					int departure = stoi(A00001.getXML("flightID", flightNo, "departure"));
					int arrival = departure + stoi(get<1>(destinationData));
					Flight createdFlight("1", tempPlane, testDestination, departure, arrival);
					createdFlight.bookSeat(1, "1", createdFlight.getID(), row, column);
				}
			}


			else if (userInput == 3) {
				return 0;
			}
			else {
				cout << "Please enter a valid number" << endl;
			}
		}

	}

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

//---------------------------------------------------------------------------------------------------------------------------
// Name: FORMAT TIME
// Description:
//----------------------------------------------------------------------------------------------------------------------------


string formatTime(int time) {
	string hours = to_string(time / 60);
	string minutes = to_string(time % 60);
	if (hours.length() == 1) {
		hours = "0" + hours;
	}
	if (minutes.length() == 1) {
		minutes = "0" + minutes;
	}
	return hours + ":" + minutes;
}

//---------------------------------------------------------------------------------------------------------------------------
// Name: QUICK SORTING ALGORITHM 
// Description:
//----------------------------------------------------------------------------------------------------------------------------


void quickSort(vector<int>& A, int p, int q)
{
	int r;
	if (p < q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}


//---------------------------------------------------------------------------------------------------------------------------
// Name: PARTITION 
// Description:
//----------------------------------------------------------------------------------------------------------------------------


int partition(vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j < q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			swap(A[i], A[j]);
		}

	}

	swap(A[i], A[p]);
	return i;
}