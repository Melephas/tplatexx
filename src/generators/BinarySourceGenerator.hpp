#pragma once

#include "IFileGenerator.hpp"

class LanguageRegistry;
class TemplateRenderer;

class BinarySourceGenerator : public IFileGenerator
{
public:
    BinarySourceGenerator(const LanguageRegistry& languages, const TemplateRenderer& renderer);

    bool appliesTo(const ProjectOptions& options) const override;
    std::vector<GeneratedFile> generate(const ProjectOptions& options) const override;

private:
    const LanguageRegistry& languages_;
    const TemplateRenderer& renderer_;
};
