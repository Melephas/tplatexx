#pragma once

#include "ILanguageProfile.hpp"

class CProfile : public ILanguageProfile
{
public:
    Language id() const override;
    std::string_view cliName() const override;
    std::string_view cmakeLanguage() const override;
    std::string_view sourceExt() const override;
    std::string_view headerExt() const override;
    int defaultStandard() const override;
    bool supportsStandard(int std) const override;
    std::string compileFeature(int std) const override;
    std::string_view extensionsProperty() const override;
};
