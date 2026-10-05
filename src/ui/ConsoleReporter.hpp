#pragma once

#include "IReporter.hpp"


struct ProjectOptions;


class ConsoleReporter : public IReporter
{
    std::ostream& out;
    std::ostream& err;

public:
    explicit ConsoleReporter(std::ostream& out, std::ostream& err);

    void note(std::string_view message) const override;
    void created(const ProjectOptions& opts) const override;
    void warn(std::string_view message) const override;
    void error(std::string_view message, std::source_location loc = std::source_location::current()) const override;
};
