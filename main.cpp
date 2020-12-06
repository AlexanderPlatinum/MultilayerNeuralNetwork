#include <iomanip>
#include <iostream>

#include "SimpleAI/Warrior.h"

std::vector<SimpleAI::TrainElement> trainElements =
{
    {
        {2.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        SimpleAI::Result::DODGE
    },

    {
        {2.0, 0.0, 0.0, 1.0},
        {0.0, 0.0, 1.0, 0.0},
        SimpleAI::Result::DODGE
    },

    {
        {2.0, 0.0, 1.0, 1.0},
        {1.0, 0.0, 0.0, 0.0},
        SimpleAI::Result::ATTACK
    },

    {
        {2.0, 0.0, 1.0, 2.0},
        {1.0, 0.0, 0.0, 0.0},
        SimpleAI::Result::ATTACK
    },

    {
        {2.0, 1.0, 0.0, 2.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {2.0, 1.0, 0.0, 1.0},
        {1.0, 0.0, 0.0, 0.0},
        SimpleAI::Result::ATTACK
    },

    {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        SimpleAI::Result::DODGE
    },

    {
        {1.0, 0.0, 0.0, 1.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {1.0, 0.0, 1.0, 1.0},
        {1.0, 0.0, 0.0, 0.0},
        SimpleAI::Result::ATTACK
    },

    {
        {1.0, 0.0, 1.0, 2.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {1.0, 1.0, 0.0, 2.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {1.0, 1.0, 0.0, 1.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        SimpleAI::Result::DODGE
    },

    {
        {0.0, 0.0, 0.0, 1.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {0.0, 0.0, 1.0, 1.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },

    {
        {0.0, 0.0, 1.0, 2.0},
        {0.0, 1.0, 0.0, 0.0},
        SimpleAI::Result::RUN
    },

    {
        {0.0, 1.0, 0.0, 2.0},
        {0.0, 1.0, 0.0, 0.0},
        SimpleAI::Result::RUN
    },

    {
        {0.0, 1.0, 0.0, 1.0},
        {0.0, 0.0, 0.0, 1.0},
        SimpleAI::Result::HIDE
    },
};

std::vector<SimpleAI::EnvironmentState> states =
{
    {2.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0, 2.0},
    {0.0, 0.0, 0.0, 0.0},
    {0.0, 1.0, 1.0, 1.0},
    {2.0, 0.0, 1.0, 3.0},
    {2.0, 1.0, 0.0, 3.0},
    {0.0, 1.0, 0.0, 3.0}
};

int main()
{
    SimpleAI::Warrior warrior;

    warrior.train(trainElements);
    double trainQuality = warrior.check(trainElements);

    std::cout << "Качество обучения сети := ";
    std::cout << static_cast<int>(trainQuality * 100.0);
    std::cout << "%" << std::endl;

    std::cout << "Здоровье Нож Пистолет Враг" << std::endl;

    std::vector<SimpleAI::EnvironmentState>::iterator it;
    for (it = states.begin(); it != states.end(); ++it)
    {
        std::cout << std::setw(5) << static_cast<int>(it->getHealth());
        std::cout << std::setw(6) << static_cast<int>(it->getKnife());
        std::cout << std::setw(7) << static_cast<int>(it->getGun());
        std::cout << std::setw(7) << static_cast<int>(it->getEnemy());

        SimpleAI::Result result = warrior.recogneize((*it));
        std::cout << "\t" << SimpleAI::Warrior::getResultString(result);
        std::cout << std::endl;
    }

    return 0;
}
