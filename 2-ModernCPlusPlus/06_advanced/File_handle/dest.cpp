#include <iostream>
#include <fstream>
#include <experimental/filesystem>

// g++ filesystemlibrary.cpp -lstdc++fs && ./a.out
int main()
{

    std::experimental::filesystem::path Source{std::experimental::filesystem::current_path()};
    Source /= "copy_file_content.cpp"; // add this at the end of the path directory
    std::experimental::filesystem::path dest{std::experimental::filesystem::current_path()};
    dest /= "dest.cpp";
    std::ifstream input;
    input.open(Source);
    std::ofstream output;
    output.open(dest);
    std::string line;
    while (!std::getline(input, line).eof())
    {
        output << line << std::endl;
    }

    input.close();
    output.close();

    return 0;
}
