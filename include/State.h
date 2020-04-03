#ifndef STATE_H
#define STATE_H

class App;

class State
{

public:
    State(float,float,char *);
    const float W_WIDTH;
    const float W_HEIGHT;
    const char* W_TITLE;
    virtual void run(App *app) = 0;
    virtual ~State();
};

#endif