#ifndef FUELSYSTEM_H
#define FUELSYSTEM_H
#include <raylib.h>
#include <vector>
#include <iostream>

#include "define.h"
#include "App.h"
#include "Tank.h"
#include "Motor.h"
#include "Valve.h"
#include "Pump.h"
#include "PipeTankToTank.h"
#include "PipeTankToMotor.h"

class FuelSystem
{

private:
    Tank m_T1, m_T2, m_T3;
    Motor m_M1, m_M2, m_M3;
    Valve m_VT12, m_VT23, m_V12, m_V13, m_V23;
    PipeTanktoTank m_T1_to_T2, m_T2_to_T3;
    PipeTanktoMotor m_P_T1, m_P_T2, m_P_T3;

public:
    //Function for App
    FuelSystem();
    std::vector<Tank *> getTanks();
    std::vector<Motor *> getMotors();
    std::vector<Valve *> getValves();
    std::vector<Pipe *> getPipe();
    void initializeValveMap();
    bool allTanksEmpty();
    void run(App *app);

    //Function for GI
    void drawPipe();
    void drawFuelSystem(App *app);
};

#endif