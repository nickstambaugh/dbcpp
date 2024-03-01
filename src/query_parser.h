#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H

#include <string>

class QueryParser {
public:
    QueryParser();

    std::string parse(const std::string& query);

private:
    // todo
};

#endif
