#include "../include/Motor.h"
#include "../include/App.h"
#include <iostream>

/**
 * @brief Construct a new Motor:: Motor object
 * 
 */
Motor::Motor()
{
}

/**
 * @brief Construct a new Motor:: Motor object
 * 
 * @param name 
 * @param origin 
 */
Motor::Motor(std::string name, Pump *origin) : m_Name(name), m_origin(origin), m_stateMotor(FED)
{
    initMemberGI();
};

/**
 * @brief Initialisation des Moteurs (graphiquement)
 * 
 */
void Motor::initMemberGI()
{
    if (m_Name.compare("M1") == 0)
    {
        M_POSX = ((FL_WIDTH / 8) + (FL_WIDTH / 6) / 2 - M_WIDTH / 2);
    }
    else if (m_Name.compare("M2") == 0)
    {
        M_POSX = (((FL_WIDTH / 2) - ((FL_WIDTH / 8) / 2)) + (FL_WIDTH / 8) / 2 - M_WIDTH / 2);
    }
    else if (m_Name.compare("M3") == 0)
    {
        M_POSX = ((FL_WIDTH - ((FL_WIDTH / 8) + (FL_WIDTH / 6))) + (FL_WIDTH / 6) / 2 - M_WIDTH / 2);
    }
}

/**
 * @brief Représentation d'un Moteur
 * 
 * @return Rectangle 
 */
Rectangle Motor::getMotorBlock()
{
    Rectangle t_rec = {(float)M_POSX, (float)M_POSY, (float)M_WIDTH, (float)M_HEIGHT};
    return t_rec;
}

/**
 * @brief Représentation des états d'un moteur
 * 
 */
void Motor::drawState(App *app)
{
    Rectangle motor = getMotorBlock();

    if (isFed())
    {
        DrawText("Fed by", motor.x + motor.width * 0.13, motor.y + motor.height * 0.25, 13, GREEN);
        DrawText(m_origin->getName().c_str(), motor.x + motor.width * 0.3, motor.y + motor.height * 0.60, 20, GREEN);
        //app->addHistory("Un Moteur etait alimenté");
    }

    else
    {
        DrawText("Not", motor.x + motor.width * 0.13, motor.y + motor.height * 0.25, 13, RED);
        DrawText("Fed", motor.x + motor.width * 0.43, motor.y + motor.height * 0.60, 13, RED);
        //app->addHistory("Un Moteur etait en panne !");
    }
}

/**
 * @brief Dessine un moteur
 * 
 */
void Motor::drawMotor(App *app)
{
    DrawRectangleRec(getMotorBlock(), M_COLOR);
    DrawRectangleLinesEx(getMotorBlock(), 4, DARKGRAY);
    drawState(app);
}

/**
 * @brief Définie une pompe au moteur
 * 
 * @param pump 
 */
void Motor::setPump(Pump *pump)
{
    m_origin = pump;
}

/**
 * @brief Retourne une pompe lié au moteur
 * 
 * @return Pump 
 */
Pump Motor::getPump()
{
    return *m_origin;
}

/**
 * @brief Moteur alimenté
 * 
 */
void Motor::beingFed()
{
    m_stateMotor = FED;
}

/**
 * @brief Moteur en panne
 * 
 */
void Motor::beingNotFed()
{
    m_stateMotor = NFED;
}

/**
 * @brief Connaitre l'état du moteur
 * 
 * @return true 
 * @return false 
 */
bool Motor::isFed()
{
    if (m_stateMotor == FED)
    {
        return true;
    }

    return false;
}

/**
 * @brief Mise à jour de l'état du moteur
 * 
 */
void Motor::update()
{
    if (m_origin->getState() != 0)
    {

        beingNotFed();
    }

    else
    {
        beingFed();
    }
}
