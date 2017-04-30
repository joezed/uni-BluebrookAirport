// queue1.cpp : Defines the entry point for the console application.
//
//#define _CRT_NONSTDC_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS_GLOBALS
#include "stdafx.h";
#include "time.h";
// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>
#include <string>
#include <ctime>

using namespace std;         // std::queue




int main()
{
	queue<float> planeQueue;									//initalise queue
	float planeTimes;

	cout << "Please enter some times (enter 0 to end):\n";		//enter flight times

	do {
		cin >> planeTimes;										//input float times
		planeQueue.push(planeTimes);							//push flight times to the queue
	} while (planeTimes);

	cout << "the plane time queue contains: ";				
	while (!planeQueue.empty())									//empty the queue
	{
		cout << ' ' << planeQueue.front();						//output(pop) first value of queue loop
		planeQueue.pop();	
		

	}
	cout << '\n';

	time_t now = time(0);

	cout << "Number of sec since January 1,1970:" << now << endl;
	;
	tm *ltm = localtime(&now);
	int timeYear = 1900 + ltm->tm_year;
	int timeMonth = 1 + ltm->tm_mon;
	int timeDay = ltm->tm_mday;
	int timeHour = 1 + ltm->tm_hour;
	int timeMin = 1 + ltm->tm_min;
	int timeSec = 1 + ltm->tm_sec;
	int TIME1 = ((timeHour) << (timeMin) << (timeSec));

																//char* time1_temp = itoa(1 + ltm->tm_hour);
																//string time1 = string(time1_temp);
																//+ ": "+ (1 + ltm->tm_min) << (1 + ltm->tm_sec);
																// print various components of tm structure.
	/*cout << "Year" << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;*/
																//cout << "THE TIME IS:" << time1 << endl;
	/*cout << "Time: " << 1 + ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl;*/
	cout << "THE TIME IS:" << TIME1 << endl;
	

																// convert now to string form
																//char* dt = ctime(&now);

																//cout << "The local date and time is: " << dt << endl;

																//// convert now to tm struct for UTC
																//tm *gmtm = gmtime(&now);
																//dt = asctime(gmtm);
																//cout << "The UTC date and time is:" << dt << endl;

	return 0;
}