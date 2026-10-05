#pragma once

#include <cstdint>


// "calls retrieve only the least significant 8 bits of the exit status"
// - https://en.wikipedia.org/wiki/Exit_status, Semantics::POSIX subsection
enum class ReturnCode : std::uint8_t
{
    Success,
    RuntimeError,
    UsageError
};
