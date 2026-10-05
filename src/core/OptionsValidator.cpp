#include "OptionsValidator.hpp"


OptionsValidator::OptionsValidator(const LanguageRegistry& languages)
    : languages { languages } {}

ProjectOptions OptionsValidator::validate(const RawArgs& raw) const
{
    ProjectOptions opts {};
    return opts;
}
