#include "Dispatcher.hpp"

#include "CommandRegistry.hpp"
#include "ICommand.hpp"
#include "../core/Errors.hpp"
#include "../ui/IReporter.hpp"


Dispatcher::Dispatcher(const CommandRegistry& registry, const IReporter& reporter)
    : registry { registry }, reporter { reporter } {}

ReturnCode Dispatcher::dispatch(const int argc, const char* const* argv) const
{
    std::vector<std::string> args {};
    args.reserve(argc);

    for (auto i { 0 }; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    return dispatch(args);
}

ReturnCode Dispatcher::dispatch(const std::vector<std::string>& args) const
{
    if (args.size() >= 2)
    {
        try
        {
            const auto& command = args.at(1);
            const auto cmd = registry.find(command);
            return cmd->run(args);
        }
        catch (const TplateError& err)
        {
            reporter.error(std::format("Failed to resolve command: {}", err.what()));
            return ReturnCode::RuntimeError;
        }
    }

    reporter.error("Failed to find enough arguments");
    const auto cmd = registry.find("help");
    cmd->run(args);

    return ReturnCode::UsageError;
}
