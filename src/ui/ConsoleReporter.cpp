#include "ConsoleReporter.hpp"

#include "../core/ProjectOptions.hpp"


ConsoleReporter::ConsoleReporter(std::ostream& out, std::ostream& err)
    : out { out }, err { err }
{
    this->out << std::boolalpha;
    this->err << std::boolalpha;
}

void ConsoleReporter::note(const std::string_view message) const
{
    out << message << "\n";
}

void ConsoleReporter::created(const ProjectOptions& opts) const
{
    out << "Created project in " << opts.root << "\n";
}

void ConsoleReporter::warn(const std::string_view message) const
{
    out << "WARN: " << message << "\n";
}

void ConsoleReporter::error(const std::string_view message, const std::source_location loc) const
{
    err << "ERROR: " << message << "\n" << loc.function_name() << std::endl;
}
