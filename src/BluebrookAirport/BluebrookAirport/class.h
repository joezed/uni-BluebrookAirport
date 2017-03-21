#include <stdio.h>
#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <ctime>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class Account {
	string forename, surname, email, phone, password;
public:
	Account(string forename, string surname, string email, string password);

	void createXML() {

		string forename_temp = forename;
		string surname_temp = surname;
		string email_temp = email;
		string phone_temp = phone;
		string password_temp = password;

		const char * forename = forename_temp.c_str();
		const char * surname = surname_temp.c_str();
		const char * email = email_temp.c_str();
		const char * phone = phone_temp.c_str();
		const char * password = password_temp.c_str();

		FILE * fp;
		fp = fopen("users.xml", "w");
		XMLPrinter printer(fp);


		XMLDocument doc;
		printer.OpenElement("users");
		printer.OpenElement("user");

		printer.OpenElement("forename");
		printer.PushText(forename);
		printer.CloseElement();

		printer.OpenElement("surname");
		printer.PushText(surname);
		printer.CloseElement();

		printer.OpenElement("email");
		printer.PushText(email);
		printer.CloseElement();

		printer.OpenElement("phone");
		printer.PushText(phone);
		printer.CloseElement();

		printer.OpenElement("password");
		printer.PushText(password);
		printer.CloseElement();

		printer.CloseElement();
		printer.CloseElement();

		doc.Print(&printer);
	}
};

class Plane {
	string planeID;
	int rows, columns, aisles;
public:
	Plane(string planeID, int rows, int columns, int aisles);

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

class Flight {
	Plane planeDetails;
	string departureTime, arrivalTime;
public:
	Flight(string flightID, Plane planeDetails, string departureTime, string arrivalTime);
	string flightID;
	int rows, columns, aisles;

	//Generate a new seating chart file
	void generateSeatingChart() {
		ofstream flightFile;
		flightFile.open(flightID + ".txt");
		for (int i = 0; i < (rows * columns) + 1; i++) {
			flightFile << "O" << endl;
		}
		flightFile.close();
	}

	//Print an existing seating chart
	void printSeatingChart() {
		string emptyCheck;
		string tempString;
		string seatingChart;

		ifstream flightFile;
		flightFile.open(flightID + ".txt");

		getline(flightFile, emptyCheck);

		if (emptyCheck == "") {
			generateSeatingChart();
		}

		while (flightFile.is_open()) {
			for (int i = 0; i < columns; i++) {
				for (int j = 0; j < rows; j++) {
					getline(flightFile, tempString);
					seatingChart += tempString;
				}
				seatingChart += "\n";
				if (i == aisles - 1 || i == columns - aisles - 1) {
					seatingChart += "\n";
				}
			}
			flightFile.close();
		}
		cout << seatingChart << endl;
	}

	//Checks to see if a seat is already booked
	bool checkSeat(int row, int column) {
		string seatValue;
		int seatID = ((((column - 1) * rows) + row));

		ifstream flightFile;
		flightFile.open(flightID + ".txt");
		for (int i = 0; i < seatID + 1; i++) {
			getline(flightFile, seatValue);
			if (i == seatID && seatValue == "X") {
				return false;
			}
		}
		return true;
	}

	//Adds a booked seat to the booking chart of a flight
	void addBooking(int row, int column) {
		int seatID = ((((column - 1) * rows) + row));
		string seatValue;
		ifstream inputFlightFile;
		ofstream outputFlightFile;
		inputFlightFile.open(flightID + ".txt");
		outputFlightFile.open(flightID + "-temp.txt");

		while (inputFlightFile.is_open()) {
			for (int i = 0; i < (rows * columns) + 1; i++) {
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

			ifstream  newFile(flightID + "-temp.txt", ios::binary);
			ofstream  oldFile(flightID + ".txt", ios::binary);

			oldFile << newFile.rdbuf();

			oldFile.close();
			newFile.close();
			remove((flightID + "-temp.txt").c_str());
		}
	}

	void createXML() {

		string flightNumber = flightID;
		int rowNumber = rows;
		int colNumber = columns;
		string fileName = flightNumber + ".xml";
		//price
		//firstclass
		//booked
		//userid

		const char * flightID = flightNumber.c_str();
		const char * XMLDoc = fileName.c_str();
		//const char * row = rowNumber.c_str();
		//const char * col = colNumber.c_str();

		FILE * fp;
		fp = fopen(XMLDoc, "w");
		XMLPrinter printer(fp);
		

		XMLDocument doc;
		printer.OpenElement("flights");
		printer.OpenElement("flight");
		printer.PushAttribute("id", flightID);
		printer.OpenElement("seat");

		printer.OpenElement("rows");
		printer.PushText("(Row number)");
		printer.CloseElement();

		printer.OpenElement("cols");
		printer.PushText("(Col number)");
		printer.CloseElement();

		printer.OpenElement("price");
		printer.PushText("(Price)");
		printer.CloseElement();

		printer.OpenElement("firstclass");
		printer.PushText("(True/False)");
		printer.CloseElement();

		printer.OpenElement("booked");
		printer.PushText("(True/False)");
		printer.CloseElement();

		printer.OpenElement("userid");
		printer.PushText("(User ID)");
		printer.CloseElement();

		printer.CloseElement();
		printer.CloseElement();
		printer.CloseElement();

		doc.Print(&printer);
	}

};