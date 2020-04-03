#ifndef PIPETANKTOMOTOR
#define PIPETANKTOMOTOR
#include "Pipe.h"
#include "Valve.h"
#include "Motor.h"

class PipeTanktoMotor : public Pipe
{

private:
    Valve *m_Valve2;
    Motor *m_Motor;

public:
    PipeTanktoMotor(Tank *, Valve *, Valve *, Motor *);
    void reconfiguration();
    virtual void run();
};

#endif