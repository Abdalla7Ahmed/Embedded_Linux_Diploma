#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include "Display.hpp"
class GitManager
{
public:
    GitManager();
    GitManager(const GitManager &ret) = delete;
    GitManager operator=(GitManager &ref) = delete;

    bool CheckExistance();
    bool add();
    void status();
    bool commit();
    bool push();

    std::string get_files();
    ;

private:
    void printTemplate();
    static const std::string ACCESS_TOKEN;
    static const std::string USERNAME;
    static const std::string REPO_DEFUALT;

    decorator display;

    std::string m_files;
};