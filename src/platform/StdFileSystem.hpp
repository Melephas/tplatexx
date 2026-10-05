#pragma once

#include "IFileSystem.hpp"

class StdFileSystem : public IFileSystem
{
public:
    bool exists(const std::filesystem::path& p) const override;
    bool isEmptyDirectory(const std::filesystem::path& p) const override;
    void createDirectories(const std::filesystem::path& p) override;
    void writeFile(const std::filesystem::path& p, std::string_view contents) override;
    void removeAll(const std::filesystem::path& p) override;
};
