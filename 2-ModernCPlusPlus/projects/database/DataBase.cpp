#include "DataBase.hpp"
void AddressBook::list()
{
    std::queue<info> temp = database;
    if (temp.empty())
    {
        std::cout << "No Contacts to list" << std::endl;
        return;
    }
    std::cout << "====== Listing all users ======= " << std::endl;
    while (!temp.empty())
    {
        std::cout << "Name: " << temp.front().name << std::endl;
        std::cout << "Phone: " << temp.front().phone << std::endl;
        std::cout << "Email: " << temp.front().email << std::endl;
        std::cout << "Age: " << temp.front().age << std::endl;
        std::cout << "User ID: " << temp.front().user_id << std::endl;
        temp.pop();
        std::cout << "================================================================" << std::endl;
    }
}

void AddressBook::addContact(info *contact)
{
    database.push(*contact);
    std::cout << "Contact added successfully!" << std::endl;
}
void AddressBook::removeContact(int user_id)
{
    if (database.empty())
    {
        std::cout << "No Contacts to list" << std::endl;
        return;
    }
    std::queue<info> temp;

    // Pop elements from database and push to temp until finding the contact
    while (!database.empty())
    {
        if (database.front().user_id == user_id)
        {
            database.pop(); // Remove the contact from database
            // break;    comment it to keep the order as it is
        }
        if (!database.empty())
        {
            // to check if the current record is the deleted record or not
            temp.push(database.front());
            database.pop();
        }
    }

    // Restore the elements back to database from temp
    while (!temp.empty())
    {
        database.push(temp.front());
        temp.pop();
    }
}
void AddressBook::remove_all()
{
    while (!database.empty())
    {
        database.pop();
    }
}

void AddressBook::search(int user_id)
{
    std::queue<info> temp = database;

    if (temp.empty())
    {
        std::cout << "No Contacts to search " << std::endl;
        return;
    }
    while (!temp.empty())
    {
        if (temp.front().user_id == user_id)
        {
            std::cout << "Name: " << database.front().name << std::endl;
            std::cout << "Phone: " << database.front().phone << std::endl;
            std::cout << "Email: " << database.front().email << std::endl;
            std::cout << "Age: " << database.front().age << std::endl;
            std::cout << "User ID: " << database.front().user_id << std::endl;
            return;
        }
        else
        {
            temp.pop();
        }
    }
    std::cout << "No Contact found" << std::endl;
}