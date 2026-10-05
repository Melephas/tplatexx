#include "HelpCommand.hpp"

#include <iostream>

#include "CommandRegistry.hpp"
#include "Errors.hpp"

HelpCommand::HelpCommand(const CommandRegistry& registry)
    : registry { registry } {}

std::string HelpCommand::name() const
{
    return "help";
}

std::string HelpCommand::description() const
{
    return "Display help information";
}

std::string HelpCommand::usage() const
{
    throw UnimplementedError {};
}

ReturnCode HelpCommand::run(const std::vector<std::string>& args)
{
    auto isHelp = [](auto x)
    {
        return x == "help";
    };

    const auto argsStart = std::ranges::find_if(args, isHelp);
    const auto notHelpArg = std::ranges::find_if_not(argsStart, args.end(), isHelp);

    // If there is an argument other than 'help'
    if (notHelpArg != args.cend())
    {
        const auto cmd = registry.find(*notHelpArg);
        std::cout << cmd->usage() << std::endl;
        return ReturnCode::Success;
    }

    const auto prog_name = args.front();

    // Otherwise the user has asked for the generic help text.
    std::cout << "usage: " << prog_name << " <command> [arguments]\n"
    << "where <command> is one of:\n";

    for (const auto command : registry.all())
    {
        std::cout << "\t" << command->name() << " - " << command->description() << "\n";
    }

    std::cout << "\nuse " << prog_name << " help <command> for more information about specific commands"
    << std::endl;

    return ReturnCode::Success;
}
