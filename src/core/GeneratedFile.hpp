#pragma once

#include <filesystem>
#include <string>
#include <vector>


struct GeneratedFile
{
    std::filesystem::path relativePath;
    std::string contents;
};

using ProjectPlan = std::vector<GeneratedFile>;
