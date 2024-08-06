#include "Display.hpp"

decorator::decorator(/* args */)
{
}

decorator::~decorator()
{
}

void decorator::printSlowly(const std::string &message, unsigned int delayMs)
{
    for (char c : message)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}
void decorator::DisplaySpliiter(std::string value)
{
    printSlowly("---------------------------------\n", delayMs);
    printSlowly("-                               -\n", delayMs);
    printSlowly("-            ", delayMs);
    printSlowly(value, delayMs);
    printSlowly("        -\n", delayMs);
    printSlowly("-                               -\n", delayMs);
    printSlowly("---------------------------------\n", delayMs);
}
