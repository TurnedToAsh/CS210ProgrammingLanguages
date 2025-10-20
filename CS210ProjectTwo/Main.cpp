#include <iostream>
#include "Menu.h"
#include "InterestCalculator.h"

using std::cout;
using std::endl;

int main() {
	// Create an object of the struct for the data input by the user.
	Menu menu;
	InputData data = menu.GetUserInput(); // Prompts the user to input 4 values and returns the struct

	// Calculator object that uses the struct from our InputData for calculations
	InterestCalculator calculator(data);

	// Displays the static reports with and without monthly deposits.
	calculator.DisplayStaticReport(false); // Without monthly deposits
	calculator.DisplayStaticReport(true);  // With monthly deposits

	return 0;
}