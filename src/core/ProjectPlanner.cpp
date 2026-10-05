#include "ProjectPlanner.hpp"


ProjectPlanner::ProjectPlanner(std::vector<std::unique_ptr<IFileGenerator>> generators)
    : generators { std::move(generators) } {}

void ProjectPlanner::detectCollisions(const ProjectPlan& plan) const {}

ProjectPlan ProjectPlanner::plan(const ProjectOptions& o) const {}
