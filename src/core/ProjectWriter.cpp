#include "ProjectWriter.hpp"

#include "Errors.hpp"


ProjectWriter::ProjectWriter(IFileSystem& fs)
    : fileSystem { fs } {}

void ProjectWriter::write(const ProjectPlan& plan, const std::filesystem::path& root)
{
    throw UnimplementedError {};
}
