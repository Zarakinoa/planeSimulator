#ifndef PIPETANKTOTANK_H
#define PIPETANKTOTANK_H
#include "Pipe.h"

class PipeTanktoTank : public Pipe {

private:
    Tank *m_Destination;

public:
    PipeTanktoTank(Tank *,Valve *,Tank *);
    virtual void reconfiguration();
    virtual void run();

};

#endif