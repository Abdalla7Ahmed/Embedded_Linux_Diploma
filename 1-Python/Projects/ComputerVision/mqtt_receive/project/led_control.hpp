#pragma once
#include <iostream>
#include <fstream>
enum class LED_NUMBER : unsigned char
{
    LED2 = 0,
    LED3,
    LED4,
    LED17,
    LED27
};
enum class LED_VALUE : unsigned char
{
    LED_OFF = 0,
    LED_ON

};
class Led_Control
{
private:
    std::fstream m_fd;
    // std::string Led1_path{"/etc/led0"};
    // std::string Led2_path{"/etc/led1"};
    // std::string Led3_path{"/etc/led2"};
    // std::string Led4_path{"/etc/led3"};
    // std::string Led5_path{"/etc/led4"};

    // for testing purposes
    std::string Led1_path{"/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python/Projects/ComputerVision/mqtt_receive/led0.txt"};
    std::string Led2_path{"/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python/Projects/ComputerVision/mqtt_receive/led1.txt"};
    std::string Led3_path{"/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python/Projects/ComputerVision/mqtt_receive/led2.txt"};
    std::string Led4_path{"/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python/Projects/ComputerVision/mqtt_receive/led3.txt"};
    std::string Led5_path{"/home/abdallah/Documents/Github/Embedded_Linux_Diploma/1-Python/Projects/ComputerVision/mqtt_receive/led4.txt"};

public:
    Led_Control() = default;
    void Led_Change_Value(int led_number, int led_value);
    ~Led_Control() = default;
};
