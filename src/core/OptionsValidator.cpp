#include "OptionsValidator.hpp"

#include "Errors.hpp"


OptionsValidator::OptionsValidator(const LanguageRegistry& languages)
    : languages { languages } {}

ProjectOptions OptionsValidator::validate(const RawArgs& raw) const
{
    throw UnimplementedError {};
}
