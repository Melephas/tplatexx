#include "InfoCommand.hpp"

#include "Errors.hpp"
#include "IReporter.hpp"


InfoCommand::InfoCommand(const IReporter& reporter)
    : reporter { reporter } {}

std::string InfoCommand::name() const
{
    return "info";
}

std::string InfoCommand::description() const
{
    return "Display information about this program";
}

std::string InfoCommand::usage() const
{
    throw UnimplementedError {};
}

ReturnCode InfoCommand::run(const std::vector<std::string>& args)
{
    reporter.note("This is some information");
    return ReturnCode::Success;
}
