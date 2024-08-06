#pragma once
#include <nlohmann/json.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <map>
#include <vector>
#include "parse_json.hpp"
#include "SocketHandler.hpp"
#include "Commands.hpp"

class execute
{
private:
    const std::string Owner;
    const std::string Id;
    Parser parse;
    std::string json_text;
    Commands m_commands;
    std::map<std::string, std::string> m_CommandsToExecute;
    const std::string OpenDirId{"1"};
    const std::string OpenVideoId{"2"};
    const std::string OpenSiteId{"3"};
    const std::string ChromeId{"1"};
    const std::string FireFoxId{"2"};
    const std::string ExecuteId{"4"};
    const std::string YoctoId{"5"};

public:
    execute(/* args */);
    void set_string(std::string json_text);
    void set_map(void);
    std::string getCommand(void);
    bool CheckPermission(void);
    void execute_command(void);
    std::string return_result(void);
    ~execute();
};
