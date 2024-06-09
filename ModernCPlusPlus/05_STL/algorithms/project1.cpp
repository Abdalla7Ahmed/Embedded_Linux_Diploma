#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

// very important project =================================================================
struct student_data
{
    std::string name;
    float age;
    int id;
    std::vector<std::string> courses;
};

class database
{
private:
    static std::vector<std::map<std::string, std::string>> data;
    void add_student(std::map<std::string, std::string> student);

public:
    database();
    ~database();
    void show_all_students(void);
};

std::vector<std::map<std::string, std::string>> database::data{};

database::database(/* args */)
{
}

database::~database()
{
}

void database::add_student(std::map<std::string, std::string> student)
{
    data.push_back(student);
}
void database::show_all_students(void)
{
    std::map<std::string, std::string> tmp{data};
    std::map<std::string, std::string>::iterator it;
    it = data.begin();
    while (it != data.end())
    {
        std::
    }
}

int main(int argc, const char **argv)
{

    return 0;
}
