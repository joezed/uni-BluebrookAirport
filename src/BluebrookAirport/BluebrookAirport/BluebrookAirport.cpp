// BluebrookAirport.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class ReservationRecords
{
private:
	struct Flight
	{
		string flightNum;
		int flightSeats;
	};

	struct Record
	{
		string recordName;
		string recordPhone;
		string recordFlightNum;
		string recordDate;
	};

	vector<Flight> FList;
	vector<Record> PList;

public:

	void NewFlight(string FN, int flightSeats)
	{
		for (int i = 0; i < FList.size(); i++)
		{
			if (FN.compare(FList[i].flightNum))
			{
				cout << "Flight already exists" << endl;
				return;Source.cpp
			}
		}

		Flight Addition;
		Addition.flightNum = FN;
		Addition.flightSeats = flightSeats;
		FList.push_back(Addition);
	};

	void add(string recordName, string recordNumber, string recordFlightNum, string recordDate)
	{

	};
};

int main()
{
	string line;
	string filename;
	cout << "Reservations>> ";
	cin >> filename;
	ifstream  myfile(filename); // stream class to read from files
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			cout << line << endl; // temporary to test if file is read.
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	return 0;
}

