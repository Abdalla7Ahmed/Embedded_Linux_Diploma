#include "SocketHandler.hpp"

std::string SocketHandler::json_data{};
Parser SocketHandler::m_parser{};
Commands SocketHandler::m_commands{};
SocketHandler::SocketHandler()
{
}

SocketHandler::~SocketHandler()
{
    close(sockfd);
    // close(client_socket);
    clean_up_threads();
}

void SocketHandler::set_sockfd(int sockfd)
{
    this->sockfd = sockfd;
}

int SocketHandler::get_sockfd(void)
{
    return this->sockfd;
}
int SocketHandler::get_client_socket(void)
{
    return client_socket;
}

int SocketHandler::createSocket(void)
{
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        std::cerr << "Error opening socket" << std::endl;
        return 1;
    }
    return 0;
}

void SocketHandler::Define_server_address(void)
{
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
}

int SocketHandler::bindSocket(void)
{
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cerr << "Binding failed" << std::endl;
        close(sockfd);
        return 1;
    }
    return 0;
}

int SocketHandler::listenSocket(void)
{
    if (listen(sockfd, 5) < 0)
    {
        std::cerr << "Listening failed" << std::endl;
        close(sockfd);
        return 1;
    }
    return 0;
}

void SocketHandler::Send_Json(int client_socket, std::string json_data)
{

    std::string http_response = "HTTP/1.1 200 OK\r\n";
    http_response += "Content-Type: application/json\r\n";
    http_response += "Content-Length: " + std::to_string(json_data.size()) + "\r\n";
    http_response += "Connection: keep-alive\r\n";
    http_response += "\r\n";
    http_response += json_data;
    // std::cout << http_response << std::endl;

    if (send(client_socket, http_response.c_str(), http_response.length(), 0) < 0)
    {
        std::cerr << "Failed to send data" << std::endl;
    }
    else
    {
        std::cout << json_data << std::endl;
    }
}

void SocketHandler::set_string(std::string json_data)
{
    this->json_data = json_data;
}

void SocketHandler::Receive_Json(int client_socket, char *buffer, size_t buffer_size)
{
    memset(buffer, 0, buffer_size);

    int n = recv(client_socket, buffer, buffer_size - 1, 0);

    if (n <= 0)
    {
        std::cerr << "Error reading from socket or client disconnected" << std::endl;
        close(client_socket);
        return;
    }

    // std::cout << "Received request:" << std::endl;
    std::cout << buffer << std::endl;

    std::string connection_Type = m_parser.ReturnConnectionType(buffer);
    if (connection_Type == "GET")
    {
        // m_GetCommands
        Send_Json(client_socket, m_commands.m_get_GetCommands()[m_parser.ReturnCommand(buffer)]);
    }
    else if (connection_Type == "POST")
    {
        std::string ReturnString{};
        ReturnString += "JSON text sent successfully.";
        ReturnString += "Name: { " + m_parser.ReturnOwner(buffer);
        ReturnString += " } Id: { " + m_parser.ReturnId(buffer);
        ReturnString += " } Command: { " + m_parser.ReturnCommand(buffer);
        ReturnString += " } CommandId: { " + m_parser.ReturnCommandId(buffer);
        ReturnString += " }";
        Send_Json(client_socket, ReturnString);
    }
    close(client_socket);
}

std::string SocketHandler::accept_multiple_connections(void)
{
    socklen_t client_len = sizeof(client_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    client_socket = newsockfd;
    if (newsockfd < 0)
    {
        std::cerr << "Error accepting connection" << std::endl;
        exit(0);
    }
    // std::cout << "Client connected" << std::endl;

    char buffer[4096];
    {
        std::lock_guard<std::mutex> lock(threads_mutex);
        threads.emplace_back(Receive_Json, newsockfd, buffer, sizeof(buffer));
    }

    clean_up_threads();
    return buffer;
}

void SocketHandler::clean_up_threads(void)
{
    std::lock_guard<std::mutex> lock(threads_mutex);
    for (auto it = threads.begin(); it != threads.end();)
    {
        if (it->joinable())
        {
            it->join();
            it = threads.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
