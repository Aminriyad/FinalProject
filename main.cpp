#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <limits>

class GrocerTracker {
private:
    std::map<std::string, int> itemFrequency;

public:
    // Read item data from a file and update item frequencies
    void readDataFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string itemName;
        int itemQty;

        while (inputFile >> itemName >> itemQty) {
            itemFrequency[itemName] += itemQty;
        }

        inputFile.close();
    }

    // Save item frequencies to a file
    void saveDataToFile(const std::string& filename) const {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        // Write each item and its frequency to the output file
        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " " << entry.second << std::endl;
        }

        outputFile.close();
    }

    // Print the frequency of a specific item
    void printItemFrequency(const std::string& itemName) const {
        auto it = itemFrequency.find(itemName);
        if (it != itemFrequency.end()) {
            std::cout << "Frequency of " << itemName << ": " << it->second << std::endl;
        } else {
            std::cout << "Item not found: " << itemName << std::endl;
        }
    }

    // Print a list of all item frequencies
    void printAllItemFrequencies() const {
        for (const auto& entry : itemFrequency) {
            std::cout << entry.first << " " << entry.second << std::endl;
        }
    }

    // Print a histogram representing item frequencies
    void printHistogram() const {
        for (const auto& entry : itemFrequency) {
            std::cout << entry.first << " ";
            for (int i = 0; i < entry.second; ++i) {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
};

// Function to get user's choice from the menu
int getUserChoice() {
    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number.\n";
        } else {
            break;
        }
    }

    return choice;
}

int main() {
    GrocerTracker GT;

    GT.readDataFromFile("CS210_Project_Three_Input_File.txt");
    GT.saveDataToFile("frequency.dat");

    int choice;
    do {
        // Display menu
        std::cout << "Menu:\n";
        std::cout << "1. Find item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";

        choice = getUserChoice(); 
        switch (choice) {
            case 1: {
                std::string itemName;
                std::cout << "Enter the item name: ";
                std::cin >> itemName;
                GT.printItemFrequency(itemName);
                break;
            }
            case 2:
                GT.printAllItemFrequencies();
                break;
            case 3:
                GT.printHistogram();
                break;
            case 4:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
