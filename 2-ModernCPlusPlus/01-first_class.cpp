#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds, std::chrono::milliseconds

constexpr int DELAY = 1;
class LED
{
private:
    /* data */
    int gpio_pin;
    std::string direction;

public:
    LED() = delete;
    LED(int gpio_pin, std::string direction);
    void Led_on();
    void Led_off();
    void Led_toggle();
    ~LED();
};
LED::LED(int gpio_pin, std::string direction) : gpio_pin(gpio_pin), direction(direction)
{
    // initialize the gpio_pin as output or input
    std::cout << "Pin " << gpio_pin << " initialized as " << direction << std::endl;
}
void LED::Led_on()
{
    // write on to /sys/class/gpio/${gpio_pin}/value one
    std::cout << "Led is on" << std::endl;
}
void LED::Led_off()
{
    // write on to /sys/class/gpio/${gpio_pin}/value zero
    std::cout << "Led is off" << std::endl;
}
void LED::Led_toggle()
{
    // on
    std::cout << "Led is on" << std::endl;
    // delay
    std::this_thread::sleep_for(std::chrono::seconds(DELAY));
    // off
    std::cout << "Led is off" << std::endl;
}
LED::~LED()
{
    std::cout << "the gpio_pin is free" << std::endl;
}
int main(int argc, const char **argv)
{

    LED led1{12, "out"};
    led1.Led_toggle();

    return 0;
}