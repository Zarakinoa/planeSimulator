#include "../include/Pipe.h"

/**
 * @brief Construct a new Pipe:: Pipe object
 * 
 * @param source 
 * @param valve 
 */
Pipe::Pipe(Tank *source, Valve *valve) : m_Source(source), m_Valve(valve)
{
}

/**
 * @brief Le tube délivre juste le fuel
 * 
 */
void Pipe::run()
{
}

/**
 * @brief Destroy the Pipe:: Pipe object
 * 
 */
Pipe::~Pipe()
{
}