#ifndef MENU_H
#define	MENU_H

#include "ItemTracker.h"

class Menu {
public:
	void InitializeTracker(); // Function to initialize the ItemTracker
	void DisplayMenu(); // Function to display the menu and handle user interaction


private:
	int choice;
	string itemName;
	bool hasDigit;
};

#endif // !1

