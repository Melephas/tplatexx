#include "ProjectPlanner.hpp"

#include <set>

#include "Errors.hpp"


ProjectPlanner::ProjectPlanner(std::vector<std::unique_ptr<IFileGenerator>> generators)
    : generators { std::move(generators) } {}

void ProjectPlanner::detectCollisions(const ProjectPlan& plan) const
{
    std::set<std::filesystem::path> seenPaths;

    for (const auto& [relativePath, content] : plan)
    {
        if (seenPaths.contains(relativePath))
        {
            throw FileSystemError {
                std::format("Detected collision in project plan: {}", relativePath.c_str())
            };
        }

        seenPaths.insert(relativePath);
    }
}

ProjectPlan ProjectPlanner::plan(const ProjectOptions& opts) const
{
    ProjectPlan plan {};

    for (const auto& gen : generators)
    {
        if (gen->appliesTo(opts))
        {
            for (auto& file : gen->generate(opts))
            {
                plan.push_back(std::move(file));
            }
        }
    }

    detectCollisions(plan);
    return plan;
}
