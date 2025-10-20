#ifndef INTEREST_CALCULATOR_H
#define INTEREST_CALCULATOR_H

#include "Menu.h" // Reference InputData

class InterestCalculator {
public:
	InterestCalculator(const InputData& data); // default constructor that accepts the input
	
	void DisplayStaticReport(bool includeMonthlyDeposits); // Method to calculate and display the monthly/no monthly deposit reports


private:
	InputData input; // Object of InputData to store user's input values
	
};

#endif
