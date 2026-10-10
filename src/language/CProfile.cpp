#include "CProfile.hpp"


constexpr std::array cStandards {
    89, 95, 99, 11, 17, 23
};

Language CProfile::id() const
{
    return Language::C;
}

std::string_view CProfile::cliName() const
{
    return "c";
}

std::string_view CProfile::cmakeLanguage() const
{
    return "C";
}

std::string_view CProfile::sourceExt() const
{
    return ".c";
}

std::string_view CProfile::headerExt() const
{
    return ".h";
}

int CProfile::defaultStandard() const
{
    return 23;
}

bool CProfile::supportsStandard(const int std) const
{
    return std::ranges::find(cStandards, std) != cStandards.end();
}

std::string CProfile::compileFeature(int std) const
{

}

std::string_view CProfile::extensionsProperty() const {}
