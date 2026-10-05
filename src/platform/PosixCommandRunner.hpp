#pragma once

#include "ICommandRunner.hpp"

class PosixCommandRunner : public ICommandRunner
{
public:
    int run(const std::vector<std::string>& argv,
            const std::filesystem::path& workingDir) override;
};
