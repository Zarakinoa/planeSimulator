#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <vector>
#include <raylib.h>
#include "FuelSystem.h"
#include "App.h"

class DashBoard
{

private:
    //Member for GI
    float FL_WIDTH;
    float FL_HEIGHT;

    std::vector<Rectangle> m_button;

public:
    DashBoard();
    void createButton();
    void createButtonName();
    void drawDashBoard();
    void mouseOn();
    void clicOn(FuelSystem *, App *app);
    void run(FuelSystem *, App *app);
};

#endif