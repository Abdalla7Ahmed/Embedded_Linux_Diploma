#include "execute.hpp"

execute::execute() : Owner{"Abdallah"}, Id{"0"}
{
    // m_CommandsToExecute = m_commands.m_get_Commands();
}

execute::~execute()
{
}
void execute::set_string(std::string json_text)
{
    this->json_text = json_text;
}

void execute::execute_command(void)
{
    bool per = CheckPermission();
    if (per == false)
    {
        std::cout << "Permission denied" << std::endl;
        return;
    }

    std::string Owner{parse.ReturnOwner(json_text)};
    std::string Id{parse.ReturnId(json_text)};
    std::string Command{parse.ReturnCommand(json_text)};
    std::string Connection_Type{parse.ReturnConnectionType(json_text)};
    std::string CommandId{parse.ReturnCommandId(json_text)};
    std::string SiteId{parse.ReturnSiteId(json_text)};
    if (Connection_Type == "POST")
    {
        // std::cout << "POST Commands" << std::endl;
        if (CommandId == OpenDirId)
        {
            // m_OpenDirCommands
            // std::cout << "open dire commands" << std::endl;
            m_CommandsToExecute = m_commands.m_get_OpenDirCommands();
        }
        else if (CommandId == OpenVideoId)
        {
            // m_OpenVideoCommands
            // std::cout << "open video commands" << std::endl;

            m_CommandsToExecute = m_commands.m_get_OpenVideoCommands();
        }
        else if (CommandId == OpenSiteId)
        {
            // m_OpenSiteCommands
            // std::cout << "open site commands" << std::endl;
            if (SiteId == ChromeId)
            {
                m_CommandsToExecute = m_commands.m_get_OpenSiteChromeCommands();
            }
            else if (SiteId == FireFoxId)
            {
                m_CommandsToExecute = m_commands.m_get_OpenSiteFirefoxCommands();
            }
        }
        else if (CommandId == ExecuteId)
        {
            // m_ExecuteCommands
            // std::cout << "execute commands" << std::endl;

            m_CommandsToExecute = m_commands.m_get_ExecuteCommands();
        }
        else if (CommandId == YoctoId)
        {
            // m_YoctoCommands
            // std::cout << "Yocto commands" << std::endl;
            m_CommandsToExecute = m_commands.m_get_YoctoCommands();
        }
        if (parse.ReturnCommand(json_text) == "CopyText")
        {
            // std::cout << "we are here now" << std::endl;
            std::string command = "echo -n \"" + parse.ReturnText(json_text) + "\" | xclip -selection clipboard";
            int result = system(command.c_str());
            if (result == -1)
            {
                std::cerr << "Failed to execute command" << std::endl;
                return;
            }
        }
        else
        {
            int result = system(m_CommandsToExecute[Command].c_str());
            if (result == -1)
            {
                std::cerr << "Failed to execute command" << std::endl;
                return;
            }
        }
    }

    // char executeC[100];
    // std::string abc;
    // abc = getCommand();
    // std::strcpy(executeC, m_CommandsToExecute[abc].c_str());
    // // std::cout << "the command to executed is ===" << executeC << std::endl;
    // char *command = strtok(executeC, " ");
    // char *args[100];
    // int args_count = 0;
    // while (command != NULL)
    // {
    //     args[args_count++] = command;
    //     command = strtok(NULL, " ");
    // }
    // args[args_count] = NULL;

    // execvp(args[0], args);
    // perror("execution failed");
    // exit(EXIT_FAILURE);
}
std::string execute::getCommand(void)
{
    std::string command;
    // command = parse.parse_text(json_text)["Command"];

    command = parse.ReturnCommand(json_text);
    return command;
}
bool execute::CheckPermission(void)
{
    bool state = false;
    // std::map<std::string, std::string> mymap;
    // mymap = parse.parse_json(json_text);
    if ((parse.ReturnOwner(json_text) == Owner) && (parse.ReturnId(json_text) == Id))
    {
        state = true;
    }
    return state;
}
