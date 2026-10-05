#pragma once

#include "../core/ProjectOptions.hpp"

class IPostCreateStep
{
public:
    virtual ~IPostCreateStep() = default;

    virtual bool appliesTo(const ProjectOptions& options) const = 0;
    virtual void run(const ProjectOptions& options) = 0;
};
