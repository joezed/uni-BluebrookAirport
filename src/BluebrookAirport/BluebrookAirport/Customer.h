using namespace std;
#include<string>

class User
{
public: 
	string accessLevel; //permission
	string username; //made in CreateCustomer();
	string password; //made in CreateCustomer();

	void Login(string accessLevel, string username, string password);

};

class Permission
{
public:
	int permissionID;

	void loadPermission(int permissionID);
	void searchPermission(int permissionID);
	void storePermission(int permissionID);
};

class Customer
{
public:
	string forename;
	string surname;
	string phone;
	string email;
	string postcode;
	string username;
	string password;

	void CreateCustomer(string forename, string surname, string phone, string email, string postcode, string username, string password);
	void EditCustomer(string forename, string surname, string phone, string email, string postcode, string username, string password);
	void DeleteCustomer(string forename, string surname, string phone, string email, string postcode, string username, string password);

};

class Booking
{
public:
	string bookingDate;
	string bookingTime;
	string bookingFlightInfo;
	string bookingSeatNo;


	void createBooking(string bookingDate, string bookingTime, string bookingFlightInfo, string bookingSeatNo);
	void editBooking(string bookingDate, string bookingTime, string bookingFlightInfo, string bookingSeatNo);
	void removeBooking(string bookingDate, string bookingTime, string bookingFlightInfo, string bookingSeatNo);
	void viewBooking(string bookingDate, string bookingTime, string bookingFlightInfo, string bookingSeatNo);
};

class Flight 

{
public:
	int flightNo;
	string flightDate;
	string flightTime;
	string staff; //who is working on that flight
	string flightLocations; // e.g. from LONDON to PARIS

	void assignStaff(int flightNo, string flightDate, string flightTime, string staff, string flightLocations);
	void displayFlightData(int flightNo, string flightDate, string flightTime, string staff, string flightLocations);
	void choosePlane(int flightNo, string flightDate, string flightTime, string staff, string flightLocations);
};

class Flight

	{
	public:
		string planeNo;
		int planeCapcity;
		bool planeAvailable; //if its at the airport ready to fly or not
	};