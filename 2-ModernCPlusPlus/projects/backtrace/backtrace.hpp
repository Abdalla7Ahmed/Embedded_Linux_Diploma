#pragma once
#include <iostream>
#include <stack>
#include <queue>

class backtrace;

// #define EnterFn             backtrace b1(__PRETTY_FUNCTION__)
#define EnterFn backtrace b1(__FUNCTION__)

#define ExitFn b1.exit()
#define PRINT_BACKtrace b1.print()
#define CLEAR_QUEUE b1.clear_queue()

class backtrace
{
private:
    std::string funname;
    static std::queue<std::string> functions;

public:
    backtrace() = default;
    backtrace(std::string function);
    ~backtrace();
    void exit(void);
    void print();
    void clear_queue();
};
