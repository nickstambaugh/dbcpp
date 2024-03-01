#include <iostream>
#include <string>
#include "database.h"
#include "query_parser.h"

void startREPL() {
    Database db;
    QueryParser parser;

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "exit")
            break;

        std::string sqlQuery = parser.parse(input);
        db.executeQuery(sqlQuery);
    }
}

int main() {
    startREPL();
    return 0;
}
