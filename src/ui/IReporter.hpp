#pragma once

#include <source_location>
#include <string_view>


struct ProjectOptions;


class IReporter
{
public:
    virtual ~IReporter() = default;

    virtual void note(std::string_view message) const = 0;
    virtual void created(const ProjectOptions& opts) const = 0;
    virtual void warn(std::string_view message) const = 0;
    virtual void error(std::string_view message, std::source_location loc = std::source_location::current()) const = 0;
};
