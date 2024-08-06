#pragma once
#include "parse_json.hpp"
#include "Commands.hpp"
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
#include <mutex>
#include <nlohmann/json.hpp>

class SocketHandler
{
private:
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    std::string portnumber;
    std::string address;
    int client_socket;
    int sockfd;
    std::vector<std::thread> threads;
    std::mutex threads_mutex;
    static std::string json_data;
    static Parser m_parser;
    static Commands m_commands;
    void clean_up_threads(void);

public:
    SocketHandler();
    ~SocketHandler();
    void set_sockfd(int sockfd);
    int get_sockfd(void);
    int get_client_socket(void);
    int createSocket(void);
    void Define_server_address(void);
    int bindSocket(void);
    int listenSocket(void);
    void set_string(std::string json_data);
    static void Send_Json(int client_socket, std::string json_data);
    static void Receive_Json(int client_socket, char *buffer, size_t buffer_size);
    std::string accept_multiple_connections(void);
};
