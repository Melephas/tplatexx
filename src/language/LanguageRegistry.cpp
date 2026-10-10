#include "LanguageRegistry.hpp"

#include "Errors.hpp"


void LanguageRegistry::add(std::unique_ptr<ILanguageProfile> profile)
{
    profiles.push_back(std::move(profile));
}

std::shared_ptr<ILanguageProfile> LanguageRegistry::byId(Language lang) const
{
    const auto idIsLang = [lang](auto& x) -> bool
    {
        return x->id() == lang;
    };

    const auto prof = std::ranges::find_if(profiles, idIsLang);
    if (prof != profiles.end())
    {
        return *prof;
    }

    throw TplateError {
        std::format("Failed to find language profile with id '{}'", lang)
    };
}

std::shared_ptr<ILanguageProfile> LanguageRegistry::byCliName(std::string_view name) const
{
    const auto cliNameIsName = [name](auto& x) -> bool
    {
        return x->cliName() == name;
    };

    const auto prof = std::ranges::find_if(profiles, cliNameIsName);
    if (prof != profiles.end())
    {
        return *prof;
    }

    throw TplateError {
        std::format("Failed to find language profile with name '{}'", name)
    };
}

const std::vector<std::shared_ptr<ILanguageProfile>>& LanguageRegistry::all() const
{
    return profiles;
}
