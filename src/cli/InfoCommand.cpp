#include "InfoCommand.hpp"

#include "Errors.hpp"
#include "IReporter.hpp"

#ifndef TPLATE_VERSION
#   define TPLATE_VERSION "VERSION_MISSING"
#endif


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
    return std::format("{}\n\nThis command takes no arguments", name());
}

ReturnCode InfoCommand::run(const std::vector<std::string>& /*args*/)
{
    reporter.note(std::format("tplate++ v{} - C/C++ project templating, rewritten", TPLATE_VERSION));
    return ReturnCode::Success;
}
