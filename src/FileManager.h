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