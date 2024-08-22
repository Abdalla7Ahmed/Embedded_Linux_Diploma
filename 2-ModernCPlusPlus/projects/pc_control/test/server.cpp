#include <iostream>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <nlohmann/json.hpp>

// Function to handle HTTP GET requests
void handle_http_request(int client_socket)
{
    // Read the request from the client
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0)
    {
        std::cerr << "Error reading from socket or client disconnected" << std::endl;
        return;
    }

    std::cout << "Received from client:" << std::endl;
    std::cout << buffer << std::endl;

    // Prepare JSON data
    nlohmann::json j;
    j["Owner"] = "abdallah";
    j["Id"] = "0";
    j["Command"] = "system_uptime";
    j["connection_status"] = "5_1_introduction 5_2_Discovering 5_3_Discovering2 5_4_bringup 5_5_bringup2 5_6_IOT 5_7_advanced";

    // Convert JSON object to string
    std::string json_data = j.dump();
    std::cout << json_data << std::endl;

    // Prepare HTTP response
    std::string http_response = "HTTP/1.1 200 OK\r\n";
    http_response += "Content-Type: application/json\r\n";
    http_response += "Content-Length: " + std::to_string(json_data.size()) + "\r\n";
    http_response += "Connection: keep-alive\r\n";
    http_response += "\r\n"; // End of headers
    http_response += json_data;

    // Send HTTP response to the client
    if (send(client_socket, http_response.c_str(), http_response.length(), 0) < 0)
    {
        std::cerr << "Failed to send data" << std::endl;
    }
    else
    {
        std::cout << "JSON data sent successfully" << std::endl;
    }
}

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Error opening socket" << std::endl;
        return 1;
    }

    // Define the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);       // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cerr << "Binding failed" << std::endl;
        close(sockfd);
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0)
    {
        std::cerr << "Listening failed" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Server listening on port 8080" << std::endl;

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd < 0)
    {
        std::cerr << "Error accepting connection" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    // Handle HTTP requests in a loop
    while (true)
    {
        handle_http_request(newsockfd);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}
