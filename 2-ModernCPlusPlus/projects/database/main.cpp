#include "DataBase.hpp"

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