#include <iostream>
#include <iomanip>
#include <string>
#include "Menu.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::string;


// Receives input from the user then returns the input as a struct
InputData Menu::GetUserInput()
{
	InputData data;
	int width = 60;
	unsigned int i;
	string message = " Data Input ";

	// Decorative header for aesthetic
	for (i = 0; i < width; ++i) {
		cout << "*";
	}
	cout << endl;

	for (i = 0; i < (width - message.length()) / 2; ++i) {
		cout << "*";
	}

	cout << message;

	for (i = 0; i < (width - message.length()) / 2; ++i) {
		cout << "*";
	}
	
	// The user will input data for the four variables
	cout << endl;
	cout << left << setw(40) << "\nInitial Investment Amount:" << "$";
	cin >> data.openingBalance;
	
	// A while loop is used to catch continuous invalid inputs from the user
	// until the appropriate input is entered.
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nInvalid input detected. Please enter a valid number: $";
		cin >> data.openingBalance;
	}

	cout << endl << left << setw(40) << "Monthly Deposit:" << "$";
	cin >> data.monthlyDeposit;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nInvalid input detected. Please enter a valid number: $";
		cin >> data.monthlyDeposit;
	}

	cout << endl << left << setw(40) << "Annual Interest:" << "%";
	cin >> data.interestRate;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nInvalid input detected. Please enter a valid number: %";
		cin >> data.interestRate;
	}

	cout << endl << left << setw(40) << "Number of years:";
	cin >> data.years;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nInvalid input detected. Please enter a valid number: ";
		cin >> data.years;
	}

	return data; // Returns the struct
}
