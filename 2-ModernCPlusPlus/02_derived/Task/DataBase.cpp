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
int main(void)
{
    AddressBook ab;
    info contact;
    int choice, temp;
    std::cout << "Welcome to your vafourite address book !!" << std::endl;
    while (1)
    {
        std::cout << "|==============================|" << std::endl;
        std::cout << "| What do you want to do?      |" << std::endl;
        std::cout << "\t |  1.List    | List all users" << std::endl;
        std::cout << "\t |  2.Add     | Add a new user" << std::endl;
        std::cout << "\t |  3.Delete  | Delete an user" << std::endl;
        std::cout << "\t |  4.Delete  | Delete all users" << std::endl;
        std::cout << "\t |  5.Search  | Search on user " << std::endl;
        std::cout << "\t |  6.Exit    | Exit the application" << std::endl;
        std::cout << " ***** Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            ab.list();
            break;
        case 2:
        {

            std::cout << "Enter name: ";
            std::cin >> contact.name;
            std::cout << "Enter phone: ";
            std::cin >> contact.phone;
            std::cout << "Enter email: ";
            std::cin >> contact.email;
            std::cout << "Enter age: ";
            std::cin >> contact.age;
            std::cout << "Enter user id: ";
            std::cin >> contact.user_id;
            ab.addContact(&contact);
            break;
        }
        case 3:
        {
            int temp;
            std::cout << "Enter user id to delete: ";
            std::cin >> temp;
            ab.removeContact(temp);
            break;
        }
        case 4:
        {
            ab.remove_all();
            break;
        }
        case 5:
        {
            std::cout << "Enter user id: to search: ";
            std::cin >> temp;
            ab.search(temp);
            break;
        }
        case 6:
            exit(1);
            break;
        }
    }

    return 0;
}