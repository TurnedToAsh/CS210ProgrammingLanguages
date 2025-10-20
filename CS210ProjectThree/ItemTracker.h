#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

using namespace std;

class ItemTracker {
public:
	void LoadItemsFromFile(const string& fileName);
	void WriteDataToFile(const string& fileName) const;
	int GetItemFrequency(const string& itemName) const;
	void PrintFrequencyList() const;
	void PrintHistogram() const;

private:
	map<string, int> itemFrequency; // Map to store item names and their frequencies
};

#endif // !1

