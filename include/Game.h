#ifndef GAME_H
#define GAME_H
#include <raylib.h>
#include "State.h"
#include "App.h"
#include "FuelSystem.h"
#include "DashBoard.h"


class Game : public State {

private:
    //Member for GI
    bool mouseOnBack = false;
    bool clicOnBack = false;

    //Member for App
    FuelSystem m_fs;
    DashBoard m_db;

public:
    //Function for GI
    Rectangle getBackBlock();
    void checkCollisionBlock();
    void drawBackBlock();

    //Function for App
    Game();
    void run(App *app);
    void isBack(App *app);

};

#endif