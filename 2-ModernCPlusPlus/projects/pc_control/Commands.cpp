#include "Commands.hpp"
std::string Commands::executeCommand(const std::string &cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

Commands::Commands()
{
    // open site commands chrome
    m_OpenSiteChromeCommands["chrome"] = "google-chrome > /dev/null 2>&1 &";
    m_OpenSiteChromeCommands["youtube"] = "google-chrome https://www.youtube.com > /dev/null 2>&1 &";
    m_OpenSiteChromeCommands["whatsapp"] = "google-chrome https://web.whatsapp.com > /dev/null 2>&1 &";
    m_OpenSiteChromeCommands["facebook"] = "google-chrome https://www.facebook.com > /dev/null 2>&1 &";
    m_OpenSiteChromeCommands["linkedin"] = "google-chrome https://www.linkedin.com > /dev/null 2>&1 &";
    m_OpenSiteChromeCommands["github"] = "google-chrome https://www.github.com > /dev/null 2>&1 &";

    // open site commands firefox
    m_OpenSiteFirefoxCommands["firefox"] = "firefox > /dev/null 2>&1 &";
    m_OpenSiteFirefoxCommands["youtube"] = "firefox https://www.youtube.com > /dev/null 2>&1 &";
    m_OpenSiteFirefoxCommands["whatsapp"] = "firefox https://web.whatsapp.com > /dev/null 2>&1 &";
    m_OpenSiteFirefoxCommands["facebook"] = "firefox https://www.facebook.com > /dev/null 2>&1 &";
    m_OpenSiteFirefoxCommands["linkedin"] = "firefox https://www.linkedin.com > /dev/null 2>&1 &";
    m_OpenSiteFirefoxCommands["github"] = "firefox https://www.github.com > /dev/null 2>&1 &";

    // execute commands
    m_ExecuteCommands["code"] = "code > /dev/null 2>&1 &";
    m_ExecuteCommands["calculator"] = "gnome-calculator &";
    m_ExecuteCommands["text_editor"] = "gedit > /dev/null 2>&1 &";
    m_ExecuteCommands["terminal"] = "gnome-terminal > /dev/null 2>&1 &";
    m_ExecuteCommands["system_monitor"] = "gnome-system-monitor > /dev/null 2>&1 &";
    m_ExecuteCommands["file_manager"] = "nautilus > /dev/null 2>&1 &";
    m_ExecuteCommands["music_player"] = "rhythmbox > /dev/null 2>&1 &";
    m_ExecuteCommands["email_client"] = "thunderbird > /dev/null 2>&1 &";
    m_ExecuteCommands["calendar"] = "gnome-calendar &";
    m_ExecuteCommands["network_monitor"] = "nm-connection-editor > /dev/null 2>&1 &";
    m_ExecuteCommands["disk_usage"] = "baobab > /dev/null 2>&1 &";
    m_ExecuteCommands["system_settings"] = "gnome-control-center > /dev/null 2>&1 &";
    m_ExecuteCommands["terminal_custom"] = "gnome-terminal -- bash -c 'ls; exec bash' > /dev/null 2>&1 &";
    m_ExecuteCommands["Camera"] = "cheese > /dev/null 2>&1 &";
    m_ExecuteCommands["Kazam"] = "kazam > /dev/null 2>&1 &";
    m_ExecuteCommands["suspend"] = "systemctl suspend -i";
    m_ExecuteCommands["lock"] = "gnome-screensaver-command -l";
    m_ExecuteCommands["restart"] = "systemctl reboot";
    m_ExecuteCommands["poweroff"] = "systemctl poweroff";

    // todo

    // open Directory commands
    m_OpenDirCommands["Home"] = "xdg-open /home/abdallah ";
    m_OpenDirCommands["Embedded_Linux_Diploma"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma";
    m_OpenDirCommands["YOCTO"] = "xdg-open /home/abdallah/Documents/YOCTO";
    m_OpenDirCommands["YOCTO_Project"] = "xdg-open /home/abdallah/Documents/YOCTO/poky/meta-project";
    m_OpenDirCommands["rpi4_image"] = "xdg-open /home/abdallah/Documents/YOCTO/build/tmp/deploy/images/raspberrypi4-64";
    m_OpenDirCommands["rpi3_image"] = "xdg-open /home/abdallah/Documents/YOCTO/build/tmp/deploy/images/raspberrypi3-64";
    m_OpenDirCommands["custom_scripts"] = "xdg-open /home/abdallah/important_scripts > /dev/null 2>&1 &";

    // embedded linux diploma Eng moatasem
    m_OpenDirCommands["Python"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/01Python";
    m_OpenDirCommands["c++"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/02C++";
    m_OpenDirCommands["Linux"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux";
    m_OpenDirCommands["Bash"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/04Bash";
    m_OpenDirCommands["Raspberrypi"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/05_Raspberrypi";
    m_OpenDirCommands["Yocto"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/06_Yocto";
    m_OpenDirCommands["Device_Drivers"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/07_Device_Drivers";
    m_OpenDirCommands["Rust"] = "xdg-open /home/abdallah/Documents/Embedded_Linux_Diploma/08_Rust_Programming";

    // open video Commands
    m_OpenVideoCommands["3_1_Introduction"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/01_Introduction -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";
    m_OpenVideoCommands["3_2init_process"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/02_initProcess -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";
    m_OpenVideoCommands["3_3_shell"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/03_shell -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";
    m_OpenVideoCommands["3_4_commands"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/04_commands -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";
    m_OpenVideoCommands["3_5_commands_P2"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/05_commands_P2 -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";
    m_OpenVideoCommands["3_6_process_user"] = "sh -c 'vlc $(find /home/abdallah/Documents/Embedded_Linux_Diploma/03Linux/06_process_user -type f \\( -name \"*.mp4\" -o -name \"*.mkv\" -o -name \"*.avi\" \\) | head -n 1)' > /dev/null 2>&1 &";

    // yocto
    m_YoctoCommands["runqemu"] = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO && source /home/abdallah/Documents/YOCTO/poky/oe-init-build-env && runqemu qemuarm my-image nographic; exec bash\"' > /dev/null 2>&1 &";
    m_YoctoCommands["setenv"] = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO && source /home/abdallah/Documents/YOCTO/poky/oe-init-build-env ; exec bash\"' > /dev/null 2>&1 &";
    m_YoctoCommands["OpenWorkDir"] = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO/build/tmp/work/armv7vet2hf-neon-poky-linux-gnueabi ; exec bash\"' > /dev/null 2>&1 &";
    m_YoctoCommands["Openworkspace"] = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO/build/workspace ; exec bash\"' > /dev/null 2>&1 &";
    m_YoctoCommands["OpenRecipesApp"] = "terminator -e 'bash -c \"cd /home/abdallah/Documents/YOCTO/poky/meta-project/recipes-applications ; exec bash\"' > /dev/null 2>&1 &";

    // get commands
    m_GetCommands["battery_status"] = executeCommand("acpi -i");
    m_GetCommands["ip_address"] = executeCommand("hostname -I");
    m_GetCommands["cpu_usage"] = executeCommand("top -bn1 | grep 'Cpu(s)'");
    m_GetCommands["Ram_usage"] = executeCommand("free -h");
    m_GetCommands["Disk_usage"] = executeCommand("df -h");
    // m_CommandsToExecute["network_connections"] = executeCommand("netstat -tunlp");
    m_GetCommands["system_uptime"] = executeCommand("uptime -p");
    m_GetCommands["running_processes"] = executeCommand("ps -u abdallah");
    m_GetCommands["kernel_version"] = executeCommand("uname -r");
}

std::map<std::string, std::string> Commands::m_get_OpenDirCommands(void)
{
    return this->m_OpenDirCommands;
}

std::map<std::string, std::string> Commands::m_get_OpenVideoCommands(void)
{
    return this->m_OpenVideoCommands;
}
std::map<std::string, std::string> Commands::m_get_OpenSiteChromeCommands(void)
{
    return this->m_OpenSiteChromeCommands;
}
std::map<std::string, std::string> Commands::m_get_OpenSiteFirefoxCommands(void)
{
    return this->m_OpenSiteFirefoxCommands;
}
std::map<std::string, std::string> Commands::m_get_GetCommands(void)
{
    return this->m_GetCommands;
}
std::map<std::string, std::string> Commands::m_get_ExecuteCommands(void)
{
    return this->m_ExecuteCommands;
}
std::map<std::string, std::string> Commands::m_get_YoctoCommands(void)
{
    return this->m_YoctoCommands;
}

Commands::~Commands()
{
}
