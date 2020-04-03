#include "../include/PipeTankToTank.h"
#include <iostream>

/**
 * @brief Construct a new Pipe Tankto Tank:: Pipe Tankto Tank object
 * 
 * @param source 
 * @param valve 
 * @param desination 
 */
PipeTanktoTank::PipeTanktoTank(Tank *source, Valve *valve, Tank *desination) : Pipe(source, valve), m_Destination(desination)
{
}

/**
 * @brief Cas custom
 * 
 */
void PipeTanktoTank::reconfiguration()
{

    if (m_Source->getCapacity() < m_Destination->getCapacity())
    {
        if (m_Source->getCapacity() < m_Source->getCapacityMax() && m_Destination->getCapacity() > 0)
        {
            m_Source->incrementCapacity();
            m_Destination->decrementCapacity(1);
        }
    }

    else if (m_Source->getCapacity() > m_Destination->getCapacity())
    {
        if (m_Source->getCapacity() > 0 && m_Destination->getCapacity() < m_Destination->getCapacityMax())
        {
            m_Source->decrementCapacity(1);
            m_Destination->incrementCapacity();
        }
    }
}

/**
 * @brief Tank to Tank
 * 
 */
void PipeTanktoTank::run()
{
    if (m_Valve->getState() == 1)
    {
        reconfiguration();
    }
}
