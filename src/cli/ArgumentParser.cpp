#include "ArgumentParser.hpp"

#include <algorithm>
#include <array>
#include <span>
#include <stdexcept>
#include <string_view>
#include <vector>


static constexpr auto binFlag { "--bin" };
static constexpr auto libFlag { "--lib" };
static constexpr auto langFlag { "--lang" };
static constexpr auto stdFlag { "--std" };
static constexpr auto nameFlag { "--name" };
static constexpr auto vcsFlag { "--vcs" };

static constexpr auto helpFlag = std::to_array<std::string_view>({ "-h", "--help" });
static constexpr auto versionFlag = std::to_array<std::string_view>({ "-V", "--version" });


static bool matchesFlag(std::span<const std::string_view> flag, const std::string_view argument)
{
    return std::ranges::contains(flag, argument);
}

static bool matchesFlag(const std::string_view flag, const std::string_view argument)
{
    return flag == argument;
}


// ReSharper disable once CppMemberFunctionMayBeStatic
RawArgs ArgumentParser::parse(const std::vector<std::string>& args) const
{
    RawArgs ret {};

    const auto args_size = args.size();
    for (auto i { 0 }; i < args_size; i++)
    {
        decltype(auto) arg = args.at(i);

        if (matchesFlag(helpFlag, arg))
        {
            ret.help = true;
        }

        if (matchesFlag(versionFlag, arg))
        {
            ret.version = true;
        }

        if (matchesFlag(binFlag, arg))
        {
            ret.bin = true;
        }

        if (matchesFlag(libFlag, arg))
        {
            ret.lib = true;
        }

        if (matchesFlag(langFlag, arg))
        {
            if (++i <= args_size)
            {
                ret.lang = args.at(i);
            }
            else
            {
                throw std::invalid_argument { "language flag does not have an associated value" };
            }
        }

        if (matchesFlag(stdFlag, arg))
        {
            if (++i <= args_size)
            {
                ret.lang = args.at(i);
            }
            else
            {
                throw std::invalid_argument { "language standard flag does not have an associated value" };
            }
        }

        if (matchesFlag(nameFlag, arg))
        {
            if (++i <= args_size)
            {
                ret.name = args.at(i);
            }
            else
            {
                throw std::invalid_argument { "name flag does not have an associated value" };
            }
        }

        if (matchesFlag(vcsFlag, arg))
        {
            if (++i <= args_size)
            {
                ret.vcs = args.at(i);
            }
            else
            {
                throw std::invalid_argument { "vcs flag does not have an associated value" };
            }
        }
    }

    return ret;
}
