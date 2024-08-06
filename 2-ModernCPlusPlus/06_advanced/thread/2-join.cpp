#include <iostream>
#include <thread>
#include <chrono>

void thread2(void)
{
    char Cap_letters = 'A';
    for (int i = 0; i < 10; i++)
    {
        std::cout << Cap_letters << std::endl;
        Cap_letters++;
        if (Cap_letters == 'Z')
        {
            Cap_letters = 'A';
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int main(int argc, const char **argv)
{
    char small_letters = 'a';
    std::thread another_thread(thread2);

    std::cout << small_letters << std::endl;
    small_letters++;
    if (small_letters == 'z')
    {
        small_letters = 'a';
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (another_thread.joinable())
    {
        another_thread.join();
    }

    return 0;
}