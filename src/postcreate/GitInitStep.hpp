#pragma once

#include "IPostCreateStep.hpp"

class ICommandRunner;

class GitInitStep : public IPostCreateStep
{
public:
    explicit GitInitStep(ICommandRunner& runner);

    bool appliesTo(const ProjectOptions& options) const override;
    void run(const ProjectOptions& options) override;

private:
    ICommandRunner& runner_;
};
