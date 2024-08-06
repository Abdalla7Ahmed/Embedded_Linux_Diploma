#include "string.hpp"

string::string() : str(nullptr), size(0)
{
    str = new char[1];
    str[0] = '\0';
}
string::string(char *string)
{
    if (string == nullptr)
    {
        this->str = new char[1];
        this->str[0] = '\0';
        this->size = 1;
    }
    else
    {
        this->size = strlen(string);
        this->str = new char[(this->size) + 1];
        strcpy(str, string);
        this->str[strlen(string)] = '\0';
    }
}

void string::print(void)
{
    std::cout << str << std::endl;
}
int string::GetStringLength(void)
{
    return this->size;
}

string::string(const string &other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
    this->size = other.size;
    this->str[strlen(other.str)] = '\0';
}
string::string(string &&other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    this->str = other.str;
    this->size = other.size;
    other.str = nullptr;
    other.size = 0;
}
string &string::operator=(const string &other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this == &other)
    {
        return *this;
    }
    if (this->str)
    {
        delete[] this->str;
    }
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
    this->size = other.size;
    this->str[strlen(other.str)] = '\0';
    return *this;
}
string &string::operator=(string &&other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this == &other)
    {
        return *this;
    }
    if (this->str)
    {
        delete[] this->str;
    }

    this->str = other.str;
    this->size = other.size;
    other.str = nullptr;
    other.size = 0;
    return *this;
}
string string::operator+(const string &other)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    int len = strlen(this->str) + strlen(other.str);
    char *buff = new char[len + 1];
    strcpy(buff, this->str);
    strcat(buff, other.str);
    buff[len] = '\0';

    string tmp{buff};
    delete[] buff;
    return tmp;
}

string::~string()
{
    if (this->str)
    {
        delete[] this->str;
    }
}

std::ostream &operator<<(std::ostream &os, const string &obj)
{
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, string &obj)
{
    char *buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = string{buff};
    delete[] buff;
    return is;
}
