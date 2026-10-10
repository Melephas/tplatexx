#include "NewCommand.hpp"

#include "ReturnCode.hpp"
#include "../core/Errors.hpp"

NewCommand::NewCommand(
    const ArgumentParser parser,
    const OptionsValidator validator,
    ProjectPlanner planner,
    const ProjectWriter writer,
    std::vector<std::unique_ptr<IPostCreateStep>> postSteps,
    IReporter& reporter
) : parser { parser },
    validator { validator },
    planner { std::move(planner) }, // No copy constructor (std::unique_ptr)
    writer { writer },
    postSteps { std::move(postSteps) },
    reporter { reporter }
{}

std::string NewCommand::name() const
{
    return "new";
}

std::string NewCommand::description() const
{
    throw UnimplementedError {};
}

std::string NewCommand::usage() const
{
    // TODO: write a proper usage for this
    throw UnimplementedError {};
}

ReturnCode NewCommand::run(const std::vector<std::string>& args)
{
    const RawArgs raw = parser.parse(args);
    const ProjectOptions options = validator.validate(raw);
    const ProjectPlan plan = planner.plan(options);

    writer.write(plan, options.root);

    for (const auto& step : postSteps)
    {
        if (step->appliesTo(options))
        {
            step->run(options);
        }
    }

    reporter.created(options);

    return ReturnCode::Success;
}
