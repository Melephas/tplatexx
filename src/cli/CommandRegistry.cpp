#include "CommandRegistry.hpp"

#include <algorithm>
#include <format>
#include <ranges>

#include "ICommand.hpp"
#include "../core/Errors.hpp"


void CommandRegistry::add(std::unique_ptr<ICommand> cmd)
{
    const std::shared_ptr temp = std::move(cmd);
    commands.push_back(temp);
}

std::shared_ptr<ICommand> CommandRegistry::find(std::string_view name) const
{
    const auto cmd = std::ranges::find_if(commands, [&](auto x)
    {
        return x->name() == name;
    });

    if (cmd == commands.end())
    {
        throw TplateError {
            std::format("No command with name '{}' found", name)
        };
    }
    return *cmd;
}

std::span<const std::shared_ptr<ICommand>> CommandRegistry::all() const
{
    return { commands };
}
