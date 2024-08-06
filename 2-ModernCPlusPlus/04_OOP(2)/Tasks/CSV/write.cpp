#include <fstream>
#include <iostream>
void create()
{
    // file pointer
    std::fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("reportcard.csv", std::ios::out | std::ios::app);

    std::cout << "Enter the details of 5 students:"
              << " roll name maths phy chem bio \n";

    int i, roll, phy, chem, math, bio;
    std::string name;

    // Read the input

    std::cin >> roll >> name >> math >> phy >> chem >> bio;

    // Insert the data to file
    fout << roll << ", "
         << name << ", "
         << math << ", "
         << phy << ", "
         << chem << ", "
         << bio
         << "\n";
}
int main(int argc, const char **argv)
{
    create();
    return 0;
}