#include "led_control.hpp"

void Led_Control::Led_Change_Value(int led_number, int led_value)
{
    switch (led_number)
    {
    case 0:
    {
        m_fd.open(Led1_path, std::ios::out | std::ios::binary);
        if (led_value == 0)
        {
            m_fd.write("0", 2);
        }
        else if (led_value == 1)
        {
            m_fd.write("1", 2);
        }
        m_fd.close();
        break;
    }
    case 1:
    {
        m_fd.open(Led2_path, std::ios::out | std::ios::binary);
        if (led_value == 0)
        {
            m_fd.write("0", 2);
        }
        else if (led_value == 1)
        {
            m_fd.write("1", 2);
        }
        m_fd.close();

        break;
    }
    case 2:
    {
        m_fd.open(Led3_path, std::ios::out | std::ios::binary);
        if (led_value == 0)
        {
            m_fd.write("0", 2);
        }
        else if (led_value == 1)
        {
            m_fd.write("1", 2);
        }
        m_fd.close();

        break;
    }
    case 3:
    {
        m_fd.open(Led4_path, std::ios::out | std::ios::binary);
        if (led_value == 0)
        {
            m_fd.write("0", 2);
        }
        else if (led_value == 1)
        {
            m_fd.write("1", 2);
        }
        m_fd.close();

        break;
    }
    case 4:
    {
        m_fd.open(Led5_path, std::ios::out | std::ios::binary);
        if (led_value == 0)
        {
            m_fd.write("0", 2);
        }
        else if (led_value == 1)
        {
            m_fd.write("1", 2);
        }
        m_fd.close();
        break;
    }
    default:
        break;
    }
}