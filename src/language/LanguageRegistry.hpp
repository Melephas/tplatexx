#pragma once

#include <memory>
#include <string_view>
#include <vector>
#include "ILanguageProfile.hpp"
#include "../core/Language.hpp"

class LanguageRegistry
{
public:
    void add(std::unique_ptr<ILanguageProfile> profile);

    const ILanguageProfile* byId(Language lang) const;
    const ILanguageProfile* byCliName(std::string_view name) const;

    const std::vector<std::unique_ptr<ILanguageProfile>>& all() const;

private:
    std::vector<std::unique_ptr<ILanguageProfile>> profiles_;
};
