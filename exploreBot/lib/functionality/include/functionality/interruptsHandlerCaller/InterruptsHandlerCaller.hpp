#ifndef INTERUPOTSHANDLERCALLER_H
#define INTERUPOTSHANDLERCALLER_H

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptsHandlerCaller {

class InteruptsHandlerCaller
{
public:
    explicit InteruptsHandlerCaller(IInterruptHandlerVector& interruptsHandler);

private:
    IInterruptHandlerVector& interruptsHandler;
};

}

#endif
