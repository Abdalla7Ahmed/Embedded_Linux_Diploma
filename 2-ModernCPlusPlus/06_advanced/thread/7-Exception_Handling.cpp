#include <iostream>
#include <thread>
#include <future>
#include <stdexcept>

// Function to be run in a separate thread
void calculate_sum_with_exception(std::promise<int> &&prom, int a, int b)
{
    try
    {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long calculation
        if (b == 0)
        {
            throw std::runtime_error("Division by zero error");
        }
        int sum = a + b;
        prom.set_value(sum); // Set the result in the promise
    }
    catch (...)
    {
        prom.set_exception(std::current_exception()); // Set the exception in the promise
    }
}

int main()
{
    // Create a promise object
    std::promise<int> prom;

    // Get the future associated with the promise
    std::future<int> fut = prom.get_future();

    // Launch a thread and pass the promise to it
    std::thread worker(calculate_sum_with_exception, std::move(prom), 10, 0);

    // In the main thread, wait for the result or handle exception
    try
    {
        std::cout << "Waiting for result..." << std::endl;
        int result = fut.get(); // This will block until the value is set in the promise or an exception is thrown
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Join the thread
    worker.join();

    return 0;
}
