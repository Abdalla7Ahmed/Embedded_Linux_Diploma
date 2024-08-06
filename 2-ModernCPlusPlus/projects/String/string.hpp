#include <iostream>
#include <string>
#include <cstring>

class string
{
private:
    char *str;
    int size;

public:
    string();
    ~string();
    explicit string(char *string);
    void print(void);
    int GetStringLength(void);
    string(const string &other);
    string(string &&other);
    string &operator=(const string &other);
    string &operator=(string &&other);
    string operator+(const string &other);
    friend std::ostream &operator<<(std::ostream &os, const string &obj);
    friend std::istream &operator>>(std::istream &is, string &obj);
};
