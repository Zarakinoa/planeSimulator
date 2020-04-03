#include "../include/Tank.h"
#include <iostream>

/**
 * @brief Etat des réservoirs
 * 
 */
enum StateTank
{
    FULL,
    EMPTY,
    FLOW,
    STOP
};

/**
 * @brief Etat des pompes
 * 
 */
enum StatePump
{
    WORKING,
    STOPPED,
    UNUSABLE
};

/**
 * @brief Construct a new Tank:: Tank object
 * 
 * @param name 
 * @param capacity 
 * @param namePPump 
 * @param nameEPump 
 */
Tank::Tank(std::string name, int capacity, std::string namePPump, std::string nameEPump) : m_Name(name), m_capacity(capacity), m_stateTank(FULL), m_primaryPump(namePPump), m_emergencyPump(nameEPump)
{
    m_capacity_Max = m_capacity;
    m_emergencyPump.stop();
    initMemberGI();
}

/**
 * @brief Retourne la capacité d'un réservoir
 * 
 * @return float 
 */
float Tank::getCapacity()
{
    return m_capacity;
}

/**
 * @brief Retourne la capacité max d'un réservoir
 * 
 * @return float 
 */
float Tank::getCapacityMax()
{
    return m_capacity_Max;
}

/**
 * @brief Retourne la pompe primaire d'un réservoir
 * 
 * @return Pump& 
 */
Pump &Tank::getPrimaryPump()
{
    return m_primaryPump;
}

/**
 * @brief Retourne la pompe de secours d'un réservoir
 * 
 * @return Pump& 
 */
Pump &Tank::getEmergencyPump()
{
    return m_emergencyPump;
}

/**
 * @brief Augmente la capacité d'un réservoir
 * 
 */
void Tank::incrementCapacity()
{
    m_capacity += 0.1;
}

/**
 * @brief Baisse la capacité d'un réservoir
 * 
 * @param mult 
 */
void Tank::decrementCapacity(int mult)
{
    m_capacity -= 0.1 * mult;
}

/**
 * @brief Écoulement d'un réservoir
 * 
 */
void Tank::flowing()
{
    m_stateTank = FLOW;
    decrementCapacity(1);
}

/**
 * @brief Réservoir à sec
 * 
 */
void Tank::emptying()
{
    m_capacity = 0;
    m_stateTank = EMPTY;
}

/**
 * @brief Réservoir à l'arrêt
 * 
 */
void Tank::stopping()
{
    m_stateTank = STOP;
}

/**
 * @brief Connaître l'état d'un réservoir
 * 
 * @return true 
 * @return false 
 */
bool Tank::isEmpty()
{
    if (m_capacity <= 0)
        return true;
    return false;
}

/**
 * @brief Init graphique
 * 
 */
void Tank::initMemberGI()
{
    if (m_Name.compare("Tank1") == 0)
    {
        T_WIDTH = (FL_WIDTH / 6);
        T_POSX = (FL_WIDTH / 8);
        T_COLOR = (Color){255, 161, 150, 255};
    }

    else if (m_Name.compare("Tank2") == 0)
    {
        T_WIDTH = (FL_WIDTH / 8);
        T_POSX = ((FL_WIDTH / 2) - (T_WIDTH / 2));
        T_COLOR = (Color){0, 228, 100, 255};
    }

    else if (m_Name.compare("Tank3") == 0)
    {
        T_WIDTH = (FL_WIDTH / 6);
        T_POSX = (FL_WIDTH - ((FL_WIDTH / 8) + T_WIDTH));
        T_COLOR = (Color){102, 191, 255, 255};
    }
}

/**
 * @brief Dessine les réservoirs
 * 
 */
void Tank::drawTank()
{
    Rectangle tank = getTankBlock();

    DrawRectangleRec(tank, T_COLOR);

    if (mouseOnTank)
        DrawRectangleLinesEx(tank, 2, BLUE);

    else
        DrawRectangleLinesEx(tank, 4, DARKGRAY);
}

/**
 * @brief Dessines les écoulements
 * 
 */
void Tank::drawFlowingTank()
{
    Rectangle tank = getTankBlock();
    Rectangle flowingTank = getFlowingTankBlock();

    DrawText(m_Name.c_str(), tank.x + tank.width / 6, tank.y + tank.height * 0.25, tank.width / 4.5, GRAY);
    DrawRectangleRec(flowingTank, (Color){T_COLOR.r - 50, T_COLOR.g - 50, T_COLOR.b - 50, T_COLOR.a - 70});

    if (mouseOnTank)
        DrawRectangleLinesEx(tank, 4, BLUE);

    else
        DrawRectangleLinesEx(tank, 4, DARKGRAY);
}

/**
 * @brief Représentation d'un réservoir
 * 
 * @return Rectangle 
 */
Rectangle Tank::getTankBlock()
{
    Rectangle t_rec = {T_POSX, T_POSY, T_WIDTH, T_HEIGHT};
    return t_rec;
}

/**
 * @brief Retourne les réservoirs en écoulements
 * 
 * @return Rectangle 
 */
Rectangle Tank::getFlowingTankBlock()
{
    Rectangle t_rec;

    if (m_Name.compare("Tank1") == 0 || m_Name.compare("Tank3") == 0)
    {
        t_rec = {T_POSX + 3, (T_POSY + 3) + (200 - m_capacity), T_WIDTH - 3, (T_HEIGHT - 3) - (200 - m_capacity)};
    }
    else
    {
        t_rec = {T_POSX + 3, (T_POSY + 3) + (200 - m_capacity * 2), T_WIDTH - 3, (T_HEIGHT - 3) - (200 - m_capacity * 2)};
    }

    return t_rec;
}

/**
 * @brief Clique sur une pompe
 * 
 */
void Tank::clicOnPump()
{
    m_primaryPump.clicOn();
    m_emergencyPump.clicOn();
}

/**
 * @brief Dessine les pompes du réservoir
 * 
 */
void Tank::drawPump()
{
    clicOnPump();
    m_primaryPump.drawPump();
    m_emergencyPump.drawPump();
}

/**
 * @brief Vérifie les cliques de la souris
 * 
 */
void Tank::checkCollisionBlock(App *app)
{
    if (CheckCollisionPointRec(GetMousePosition(), getTankBlock()))
    {
        mouseOnTank = true;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            clicOnTank = true;
            app->addHistory("Une pompe etait en panne !");
            app->addRating(-1);
        }
    }
    else
        mouseOnTank = false;

    if (CheckCollisionPointRec(GetMousePosition(), getTankBlock()) && !CheckCollisionPointCircle(GetMousePosition(), m_primaryPump.getPosition(), m_primaryPump.getRadius()) && !CheckCollisionPointCircle(GetMousePosition(), m_emergencyPump.getPosition(), m_emergencyPump.getRadius()) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON) /*&& m_stateTank != FLOW*/)
    {
        m_stateTank = FLOW;
        emptying();
    }
}

/**
 * @brief Init un Réservoir
 * 
 */
void Tank::run(App *app)
{
    checkCollisionBlock(app);

    drawTank();
    drawFlowingTank();
    drawPump();
}