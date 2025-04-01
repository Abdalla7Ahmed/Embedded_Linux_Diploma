#include <iostream>
#include <stack>
#include <queue>
void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
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
std::queue<std::string> backtrace::functions{};
backtrace::backtrace(std::string function)
{
    this->funname = function;
    std::cout << "Enter to [ " << function << " ]" << std::endl;
    functions.push(function);
}
backtrace::~backtrace()
{
    std::cout << "Exit from [ " << funname << " ]" << std::endl;
}
void backtrace::print()
{
    std::queue<std::string> temp;
    temp = functions;
    int counter = 0;
    if (temp.empty())
    {
        std::cout << "Queue is empty " << std::endl;
        return;
    }
    while (!temp.empty())
    {
        std::cout << counter++ << "- " << temp.front() << std::endl;
        temp.pop();
    }
    std::cout << "backtrace is finished" << std::endl;
}
void backtrace::exit(void)
{
    std::cout << "Exit from [ " << funname << " ]" << std::endl;
}
void backtrace::clear_queue(void)
{
    while (!functions.empty())
    {
        functions.pop();
    }
}

void fun1(void)
{
    EnterFn;
    fun2();
    // ExitFn;
}
void fun2(void)
{
    EnterFn;
    fun3();
    // ExitFn;
}
void fun3(void)
{
    EnterFn;
    PRINT_BACKtrace;
    fun4();
    // ExitFn;
}
void fun4(void)
{
    EnterFn;
    PRINT_BACKtrace;
    // ExitFn;
}
int main()
{
    EnterFn;
    fun1();
    PRINT_BACKtrace;
    CLEAR_QUEUE;
    PRINT_BACKtrace;
    // ExitFn;

    return 0;
}