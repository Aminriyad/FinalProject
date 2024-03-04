#include "grocer_tracker.h"

// This function prints a list showing each item and the number of times it was purchased.
void GrocerTracker::printItemFrequencyList() const {
    // Iterate through each item-frequency pair in the 'itemFrequency' map.
    for (const auto& entry : itemFrequency) {
        // Print the item name, a space, and the number of times it was purchased.
        std::cout << entry.first << " " << entry.second << std::endl;
    }
}
