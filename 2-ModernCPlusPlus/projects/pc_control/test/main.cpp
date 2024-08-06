#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "httplib.h"

using json = nlohmann::json;

void handle_request(const httplib::Request &req, httplib::Response &res)
{
    try
    {
        json received_json = json::parse(req.body);
        std::cout << "Received JSON: " << received_json.dump(4) << std::endl;

        // Process the JSON as needed

        // Send a file as response
        std::ifstream file("example.txt", std::ios::binary);
        if (file)
        {
            std::string file_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            res.set_content(file_content, "text/plain");
        }
        else
        {
            res.status = 500;
            res.set_content("File not found", "text/plain");
        }
    }
    catch (const json::parse_error &e)
    {
        res.status = 400;
        res.set_content("Invalid JSON", "text/plain");
    }
}

int main()
{
    httplib::Server svr;
    svr.Post("/api", handle_request);
    std::cout << "Server started at http://192.168.1.2:8080" << std::endl;
    if (!svr.listen("192.168.1.2", 8080))
    {
        std::cerr << "Error starting server!" << std::endl;
        return 1;
    }
    return 0;
}
