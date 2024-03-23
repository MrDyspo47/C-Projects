#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Welcome to my to-do list program.\n";

    std::string usrInput;
    std::string line;
    int number_of_lines = 0;
    std::string fileName;
    std::string finalFileName;

    std::cout << "What is the name of your to-do list? : ";
    std::cin >> fileName; // Gets user's custom filename
    std::cin.ignore(); // Clears the newline character left in the input stream
    finalFileName = fileName + ".txt"; // Correctly append ".txt" to form the final filename

    std::ifstream inFile(finalFileName); // Opens the user's filename to count lines

    while (std::getline(inFile, line)) {
        ++number_of_lines;
    }
    inFile.close(); // Close the file after counting lines

    std::fstream newFile;
    newFile.open(finalFileName, std::ios::out | std::ios::app); // Use finalFileName here

    if (newFile.is_open()) {
        while (true) {
            std::cout << "Enter an item for your to-do list (or type 'exit' to finish): ";
            std::getline(std::cin, usrInput); // Use getline to include spaces
            
            if (usrInput == "exit") { // Check if the user wants to exit
                break;
            }

            if (!usrInput.empty()) { // Check if the input is not empty
                ++number_of_lines;
                newFile << number_of_lines << ". " << usrInput << std::endl; // Prepend line number
            }
        }
        newFile.close(); // Close the file after finishing
    } else {
        std::cerr << "Failed to open file for writing.\n";
    }

    return 0;
}
