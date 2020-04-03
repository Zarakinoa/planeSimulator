#include "../include/DashBoard.h"
#include <iostream>

/**
 * @brief Construct a new Dash Board:: Dash Board object
 * 
 */
DashBoard::DashBoard() : FL_WIDTH(800), FL_HEIGHT(700)
{
    createButton();
};

/**
 * @brief Liste des boutons du dash board
 * 
 */
void DashBoard::createButton()
{
    //V12
    Rectangle r1 = {
        (FL_WIDTH / 3),
        (FL_HEIGHT / (float)1.1),
        (FL_WIDTH / 10),
        (FL_HEIGHT / 20),
    };
    m_button.push_back(r1);

    //V13
    Rectangle r2 = {((FL_WIDTH / 2) - ((FL_WIDTH / 10) / 2)), (FL_HEIGHT / (float)1.1), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r2);

    //V23
    Rectangle r3 = {(FL_WIDTH - ((FL_WIDTH / 3) + (FL_WIDTH / 10))), (FL_HEIGHT / (float)1.1), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r3);

    //VT12
    Rectangle r4 = {(FL_WIDTH / (float)2.6), (FL_HEIGHT / (float)1.32), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r4);

    //VT23
    Rectangle r5 = {(FL_WIDTH - ((FL_WIDTH / (float)2.6) + (FL_WIDTH / 10))), (FL_HEIGHT / (float)1.32), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r5);

    //P12
    Rectangle r6 = {(FL_WIDTH / 3), (FL_HEIGHT / (float)(float)1.2), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r6);

    //P22
    Rectangle r7 = {((FL_WIDTH / 2) - ((FL_WIDTH / 10) / 2)), (FL_HEIGHT / (float)1.2), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r7);

    //P32
    Rectangle r8 = {(FL_WIDTH - ((FL_WIDTH / 3) + (FL_WIDTH / 10))), (FL_HEIGHT / (float)1.2), (FL_WIDTH / 10), (FL_HEIGHT / 20)};
    m_button.push_back(r8);
}

/**
 * @brief Nom des boutons
 * 
 */
void DashBoard::createButtonName()
{
    DrawText("V12", m_button.at(0).x + (m_button.at(0).width * 0.25), m_button.at(0).y + (m_button.at(0).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("V13", m_button.at(1).x + (m_button.at(1).width * 0.25), m_button.at(1).y + (m_button.at(1).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("V23", m_button.at(2).x + (m_button.at(2).width * 0.25), m_button.at(2).y + (m_button.at(2).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("VT12", m_button.at(3).x + (m_button.at(3).width * 0.15), m_button.at(3).y + (m_button.at(3).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("VT23", m_button.at(4).x + (m_button.at(4).width * 0.11), m_button.at(4).y + (m_button.at(4).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("P12", m_button.at(5).x + (m_button.at(5).width * 0.25), m_button.at(5).y + (m_button.at(5).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("P22", m_button.at(6).x + (m_button.at(6).width * 0.25), m_button.at(6).y + (m_button.at(6).height * 0.20), FL_WIDTH * 0.030, BLUE);
    DrawText("P32", m_button.at(7).x + (m_button.at(7).width * 0.25), m_button.at(7).y + (m_button.at(7).height * 0.20), FL_WIDTH * 0.030, BLUE);
}

/**
 * @brief Dessine les composants graphiques
 * 
 */
void DashBoard::drawDashBoard()
{
    for (Rectangle r : m_button)
    {
        DrawRectangleRounded(r, 0.5, 4, LIGHTGRAY);
    }
    createButtonName();
}

/**
 * @brief Détection de la position de la souris
 * 
 */
void DashBoard::mouseOn()
{
    for (Rectangle r : m_button)
    {
        if (CheckCollisionPointRec(GetMousePosition(), r))
        {
            DrawRectangleRoundedLines(r, 0.5, 4, 5, BLUE);
        }

        else
        {
            DrawRectangleRoundedLines(r, 0.5, 4, 5, GRAY);
        }
    }
}

/**
 * @brief Pression sur un bouton
 * 
 * @param fs 
 */
void DashBoard::clicOn(FuelSystem *fs, App *app)
{
    std::vector<Valve *> v_Valves = fs->getValves();
    std::vector<Pump *> p_Pumps = {&fs->getTanks().at(0)->getEmergencyPump(), &fs->getTanks().at(1)->getEmergencyPump(), &fs->getTanks().at(2)->getEmergencyPump()};

    //V12
    if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(0)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        v_Valves.at(0)->update();
        app->addHistory("Changement de l'etat de la vanne V12");
    }

    //V13
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(1)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        v_Valves.at(1)->update();
        app->addHistory("Changement de l'etat de la vanne V13");
    }

    //V23
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(2)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        v_Valves.at(2)->update();
        app->addHistory("Changement de l'etat de la vanne V23");
    }

    //VT12
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(3)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        v_Valves.at(3)->update();
        app->addHistory("Changement de l'etat de la vanne VT12");
    }

    //VT23
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(4)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        v_Valves.at(4)->update();
        app->addHistory("Changement de l'etat de la vanne VT23");
    }

    //P12
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(5)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        p_Pumps.at(0)->update();
        app->addHistory("Changement de l'etat de la pompe P12");
    }

    //P22
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(6)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        p_Pumps.at(1)->update();
        app->addHistory("Changement de l'etat de la pompe P22");
    }

    //P32
    else if (CheckCollisionPointRec(GetMousePosition(), this->m_button.at(7)) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        p_Pumps.at(2)->update();
        app->addHistory("Changement de l'etat de la pompe P32");
    }
}

void DashBoard::run(FuelSystem *fs, App *app)
{
    clicOn(fs, app);
    mouseOn();
    drawDashBoard();
}