#include <iostream>
#include <forward_list>

void print(std::string str)
{
    std::cout << str << std::endl;
}
void print(int i)
{
    std::cout << i << std::endl;
}

void showlist(std::forward_list<std::string> d)
{
    std::forward_list<std::string>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

void showlist(std::forward_list<int> d)
{
    std::forward_list<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
    {
        std::cout << *it << "   ";
    }

    std::cout << std::endl;
}

int main(void)
{
    std::forward_list<std::string> d1{"Abdallah", "Ali", "Omar", "Ahmed"};

    // d1.push_back("back");   error front inly
    d1.push_front("front");
    showlist(d1); // front   Abdallah   Ali   Omar   Ahmed
    d1.pop_front();
    showlist(d1); // Abdallah   Ali   Omar   Ahmed

    print(d1.max_size()); // max number 288230376151711743

    print(d1.front()); // Abdallah

    d1.emplace_after(d1.begin(), "Front");
    showlist(d1); // Abdallah   Front   Ali   Omar   Ahmed

    d1.emplace_front("begin");
    showlist(d1); // begin Abdallah   Front   Ali   Omar   Ahmed

    std::forward_list<int> f1, f2, f3;
    f1.assign({1, 2, 3, 4, 4});
    showlist(f1); // 1   2   3   4   4

    f2.assign(5, 10);
    showlist(f2); // 10 10 10 10 10

    f3.assign(f1.begin(), f2.end());
    showlist(f3); // 1   2   3   4   4

    // Declaring a forward list iterator
    std::forward_list<int>::iterator ptr;

    // Inserting value using insert_after()
    // starts insertion from second position
    ptr = f1.insert_after(f1.begin(), {100, 100, 100});
    showlist(f1); // 1   100   100   100   2   3   4   4

    std::forward_list<std::string>::iterator ptr2;
    ptr2 = d1.insert_after(d1.begin(), {"second", "third", "fourth"});
    // d1.insert_after(d1.begin(), {"second", "third", "fourth"});  < ==== or
    showlist(d1); // begin   second   third   fourth   Abdallah   Front   Ali   Omar   Ahmed

    ptr2 = d1.emplace_after(ptr2, "back");
    showlist(d1); // begin   second   third   fourth   back   Abdallah   Front   Ali   Omar   Ahmed

    print(*ptr2); // back
    ptr2 = d1.erase_after(ptr2);
    print(*ptr2); // front

    showlist(d1); // begin   second   third   fourth   back   Front   Ali   Omar   Ahmed
    d1.erase_after(ptr2);
    d1.erase_after(ptr2);
    showlist(d1); // begin   second   third   fourth   back   Front   Ahmed
    print(*ptr2); // front

    // Deleting value in a range
    // another variant of erase which uses start and end iterator
    // and deletes all the values in between them
    ptr2 = d1.erase_after(d1.begin(), d1.end()); // erase from after begin
    showlist(d1);                                // begin

    std::forward_list<int> f4{20, 2, 45, 651, 32, 15, 1};
    f4.remove(45);
    showlist(f4);  // 20   2   651   32   15   1
    f4.remove(40); // nothing
    showlist(f4);  // 20   2   651   32   15   1

    // Removing according to condition. Removes
    // elements greater than 20.
    f4.remove_if([](int x)
                 { return x > 20; });
    showlist(f4); // 20   2   15   1

    f4.clear();
    showlist(f4); //

    if (f4.empty())
    {
        print("the forward list is empty");
    }
    else
    {
        print("the forward list is not empty");
    }

    // Initializing forward list
    std::forward_list<int> flist1 = {10, 20, 30};

    // Initializing second list
    std::forward_list<int> flist2 = {40, 50, 60};

    // Shifting elements from first to second
    // forward list after 1st position
    flist2.splice_after(flist2.begin(), flist1);

    showlist(flist2); // 40   10   20   30   50   60

    return 0;
}