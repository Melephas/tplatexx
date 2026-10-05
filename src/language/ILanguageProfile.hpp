#pragma once

#include <string>
#include <string_view>
#include "../core/Language.hpp"

struct ILanguageProfile
{
    virtual ~ILanguageProfile() = default;

    virtual Language id() const = 0;
    virtual std::string_view cliName() const = 0;
    virtual std::string_view cmakeLanguage() const = 0;
    virtual std::string_view sourceExt() const = 0;
    virtual std::string_view headerExt() const = 0;
    virtual int defaultStandard() const = 0;
    virtual bool supportsStandard(int std) const = 0;
    virtual std::string compileFeature(int std) const = 0;
    virtual std::string_view extensionsProperty() const = 0;
};
