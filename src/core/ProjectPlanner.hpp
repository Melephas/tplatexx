#pragma once

#include <memory>
#include <vector>

#include "GeneratedFile.hpp"
#include "IFileGenerator.hpp"
#include "ProjectOptions.hpp"



class ProjectPlanner
{
    std::vector<std::unique_ptr<IFileGenerator>> generators;

    void detectCollisions(const ProjectPlan& plan) const;

public:
    explicit ProjectPlanner(std::vector<std::unique_ptr<IFileGenerator>> generators);

    ProjectPlan plan(const ProjectOptions& opts) const;
};



