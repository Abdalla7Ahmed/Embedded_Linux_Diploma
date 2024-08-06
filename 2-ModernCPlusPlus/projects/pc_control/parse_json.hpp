#pragma once

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <map>
#include <variant>
#include <vector>

class Parser
{
private:
    /* data */
    std::string extractJSON(const std::string &input);
    std::map<std::string, std::string> parse_text(std::string json_text);

public:
    Parser(/* args */);

    std::string ReturnOwner(std::string json_text);
    std::string ReturnId(std::string json_text);
    std::string ReturnCommand(std::string json_text);
    std::string ReturnConnectionType(std::string json_text);
    std::string ReturnCommandId(std::string json_text);
    std::string ReturnSiteId(std::string json_text);
    std::string ReturnText(std::string json_text);

    ~Parser();
};
