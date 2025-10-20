/*
    Author: Ashton Sells
    Date: 09/21/2025
    Project: CS 210 Project One
*/

/*
    The purpose of this program is to simulate a clock in both a 12-hour and 24-hour format. The user will visually see both clocks with the current time displayed for both.
    The use will also see a menu with 4 possible choices: add one hour, add one minute, add one second, and exit program. The user will be able to input any of the first
    three options to increment the clock by designated amount of time. when the user inputs 4, the loop will end and the program will terminate. If a number outside of the
    menu selection range or a character is entered, then the user will be prompted to input a valid number.
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Global variables
unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;

// function prototypes
void displayClocks(unsigned int h, unsigned int m, unsigned int s);
void printMenu(char* strings[], unsigned int numStrings, unsigned char width);
void mainMenu();
unsigned int getMenuChoice(unsigned int maxChoice);
unsigned int getHour();
unsigned int getMinute();
unsigned int getSecond();
void setHour(unsigned int h);
void setMinute(unsigned int m);
void setSecond(unsigned int s);

int main() {
    // Retrieves current time
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);

    setHour(localTime.tm_hour);
    setMinute(localTime.tm_min);
    setSecond(localTime.tm_sec);

    // Loop through menu until option 4 is chosen
    while (true) {
        mainMenu(); // Call to our mainMenu() method. 
        break; //Once the loop ends in the mainMenu() method the program will break out of the loop in main().
    }

    return 0;
}

// Function that sets number to a two digit format.
string twoDigitString(unsigned int n) {
    string str;
    if (n >= 0 && n <= 9) {
        str = "0" + to_string(n);
    }
    else {
        str = to_string(n);
    }

    return str;
}

// Function that converts a single character into a string of specified size of the same character.
string nCharString(size_t n, char c) {

    string str(n, c);

    return str;
}

// Format a 24-hour clock;
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string time_24 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return time_24;
}

// Format a 12-hour clock with A M and P M included.
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string period = (h < 12) ? " A M" : " P M";
    h = (h % 12 == 0) ? 12 : h % 12;
    string time_12 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + period;

    return time_12;
}

// Display a visual menu for the user.
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*') << endl;

    // Loop for concatenating the menu items to respective number, spaces, and *
    for (unsigned int i = 0; i < numStrings; ++i) {
        string menuItem = "* ";

        menuItem += to_string(i + 1) + " - " + strings[i]; 

        size_t spacesNeeded = width - menuItem.length() - 1; 

        menuItem += nCharString(spacesNeeded, ' '); 
        menuItem += "*";

        cout << menuItem << endl;

        if (i != numStrings - 1) {
            cout << endl;
        }
    }

    cout << nCharString(width, '*') << endl;
}

// Returns the user input of an unsigned value.
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;

    while (true) {
        cin >> choice;

        if (choice >= 1 && choice <= maxChoice) {
            break;
        }
        // Error handling by clearing input and prompting user to input a valid number
        else {            
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a number between 1 and " << maxChoice << "." << endl; 
        }
    }

    return choice;
}

// Displays updated clock information
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}


// Getters
unsigned int getHour() {
    return hour;
}

unsigned int getMinute() {
    return minute;
}

unsigned int getSecond() {
    return second;
}

// Setters
void setHour(unsigned int h) {
    hour = h;
}

void setMinute(unsigned int m) {
    minute = m;
}

void setSecond(unsigned int s) {
    second = s;
}


// Adding one hour, minute, second, respectively
void addOneHour() {
    unsigned int h = getHour();

    if (h >= 0 && h <= 22) {
        setHour(h + 1);
    }
    else if (h == 23) {
        setHour(0);
    }
}

void addOneMinute() {
    unsigned int m = getMinute();

    if (m >= 0 && m <= 58) {
        setMinute(m + 1);
    }
    else if (m == 59) {
        setMinute(0);
        addOneHour();
    }
}

void addOneSecond() {
    unsigned int s = getSecond();

    if (s >= 0 && s <= 58) {
        setSecond(s + 1);
    }
    else if (s == 59) {
        setSecond(0);
        addOneMinute();
    }
}

// Gets the current time, takes the user's choice, and outputs the updated time.
void mainMenu() {
    unsigned int choice;

    // Create an array of menu options
    char* menuOptions[] = {
        (char*)"Add One Hour",
        (char*)"Add One Minute",
        (char*)"Add One Second",
        (char*)"Exit Program"
    };

    // Initial display of clocks and menu
    displayClocks(getHour(), getMinute(), getSecond());
    printMenu(menuOptions, 4, 27);

    // Loop until exit program (4) is selected. Calls to the add time methods
    do {
        choice = getMenuChoice(4);

        if (choice == 1) {
            addOneHour();
        }
        else if (choice == 2) {
            addOneMinute();
        }
        else if (choice == 3) {
            addOneSecond();
        }
        displayClocks(getHour(), getMinute(), getSecond());
    } while (choice != 4);
}