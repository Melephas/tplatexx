#pragma once

#include <vector>
#include "../core/GeneratedFile.hpp"
#include "../core/ProjectOptions.hpp"


class IFileGenerator
{
public:
    virtual ~IFileGenerator() = default;

    virtual bool appliesTo(const ProjectOptions& options) const = 0;
    virtual std::vector<GeneratedFile> generate(const ProjectOptions& options) const = 0;
};
