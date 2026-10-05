#pragma once

#include "IFileGenerator.hpp"

class TemplateRenderer;

class ReadmeGenerator : public IFileGenerator
{
public:
    explicit ReadmeGenerator(const TemplateRenderer& renderer);

    bool appliesTo(const ProjectOptions& options) const override;
    std::vector<GeneratedFile> generate(const ProjectOptions& options) const override;

private:
    const TemplateRenderer& renderer_;
};
