#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <memory>
#include <map>

class Commands
{
private:
    std::string executeCommand(const std::string &cmd);
    std::map<std::string, std::string> m_OpenDirCommands;
    std::map<std::string, std::string> m_OpenVideoCommands;
    std::map<std::string, std::string> m_OpenSiteChromeCommands;
    std::map<std::string, std::string> m_OpenSiteFirefoxCommands;
    std::map<std::string, std::string> m_GetCommands;
    std::map<std::string, std::string> m_ExecuteCommands;
    std::map<std::string, std::string> m_YoctoCommands;

public:
    // todo: restoring the commands from file to can add new one
    std::map<std::string, std::string> m_get_OpenDirCommands(void);
    std::map<std::string, std::string> m_get_OpenVideoCommands(void);
    std::map<std::string, std::string> m_get_OpenSiteChromeCommands(void);
    std::map<std::string, std::string> m_get_OpenSiteFirefoxCommands(void);
    std::map<std::string, std::string> m_get_GetCommands(void);
    std::map<std::string, std::string> m_get_ExecuteCommands(void);
    std::map<std::string, std::string> m_get_YoctoCommands(void);

    Commands(/* args */);
    ~Commands();
};
