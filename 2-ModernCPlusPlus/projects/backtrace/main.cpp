#include "backtrace.hpp"

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
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

int main(int argc, const char **argv)
{

    EnterFn;
    fun1();
    PRINT_BACKtrace;
    CLEAR_QUEUE;
    PRINT_BACKtrace;
    // ExitFn;

    return 0;
    return 0;
}