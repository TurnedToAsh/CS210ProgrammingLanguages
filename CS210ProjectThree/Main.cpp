/*
* Author: Ashton Sells
* Date: 2024-06-15
* Program: CS210 Module 7 Project Three
*/

/*
* This program implements a menu-driven application that allows users to manage an item tracker.
* The application provides options to search for item frequencies, view all sold items and their frequencies,
* view a histogram of sold items, and exit the program. The item tracker is initialized by loading data from a file.
* The program ensures input validation and user interaction through a console-based menu.
* The main function creates a Menu object and calls the DisplayMenu function to start the application.
*/

#include "Menu.h"

int main() {
	Menu menu; // Create menu object

	menu.DisplayMenu(); // Call the display menu function

	return 0;
}