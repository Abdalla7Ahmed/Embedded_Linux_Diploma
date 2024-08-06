#include <iostream>
#include <thread>
#include <chrono>
#include <future>
int return_sum(int count)
{
    int sum{};
    for (int i = 0; i < count; i++)
    {
        sum += i;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return sum;
}
int main(int argc, const char **argv)
{
    // 1-Create a std::packaged_task
    // A std::packaged_task is created to wrap the return_sum function,allowing it to be executed asynchronously and its result to be stored in a std::future.
    std::packaged_task<int(int)> p_t(return_sum);
    // 2-Get a std::future Object
    // A std::future object is obtained from the packaged_task. This future will hold the result of the return_sum function once it is computed.
    std::future<int> fu = p_t.get_future();
    // 3-Start a Thread
    // A new thread is created to run the packaged_task with the argument 10. std::move(p_t) is used to transfer ownership of the packaged_task to the thread.
    std::thread th(std::move(p_t), 10);
    // 4-Get the Result

    auto ret_val = fu.get();
    std::cout << "the summation is " << ret_val << "\n";
    // 5-Join the Thread
    if (th.joinable())
    {
        th.join();
    }

    return 0;
}