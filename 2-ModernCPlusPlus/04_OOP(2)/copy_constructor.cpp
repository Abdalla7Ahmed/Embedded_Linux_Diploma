#include <iostream>

class Integer
{
private:
    int *ptr;
    int x;

public:
    void set(int ptr) { *(this->ptr) = ptr; }
    void print() { std::cout << *ptr << std::endl; }
    Integer() = default;

    explicit Integer(int *ptr) : ptr(ptr)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Integer(const Integer &other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        this->x = other.x;
        this->ptr = new int(*other.ptr);
    }
    Integer &operator=(const Integer &other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (this == &other)
        {
            return *this;
        }
        if (this->ptr)
        {
            delete this->ptr;
        }
        this->x = other.x;
        this->ptr = new int(*other.ptr);
        return *this;
    }
    Integer(Integer &&other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        this->x = other.x;
        other.x = 0;
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }

    Integer &operator=(Integer &&other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (this != &other)
        {
            if (this->ptr)
            {
                delete this->ptr;
            }
            this->x = other.x;
            other.x = 0;
            this->ptr = other.ptr;
            other.ptr = nullptr;

            return *this;
        }
        return *this;
    }

    ~Integer()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        if (this->ptr)
        {
            delete this->ptr;
        }
        ptr = nullptr;
    }
};
Integer get_obj(void)
{
    Integer obj(new int(5));
    return obj;
}

int get_pointer(void)
{
    int *ptr = new int(5);
    return *ptr;
}

void printt(const int &other)
{
    std::cout << other << std::endl;
}

int main(int argc, char **argv)
{

    Integer i1(new int(5));
    Integer i2(std::move(i1));
    i2.print();
    // i1.print();  // Segmentation fault (core dumped) i doesn't exist now
    Integer i3(new int(5));
    Integer i4(new int(10));
    i4 = std::move(i3);

    printt(get_pointer());
    return 0;
}