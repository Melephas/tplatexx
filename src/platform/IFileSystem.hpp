#pragma once

#include <filesystem>
#include <string_view>

class IFileSystem
{
public:
    virtual ~IFileSystem() = default;

    virtual bool exists(const std::filesystem::path& p) const = 0;
    virtual bool isEmptyDirectory(const std::filesystem::path& p) const = 0;
    virtual void createDirectories(const std::filesystem::path& p) = 0;
    virtual void writeFile(const std::filesystem::path& p, std::string_view contents) = 0;
    virtual void removeAll(const std::filesystem::path& p) = 0;
};
