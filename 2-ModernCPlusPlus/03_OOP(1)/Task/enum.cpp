#include <iostream>

enum to_string1
{
    DigBridge,
    OtaBridge,
    FlashingApp
};

enum class to_string2
{
    DigBridge,
    OtaBridge,
    FlashingApp

};

std::string SwUpdateJsonParse(to_string2 key)
{
#define MyCase(x) \
    case x:       \
        return std::string(#x);
    switch (key)
    {
        MyCase(to_string2::DigBridge);
        MyCase(to_string2::OtaBridge);
        MyCase(to_string2::FlashingApp);
    }
    return "";
}

std::string SwUpdateJsonParse(to_string1 key)
{
#define MyCase(x) \
    case x:       \
        return std::string(#x);
    switch (key)
    {
        MyCase(DigBridge);
        MyCase(OtaBridge);
        MyCase(FlashingApp);
    }
    return "";
}

int main(int argc, const char **argv)
{

    to_string1 t1 = DigBridge;
    std::cout << SwUpdateJsonParse(t1) << std::endl;
    t1 = OtaBridge;
    std::cout << SwUpdateJsonParse(t1) << std::endl;
    t1 = FlashingApp;
    std::cout << SwUpdateJsonParse(t1) << std::endl;

    to_string2 t2 = to_string2::DigBridge;
    std::cout << SwUpdateJsonParse(t2) << std::endl;
    t2 = to_string2::OtaBridge;
    std::cout << SwUpdateJsonParse(t2) << std::endl;
    t2 = to_string2::FlashingApp;
    std::cout << SwUpdateJsonParse(t2) << std::endl;

    /*

    DigBridge
    OtaBridge
    FlashingApp
    to_string2::DigBridge
    to_string2::OtaBridge
    to_string2::FlashingApp

    in this case the enum is better than enum class
    */
    return 0;
}