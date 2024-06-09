#include <iostream>
#include <fstream>
#include <cstring>
struct Recodrds
{
    int id;
    char name[10];
    float age;
};

void AddRecord(Recodrds *R)
{
    std::ofstream ofs;
    ofs.open("record.bin", std::ios::binary | std::ios::out);
    if (!ofs.is_open())
    {
        std::cout << "failed to open record.bin file" << std::endl;
        return;
    }
    ofs.write((const char *)R, sizeof(Recodrds));
    ofs.close();
}
Recodrds GetRecord(void)
{
    Recodrds R;
    std::ifstream ifs;
    ifs.open("record.bin", std::ios::binary | std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "failed to open record.bin file" << std::endl;
        return R;
    }
    ifs.read((char *)&R, sizeof(Recodrds));
    ifs.close();

    return R;
}
int main()
{

    std::ofstream ofs;
    ofs.open("bin1.bin");
    if (!ofs.is_open())
    {
        std::cout << "failed to open bin1.bin file" << std::endl;
    }
    ofs << 123456789;
    ofs.close();

    // this will store as an ascii in the file and the size of this file will be  9 bytes

    std::ofstream ofs2{"bin2.bin", std::ios::binary | std::ios::out};
    if (!ofs2.is_open())
    {
        std::cout << "failed to open bin2.bin file" << std::endl;
    }
    int num = 123456789;
    ofs2.write((const char *)&num, sizeof(num));
    ofs2.close();
    // this will store as a binary , the size of this file is 4 bytes only

    std::ifstream ofs3;
    ofs3.open("bin2.bin", std::ios::binary | std::ios::in);
    if (!ofs3.is_open())
    {
        std::cout << "failed to open bin2.bin file" << std::endl;
    }
    num = 0;
    ofs3.read((char *)&num, sizeof(num));
    std::cout << num << std::endl;

    Recodrds R;
    R.age = 23.5;
    strcpy(R.name, "Abdallah");
    // R.name = "Abdallah";
    R.id = 1;
    AddRecord(&R);
    Recodrds R2;
    R2 = GetRecord();
    std::cout << "the name is " << R2.name << std::endl;
    std::cout << "the age is " << R2.age << std::endl;
    std::cout << "the id is " << R2.id << std::endl;

    return 0;
}