#include "parse_json.hpp"

Parser::Parser(/* args */)
{
}

Parser::~Parser()
{
}

std::string Parser::extractJSON(const std::string &input)
{
    std::istringstream iss(input);
    std::string line;
    bool found_json = false;
    std::stringstream json_stream;

    while (std::getline(iss, line))
    {
        if (line.find("{") != std::string::npos)
        {
            found_json = true;
        }

        if (found_json)
        {
            json_stream << line << "\n";
        }

        if (found_json && line.find("}") != std::string::npos)
        {
            break;
        }
    }

    return json_stream.str();
}
std::map<std::string, std::string> Parser::parse_text(std::string json_text)
{
    std::map<std::string, std::string> parsed_json;
    std::string extracted_json = extractJSON(json_text);
    nlohmann::json json_obj = nlohmann::json::parse(extracted_json);

    // Loop through the JSON object and store the key-value pairs in the map
    for (auto &[key, value] : json_obj.items())
    {
        parsed_json[key] = value;
    }

    // // Output the contents of the map
    // for (const auto &[key, value] : parsed_json)
    // {
    //     std::cout << "Key: " << key << ", Value: " << value << "\n";
    // }

    return parsed_json;
}

std::string Parser::ReturnOwner(std::string json_text)
{
    return parse_text(json_text)["Owner"];
}
std::string Parser::ReturnId(std::string json_text)
{
    return parse_text(json_text)["Id"];
}
std::string Parser::ReturnCommand(std::string json_text)
{
    return parse_text(json_text)["Command"];
}
std::string Parser::ReturnConnectionType(std::string json_text)
{
    return parse_text(json_text)["Connection_Type"];
}
std::string Parser::ReturnCommandId(std::string json_text)
{
    return parse_text(json_text)["CommandId"];
}
std::string Parser::ReturnSiteId(std::string json_text)
{
    return parse_text(json_text)["SiteId"];
}

std::string Parser::ReturnText(std::string json_text)
{
    return parse_text(json_text)["Text"];
}

// int main(int argc, const char **argv)
// {

//     std::string json_text = R"({
//         "name": "John",
//         "age": "30",
//         "city": "New York",
//         "is_student": "false",
//         "grades": "int"
//     })";

//     std::string a;
//     std::string command2 = R"(
// user-agent: apitester.org Android/7.5(641)
// accept: */*
// Content-Type: application/json
// Content-Length: 56
// Host: 192.168.1.2:8080
// Connection: Keep-Alive
// Accept-Encoding: gzip

// {
//         "name": "Abdallah",
//         "Id": "0",
//         "command": "YOCTO"
// }
// }
// // )";

//     Parser p;
//     std::map<std::string, std::string> map;
//     map = p.parse_json(command2);

//     for (const auto &[key, value] : map)
//     {
//         std::cout << "Key: " << key << ", Value: " << value << "\n";
//     }

//     return 0;
// }