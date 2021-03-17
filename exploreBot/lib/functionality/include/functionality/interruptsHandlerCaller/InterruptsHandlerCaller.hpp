#ifndef INTERUPOTSHANDLERCALLER_H
#define INTERUPOTSHANDLERCALLER_H

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptsHandlerCaller {

class InteruptsHandlerCaller
{
public:
    explicit InteruptsHandlerCaller(IInterruptHandlerVector& interruptsHandler);

    [[nodiscard]] bool callHandler(Common::GPIO::GPIOPin gpioPin) const noexcept;

private:
    IInterruptHandlerVector& _interruptsHandler;
};

}

#endif
