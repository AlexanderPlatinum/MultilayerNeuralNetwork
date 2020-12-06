#include "EnvironmentState.h"

using namespace SimpleAI;

EnvironmentState::EnvironmentState() :
    health(0.0),
    knife(0.0),
    gun(0.0),
    enemy(0.0)
{}

EnvironmentState::EnvironmentState(const double health, const double knife,
                                   const double gun, const double enemy) :
    health(health),
    knife(knife),
    gun(gun),
    enemy(enemy)
{}

double EnvironmentState::getHealth() const
{
    return health;
}

void EnvironmentState::setHealth(const double value)
{
    health = value;
}

double EnvironmentState::getKnife() const
{
    return knife;
}

void EnvironmentState::setKnife(const double value)
{
    knife = value;
}

double EnvironmentState::getGun() const
{
    return gun;
}

void EnvironmentState::setGun(const double value)
{
    gun = value;
}

double EnvironmentState::getEnemy() const
{
    return enemy;
}

void EnvironmentState::setEnemy(const double value)
{
    enemy = value;
}
