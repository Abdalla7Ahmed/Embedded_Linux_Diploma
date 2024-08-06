
#include "Log.hpp"

Parse_Log::Parse_Log(std::string File_name) : File_name(File_name)
{
    file_handle.create_log_file(File_name);

    if (file_handle.is_file_empty(File_name))
    {
        std::string time = "Time";
        std::string message = "Message";
        std::string log = "Log";
        std::string fullstring = time + ',' + message + ',' + log + '\n';
        file_handle.write_log(fullstring);
    }
}
bool Parse_Log::write(LogType logtype, const std::string log)
{
    bool success = false;
    std::string message, fullstring;
    message = ConvertToString(logtype);
    if (!message.empty())
    {
        fullstring = Clock_now() + ',' + message + ',' + log + '\n';
        file_handle.write_log(fullstring);
        success = true;
    }
    return success;
}

void Parse_Log::Dump(void)
{
    fin.open(File_name, std::ios::in);

    // Check if file is open
    if (!fin.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return;
    }
    // Read the data from the file as String Vector
    std::vector<std::string> row;
    std::string line, word;

    while (getline(fin, line))
    {

        // Skip empty lines
        if (line.empty())
        {
            continue;
        }

        std::cout << line << std::endl;
    }
}
bool Parse_Log::Clear()
{
    // Use std::remove to delete the file
    if (std::remove(File_name.c_str()) != 0)
    {
        std::perror("Error deleting file");
        return false;
    }
    else
    {
        std::cout << "File successfully deleted" << std::endl;
        return true;
    }
}

std::string Parse_Log::ConvertToString(LogType logtype)
{
#define MyCase(x) \
    case x:       \
        return std::string(#x);
    switch (logtype)
    {
        MyCase(INFO);
        MyCase(DEBUG);
        MyCase(ERROR);
    }
    return "";
}

std::string Parse_Log::Clock_now()
{
    // Get the current time from the system clock
    auto now = std::chrono::system_clock::now();

    // Convert to time_t, which represents the time as a C-style time
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert to a tm struct, which holds the time in a more convenient form
    std::tm *localTime = std::localtime(&currentTime);

    // Create a string stream to format the time
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

    // Return the formatted time as a string
    return oss.str();
}
Parse_Log::~Parse_Log()
{
    file_handle.close_file();
}