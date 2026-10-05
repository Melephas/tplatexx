#pragma once

#include <filesystem>
#include <string>
#include "Language.hpp"
#include "ProjectKind.hpp"
#include "Vcs.hpp"


struct ProjectOptions
{
    std::string name;
    std::string identifier;
    std::filesystem::path root;
    Language language;
    ProjectKind kind;
    int standard;
    Vcs vcs;
};
