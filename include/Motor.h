#ifndef MOTOR_H
#define MOTOR_H
#include <raylib.h>
#include <string>
#include "define.h"
#include "App.h"

#include "Pump.h"

class Motor
{

private:
    //member for GI
    int M_WIDTH = (FL_WIDTH / 14);
    int M_HEIGHT = (FL_HEIGHT / 10);
    int M_POSY = (FL_HEIGHT - (FL_HEIGHT / 2.5));
    int M_POSX;
    Color M_COLOR = GRAY;

    //Member for App
    std::string m_Name;
    Pump *m_origin;
    enum StateMotor
    {
        FED,
        NFED
    } m_stateMotor;

public:
    //Function for Gi
    void initMemberGI();
    Rectangle getMotorBlock();
    void drawState(App *app);
    void drawMotor(App *app);

    //Function for App
    Motor();
    Motor(std::string, Pump *);
    StateMotor getStateMotor() { return m_stateMotor; }
    void setPump(Pump *);
    Pump getPump();
    void beingFed();
    void beingNotFed();
    bool isFed();
    void update();
};

#endif