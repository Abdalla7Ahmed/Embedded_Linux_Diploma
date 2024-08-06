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
    // std::future<int> asynch = std::async(return_sum, 10);
    // std::future<int> asynch = std::async(std::launch::async, return_sum, 10);
    std::future<int> asynch = std::async(std::launch::deferred, return_sum, 10);

    auto ret_val = asynch.get();
    std::cout << "the summation is " << ret_val << "\n";

    return 0;
}

/*


1-std::async(std::launch::async, return_sum, 10);  == std::future<int> asynch = std::async(return_sum, 10);

This line specifies std::launch::async as the launch policy. This means that the function return_sum
will be executed asynchronously (potentially in a separate thread), starting as soon as std::async is called.
The future object asynch will hold the result of return_sum(10) when it completes.

2-std::async(std::launch::deferred, return_sum, 10);

Here, std::launch::deferred is the launch policy. With this policy, the function return_sum will not be executed
asynchronously when std::async is called. Instead, it will be executed when asynch.get() is called
(or another function that requires the result). The function will execute synchronously in the thread that calls get().

Key Differences:
1-Execution Timing:
std::launch::async: The function starts executing immediately in a separate thread (asynchronously).
std::launch::deferred: The function starts executing when get() is called on the future object (synchronously).
2-Thread Usage:
std::launch::async: Potentially uses a new thread for execution.
std::launch::deferred: Executes in the thread that calls get().
3-Use Cases:
Use std::launch::async when you want the function to start executing immediately and potentially in parallel with other tasks.
Use std::launch::deferred when you prefer lazy evaluation, where the function executes only when its result is needed and in the current thread context.


Considerations:
Performance: std::launch::async may incur overhead from thread creation, while std::launch::deferred avoids this overhead until get() is called.
Concurrency: std::launch::async allows for potential parallelism, whereas std::launch::deferred executes in a sequential manner relative to the caller.








*/