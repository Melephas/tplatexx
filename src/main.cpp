#include <iostream>

#include "HelpCommand.hpp"
#include "InfoCommand.hpp"
#include "NewCommand.hpp"
#include "cli/CommandRegistry.hpp"
#include "cli/Dispatcher.hpp"
#include "ui/ConsoleReporter.hpp"


int main(const int argc, const char* const* argv)
{
    const ConsoleReporter reporter { std::cout, std::cerr };
    CommandRegistry commands {};
    commands.add(std::make_unique<HelpCommand>(commands));
    commands.add(std::make_unique<InfoCommand>(reporter));
    // commands.add(std::make_unique<NewCommand>(
    //     ArgumentParser {},
    //     OptionsValidator {}
    //     ProjectPlanner {}
    //
    // ));

    const Dispatcher d { commands, reporter };

    ReturnCode r = d.dispatch(argc, argv);
    return static_cast<int>(r);
}
