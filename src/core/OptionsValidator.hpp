#pragma once

#include "ProjectOptions.hpp"


struct RawArgs;
class LanguageRegistry;


class OptionsValidator
{
    const LanguageRegistry& languages;

public:
    explicit OptionsValidator(const LanguageRegistry& languages);

    ProjectOptions validate(const RawArgs& raw) const;
};
