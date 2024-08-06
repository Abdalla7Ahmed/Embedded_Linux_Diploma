#include <iostream>
#include <cstdlib>
#include <map>
// void openCalculator()
// {
//     system("gnome-calculator > /dev/null 2>&1 &");
// }

void openVSCode()
{
    system("code > /dev/null 2>&1 &");
}

void openFirefox()
{
    system("firefox > /dev/null 2>&1 &");
}

// void openChrome()
// {
//     system("google-chrome > /dev/null 2>&1 &");
// }

void openWhatsApp()
{
    system("google-chrome https://web.whatsapp.com > /dev/null 2>&1 &");
}

void openYouTube()
{
    system("google-chrome https://www.youtube.com > /dev/null 2>&1 &");
}

void openFacebook()
{
    system("google-chrome https://www.facebook.com > /dev/null 2>&1 &");
}

void openLinkedIn()
{
    system("google-chrome https://www.linkedin.com > /dev/null 2>&1 &");
}

void openGitHub()
{

    system("sh -c 'vlc $(find /home/abdallah/Documents/Motasem/03Linux/06_process_user -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &");
}

// int main()
// {
//     // openCalculator();
//     // openVSCode();
//     // openFirefox();
//     // openChrome();
//     // openWhatsApp();
//     // openYouTube();
//     // openFacebook();
//     // openLinkedIn();
//     openGitHub();

//     std::cout << "All applications and websites have been launched." << std::endl;

//     return 0;
// }

#include <unistd.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
void executeCommand(const std::vector<std::string> &args)
{
    std::vector<char *> c_args;
    for (const auto &arg : args)
    {
        c_args.push_back(const_cast<char *>(arg.c_str()));
    }
    c_args.push_back(nullptr); // execvp expects a null-terminated array of char*

    if (execvp(c_args[0], c_args.data()) == -1)
    {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

void openCalculator()
{
    std::vector<std::string> args = {"gnome-calculator"};
    executeCommand(args);
}

void openVLC()
{
    std::vector<std::string> args = {"vlc"};
    executeCommand(args);
}

void openChrome()
{
    std::vector<std::string> args = {"sh -c 'vlc $(find /home/abdallah/Documents/Motasem/03Linux/01_Introduction -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &"};
    executeCommand(args);
}

int main()
{

    std::string command = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO && source /home/abdallah/Documents/YOCTO/poky/oe-init-build-env && runqemu qemuarm my-image nographic; exec bash\"' > /dev/null 2>&1 &";
    int result = system(command.c_str());
    if (result == -1)
    {
        std::cerr << "Failed to execute command" << std::endl;
    }

    return 0;
}
