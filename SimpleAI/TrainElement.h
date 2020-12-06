#pragma once

#include <array>

#include "Result.h"
#include "EnvironmentState.h"

namespace SimpleAI
{

struct TrainElement
{
    EnvironmentState state;

    std::array<double, 4> outputNwuronsResult;
    Result recognizeResult;
};

}
