#pragma once
#include <iostream>
#include <thread>
#include <chrono>

class decorator
{
private:
    /* data */
    unsigned int delayMs = 10;
    void printSlowly(const std::string &message, unsigned int delayMs);

public:
    decorator(/* args */);
    void DisplaySpliiter(std::string value);

    ~decorator();
};