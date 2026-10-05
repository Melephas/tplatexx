#pragma once

#include <filesystem>
#include "GeneratedFile.hpp"


class IFileSystem;


class ProjectWriter
{
    IFileSystem& fileSystem;

public:
    explicit ProjectWriter(IFileSystem& fs);

    void write(const ProjectPlan& plan, const std::filesystem::path& root);
};
