#include <stdio.h>
#include "stdafx.h"
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
		flight(plane, string, string);
		int rows;
		int columns;
		int aisles;
		void generateSeatingChart(int rows, int columns, int aisles) {
			char ** seatingChart = new char *[columns];

			for (int i = 0; i < columns; i++) {
				seatingChart[i] = new char[rows];

				for (int j = 0; j < rows; j++) {
					seatingChart[i][j] = 'x';
				}
			}

			for (int i = 0; i <columns; i++) {
				for (int j = 0; j < rows; j++) {
					cout << seatingChart[i][j];
				}
				if (i == aisles - 1 || i == columns - aisles - 1) {
					cout << "" << endl;
				}
				cout << "" << endl;
			}
		}
	};

	flight::flight(plane planeInfo, string departure, string arrival) {
		planeDetails = planeInfo;
		departureTime = departure;
		arrivalTime = arrival;
		rows = planeDetails.getRows();
		columns = planeDetails.getColumns();
	aisles = planeDetails.getAisles();
}

/*int main() {
plane testPlane("AAA001", 60, 10, 3);
flight testFlight(testPlane, "12:00", "2:30");
testFlight.generateSeatingChart(testFlight.rows, testFlight.columns, testFlight.aisles);
}*/