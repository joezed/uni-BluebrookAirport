#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <string>
using namespace std;

static const char flightNumChar[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char flightNumInt[] =
"0123456789";

int stringLengthChar = sizeof(flightNumChar) - 1;
int stringLengthInt = sizeof(flightNumInt) - 1;

char genRandomChar()
{
	return flightNumChar[rand() % stringLengthChar];
}

char genRandomInt()
{
	return flightNumInt[rand() % stringLengthInt];
}

string PlaneIDGen()
{
	string PlaneNo;
	for (unsigned int j = 0; j < 1; j++) {
		for (unsigned int i = 0; i < 3; i++)
		{
			PlaneNo += genRandomChar();
		}
		for (unsigned int i = 0; i < 3; i++)
		{
			PlaneNo += genRandomInt();
		}
	}

	return PlaneNo;
}