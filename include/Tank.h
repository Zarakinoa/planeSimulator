#ifndef TANK_H
#define TANK_H
#include <raylib.h>
#include <vector>
#include <string>
#include "define.h"
#include "Pump.h"
#include "App.h"

class Tank
{

private:
    //Member for GI
    float T_WIDTH;
    float T_HEIGHT = (FL_HEIGHT / 5);
    float T_POSX;
    float T_POSY = (FL_HEIGHT / 50);
    Color T_COLOR;
    bool mouseOnTank = false;
    bool clicOnTank = false;

    std::vector<Rectangle> m_Rectangle;

    //Member for App
    std::string m_Name;
    float m_capacity;
    float m_capacity_Max;
    enum StateTank
    {
        FULL,
        EMPTY,
        FLOW,
        STOP
    } m_stateTank;
    Pump m_primaryPump;
    Pump m_emergencyPump;

public:
    //Function for App
    Tank(std::string, int, std::string, std::string);
    float getCapacity();
    float getCapacityMax();
    StateTank getState() { return m_stateTank; }
    Pump &getPrimaryPump();
    Pump &getEmergencyPump();
    void incrementCapacity();
    void decrementCapacity(int);
    void flowing();
    void emptying();
    void stopping();
    bool isEmpty();
    void run(App *app);

    bool operator<(const Tank &other) const { return m_Name < other.m_Name; }

    //Function for GI
    void initMemberGI();
    void drawTank();
    void drawFlowingTank();
    void drawPump();
    Rectangle getTankBlock();
    Rectangle getFlowingTankBlock();
    void clicOnPump();
    void checkCollisionBlock(App *app);
};

#endif
