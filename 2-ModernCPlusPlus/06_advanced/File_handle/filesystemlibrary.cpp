#include <iostream>
#include <experimental/filesystem>

// g++ filesystemlibrary.cpp -lstdc++fs && ./a.out
int main()
{

    std::experimental::filesystem::path p{R"(/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced)"};
    if (p.has_filename())
    {
        std::cout << p.filename() << std::endl; //"06_advanced"
    }
    for (auto &x : p)
    {
        std::cout << x << " "; //  "/" "home" "abdallah" "Documents" "Github" "ModernCPlusPlus" "06_advanced"
    }
    std::cout << std::endl;

    std::experimental::filesystem::directory_iterator beg{p};
    std::experimental::filesystem::directory_iterator end{};
    for (auto &x : beg)
    {
        std::cout << x << std::endl;
    }

    /*
    "/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/smart_pointer"
    "/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/a.out"
    "/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/error-handle"
    "/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/File_handle"
    "/home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/namespace.cpp"
"   /home/abdallah/Documents/Github/ModernCPlusPlus/06_advanced/.vscode"
    */

    return 0;
}