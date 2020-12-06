#include "NeuroNetwork.h"

using namespace Common;

NeuroNetwork::NeuroNetwork() :
    countOfInput{0},
    countOfHidden{0},
    countOfOutput{0},
    learnRate{0.0}
{
    weightsInputToHidden  = nullptr;
    weightsHiddenToOutput = nullptr;

    inputCells   = nullptr;
    hiddenCells  = nullptr;
    targetValues = nullptr;
    calcResult   = nullptr;

    errorsOutput = nullptr;
    errorsHidden = nullptr;

    setDefaultActivationFunctions();
}

NeuroNetwork::~NeuroNetwork()
{
    deleteAllocatedMemory();
}

int NeuroNetwork::getCountOfInput() const
{
    return countOfInput;
}

void NeuroNetwork::setCountOfInput(const int value)
{
    countOfInput = value;
}

int NeuroNetwork::getCountOfHidden() const
{
    return countOfHidden;
}

void NeuroNetwork::setCountOfHidden(const int value)
{
    countOfHidden = value;
}

int NeuroNetwork::getCountOfOutput() const
{
    return countOfOutput;
}

void NeuroNetwork::setCountOfOutput(const int value)
{
    countOfOutput = value;
}

double NeuroNetwork::getLearnRate() const
{
    return learnRate;
}

void NeuroNetwork::setLearnRate(const double value)
{
    learnRate = value;
}

void NeuroNetwork::setInputValue(const int index, const double value)
{
    if (index >= countOfInput)
    {
        throw std::out_of_range("setInputValue index can be < countOfInput");
    }

    inputCells[index] = value;
}

double NeuroNetwork::getInputValue(const int index) const
{
    if (index >= countOfInput)
    {
        throw std::out_of_range("getInputValue index can be < countOfInput");
    }

    return inputCells[index];
}

void NeuroNetwork::setTargetValue(int index, double value)
{
    if (index >= countOfOutput)
    {
        throw std::out_of_range("setTargetValue index can be < countOfOutput");
    }

    targetValues[index] = value;
}

double NeuroNetwork::getTargetValue(const int index) const
{
    if (index >= countOfOutput)
    {
        throw std::out_of_range("getTargetValue index can be < countOfOutput");
    }

    return targetValues[index];
}

double NeuroNetwork::getCalcResult(const int index) const
{
    if (index >= countOfOutput)
    {
        throw std::out_of_range("getCalcResult index can be < countOfOutput");
    }

    return calcResult[index];
}

void NeuroNetwork::configureCells()
{
    allocateMemory();
    setRandomWeights();
    feedForwardMethod();
}

void NeuroNetwork::allocateMemory()
{
    {
        weightsInputToHidden = new double*[countOfInput + 1];

        for (int i = 0; i < countOfInput + 1; i++)
        {
            weightsInputToHidden[i] = new double[countOfHidden];
        }
    }

    {
        weightsHiddenToOutput = new double*[countOfHidden + 1];

        for (int i = 0; i < countOfHidden + 1; i++)
        {
            weightsHiddenToOutput[i] = new double[countOfOutput];
        }
    }

    inputCells   = new double[countOfInput];
    hiddenCells  = new double[countOfHidden];
    targetValues = new double[countOfOutput];
    calcResult   = new double[countOfOutput];

    errorsOutput = new double[countOfOutput];
    errorsHidden = new double[countOfHidden];
}

void NeuroNetwork::setRandomWeights()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::function<double ()> random = [] () -> double
    {
        const double LOW = -0.5;
        const double HIGH = 0.5;

        return (LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX / (HIGH - LOW)));
    };

    for (int input = 0; input < countOfInput + 1; input++)
    {
        for (int hidden = 0; hidden < countOfHidden; hidden++)
        {
            weightsInputToHidden[input][hidden] = random();
        }
    }

    for (int hidden = 0; hidden < countOfHidden + 1; hidden++)
    {
        for (int output = 0; output < countOfOutput; output++)
        {
            weightsHiddenToOutput[hidden][output] = random();
        }
    }
}

void NeuroNetwork::feedForwardMethod()
{
    for (int hidden = 0; hidden < countOfHidden; hidden++)
    {
        double summary = 0.0;

        for (int input = 0; input < countOfInput; input++)
        {
            summary += inputCells[input] * weightsInputToHidden[input][hidden];
        }

        summary += weightsInputToHidden[countOfInput][hidden];
        hiddenCells[hidden] = activationFunction(summary);
    }

    for (int output = 0; output < countOfOutput; output++)
    {
        double summary = 0.0;

        for (int hidden = 0; hidden < countOfHidden; hidden++)
        {
            summary += hiddenCells[hidden] * weightsHiddenToOutput[hidden][output];
        }

        summary += weightsHiddenToOutput[countOfHidden][output];
        calcResult[output] = activationFunction(summary);
    }
}

void NeuroNetwork::backPropagationMethod()
{
    for (int output = 0; output < countOfOutput; output++)
    {
        errorsOutput[output] =
            (targetValues[output] - calcResult[output]) *
                reverseActivationFunction(calcResult[output]);
    }

    for (int hidden = 0; hidden < countOfHidden; hidden++)
    {
        errorsHidden[hidden] = 0.0;

        for (int output = 0; output < countOfOutput; output++)
        {
            errorsHidden[hidden] += errorsOutput[output] *
                    weightsHiddenToOutput[hidden][output];
        }

        errorsHidden[hidden] *= reverseActivationFunction(hiddenCells[hidden]);
    }

    for (int output = 0; output < countOfOutput; output++)
    {
        for (int hidden = 0; hidden < countOfHidden; hidden++)
        {
            weightsHiddenToOutput[hidden][output] +=
                    (learnRate * errorsOutput[output] * hiddenCells[hidden]);
        }

        weightsHiddenToOutput[countOfHidden][output] += (learnRate * errorsOutput[output]);
    }

    for (int hidden = 0; hidden < countOfHidden; hidden++)
    {
        for (int input = 0; input < countOfInput; input++)
        {
            weightsInputToHidden[input][hidden] +=
                    (learnRate * errorsHidden[hidden] * inputCells[input]);
        }

        weightsInputToHidden[countOfInput][hidden] += (learnRate * errorsHidden[hidden]);
    }
}

void NeuroNetwork::deleteAllocatedMemory()
{
    if (weightsInputToHidden != nullptr)
    {
        for (int i = 0; i < countOfInput + 1; i++)
        {
            delete [] weightsInputToHidden[i];
        }

        delete [] weightsInputToHidden;
    }

    if (weightsHiddenToOutput != nullptr)
    {
        for (int i = 0; i < countOfHidden + 1; i++)
        {
            delete [] weightsHiddenToOutput[i];
        }

        delete [] weightsHiddenToOutput;
    }

    delete [] inputCells;
    delete [] hiddenCells;
    delete [] targetValues;
    delete [] calcResult;
    delete [] errorsOutput;
    delete [] errorsHidden;
}

void NeuroNetwork::setDefaultActivationFunctions()
{
    activationFunction = [] (double value) -> double
    {
        return (1.0 / (1.0 + std::exp(-value)));
    };

    reverseActivationFunction = [] (double value) -> double
    {
        return (value * (1.0 - value));
    };
}
