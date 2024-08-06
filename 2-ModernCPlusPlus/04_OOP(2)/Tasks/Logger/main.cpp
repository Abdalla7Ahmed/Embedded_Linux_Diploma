
#include "Log.hpp"
int main(int argc, const char **argv)
{
    Parse_Log l1{"test.csv"};
    l1.write(Parse_Log::LogType::INFO, "this is INFO");
    l1.write(Parse_Log::LogType::DEBUG, "this DEBUG");
    l1.write(Parse_Log::LogType::ERROR, "this ERROR");
    l1.Dump();
    l1.Clear();

    return 0;
}
