#pragma once

#include "IFileGenerator.hpp"

class GitignoreGenerator : public IFileGenerator
{
public:
    bool appliesTo(const ProjectOptions& options) const override;
    std::vector<GeneratedFile> generate(const ProjectOptions& options) const override;
};
