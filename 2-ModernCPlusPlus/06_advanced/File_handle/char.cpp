#include <iostream>
#include <fstream>
void write(void)
{
    std::ofstream ofs;
    ofs.open("test.txt");
    if (!ofs.is_open())
    {
        std::cout << "COUDN'T OPEN THE FILE FOR WRITING" << std::endl;
        return;
    }
    std::string message{"hello this is test string ready to copy"};
    for (auto &ch : message)
    {
        ofs.put(ch);
    }

    ofs.seekp(10); // make cursor position is 10
    ofs.put('%');

    ofs.close();
}
void read(void)
{
    std::ifstream ifs;
    ifs.open("test.txt");
    if (!ifs.is_open())
    {
        std::cout << "COUDN'T OPEN THE FILE FOR READING" << std::endl;
        return;
    }

    std::cout << "the current position is " << ifs.tellg() << std::endl;
    // we can change the position of the cursor
    ifs.seekg(10);
    std::cout << "the current position is " << ifs.tellg() << std::endl; // 10
    ifs.seekg(10, std::ios::beg);                                        // 10 from the beginning
    std::cout << "the current position is " << ifs.tellg() << std::endl; // 10
    ifs.seekg(10, std::ios::end);
    std::cout << "the current position is " << ifs.tellg() << std::endl; // 49
    ifs.seekg(10, std::ios::end);                                        // 10 from the end
    std::cout << "the current position is " << ifs.tellg() << std::endl; // 49
    // ifs.seekg(0);
    ifs.seekg(10, std::ios::cur);                                        // 10 from the current position
    std::cout << "the current position is " << ifs.tellg() << std::endl; // 59

    ifs.seekg(0);
    char ch;
    while (ifs.get(ch))
    {
        std::cout << ch;
    }
    std::cout << std::endl;

    ifs.close();
}

void using_fstream(void)
{
    std::fstream fst;
    fst.open("test_fstream.txt");
    if (!fst.is_open())
    {
        std::cout << "FILE DOESN'T EXSIS , CREATE ONE ......" << std::endl;
        // create a new file name test_fstream.txt
        std::ofstream out;
        out.open("test_fstream.txt");
        out.close();
        fst.open("test_fstream.txt");
    }

    fst << "Hello world , this is test text" << std::endl;
    std::cout << "the current position is " << fst.tellg() << std::endl; // 32  now the cursor is at the end of the file
    fst.seekp(0);
    std::string str;
    std::getline(fst, str);
    std::cout << str << std::endl;
}
int main()
{
    //     write();
    //     read();
    using_fstream();
    return 0;
}