#include <iostream>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <vector>

// Function to handle client connections
void handle_client(int client_socket)
{
    // Define JSON data to send
    std::string json_data = R"({
        "user": {
            "name": "John Doe",
            "email": "john.doe@example.com"
        },
        "posts": [
            {
                "title": "Post 1",
                "content": "This is the content of post 1."
            },
            {
                "title": "Post 2",
                "content": "This is the content of post 2."
            }
        ]
    })";

    // Prepare HTTP response
    std::string http_response = "HTTP/1.1 200 OK\r\n";
    http_response += "Content-Type: application/json\r\n";
    http_response += "Content-Length: " + std::to_string(json_data.size()) + "\r\n";
    http_response += "Connection: close\r\n";
    http_response += "\r\n"; // End of headers
    http_response += json_data;

    // Read the request from the client
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int n = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (n > 0)
    {
        std::cout << "Received request:" << std::endl;
        // std::cout << buffer << std::endl;

        // // Send response to the client
        // if (send(client_socket, http_response.c_str(), http_response.length(), 0) < 0)
        // {
        //     std::cerr << "Failed to send data" << std::endl;
        // }
    }
    else
    {
        std::cerr << "Error reading from socket" << std::endl;
    }

    // Close the client socket
    close(client_socket);
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
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address

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

    std::vector<std::thread> threads;

    // Main loop to accept and handle multiple connections
    while (true)
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (newsockfd < 0)
        {
            std::cerr << "Error accepting connection" << std::endl;
            continue; // Continue to the next iteration to accept new connections
        }

        std::cout << "Client connected" << std::endl;

        // Spawn a new thread to handle the client
        threads.emplace_back(handle_client, newsockfd);

        // Clean up finished threads
        for (auto &th : threads)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
    }

    // Close the server socket
    close(sockfd);

    return 0;
}
