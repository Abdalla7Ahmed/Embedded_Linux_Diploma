#include <iostream>
#include <thread>
#include <chrono>

// void thread2(void)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << i << " ";
//     }
//     std::this_thread::sleep_for(std::chrono::seconds(10));
// }
// int main(int argc, const char **argv)
// {
//     char small_letters = 'a';
//     std::thread another_thread(thread2);

//     std::cout << small_letters << std::endl;
//     small_letters++;
//     if (small_letters == 'z')
//     {
//         small_letters = 'a';
//     }
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     another_thread.detach();
//     std::cout << "\nthis thread not blocked due to detach" << std::endl;

//     return 0;
// }
/*
what is the different between join and detach ?
In C++, join and detach are two methods associated with the std::thread class, used to handle threads.
They manage the thread's lifecycle and determine how the main thread interacts with the child thread.
Here's a detailed explanation and examples for both:

join()
The join() method blocks the execution of the calling thread (typically the main thread)
until the thread represented by the std::thread object has finished executing.
It ensures that the thread completes its work before the calling thread continues.

#include <iostream>
#include <thread>

void printNumbers() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::thread t(printNumbers);
    t.join();  // Wait for the thread to finish
    std::cout << "Thread joined!" << std::endl;
    return 0;
}
In this example, the main thread waits for the t thread to finish executing printNumbers before printing "Thread joined!".


*/

/*

detach()
The detach() method allows the thread to run independently from the main thread. Once detached,
the thread continues to run on its own, and the main thread does not wait for it to finish.
A detached thread cannot be joined later, and its resources are automatically cleaned up once it completes execution.

In this example, the main thread prints "Thread detached!" and might finish its execution before the detached
thread completes its printNumbers task.

Key Differences:
Blocking:
join blocks the calling thread until the thread completes, whereas detach does not block the calling thread.
Thread Management:
With join, the main thread manages the child thread's lifecycle, ensuring it completes before proceeding.
With detach, the thread runs independently, and its lifecycle is not managed by the main thread.
Resource Cleanup:
join ensures resources are cleaned up when the thread finishes.
detach makes the thread responsible for cleaning up its own resources.


Choosing between join and detach depends on whether you need the main thread to wait for the child
thread to finish or if you want the child thread to run independently.







*/

#include <iostream>
#include <thread>
#include <chrono>

void printNumbers()
{
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << i << " ";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    }
    std::cout << std::endl;
    std::cout << "/* message */" << std::endl;
}

int main()
{
    std::thread t(printNumbers);
    t.detach(); // Let the thread run independently
    std::cout << "Thread detached!" << std::endl;
    // The main thread might finish before the detached thread completes
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Give some time to observe the detached thread
    return 0;
}
