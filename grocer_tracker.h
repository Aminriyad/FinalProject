// grocer_tracker.h

#ifndef GROCER_TRACKER_H
#define GROCER_TRACKER_H

#include <iostream>
#include <fstream>
#include <map>

class GrocerTracker {
private:
    std::map<std::string, int> itemFrequency;  // Map to store item frequencies

public:
    GrocerTracker();  // Constructor (if needed)
    void readDataFromFile(const std::string& filename);  // Read data from a file
    void saveDataToFile(const std::string& filename) const;  // Save data to a file
    void printItemFrequency(const std::string& itemName) const;  // Print frequency of a specific item
    void printAllItemFrequencies() const;  // Print a list of all item frequencies (Menu Option Two)
    void printHistogram() const;  // Print a histogram representing item frequencies
    void printItemFrequencyList() const;  // Print item frequencies as a list (Menu Option Two)
};

#endif // GROCER_TRACKER_H
