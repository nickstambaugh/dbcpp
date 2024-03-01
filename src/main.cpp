#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Class for file manipulation
class FileManager {
public:
    static std::vector<std::string> readFile(const std::string& filename) {
        std::vector<std::string> lines;
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                lines.push_back(line);
            }
            file.close();
        }
        return lines;
    }

    static bool writeFile(const std::string& filename, const std::vector<std::string>& lines) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& line : lines) {
                file << line << std::endl;
            }
            file.close();
            return true;
        }
        return false;
    }

    static bool deleteData(const std::string& filename, const std::string& dataToDelete) {
        std::vector<std::string> lines = readFile(filename);

        // Remove all occurrences of dataToDelete from lines
        lines.erase(std::remove_if(lines.begin(), lines.end(), [&dataToDelete](const std::string& line) {
            return line == dataToDelete;
        }), lines.end());

        return writeFile(filename, lines);
}

};

// REPL function
void startREPL() {
    // Your REPL logic here
    // Example:
    std::string command;
    std::cout << "Enter a command: ";
    std::cin >> command;

    // Check if the command is for reading, writing, or deleting from a text file
    if (command == "read") {
        std::string filename;
        std::cout << "Enter the filename to read: ";
        std::cin >> filename;
        std::vector<std::string> lines = FileManager::readFile(filename);
        // Process the lines as needed
    } else if (command == "write") {
        std::string filename;
        std::cout << "Enter the filename to write: ";
        std::cin >> filename;
        std::vector<std::string> lines;
        // Populate lines with data to write
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
        // Handle other commands
    }
}


int main() {
    startREPL();
    return 0;
}
