#pragma once

#include <string>
#include <vector>

#include "ReturnCode.hpp"


struct ICommand
{
    virtual ~ICommand() = default;

    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    virtual std::string usage() const = 0;

    virtual ReturnCode run(const std::vector<std::string>& args) = 0;
};
