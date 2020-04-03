#ifndef VALVE_H
#define VALVE_H
#include "define.h"
#include <raylib.h>
#include <string>
#include <map>
#include <utility>
#include <unordered_map>
#include "Tank.h"
#include "Motor.h"

class Valve
{

private:
    //Member for GI
    int V_CENTERX;
    int V_CENTERY;
    int V_RADIUS = (FL_HEIGHT / 40);
    Color V_COLOR = BLACK;

    int VR_POSX;
    int VR_POSY;
    int VR_WIDTH;
    int VR_HEIGHT;
    Color VR_COLOR;

    //Member for App
    std::string m_valveName;
    enum StateValve { OPEN,CLOSE } m_stateValve;
    std::map<Tank *, Motor *> map_Valve;

public:
    //Function for GI
    void initMemberCloseGI();
    void initMemberOpenGI();
    void drawValve();

    //Function for App
    Valve(std::string);
    std::string getName();
    StateValve getState() { return m_stateValve; }
    void open();
    void close();
    void update();
    void push_in_map(Tank *, Motor *);
    bool isClose();
    Motor* getMotor(Tank*);
};
#endif
