#ifndef MENU_H
#define MENU_H

#include <iostream>

// Group data together
struct InputData {
	double openingBalance;
	double monthlyDeposit;
	double interestRate;
	int years;
};

class Menu {
public:
	InputData GetUserInput();
};


#endif

