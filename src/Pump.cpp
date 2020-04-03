#include "../include/Pump.h"
#include <iostream>

/**
 * @brief Construct a new Pump:: Pump object
 * 
 */
Pump::Pump()
{
}

/**
 * @brief Construct a new Pump:: Pump object
 * 
 * @param name 
 */
Pump::Pump(std::string name) : m_Name(name), m_statePump(WORKING)
{
    initMemberGI();
};

/**
 * @brief Retourne le nom de la pompe
 * 
 * @return std::string 
 */
std::string Pump::getName()
{
    return m_Name;
}

/**
 * @brief Démarrage de la pompe
 * 
 */
void Pump::start()
{
    m_statePump = WORKING;
    P_COLOR = BLACK;
}

/**
 * @brief Arrêt de la pompe
 * 
 */
void Pump::stop()
{
    m_statePump = STOPPED;
    P_COLOR = RED;
}

/**
 * @brief Panne de la pompe
 * 
 */
void Pump::failure()
{
    m_statePump = UNUSABLE;
    P_COLOR = PURPLE;
}

/**
 * @brief Représente les pompes (graphiquement)
 * 
 */
void Pump::initMemberGI()
{
    if (m_Name.compare("P11") == 0)
    {
        P_CENTERX = (FL_WIDTH / 8) + ((FL_WIDTH / 6) / 3.5);
        P_RADIUS = (FL_HEIGHT / 40);
    }
    else if (m_Name.compare("P12") == 0)
    {
        P_CENTERX = ((FL_WIDTH / 8) + (FL_WIDTH / 6)) - ((FL_WIDTH / 6) / 3.5);
        P_RADIUS = (FL_HEIGHT / 40);
    }
    else if (m_Name.compare("P21") == 0)
    {
        P_CENTERX = FL_WIDTH * 0.47;
        P_RADIUS = (FL_HEIGHT / 41.1764705882);
    }
    else if (m_Name.compare("P22") == 0)
    {
        P_CENTERX = FL_WIDTH * 0.53;
        P_RADIUS = (FL_HEIGHT / 41.1764705882);
    }
    else if (m_Name.compare("P31") == 0)
    {
        P_CENTERX = (FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + ((FL_WIDTH / 6) / 3.5);
        P_RADIUS = (FL_HEIGHT / 40);
    }
    else if (m_Name.compare("P32") == 0)
    {
        P_CENTERX = ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + (FL_WIDTH / 6)) - ((FL_WIDTH / 6) / 3.5);
        P_RADIUS = (FL_HEIGHT / 40);
    }
}

/**
 * @brief Retourne la position d'une pompe
 * 
 * @return Vector2 
 */
Vector2 Pump::getPosition()
{
    Vector2 v = {(float)P_CENTERX, (float)P_CENTERY};
    return v;
}

/**
 * @brief Retourne le rayon d'une pompe
 * 
 * @return int 
 */
int Pump::getRadius()
{
    return P_RADIUS;
}

/**
 * @brief Dessine une pompe
 * 
 */
void Pump::drawPump()
{
    DrawCircle(P_CENTERX, P_CENTERY, P_RADIUS, P_COLOR);
}

/**
 * @brief Opération sur une pompe
 * 
 */
void Pump::clicOn()
{
    if (((m_statePump == STOPPED || m_statePump == WORKING) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) && (GetMouseX() > (P_CENTERX - P_RADIUS) && GetMouseX() < (P_CENTERX + P_RADIUS)) && (GetMouseY() > (P_CENTERY - P_RADIUS) && GetMouseY() < (P_CENTERY + P_RADIUS)))
    {
        failure();
    }
}

/**
 * @brief Mise à jour d'une pompe
 * 
 */
void Pump::update()
{
    if (m_statePump == STOPPED)
    {
        start();
    }

    else if (m_statePump == WORKING)
    {
        stop();
    }
}