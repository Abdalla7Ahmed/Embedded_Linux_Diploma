#pragma once
#include <iostream>
#include <queue>
#include <string>

struct info
{
    std::string name;
    std::string phone;
    std::string email;
    int age;
    int user_id;
};

class AddressBook
{
private:
    std::queue<info> database;

public:
    AddressBook() = default;
    ~AddressBook() = default;
    void list();
    void addContact(info *contact);
    void removeContact(int user_id);
    void remove_all();
    void search(int user_id);
};
