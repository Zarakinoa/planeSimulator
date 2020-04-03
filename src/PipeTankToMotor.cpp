#include "../include/PipeTankToMotor.h"
#include <iostream>

/**
 * @brief Construct a new Pipe Tankto Motor:: Pipe Tankto Motor object
 * 
 * @param source 
 * @param valve1 
 * @param valve2 
 * @param motor 
 */
PipeTanktoMotor::PipeTanktoMotor(Tank *source, Valve *valve1, Valve *valve2, Motor *motor) : Pipe(source, valve1), m_Valve2(valve2), m_Motor(motor)
{
}

/**
 * @brief Cas custome
 * 
 */
void PipeTanktoMotor::reconfiguration()
{
    if (m_Source->isEmpty())
    {
        if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
        {
            m_Valve->getMotor(m_Source)->beingNotFed();
        }

        if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
        {
            m_Valve2->getMotor(m_Source)->beingNotFed();
        }

        if (m_Motor->isFed() && (m_Motor->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Motor->getPump().getName() == m_Source->getEmergencyPump().getName()))
        {
            m_Motor->beingNotFed();
        }
    }

    else
    {
        if (m_Source->getPrimaryPump().getState() == 0 && m_Source->getEmergencyPump().getState() != 0)
        {
            m_Source->decrementCapacity(1);

            if (!m_Valve->isClose() && !m_Valve2->isClose())
            {
                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && !m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (!m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(2);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }
            }
        }

        else if (m_Source->getPrimaryPump().getState() == 0 && m_Source->getEmergencyPump().getState() == 0)
        {
            m_Source->decrementCapacity(2);

            if (!m_Valve->isClose() && !m_Valve2->isClose())
            {
                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && !m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (!m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(2);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getPrimaryPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getPrimaryPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }
            }
        }

        else if (m_Source->getPrimaryPump().getState() == 2 && m_Source->getEmergencyPump().getState() == 0)
        {
            m_Source->decrementCapacity(1);

            if (!m_Valve->isClose() && !m_Valve2->isClose())
            {
                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getEmergencyPump());
                    m_Motor->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && !m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getEmergencyPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getEmergencyPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve2->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (!m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(1);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getEmergencyPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getEmergencyPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }

                if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
                {
                    m_Valve->getMotor(m_Source)->beingNotFed();
                }
            }

            else if (m_Valve->isClose() && m_Valve2->isClose())
            {
                m_Source->decrementCapacity(2);

                if (!m_Motor->isFed())
                {
                    m_Motor->setPump(&m_Source->getEmergencyPump());
                    m_Motor->beingFed();
                }

                if (!m_Valve->getMotor(m_Source)->isFed())
                {
                    m_Valve->getMotor(m_Source)->setPump(&m_Source->getEmergencyPump());
                    m_Valve->getMotor(m_Source)->beingFed();
                }

                if (!m_Valve2->getMotor(m_Source)->isFed())
                {
                    m_Valve2->getMotor(m_Source)->setPump(&m_Source->getEmergencyPump());
                    m_Valve2->getMotor(m_Source)->beingFed();
                }
            }
        }

        else if (m_Source->getPrimaryPump().getState() == 2 && m_Source->getEmergencyPump().getState() != 0)
        {
            m_Source->stopping();

            if (m_Motor->isFed() && (m_Motor->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Motor->getPump().getName() == m_Source->getEmergencyPump().getName()))
            {
                m_Motor->beingNotFed();
            }

            if (m_Valve->getMotor(m_Source)->isFed() && (m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
            {
                m_Valve->getMotor(m_Source)->beingNotFed();
            }

            if (m_Valve2->getMotor(m_Source)->isFed() && (m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getPrimaryPump().getName() || m_Valve2->getMotor(m_Source)->getPump().getName() == m_Source->getEmergencyPump().getName()))
            {
                m_Valve2->getMotor(m_Source)->beingNotFed();
            }
        }
    }
}

/**
 * @brief Pompe to moteur
 * 
 */
void PipeTanktoMotor::run()
{
    reconfiguration();
}