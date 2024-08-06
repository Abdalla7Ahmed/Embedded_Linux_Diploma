#include "gitmanager.hpp"
const std::string GitManager::ACCESS_TOKEN{""};
const std::string GitManager::USERNAME{""};
const std::string GitManager::REPO_DEFUALT{"cpp-manage-git"};
GitManager::GitManager()
{
    display.DisplaySpliiter("Start");
    if (CheckExistance() == true)
    {
        status();
    }
}
std::string GitManager::get_files()
{
    return m_files;
}

void GitManager::printTemplate()
{
    std::string form = R"(echo "#cpp - manage - git " >> README.md
git init
git add README.md
git commit -m "first commit
git branch -M main
git remote add origin https://github.com/Abdalla7Ahmed
")";
    std::cout << form << std::endl;
}

bool GitManager::CheckExistance()
{
    bool ret = std::system("[ -d .git ]");
    if (ret != 0)
    {
        std::cout << "[-] Failed : please adjust .git settings " << std::endl;
        printTemplate();
        exit(1);
    }
    return ret;
}

bool GitManager::add()
{
    display.DisplaySpliiter("Add");
    bool ret = true;
    std::string files;
    std::string cmd = "git add ";
    char answer;
    std::cout << " would you like to add all changing files Y/N ?\n";
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        cmd += "*";
        ret = std::system(cmd.c_str());
    }
    else if (answer == 'n' || answer == 'N')
    {
        std::cout << "please write the name of files to add " << std::endl;
        // std::getline(std::cin, files);
        std::cin >> files;
        if (files.find('/') != std::string::npos && files.find(';') != std::string::npos && files.find('&') != std::string::npos && files.find('|') != std::string::npos)
        {
            std::cout << "Wrong Usage " << std::endl;
            std::cout << "Usage : filename1 filename2 filename3 etc " << std::endl;
            ret = 1;
        }
        else if (files.size() != 0)
        {
            cmd += files;
            ret = std::system(cmd.c_str());
        }

        else
        {
            std::cout << "Wrong option try again" << std::endl;
            add();
        }
    }
    return ret;
}

void GitManager::status()
{
    display.DisplaySpliiter("Status");

    std::system("git status");
}

bool GitManager::commit()
{
    display.DisplaySpliiter("Commit");

    std::string message = " ";
    std::cout << "please write your commit message" << std::endl;
    std::cin >> message;
    // std::getline(std::cin, message);
    std::string cmd("git commit -m \"" + std::string{message} + "\"");
    std::cout << "command is " << cmd << std::endl;
    return std::system(cmd.c_str());
}

bool GitManager::push()
{
    display.DisplaySpliiter("Push");
    bool ret = false;
    std::string repo_name, username;
    std::cout << "Enter the repo name" << std::endl;
    std::cin >> repo_name;
    // std::getline(std::cin, repo_name);
    if (repo_name.size() == 0)
    {
        repo_name = REPO_DEFUALT;
    }
    std::cout << "Enter the user name" << std::endl;
    std::cin >> username;
    // std::getline(std::cin, username);
    if (username.size() == 0)
    {
        username = USERNAME;
    }
    std::string cmd(" git push https://" + ACCESS_TOKEN + "@github.com/" + username + "/" + repo_name + ".git");
    ret = std::system(cmd.c_str());
    // std::cout << cmd << std::endl;
    return ret;
}
