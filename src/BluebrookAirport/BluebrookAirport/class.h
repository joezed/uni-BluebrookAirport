#include <stdio.h>
#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <ctime>
#include <tuple>
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class Account {
	int id; string forename, surname, email, phone, password, authority;
public:
	Account(int id, string forename, string surname, string email, string phone, string password, string authority);

	void createXML() {

		bool uniqueID = false;
		int id;
		string forename_temp = forename;
		string surname_temp = surname;
		string email_temp = email;
		string phone_temp = phone;
		string password_temp = password;
		string auth_temp = authority;

		const char * forename = forename_temp.c_str();
		const char * surname = surname_temp.c_str();
		const char * email = email_temp.c_str();
		const char * phone = phone_temp.c_str();
		const char * password = password_temp.c_str();
		const char * auth = auth_temp.c_str();

		vector<tuple <string, string, string, string, string, string, string>> testVector = parseXML();
		tuple <string, string, string, string, string, string, string> data;

		XMLDocument xmlDoc;
		XMLNode * pRoot = xmlDoc.NewElement("Users");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement * pElement = xmlDoc.NewElement("User");
		for (int i = 0; i < testVector.size(); i++) {
			data = testVector.at(i);

			const char * eID = get<0>(data).c_str();
			const char * eForename = get<1>(data).c_str();
			const char * eSurname = get<2>(data).c_str();
			const char * eEmail = get<3>(data).c_str();
			const char * ePhone = get<4>(data).c_str();
			const char * ePassword = get<5>(data).c_str();
			const char * eAuth = get<6>(data).c_str();

			pElement->SetAttribute("id", eID);
			pElement->SetAttribute("forename", eForename);
			pElement->SetAttribute("surname", eSurname);
			pElement->SetAttribute("email", eEmail);
			pElement->SetAttribute("phone", ePhone);
			pElement->SetAttribute("password", ePassword);
			pElement->SetAttribute("auth", eAuth);
			pRoot->InsertEndChild(pElement);

			int j = 1;
			while (uniqueID == false) {
				string userID = to_string(j);
				if (searchXML("id", userID) == false) {
					id = j;
					uniqueID = true;
				}
				j++;
			}

			pElement = xmlDoc.NewElement("User");
			pElement->SetAttribute("id", id);
			pElement->SetAttribute("forename", forename);
			pElement->SetAttribute("surname", surname);
			pElement->SetAttribute("email", email);
			pElement->SetAttribute("phone", phone);
			pElement->SetAttribute("password", password);
			pElement->SetAttribute("auth", auth);
			pRoot->InsertEndChild(pElement);
		}

		xmlDoc.SaveFile("DataFiles\\users.xml");

	}

	bool searchXML(string node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("users.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("User");

		const char * searchNode = node.c_str();

		while ((pElement != nullptr) && (pElement->Attribute(searchNode) != nullptr)) {
			string output = pElement->Attribute(searchNode);
			if (value == output) {
				return true;
			}
			pElement = pElement->NextSiblingElement("User");
		}
		return false;
	}

	bool compareXML(string node1, string value1, string node2, string value2) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("users.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("User");

		const char * searchNode1 = node1.c_str();
		const char * searchNode2 = node2.c_str();

		while ((pElement != nullptr) && (pElement->Attribute(searchNode1) != nullptr) && (pElement->Attribute(searchNode2) != nullptr)) {
			string output1 = pElement->Attribute(searchNode1);
			if (value1 == output1) {
				string output2 = pElement->Attribute(searchNode2);
				if (value2 == output2) {
					return true;
				}
			}
			pElement = pElement->NextSiblingElement("User");
		}
		return false;
	}

	vector<tuple <string, string, string, string, string, string, string>> parseXML() {
		vector<tuple <string, string, string, string, string, string, string>> lineOutput;

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("users.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("User");
		while (pElement != nullptr) {
			string IDOut, forenameOut, surnameOut, emailOut, phoneOut, passOut, authOut;
			IDOut = pElement->Attribute("id");
			forenameOut = pElement->Attribute("forename");
			surnameOut = pElement->Attribute("surname");
			emailOut = pElement->Attribute("email");
			phoneOut = pElement->Attribute("phone");
			passOut = pElement->Attribute("password");
			authOut = pElement->Attribute("auth");
			tuple <string, string, string, string, string, string, string> output(IDOut, forenameOut, surnameOut, emailOut, phoneOut, passOut, authOut);
			lineOutput.push_back(output);
			pElement = pElement->NextSiblingElement("User");
		}
		return lineOutput;
	}

	string getForename() {
		return forename;
	}

	void setForename(string name) {
		forename = name;
	}

	void setSurname(string name) {
		surname = name;
	}

	void setEmail(string emailAddress) {
		email = emailAddress;
	}

	void setPhone(string number) {
		phone = number;
	}

	void setPassword(string pass) {
		password = pass;
	}

	void setAuth(string auth) {
		authority = auth;
	}
};

class Destination {
	string destinationID, destination; int avgFlightTime, flightDistance;
public:
	Destination(string destinationID, string destination, int avgFlightTime, int flightDistance);

	tuple <string, string, string> getDestinationInfo(const char * node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("destinations.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("Destination");
		while ((pElement != nullptr) && (pElement->Attribute(node) != nullptr)) {
			if (value == pElement->Attribute(node)) {
				string nameOut, avgFlightTimeOut, distanceOut;
				nameOut = pElement->Attribute(node);
				avgFlightTimeOut = pElement->Attribute("avgflighttimemins");
				distanceOut = pElement->Attribute("miledistance");
				return make_tuple(nameOut, avgFlightTimeOut, distanceOut);
			}
			pElement = pElement->NextSiblingElement("Destination");
		}
	}

	bool searchXML(string node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("destinations.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("Destination");

		const char * searchNode = node.c_str();

		while ((pElement != nullptr) && (pElement->Attribute(searchNode) != nullptr)) {
			string output = pElement->Attribute(searchNode);
			if (value == output) {
				return true;
			}
			pElement = pElement->NextSiblingElement("Destination");
		}
		return false;
	}

	string getID() {
		return destinationID;
	}

	string getDestination() {
		return destination;
	}

	int getFlightTime() {
		return avgFlightTime;
	}

	int getDistance() {
		return flightDistance;
	}

	void setID(string id) {
		destinationID = id;
	}

	void setDestination(string dest) {
		destination = dest;
	}

	void setFlightTime(int time) {
		avgFlightTime = time;
	}

	void setDistance(int dist) {
		flightDistance = dist;
	}
};

class Plane {
	string planeID, status;
	int rows, columns, aisles, milerange;
public:
	Plane(string planeID, int rows, int columns, int aisles, string status, int milerange);

	tuple <string, string, string, string, string, string> getPlaneInfo(const char * node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("planes.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("Plane");
		while ((pElement != nullptr) && (pElement->Attribute(node) != nullptr)) {
			if (value == pElement->Attribute(node)) {
				string idOut, rowsOut, columnsOut, aislesOut, statusOut, milerangeOut;
				idOut = pElement->Attribute("id");
				rowsOut = pElement->Attribute("rows");
				columnsOut = pElement->Attribute("columns");
				aislesOut = pElement->Attribute("aisle");
				statusOut = pElement->Attribute("status");
				milerangeOut = pElement->Attribute("milerange");
				return make_tuple(idOut, rowsOut, columnsOut, aislesOut, statusOut, milerangeOut);
			}
			pElement = pElement->NextSiblingElement("Plane");
		}
	}

	bool searchXML(string node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("planes.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("Plane");

		const char * searchNode = node.c_str();

		while ((pElement != nullptr) && (pElement->Attribute(searchNode) != nullptr)) {
			string output = pElement->Attribute(searchNode);
			if (value == output) {
				return true;
			}
			pElement = pElement->NextSiblingElement("Plane");
		}
		return false;
	}

	string getID() {
		return planeID;
	}

	int getRows() {
		return rows;
	}

	int getColumns() {
		return columns;
	}

	int getAisles() {
		return aisles;
	}

	void setID(string id) {
		planeID = id;
	}

	void setRows(int r) {
		rows = r;
	}

	void setColumns(int c) {
		columns = c;
	}

	void setAisles(int a) {
		aisles = a;
	}

	void setStatus(string s) {
		status = s;
	}

	void setMileRange(int range) {
		milerange = range;
	}


};

class Flight {
	Plane planeDetails;
	Destination destinationDetails;
	int departureTime, arrivalTime;
public:
	Flight(string flightID, Plane planeDetails, Destination destinationDetails, int departureTime, int arrivalTime);
	string flightID;
	int rows, columns, aisles;

	int getLastID() {
		XMLDocument xmlDoc;
		xmlDoc.LoadFile("flights.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("Flight");
		int highestID = 1;

		while ((pElement != nullptr) && (pElement->Attribute("flightID") != nullptr)) {
			string output = pElement->Attribute("flightID");
			if (stoi(output) > highestID) {
				highestID = stoi(output);
			}
			pElement = pElement->NextSiblingElement("Flight");
		}
		return highestID;
	}

	string getID(){
		return flightID;
	}

	void bookSeat(int reference, string user, string flight, string row, string column) {

		const char * cUser = user.c_str();
		const char * cFlight = flight.c_str();
		const char * cRow = row.c_str();
		const char * cColumn = column.c_str();

		vector<tuple <string, string, string, string, string>> testVector = parseSeat();
		tuple <string, string, string, string, string> data;

		XMLDocument xmlDoc;
		XMLNode * pRoot = xmlDoc.NewElement("Flights");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement * pElement = xmlDoc.NewElement("Flight");
		for (int i = 0; i < testVector.size(); i++) {
			data = testVector.at(i);

			const char * eReference = get<0>(data).c_str();
			const char * eUser = get<1>(data).c_str();
			const char * eFlight = get<2>(data).c_str();
			const char * eRow = get<3>(data).c_str();
			const char * eColumn = get<4>(data).c_str();

			pElement->SetAttribute("reference", eReference);
			pElement->SetAttribute("user", eUser);
			pElement->SetAttribute("flight", eFlight);
			pElement->SetAttribute("row", eRow);
			pElement->SetAttribute("column", eColumn);
			pRoot->InsertEndChild(pElement);

			pElement = xmlDoc.NewElement("Flight");
			pElement->SetAttribute("reference", reference);
			pElement->SetAttribute("user", cUser);
			pElement->SetAttribute("flight", cFlight);
			pElement->SetAttribute("row", cRow);
			pElement->SetAttribute("column", cColumn);
			pRoot->InsertEndChild(pElement);
		}

		xmlDoc.SaveFile("seats.xml");

	}

	vector<tuple <string, string, string, string, string>> parseSeat() {
		vector<tuple <string, string, string, string, string>> lineOutput;

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("seats.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("Seat");
		while (pElement != nullptr) {
			string referenceOut, userOut, flightOut, rowOut, columnOut;
			referenceOut = pElement->Attribute("reference");
			userOut = pElement->Attribute("user");
			flightOut = pElement->Attribute("flight");
			rowOut = pElement->Attribute("row");
			columnOut = pElement->Attribute("column");
			tuple <string, string, string, string, string> output(referenceOut, userOut, flightOut, rowOut, columnOut);
			lineOutput.push_back(output);
			pElement = pElement->NextSiblingElement("Seat");
		}
		return lineOutput;
	}

	void createXML() {

		string flightID_temp = flightID;
		string planeID_temp = planeDetails.getID();
		string destination_temp = destinationDetails.getDestination();
		string departureTime_temp = to_string(departureTime);
		string arrivalTime_temp = to_string(arrivalTime);

		const char * flightID = flightID_temp.c_str();
		const char * planeID = planeID_temp.c_str();
		const char * destination = destination_temp.c_str();
		const char * departureTime = departureTime_temp.c_str();
		const char * arrivalTime = arrivalTime_temp.c_str();

		vector<tuple <string, string, string, string, string>> testVector = parseXML();
		tuple <string, string, string, string, string> data;

		XMLDocument xmlDoc;
		XMLNode * pRoot = xmlDoc.NewElement("Flights");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement * pElement = xmlDoc.NewElement("Flight");
		for (int i = 0; i < testVector.size(); i++) {
			data = testVector.at(i);

			const char * eFlightID = get<0>(data).c_str();
			const char * ePlaneID = get<1>(data).c_str();
			const char * eDestination = get<2>(data).c_str();
			const char * eDepartureTime = get<3>(data).c_str();
			const char * eArrivalTime = get<4>(data).c_str();

			pElement->SetAttribute("flightID", eFlightID);
			pElement->SetAttribute("planeID", ePlaneID);
			pElement->SetAttribute("destination", eDestination);
			pElement->SetAttribute("departure", eDepartureTime);
			pElement->SetAttribute("arrival", eArrivalTime);
			pRoot->InsertEndChild(pElement);

			pElement = xmlDoc.NewElement("Flight");
			pElement->SetAttribute("flightID", flightID);
			pElement->SetAttribute("planeID", planeID);
			pElement->SetAttribute("destination", destination);
			pElement->SetAttribute("departure", departureTime);
			pElement->SetAttribute("arrival", arrivalTime);
			pRoot->InsertEndChild(pElement);
		}

		xmlDoc.SaveFile("flights.xml");

	}

	vector<tuple <string, string, string, string, string>> parseXML() {
		vector<tuple <string, string, string, string, string>> lineOutput;

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("flights.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();

		XMLElement * pElement = pRoot->FirstChildElement("Flight");
		while (pElement != nullptr) {
			string flightIDOut, planeIDOut, destinationOut, departureOut, arrivalOut;
			flightIDOut = pElement->Attribute("flightID");
			planeIDOut = pElement->Attribute("planeID");
			destinationOut = pElement->Attribute("destination");
			departureOut = pElement->Attribute("departure");
			arrivalOut = pElement->Attribute("arrival");
			tuple <string, string, string, string, string> output(flightIDOut, planeIDOut, destinationOut, departureOut, arrivalOut);
			lineOutput.push_back(output);
			pElement = pElement->NextSiblingElement("Flight");
		}
		return lineOutput;
	}

	bool searchXML(string node, string value) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("flights.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("Flight");

		const char * searchNode = node.c_str();

		while ((pElement != nullptr) && (pElement->Attribute(searchNode) != nullptr)) {
			string output = pElement->Attribute(searchNode);
			if (value == output) {
				return true;
			}
			pElement = pElement->NextSiblingElement("Flight");
		}
		return false;
	}

	string getXML(string node1, string value1, string node2) {

		XMLDocument xmlDoc;
		xmlDoc.LoadFile("flights.xml");
		XMLNode * pRoot = xmlDoc.FirstChild();
		XMLElement * pElement = pRoot->FirstChildElement("Flight");
		const char * searchNode1 = node1.c_str();
		const char * searchNode2 = node2.c_str();
		string output;

		while ((pElement != nullptr) && (pElement->Attribute(searchNode1) != nullptr) && (pElement->Attribute(searchNode2) != nullptr)) {
			if (value1 == pElement->Attribute(searchNode1)) {
				output = pElement->Attribute(searchNode2);
				return output;
			}
			pElement = pElement->NextSiblingElement("Flight");
		}
	}


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
};