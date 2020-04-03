#ifndef PUMP_H
#define PUMP_H
#include <raylib.h>
#include <string>
#include "define.h"

class Pump
{

private:
    //Member for GI
    int P_CENTERX;
    int P_CENTERY = (FL_HEIGHT / 50) + ((FL_HEIGHT / 5) * 0.8);
    int P_RADIUS;
    Color P_COLOR = BLACK;

    //Member for App
    std::string m_Name;
    enum StatePump
    {
        WORKING,
        STOPPED,
        UNUSABLE
    } m_statePump;

public:
    //Function for GI
    void initMemberGI();
    void drawPump();
    Vector2 getPosition();
    int getRadius();

    //Function for App
    Pump();
    Pump(std::string);
    std::string getName();
    StatePump getState() { return m_statePump; }
    void start();
    void stop();
    void failure();
    void clicOn();
    void update();
};

#endif

