#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "FileManager.h"

void startREPL() {
    std::string command;
    std::cout << ">";
    std::cin >> command;

    if (command == "read") {
        std::string filename;
        std::cout << "Enter the filename to read: ";
        std::cin >> filename;
        std::vector<std::string> lines = FileManager::readFile(filename);
    } else if (command == "write") {
        std::string filename;
        std::cout << "Enter the filename to write: ";
        std::cin >> filename;
        std::vector<std::string> lines;
        bool success = FileManager::writeFile(filename, lines);
        if (success) {
            std::cout << "File written successfully!" << std::endl;
        } else {
            std::cout << "Failed to write file." << std::endl;
        }
    } else if (command == "delete") {
        std::string filename, dataToDelete;
        std::cout << "Enter the filename: ";
        std::cin >> filename;
        std::cout << "Enter the data to delete: ";
        std::cin >> dataToDelete;
        bool success = FileManager::deleteData(filename, dataToDelete);
        if (success) {
            std::cout << "Data deleted successfully!" << std::endl;
        } else {
            std::cout << "Failed to delete data." << std::endl;
        }
    } else {
        // todo
    }
}


int main() {
    startREPL();
    return 0;
}
