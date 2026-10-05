#pragma once

#include <memory>
#include <span>
#include <string_view>
#include <vector>


struct ICommand;


class CommandRegistry
{
    std::vector<std::shared_ptr<ICommand>> commands;

public:
    void add(std::unique_ptr<ICommand> cmd);
    std::shared_ptr<ICommand> find(std::string_view name) const;
    std::span<const std::shared_ptr<ICommand>> all() const;
};
