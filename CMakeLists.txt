cmake_minimum_required(VERSION 4.3)
project(tplate++
    LANGUAGES CXX
    VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp
    src/cli/ArgumentParser.cpp
    src/cli/CommandRegistry.cpp
    src/cli/NewCommand.cpp
    src/core/OptionsValidator.cpp
    src/ui/ConsoleReporter.cpp
    src/cli/Dispatcher.cpp
    src/cli/HelpCommand.cpp
    src/core/ProjectPlanner.cpp
    src/core/ProjectWriter.cpp
    src/cli/InfoCommand.cpp
    src/cli/InfoCommand.hpp
    src/language/LanguageRegistry.cpp
    src/language/CProfile.cpp
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
        src/cli
        src/core
        src/generators
        src/language
        src/platform
        src/postcreate
        src/templates
        src/ui
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE TPLATE_VERSION="${PROJECT_VERSION}"
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic
)
