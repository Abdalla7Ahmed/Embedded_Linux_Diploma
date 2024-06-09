#include<iostream>
#include<string>
#include <cstring>

namespace mystring
{
class string
{
private:
    char str[20];
    int length;
public:
    string(/* args */) = delete;
    string(const char str[]);
    ~string() = default;
    const char * GetString(void);
    int GetStringLength(void);

};

string::string(const char str[])
{
    strcpy(this->str, str);
    this->length = strlen(str);
}

const char * string::GetString(void)
{
    return this->str;
}

int string::GetStringLength(void)
{
    return this->length;
}


} // end of namespace mystring


int main(void)
{
    mystring::string s1("hello world");
    std::cout << s1.GetString() << std::endl;
    std::cout << s1.GetStringLength() << std::endl;
    return 0;
}



