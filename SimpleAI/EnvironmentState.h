#pragma once

namespace SimpleAI
{

class EnvironmentState
{
private:

    double health;
    double knife;
    double gun;
    double enemy;

public:

    EnvironmentState();

    /*!
     * \brief EnvironmentState
     * \param health
     * \param knife
     * \param gun
     * \param enemy
     */
    EnvironmentState(const double health, const double knife,
                     const double gun, const double enemy);

    /*!
     * \brief getHealth
     * \return
     */
    double getHealth() const;

    /*!
     * \brief setHealth
     * \param value
     */
    void setHealth(const double value);

    /*!
     * \brief getKnife
     * \return
     */
    double getKnife() const;

    /*!
     * \brief setKnife
     * \param value
     */
    void setKnife(const double value);

    /*!
     * \brief getGun
     * \return
     */
    double getGun() const;

    /*!
     * \brief setGun
     * \param value
     */
    void setGun(const double value);

    /*!
     * \brief getEnemy
     * \return
     */
    double getEnemy() const;

    /*!
     * \brief setEnemy
     * \param value
     */
    void setEnemy(const double value);
};

}
