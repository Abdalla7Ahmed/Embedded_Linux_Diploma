#include <iostream>
#include <thread>
#include <vector>
#include <future>

std::vector<int> data{};
std::mutex mut;
void print(int count)
{
    for (int i = 0; i < count; i++)
    {
        // std::cout << i << " ";
        mut.lock();
        data.push_back(i);
        mut.unlock();

        // or using lock-gard
        // std::lock_guard<std::mutex> lock(mut);
        // data.push_back(i);
    }

    std::cout << "\n";
}

int main(int argc, const char **argv)
{
    std::future<void> fu1 = std::async(std::launch::async, print, 1000);
    std::future<void> fu2 = std::async(std::launch::async, print, 1000);

    fu1.wait();
    fu2.wait();
    std::cout << data.size() << std::endl;

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << data[i] << " ";
    }

    return 0;
}