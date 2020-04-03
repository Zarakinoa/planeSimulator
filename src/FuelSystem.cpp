#include "../include/FuelSystem.h"

/**
 * @brief Construct a new Fuel System:: Fuel System object
 * 
 */
FuelSystem::FuelSystem() : m_T1("Tank1", 200, "P11", "P12"), m_T2("Tank2", 100, "P21", "P22"), m_T3("Tank3", 200, "P31", "P32"),
                           m_M1("M1", &m_T1.getPrimaryPump()), m_M2("M2", &m_T2.getPrimaryPump()), m_M3("M3", &m_T3.getPrimaryPump()),
                           m_V12("V12"), m_V13("V13"), m_V23("V23"), m_VT12("VT12"), m_VT23("VT23"),
                           m_T1_to_T2(&m_T1, &m_VT12, &m_T2), m_T2_to_T3(&m_T2, &m_VT23, &m_T3),
                           m_P_T1(&m_T1, &m_V12, &m_V13, &m_M1), m_P_T2(&m_T2, &m_V12, &m_V23, &m_M2), m_P_T3(&m_T3, &m_V13, &m_V23, &m_M3)
{
    initializeValveMap();
}

/**
 * @brief Représentation des Réservoirs
 * 
 * @return std::vector<Tank *> 
 */
std::vector<Tank *> FuelSystem::getTanks()
{
    std::vector<Tank *> v_Tanks = {&m_T1, &m_T2, &m_T3};
    return v_Tanks;
}

/**
 * @brief Représentation des Moteurs
 * 
 * @return std::vector<Motor *> 
 */
std::vector<Motor *> FuelSystem::getMotors()
{
    std::vector<Motor *> v_Motors = {&m_M1, &m_M2, &m_M3};
    return v_Motors;
}

/**
 * @brief Représentation des Vannes
 * 
 * @return std::vector<Valve *> 
 */
std::vector<Valve *> FuelSystem::getValves()
{
    std::vector<Valve *> v_Valves = {&m_V12, &m_V13, &m_V23, &m_VT12, &m_VT23};
    return v_Valves;
}

/**
 * @brief Représentation des Tubes
 * 
 * @return std::vector<Pipe *> 
 */
std::vector<Pipe *> FuelSystem::getPipe()
{
    std::vector<Pipe *> v_Pipe = {&m_T1_to_T2, &m_T2_to_T3, &m_P_T1, &m_P_T2, &m_P_T3};
    return v_Pipe;
}

/**
 * @brief Connexion entre les Moteurs et les Réservoirs
 * 
 */
void FuelSystem::initializeValveMap()
{
    m_V12.push_in_map(&m_T1, &m_M2);
    m_V12.push_in_map(&m_T2, &m_M1);

    m_V13.push_in_map(&m_T1, &m_M3);
    m_V13.push_in_map(&m_T3, &m_M1);

    m_V23.push_in_map(&m_T2, &m_M3);
    m_V23.push_in_map(&m_T3, &m_M2);
}

/**
 * @brief Retourne si les réservoirs sont vides ou pas
 * 
 * @return true 
 * @return false 
 */
bool FuelSystem::allTanksEmpty()
{
    if (m_T1.isEmpty() && m_T2.isEmpty() && m_T3.isEmpty())
    {
        return true;
    }

    return false;
}

/**
 * @brief Dessine les tubes
 * 
 */
void FuelSystem::drawPipe()
{
    DrawLine((FL_WIDTH / 8) + (FL_WIDTH / 6), (FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2, ((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)), (FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2, BLACK);
    DrawLine(((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8), (FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2, (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))), (FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2, BLACK);
    DrawLine((FL_WIDTH / 8) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.7, (FL_WIDTH / 8) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)), BLACK);
    DrawLine((FL_WIDTH / 8) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.7, (FL_WIDTH / 8) + ((FL_WIDTH / 6) / 1.5), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.7, BLACK);
    DrawLine((FL_WIDTH / 8) + ((FL_WIDTH / 6) / 1.5), (FL_HEIGHT / 50) + (FL_HEIGHT / 5), (FL_WIDTH / 8) + ((FL_WIDTH / 6) / 1.5), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8, BLACK);
    DrawLine(((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + ((FL_WIDTH / 8) / 2), (FL_HEIGHT / 50) + (FL_HEIGHT / 5), (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8) / 2 - (FL_WIDTH / 14) / 2) + ((FL_WIDTH / 14) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)), BLACK);
    DrawLine((FL_WIDTH / 8) + ((FL_WIDTH / 6) / 1.5), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8, ((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + ((FL_WIDTH / 8) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8, BLACK);
    DrawLine((FL_WIDTH / 8) + ((FL_WIDTH / 6) / 1.5), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6, (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6, BLACK);
    DrawLine((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6, (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)), BLACK);
    DrawLine((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 3), (FL_HEIGHT / 50) + (FL_HEIGHT / 5), (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 3), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9, BLACK);
    DrawLine((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 3), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9, ((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + ((FL_WIDTH / 8) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9, BLACK);
    DrawLine((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 3), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.7, (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 2), (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.7, BLACK);
}

/**
 * @brief Dessine le schéma complet
 * 
 */
void FuelSystem::drawFuelSystem(App *app)
{
    drawPipe();

    std::vector<Tank *> v_tank = getTanks();
    std::vector<Motor *> v_Motors = getMotors();
    std::vector<Valve *> v_Valves = getValves();

    for (Tank *t : v_tank)
    {
        t->run(app);
    }

    for (Motor *m : v_Motors)
    {
        m->drawMotor(app);
    }

    for (Valve *v : v_Valves)
    {
        v->drawValve();
    }
}

/**
 * @brief Tubes opérationnels
 * 
 */
void FuelSystem::run(App *app)
{
    std::vector<Pipe *> v_Pipe = getPipe();

    for (Pipe *p : v_Pipe)
    {
        p->run();
    }
    if (!this->allTanksEmpty())
    {
        app->zero();
    }

    app->checkRating();
    app->addDate();
    app->printJson();

    drawFuelSystem(app);
}
