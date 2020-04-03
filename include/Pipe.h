#ifndef PIPE_H
#define PIPE_H
#include "Tank.h"
#include "Valve.h"

class Pipe {

    protected:
    Tank  *m_Source;
    Valve *m_Valve;

    public:
    Pipe(Tank *,Valve *);
    virtual ~Pipe();
    virtual void reconfiguration() = 0;
    virtual void run();

};

#endif