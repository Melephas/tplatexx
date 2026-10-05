#pragma once

#include "ICommand.hpp"


class IReporter;


class InfoCommand : public ICommand
{
    const IReporter& reporter;
public:
    explicit InfoCommand(const IReporter& reporter);
    ~InfoCommand() override = default;

    std::string name() const override;
    std::string description() const override;
    std::string usage() const override;

    ReturnCode run(const std::vector<std::string>& args) override;
};
