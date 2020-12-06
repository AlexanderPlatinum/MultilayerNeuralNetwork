#pragma once

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <functional>

namespace Common
{

class NeuroNetwork
{
private:

    int countOfInput;
    int countOfHidden;
    int countOfOutput;

    double learnRate;

    double **weightsInputToHidden;
    double **weightsHiddenToOutput;

    double *inputCells;
    double *hiddenCells;
    double *targetValues;
    double *calcResult;

    double *errorsOutput;
    double *errorsHidden;

    std::function<double (double)> activationFunction;
    std::function<double (double)> reverseActivationFunction;

public:

    NeuroNetwork();
    ~NeuroNetwork();

    /*!
     * \brief getCountOfInput
     * \return
     */
    int getCountOfInput() const;

    /*!
     * \brief setCountOfInput
     * \param value
     */
    void setCountOfInput(const int value);

    /*!
     * \brief getCountOfHidden
     * \return
     */
    int getCountOfHidden() const;

    /*!
     * \brief setCountOfHidden
     * \param value
     */
    void setCountOfHidden(const int value);

    /*!
     * \brief getCountOfOutput
     * \return
     */
    int getCountOfOutput() const;

    /*!
     * \brief setCountOfOutput
     * \param value
     */
    void setCountOfOutput(const int value);

    /*!
     * \brief getLearnRate
     * \return
     */
    double getLearnRate() const;

    /*!
     * \brief setLearnRate
     * \param value
     */
    void setLearnRate(const double value);

    /*!
     * \brief setInputValue
     * \param index
     * \param value
     */
    void setInputValue(const int index, const double value);

    /*!
     * \brief getInputValue
     * \param index
     * \return
     */
    double getInputValue(const int index) const;

    /*!
     * \brief setTargetValue
     * \param index
     * \param value
     */
    void setTargetValue(const int index, const double value);

    /*!
     * \brief getTargetValue
     * \param index
     * \return
     */
    double getTargetValue(const int index) const;

    /*!
     * \brief getCalcResult
     * \param index
     * \return
     */
    double getCalcResult(const int index) const;

    /*!
     * \brief configureCells
     */
    void configureCells();

    /*!
     * \brief feedForwardMethod
     */
    void feedForwardMethod();

    /*!
     * \brief learnWithBackPropagationMethod
     */
    void backPropagationMethod();

private:

    /*!
     * \brief allocateMemory
     */
    void allocateMemory();

    /*!
     * \brief setRandomWeights
     */
    void setRandomWeights();

    /*!
     * \brief deleteAllocatedMemory
     */
    void deleteAllocatedMemory();

    /*!
     * \brief setDefaultActivationFunctions
     */
    void setDefaultActivationFunctions();
};

}
