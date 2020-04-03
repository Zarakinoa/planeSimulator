#ifndef LOGIN_H
#define LOGIN_H
#include <raylib.h>
#include <string.h>
#include <fstream>
#include "State.h"
#include "App.h"

class Login : public State
{
private:
    //Member
    const int MAX_INPUT_CHARS = 9;
    std::string m_id;
    std::string m_pass;

    bool connexion = true;
    static int framesCounterLogin;
    static int framesCounterPassword;
    bool clicOnEnter = false;
    bool clicOnBack = false;
    bool mouseOnId = false;
    bool mouseOnPassword = false;
    bool mouseOnEnter = false;
    bool mouseOnBack = false;

public:
    Login();
    void checkCollisionBlock();
    Rectangle getIdBlock();
    Rectangle getPasswordBlock();
    Rectangle getEnterBlock();
    Rectangle getBackBlock();
    void drawIdBlock();
    void drawPasswordBlock();
    void drawEnterBlock();
    void drawBackBlock();

    virtual void run(App *app);
};

#endif