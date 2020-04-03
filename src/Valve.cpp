#include "../include/Valve.h"
#include <iostream>

/**
 * @brief Construct a new Valve:: Valve object
 * 
 * @param valveName 
 */
Valve::Valve(std::string valveName) : m_stateValve(OPEN), m_valveName(valveName)
{
    initMemberOpenGI();
};

/**
 * @brief Retourne le nom de la Vanne
 * 
 * @return std::string 
 */
std::string Valve::getName()
{
    return m_valveName;
}

/**
 * @brief Ouvre la vanne
 * 
 */
void Valve::open()
{
    initMemberOpenGI();
    m_stateValve = OPEN;
}

/**
 * @brief Ferme la Vanne
 * 
 */
void Valve::close()
{
    initMemberCloseGI();
    m_stateValve = CLOSE;
}

/**
 * @brief Met à jour la Vanne
 * 
 */
void Valve::update()
{
    if (m_stateValve == OPEN)
    {
        close();
    }
    else
        open();
}

/**
 * @brief Representation Vanne Ouvert (graphiquement)
 * 
 */
void Valve::initMemberOpenGI()
{
    VR_COLOR = LIGHTGRAY;
    VR_WIDTH = ((FL_HEIGHT / 40) / 2);
    VR_HEIGHT = ((FL_HEIGHT / 40) * 2);

    if (m_valveName.compare("VT12") == 0)
    {
        V_CENTERX = (((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2;
        V_CENTERY = (FL_HEIGHT / 50) + ((FL_HEIGHT / 5) / 2);
        VR_POSX = ((((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2) - (VR_WIDTH / 2);
        VR_POSY = ((FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2) - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("VT23") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT / 50) + ((FL_HEIGHT / 5) / 2);
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = ((FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2) - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V12") == 0)
    {
        V_CENTERX = (((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8;
        VR_POSX = ((((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8 - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V13") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6;
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6 - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V23") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9;
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9 - (VR_HEIGHT / 2);
    }
}

/**
 * @brief Représentation Vanne Fermer (graphiquement)
 * 
 */
void Valve::initMemberCloseGI()
{
    VR_COLOR = (Color){232, 140, 8, 255};
    VR_WIDTH = ((FL_HEIGHT / 40) * 2);
    VR_HEIGHT = ((FL_HEIGHT / 40) / 2);

    if (m_valveName.compare("VT12") == 0)
    {
        V_CENTERX = (((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2;
        V_CENTERY = (FL_HEIGHT / 50) + ((FL_HEIGHT / 5) / 2);
        VR_POSX = V_CENTERX - V_RADIUS;
        VR_POSY = V_CENTERY - VR_HEIGHT / 2;
    }

    else if (m_valveName.compare("VT23") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT / 50) + ((FL_HEIGHT / 5) / 2);
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = ((FL_HEIGHT / 50) + (FL_HEIGHT / 5) / 2) - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V12") == 0)
    {
        V_CENTERX = (((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8;
        VR_POSX = ((((FL_WIDTH / 8) + (FL_WIDTH / 6)) + (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.8 - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V13") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6;
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.6 - (VR_HEIGHT / 2);
    }

    else if (m_valveName.compare("V23") == 0)
    {
        V_CENTERX = ((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2;
        V_CENTERY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9;
        VR_POSX = (((((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8)) + ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))))) / 2) - (VR_WIDTH / 2);
        VR_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5)) * 0.9 - (VR_HEIGHT / 2);
    }
}

/**
 * @brief Dessine Vanne
 * 
 */
void Valve::drawValve()
{
    DrawCircle(V_CENTERX, V_CENTERY, V_RADIUS, V_COLOR);
    DrawRectangle(VR_POSX, VR_POSY, VR_WIDTH, VR_HEIGHT, VR_COLOR);
}

/**
 * @brief Connaitre l'état de la vanne
 * 
 * @return true 
 * @return false 
 */
bool Valve::isClose()
{
    if (m_stateValve == CLOSE)
        return true;
    return false;
}

/**
 * @brief Réservoir to Vanne to Moteur
 * 
 * @param tank 
 * @param motor 
 */
void Valve::push_in_map(Tank *tank, Motor *motor)
{
    map_Valve[tank] = motor;
}

/**
 * @brief Retourne le moteur lié à la vanne
 * 
 * @param tank 
 * @return Motor* 
 */
Motor *Valve::getMotor(Tank *tank)
{
    return map_Valve[tank];
}