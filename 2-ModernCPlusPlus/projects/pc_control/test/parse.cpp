#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

int main()
{
    // Sample JSON text
    std::string json_text = R"({
        "name": "John",
        "age": 30,
        "city": "New York",
        "is_student": false,
        "grades": [85, 90, 92]
    })";

    // Parse JSON text
    nlohmann::json json_obj = nlohmann::json::parse(json_text);

    // Accessing data
    std::string name = json_obj["name"];
    int age = json_obj["age"];
    std::string city = json_obj["city"];
    bool is_student = json_obj["is_student"];
    std::vector<int> grades = json_obj["grades"];

    // Output the parsed data
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "City: " << city << "\n";
    std::cout << "Is Student: " << (is_student ? "Yes" : "No") << "\n";
    std::cout << "Grades: ";
    for (int grade : grades)
    {
        std::cout << grade << " ";
    }
    std::cout << "\n";

    std::string json_data = R"({
        "user": {
            "name": "John Doe",
            "email": "john.doe@example.com"
        },
        "posts": [
            {
                "title": "Post 1",
                "content": "This is the content of post 1."
            },
            {
                "title": "Post 2",
                "content": "This is the content of post 2."
            }
        ]
    })";
    nlohmann::json json_obj2 = nlohmann::json::parse(json_data);

    std::string name2 = json_obj2["posts"]["title"];
    // int age = json_obj["age"];
    // std::string city = json_obj["city"];
    // bool is_student = json_obj["is_student"];
    // std::vector<int> grades = json_obj["grades"];
    std::cout << "Name: " << name2 << "\n";

    return 0;
}
