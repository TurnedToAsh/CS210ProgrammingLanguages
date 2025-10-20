#include <iostream>
#include <limits>

#include "Menu.h"

using namespace std;

ItemTracker tracker; // Create an instance of ItemTracker

// Function to initialize the ItemTracker by loading data from file
void Menu::InitializeTracker()
{
    tracker.LoadItemsFromFile("ProduceList.txt");
    tracker.WriteDataToFile("frequency.dat");
}

void Menu::DisplayMenu()
{
    InitializeTracker(); // Ensure tracker is initialized

    do {
        // Implementation of menu display
        cout << endl << "**** Corner Grocer Item Sales Menu ****" << endl;
        cout << "1. Search for frequency of a sold item" << endl;
        cout << "2. View all sold items and frequencies" << endl;
        cout << "3. View histogram of sold items" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option (1-4): ";
        cin >> choice;
        cout << endl;

        // Validate input
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number between 1 and 4." << endl;
            cin >> choice;
        }

        // Handle user choice
        switch (choice) {
        case 1:
            // Get and display item frequency
            cout << endl << "Enter the item name to search." << endl
                << "The first letter is capitalized "
                << "and the word is in plural form." << endl
                << endl << "Example: Potatoes" << endl << endl;
            cin >> itemName;

            // Input validation: check if input is all digits
            hasDigit = true;

            for (char c : itemName) {
                if (!isdigit(c)) {
                    hasDigit = false;

                    break;
                }
            }

            // If input has digits, display error message
            if (hasDigit) {
                cout << endl << "Invalid input. Please enter a valid item name (not a number)." << endl;

                break;
            }

            cout << endl << itemName << ": " << tracker.GetItemFrequency(itemName) << endl;

            break;
        case 2:
            // Display all sold items and their frequencies
            cout << endl << "Displaying all sold items and their frequencies..." << endl << endl;
            tracker.PrintFrequencyList();

            break;
        case 3:
            // Display histogram of sold items
            cout << endl << "Displaying histogram of sold items..." << endl << endl;
            tracker.PrintHistogram();

            break;
        case 4:
            // Exit the program
            cout << endl << "Exiting the program. Goodbye!" << endl;

            break;
        default:
            // Handle invalid choice
            cout << endl << "Invalid number. Please ener a number between 1 and 4." << endl;

            break;
        }

    } while (choice != 4); // Continue until user chooses to exit
}
