#pragma once

#include <string>
#include <vector>
#include "RawArgs.hpp"


class ArgumentParser
{
public:
    RawArgs parse(const std::vector<std::string>& args) const;
};
