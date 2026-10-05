#pragma once

#include <optional>
#include <string>


struct RawArgs
{
    std::string path = ".";
    bool bin = false;
    bool lib = false;
    std::optional<std::string> lang = std::nullopt;
    std::optional<int> stdVal = std::nullopt;
    std::optional<std::string> name = std::nullopt;
    std::optional<std::string> vcs = std::nullopt;
    bool help = false;
    bool version = false;
};
