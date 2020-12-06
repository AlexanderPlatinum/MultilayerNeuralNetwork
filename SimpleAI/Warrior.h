#pragma once

#include <array>
#include <vector>
#include <string>
#include <functional>

#include "../Common/NeuroNetwork.h"
#include "EnvironmentState.h"

#include "Result.h"
#include "TrainElement.h"

namespace SimpleAI
{

class Warrior
{
private:

    const int COUNT_INPUT_NEURONS = 4;
    const int COUNT_HIDDEN_NEURONS = 3;
    const int COUNT_OUTPUT_NEURONS = 4;

    const double LEARN_RATE = 0.2;

    const int COUNT_OF_SAMPLES = 10000;

    Common::NeuroNetwork network;

public:

    Warrior();

    /*!
     * \brief train
     * \param elements
     */
    void train(const std::vector<TrainElement> &elements);

    /*!
     * \brief check
     * \param elements
     * \return
     */
    double check(const std::vector<TrainElement> &elements);

    /*!
     * \brief recogneize
     * \param state
     * \return
     */
    Result recogneize(const EnvironmentState &state);

    /*!
     * \brief getResultString
     * \param value
     * \return
     */
    static std::string getResultString(const Result value);

private:

    /*!
     * \brief configureNetwork
     */
    void configureNetwork();

    /*!
     * \brief setEnviropmentStateToNetwork
     * \param state
     */
    void setEnvironmentStateToNetwork(const EnvironmentState &state);
};

}
