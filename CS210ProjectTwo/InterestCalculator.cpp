#include "InterestCalculator.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;


// Initializing member: input to take the data struct from menu
InterestCalculator::InterestCalculator(const InputData& data) : input(data) {}

// Use a boolean for including monthly deposits in the static report or not
void InterestCalculator::DisplayStaticReport(bool includeMonthlyDeposits)
{
    double balance = input.openingBalance;
    double monthlyRate = (input.interestRate / 100.0) / 12;
    int totalMonths = input.years * 12;
    int width = 60;
    unsigned int i;

    // Print message depending on if there are monthly deposits
    cout << "\n"
        << (includeMonthlyDeposits ?
            "  Balance and Interest Without Additional Monthly Deposits" :
            "  Balance and Interest With Additional Monthly Deposits") << "\n";

    // Aesthetic for the static report
    for (i = 0; i < width; ++i) {
        cout << "-";
    }

    cout << endl;

    for (i = 0; i < width; ++i) {
        cout << "-";
    }
    
    cout << endl;
    cout << left
        << setw(15) << "Year"
        << setw(25) << "Year End Balance"
        << setw(20) << "Year End Interest" << "\n";

    for (i = 0; i < width; ++i) {
        cout << "-";
    }

    cout << endl;

    // Calculate the year end balance
    for (int year = 1; year <= input.years; ++year) {
        double yearlyInterest = 0; // Reset yearly interest to 0 so each year's interest can be displayed

        for (int month = 1; month <= 12; ++month) {
            if (includeMonthlyDeposits) {
                balance += input.monthlyDeposit; // Monthly deposit added for the static report that displays balance with monthly deposits
            }

            // Formula for compounding interest
            double interest = balance * monthlyRate;
            yearlyInterest += interest; // The value of each year's interest
            balance += interest;
        }

        // Values to only output to two decimal places.
        cout << fixed << setprecision(2);
        cout << setw(15) << year
            << setw(25) << balance
            << setw(20) << yearlyInterest << "\n";
    }
}
