#include <iostream>
#include <fstream>
void write(void)
{
    std::ofstream ofs;
    ofs.open("data.txt");
    if (ofs.is_open())
    {
        ofs << "hello World" << std::endl;
        ofs << 10;
    }
    ofs.close();
}
void read(void)
{
    std::ifstream ifs;
    ifs.open("data.txt");
    if (ifs.is_open())
    {
        std::string first_line;
        std::getline(ifs, first_line);
        // ifs >> first_line;   // until first space
        int value;
        ifs >> value;
        std::cout << first_line << "  " << value << std::endl;
    }

    ifs.close();
}

int main()
{
    write();
    read();
    return 0;
}