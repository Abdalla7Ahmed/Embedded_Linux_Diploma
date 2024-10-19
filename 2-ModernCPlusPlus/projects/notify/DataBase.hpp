#pragma once
#include <iostream>
#include <sqlite3.h>
#include <memory>
class DataBase
{
private:
    std::string m_DBName;
    sqlite3 *DB;
    sqlite3_stmt *stmt;
    DataBase() = default;
    ~DataBase() = default;
    static DataBase *DataBaseInstance;

public:
    static DataBase &GetDataBaseInstance(void);
    int createDatabase(std::string dbName);
    int createTable(std::string dbName, std::string sql);
    int insertData(std::string dbName, std::string StringToInsert);
    std::string getValue(const std::string &dbName, const std::string &tableName, const std::string &columnName);
    int Display(std::string dbName, std::string TableName);
    int deleteData(std::string dbName, std::string Table_name, int id);
    int updateData(std::string dbName, std::string newsql);
    bool checkTableExists(const std::string &dbName, const std::string &tableName);
};
