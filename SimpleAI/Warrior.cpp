#include "Warrior.h"

using namespace SimpleAI;

Warrior::Warrior()
{
    configureNetwork();
}

void Warrior::train(const std::vector<TrainElement> &elements)
{
    for (int i = 0; i < COUNT_OF_SAMPLES; i++)
    {
        std::vector<TrainElement>::const_iterator it;
        for (it = elements.cbegin(); it != elements.cend(); ++it)
        {
            setEnvironmentStateToNetwork(it->state);

            for (int t = 0; t < COUNT_OUTPUT_NEURONS; t++)
            {
                network.setTargetValue(t, it->outputNwuronsResult[t]);
            }

            network.feedForwardMethod();
            network.backPropagationMethod();
        }
    }
}

double Warrior::check(const std::vector<TrainElement> &elements)
{
    int countOfGoodChecks = 0;

    std::vector<TrainElement>::const_iterator it;
    for (it = elements.cbegin(); it != elements.cend(); ++it)
    {
        Result calcResult = recogneize(it->state);

        if (calcResult == it->recognizeResult)
        {
            countOfGoodChecks++;
        }

    }

    return static_cast<double>(countOfGoodChecks) / static_cast<double>(elements.size());
}

Result Warrior::recogneize(const EnvironmentState &state)
{
    setEnvironmentStateToNetwork(state);
    network.feedForwardMethod();

    int index = 1;
    double maxValue = 0.0;

    for(int i = 1; i <= COUNT_OUTPUT_NEURONS; i++)
    {
        double currentValue = network.getCalcResult(i - 1);

        if (currentValue >= maxValue)
        {
            index = i;
            maxValue = currentValue;
        }
    }

    return static_cast<Result>(index);
}

std::string Warrior::getResultString(const Result value)
{
    switch (value)
    {
        case Result::ATTACK:
            return std::string{"Атаковать"};

        case Result::RUN:
            return std::string{"Бежать"};

        case Result::DODGE:
            return std::string{"Уворачиваться"};

        case Result::HIDE:
            return std::string{"Прятаться"};

        default:
            return std::string{"Действие не найдено!"};
    }
}

void Warrior::configureNetwork()
{
    network.setCountOfInput(COUNT_INPUT_NEURONS);
    network.setCountOfHidden(COUNT_HIDDEN_NEURONS);
    network.setCountOfOutput(COUNT_OUTPUT_NEURONS);

    network.setLearnRate(LEARN_RATE);

    network.configureCells();
}

void Warrior::setEnvironmentStateToNetwork(const EnvironmentState &state)
{
    network.setInputValue(0, state.getHealth());
    network.setInputValue(1, state.getKnife());
    network.setInputValue(2, state.getGun());
    network.setInputValue(3, state.getEnemy());
}
