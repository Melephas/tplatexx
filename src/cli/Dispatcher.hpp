#pragma once

#include <string>
#include <vector>

#include "ReturnCode.hpp"


class CommandRegistry;
class IReporter;


class Dispatcher
{
    const CommandRegistry& registry;
    const IReporter& reporter;

public:
    explicit Dispatcher(const CommandRegistry& registry, const IReporter& reporter);

    ReturnCode dispatch(int argc, const char* const* argv) const;
    ReturnCode dispatch(const std::vector<std::string>& args) const;
};
