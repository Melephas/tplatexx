#pragma once

#include <memory>
#include <string_view>
#include <vector>
#include "ILanguageProfile.hpp"
#include "../core/Language.hpp"


class LanguageRegistry
{
    std::vector<std::shared_ptr<ILanguageProfile>> profiles;

public:
    void add(std::unique_ptr<ILanguageProfile> profile);

    std::shared_ptr<ILanguageProfile> byId(Language lang) const;
    std::shared_ptr<ILanguageProfile> byCliName(std::string_view name) const;

    const std::vector<std::shared_ptr<ILanguageProfile>>& all() const;
};
