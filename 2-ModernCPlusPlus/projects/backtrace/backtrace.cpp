#include "backtrace.hpp"
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
