#pragma once
#include <map>
#include <string>
#include <string_view>

class TemplateRenderer
{
public:
    using Vars = std::map<std::string, std::string>;

    std::string render(std::string_view tmpl, const Vars& vars) const;
};
