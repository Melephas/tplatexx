#pragma once

#include <memory>
#include <string>
#include <vector>
#include "ArgumentParser.hpp"
#include "ICommand.hpp"
#include "ReturnCode.hpp"
#include "../core/OptionsValidator.hpp"
#include "../core/ProjectPlanner.hpp"
#include "../core/ProjectWriter.hpp"
#include "../postcreate/IPostCreateStep.hpp"
#include "../ui/IReporter.hpp"

class NewCommand : public ICommand
{
    ArgumentParser parser;
    OptionsValidator validator;
    ProjectPlanner planner;
    ProjectWriter writer;
    std::vector<std::unique_ptr<IPostCreateStep>> postSteps;
    IReporter& reporter;

public:
    NewCommand(
        ArgumentParser parser,
        OptionsValidator validator,
        ProjectPlanner planner,
        ProjectWriter writer,
        std::vector<std::unique_ptr<IPostCreateStep>> postSteps,
        IReporter& reporter
    );

    ~NewCommand() override = default;

    std::string name() const override;
    std::string usage() const override;

    ReturnCode run(const std::vector<std::string>& args) override;
};
