#pragma onec
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
class File_handle
{
private:
    std::fstream fout;

public:
    File_handle() = default;
    bool is_file_empty(const std::string &filename);
    void create_log_file(std::string filename);
    void write_log(std::string Log);
    void close_file();
    ~File_handle() = default;
};
