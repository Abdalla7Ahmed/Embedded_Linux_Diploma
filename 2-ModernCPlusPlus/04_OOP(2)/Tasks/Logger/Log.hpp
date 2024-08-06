#pragma once
#include "File_handle.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdio> // For std::remove

class Parse_Log
{
private:
    File_handle file_handle;

    std::string File_name;

    std::fstream fin;
    std::string Clock_now();

public:
    enum LogType : unsigned char
    {
        INFO,
        DEBUG,
        ERROR
    };
    std::string ConvertToString(LogType logtype);

    Parse_Log() = delete;
    explicit Parse_Log(std::string File_name);
    bool write(LogType logtype, const std::string log);
    void Dump(void);
    bool Clear(void);
    ~Parse_Log();
};