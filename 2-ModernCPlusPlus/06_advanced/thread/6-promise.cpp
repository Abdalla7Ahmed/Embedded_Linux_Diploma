#include <iostream>
#include <thread>
#include <future>

// Function to be run in a separate thread
void calculate_sum(std::promise<int> &&prom, int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long calculation
    int sum = a + b;
    prom.set_value(sum); // Set the result in the promise
}

int main()
{
    // Create a promise object
    std::promise<int> prom;

    // Get the future associated with the promise
    std::future<int> fut = prom.get_future();

    // Launch a thread and pass the promise to it
    std::thread worker(calculate_sum, std::move(prom), 10, 20);

    // In the main thread, wait for the result
    std::cout << "Waiting for result..." << std::endl;
    int result = fut.get(); // This will block until the value is set in the promise
    std::cout << "Result: " << result << std::endl;

    // Join the thread
    worker.join();

    return 0;
}
/*

The std::future and std::promise classes in C++ provide a mechanism to access the result of an asynchronous operation.
They are often used together in multithreading to pass a value or an exception from one thread to another.

std::promise
std::promise is used to set a value or an exception that will be retrieved by a corresponding std::future.
The std::promise object is set in one thread, and the value or exception can be retrieved from the associated std::future object in another thread.

std::future
std::future is used to retrieve the value or exception set by std::promise.
It represents a value that will be available at some point in the future.


*/