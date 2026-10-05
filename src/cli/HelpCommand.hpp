#pragma once

#include "ICommand.hpp"
#include "ReturnCode.hpp"


class CommandRegistry;


class HelpCommand : public ICommand
{
    const CommandRegistry& registry;

public:
    HelpCommand(const CommandRegistry& registry);
    ~HelpCommand() override = default;

    std::string name() const override;
    std::string description() const override;
    std::string usage() const override;

    ReturnCode run(const std::vector<std::string>& args) override;
};
