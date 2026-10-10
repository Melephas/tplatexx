#pragma once

#include <format>

enum class Language
{
    C,
    Cpp
};

template <class CharT>
struct std::formatter<Language, CharT> : std::formatter<std::string>
{
    auto format(Language l, format_context& ctx) const
    {
        switch (l)
        {
        case Language::C:
            return std::format_to(ctx.out(), "Language::C");
        case Language::Cpp:
            return std::format_to(ctx.out(), "Language::Cpp");
        }
    }
};
