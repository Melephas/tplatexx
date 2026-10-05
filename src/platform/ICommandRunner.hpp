#pragma once

#include <filesystem>
#include <string>
#include <vector>

class ICommandRunner
{
public:
    virtual ~ICommandRunner() = default;

    virtual int run(const std::vector<std::string>& argv,
                    const std::filesystem::path& workingDir) = 0;
};
