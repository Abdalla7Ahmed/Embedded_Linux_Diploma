#include "DataBase.hpp"
DataBase *DataBase::DataBaseInstance = nullptr;

DataBase &DataBase::GetDataBaseInstance(void)
{
    if (!DataBaseInstance)
    {
        DataBaseInstance = new DataBase();
    }
    return *DataBaseInstance;
}

int DataBase::createDatabase(std::string dbName)
{
    int exit = sqlite3_open(dbName.c_str(), &DB);

    if (exit)
    {
        std::cerr << "Error creating database: " << sqlite3_errmsg(DB) << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Database created successfully!" << std::endl;
    }

    sqlite3_close(DB);
    std::string sql = "CREATE TABLE IF NOT EXISTS TO_DO("
                      "_12AM TEXT NOT NULL, "
                      "_1AM TEXT NOT NULL, "
                      "_2AM TEXT NOT NULL, "
                      "_3AM TEXT NOT NULL, "
                      "_4AM TEXT NOT NULL, "
                      "_5AM TEXT NOT NULL, "
                      "_6AM TEXT NOT NULL, "
                      "_7AM TEXT NOT NULL, "
                      "_8AM TEXT NOT NULL, "
                      "_9AM TEXT NOT NULL, "
                      "_10AM TEXT NOT NULL, "
                      "_11AM TEXT NOT NULL, "
                      "_12PM TEXT NOT NULL, "
                      "_1PM TEXT NOT NULL, "
                      "_2PM TEXT NOT NULL, "
                      "_3PM TEXT NOT NULL, "
                      "_4PM TEXT NOT NULL, "
                      "_5PM TEXT NOT NULL, "
                      "_6PM TEXT NOT NULL, "
                      "_7PM TEXT NOT NULL, "
                      "_8PM TEXT NOT NULL, "
                      "_9PM TEXT NOT NULL, "
                      "_1PAM TEXT NOT NULL, "
                      "_11PM TEXT NOT NULL); ";
    createTable(dbName, sql);

    sql = "INSERT INTO TO_DO(_12AM, _1AM, _2AM, _3AM, _4AM, _5AM, _6AM, _7AM, _8AM, _9AM, _10AM, _11AM, _12PM, _1PM, _2PM, _3PM, _4PM, _5PM, _6PM, _7PM, _8PM, _9PM, _1PAM, _11PM)"
          "VALUES("
          "'GAM', "
          "'Free', "
          "'English', "
          "'Embedded System', "
          "'Embedded System + GitHub', "
          "'Free', "
          "'Sleeping', "
          "'Sleeping', "
          "'Sleeping', "
          "'Sleeping', "
          "'Sleeping', "
          "'Sleeping', "
          "'Sleeping', "
          "'Embedded Linux', "
          "'Embedded Linux + Design Pattern', "
          "'Design Pattern', "
          "'Free', "
          "'System Admin', "
          "'GitHub', "
          "'Free', "
          "'System Admin', "
          "'GAM', "
          "'GAM', "
          "'System Admin'); ";
    insertData(dbName, sql);
    return 0;
}

int DataBase::insertData(std::string dbName, std::string StringToInsert)
{
    int exit = sqlite3_open(dbName.c_str(), &DB);
    char *errMsg;

    exit = sqlite3_exec(DB, StringToInsert.c_str(), 0, 0, &errMsg);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error inserting data: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return -1;
    }
    else
    {
        // std::cout << "Data inserted successfully!" << std::endl;
    }
    sqlite3_close(DB);
    return 0;
}
int DataBase::createTable(std::string dbName, std::string sql)
{
    return insertData(dbName, sql);
}
std::string DataBase::getValue(const std::string &dbName, const std::string &tableName, const std::string &columnName)
{
    std::string value = "";
    std::string sql = "SELECT " + columnName + " FROM " + tableName + " LIMIT 1;"; // Query to select the column value

    // Open the database
    if (sqlite3_open(dbName.c_str(), &DB) != SQLITE_OK)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(DB) << std::endl;
        return "";
    }

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_close(DB);
        return "";
    }

    // Execute the query and fetch the result
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *result = sqlite3_column_text(stmt, 0);
        if (result)
        {
            value = std::string(reinterpret_cast<const char *>(result));
        }
    }
    else
    {
        std::cerr << "No records found." << std::endl;
    }

    // Finalize and close the database
    sqlite3_finalize(stmt);
    sqlite3_close(DB);

    return value;
}

int DataBase::Display(std::string dbName, std::string TableName)
{
    std::string sql = "SELECT * FROM " + TableName + ";";

    int exit = sqlite3_open(dbName.c_str(), &DB);

    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0) != SQLITE_OK)
    {
        std::cerr << "Error selecting data!" << std::endl;
        return -1;
    }
    int columnCount = sqlite3_column_count(stmt);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        for (int i = 0; i < columnCount; i++)
        {
            int colType = sqlite3_column_type(stmt, i);

            switch (colType)
            {
            case SQLITE_INTEGER:
                std::cout << sqlite3_column_int(stmt, i);
                break;
            case SQLITE_FLOAT:
                std::cout << sqlite3_column_double(stmt, i);
                break;
            case SQLITE_TEXT:
                std::cout << sqlite3_column_text(stmt, i);
                break;
            case SQLITE_BLOB:
                std::cout << "(BLOB)";
                break;
            case SQLITE_NULL:
                std::cout << "NULL";
                break;
            }

            if (i < columnCount - 1)
                std::cout << " | "; // Separator between columns
        }
        std::cout << std::endl; // New line for each row
    }

    std::cout << columnCount << std::endl;

    sqlite3_finalize(stmt);
    sqlite3_close(DB);

    return 0;
}

int DataBase::deleteData(std::string dbName, std::string Table_name, int id)
{
    std::string sql = "DELETE FROM " + Table_name + " WHERE ISBN = " + std::to_string(id) + ";";
    return insertData(dbName, sql);
}

int DataBase::updateData(std::string dbName, std::string newsql)
{

    return insertData(dbName, newsql);
}

bool DataBase::checkTableExists(const std::string &dbName, const std::string &tableName)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::string sql = "SELECT name FROM sqlite_master WHERE type='table' AND name=?;";

    // Open the database
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Bind the table name to the statement
    sqlite3_bind_text(stmt, 1, tableName.c_str(), -1, SQLITE_STATIC);

    // Execute the statement
    bool exists = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        exists = true; // Table exists
    }

    // Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return exists;
}
