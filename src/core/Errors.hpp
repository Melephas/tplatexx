#pragma once

#include <format>
#include <source_location>
#include <stdexcept>


class TplateError : public std::runtime_error
{
public:
    explicit TplateError(const std::string& what_arg, const std::source_location loc = std::source_location::current())
        : std::runtime_error { std::format("{}: {}", loc.function_name(), what_arg) } {}
    explicit TplateError(const char* what_arg, const std::source_location loc = std::source_location::current())
        : std::runtime_error { std::format("{}: {}", loc.function_name(), what_arg) } {}
};


class UsageError : public TplateError
{
public:
    using TplateError::TplateError;
};


class FileSystemError : public TplateError
{
public:
    using TplateError::TplateError;
};


class UnimplementedError : public std::runtime_error
{
public:
    explicit UnimplementedError(const std::source_location loc = std::source_location::current())
        : std::runtime_error(std::format("{} is currently unimplemented", loc.function_name())) {}
};
