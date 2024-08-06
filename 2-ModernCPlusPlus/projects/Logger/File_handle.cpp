#include "File_handle.hpp"

void File_handle::create_log_file(std::string filename)
{

    // opens an existing csv file or creates a new file.
    fout.open(filename, std::ios::out | std::ios::app);
}
void File_handle::write_log(std::string Log)
{
    fout << Log;
}

bool File_handle::is_file_empty(const std::string &filename)
{
    std::ifstream infile(filename, std::ios::ate | std::ios::binary);
    return infile.tellg() == 0;
}
void File_handle::close_file()
{
    fout.close();
}
