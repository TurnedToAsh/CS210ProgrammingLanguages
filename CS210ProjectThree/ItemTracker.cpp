#include <iostream>
#include <fstream>
#include <iomanip>
#include "ItemTracker.h"

// Load items from a file and count their frequencies
void ItemTracker::LoadItemsFromFile(const string& fileName)
{
	string item;
	ifstream inputFile(fileName);

	// Check if file opened successfully
	if (!inputFile) {
		cerr << "Error opening file." << endl;
		return;
	}

	// Read items and count frequencies. 'item' represents each line(produce) in the file.
	while (getline(inputFile, item)) {
		auto result = itemFrequency.emplace(item, 1); // Try to insert the item with initial frequency 1

		// If the item already exists (because emplace failed), increment its frequency
		if (!result.second) {
			++result.first->second;
		}
	}

	inputFile.close();
}

// Write item frequencies to a file
void ItemTracker::WriteDataToFile(const string& fileName) const
{
	// Open file for writing
	ofstream outputFile(fileName);

	// Check if file opened successfully
	if (!outputFile) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	// Write each item and its frequency to the file
	for (const auto& produceEntry : itemFrequency) {
		outputFile << produceEntry.first << ": " << produceEntry.second << endl; // produceEntry.first is the item name, produceEntry.second is the item frequency
	}
	outputFile.close();
}

int ItemTracker::GetItemFrequency(const string& itemName) const
{
	// Check if item exists in the map and return its frequency
	if (itemFrequency.count(itemName)) {
		return itemFrequency.at(itemName);
	}
	else {
		cout << endl << "No items with the name, " << itemName << ", were sold." << endl; // Inform user if item not found
		return 0; // Item not found
	}
}

void ItemTracker::PrintFrequencyList() const
{
	// Print each item and its frequency
	for (const auto& produceEntry : itemFrequency) {
		cout << produceEntry.first << " " << produceEntry.second << endl;
	}
}

void ItemTracker::PrintHistogram() const
{
	// Print histogram representation of item frequencies
	for (const auto& produceEntry : itemFrequency) {
		cout << left << setw(12) << produceEntry.first << " "; // Set the item name to the left

		// Print asterisks corresponding to the frequency of the item
		for (int i = 0; i < produceEntry.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}
