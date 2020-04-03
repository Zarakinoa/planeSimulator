#ifndef MENU_H
#define MENU_H
#include "State.h"
#include "App.h"

class Menu : public State
{

private:
    bool clicOnStart = false;
    bool clickOnBack = false;
    bool mouseOnStart = false;
    bool mouseOnBack = false;

public:
    Menu();
    Rectangle getStartBlock();
    Rectangle getBackBlock();

    void checkCollisionBlock();
    void drawStartBlock();
    void drawBackBlock();

    virtual void run(App *app);
};

#endif