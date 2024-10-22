#include "DataBase.hpp"

int main(int argc, const char **argv)
{

    DataBase &d1 = DataBase::GetDataBaseInstance();
    DataBase &d2 = DataBase::GetDataBaseInstance();
    DataBase &d3 = DataBase::GetDataBaseInstance();
    DataBase &d4 = DataBase::GetDataBaseInstance();
    DataBase &d5 = DataBase::GetDataBaseInstance();
    DataBase &d6 = DataBase::GetDataBaseInstance();

    d1.createDatabase("mydb.db");
    std::cout << d1.getValue("mydb.db", "TO_DO", "_2AM") << std::endl;

    return 0;
}