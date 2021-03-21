#ifndef INTERUPOTSHANDLERCALLER_H
#define INTERUPOTSHANDLERCALLER_H

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

class InterruptsHandlerCaller
{
public:
    explicit InterruptsHandlerCaller(IInterruptHandlerVector& interruptsHandler);

    [[nodiscard]] bool callHandler(Common::GPIO::GPIOPin gpioPin) noexcept;

private:
    IInterruptHandlerVector& _interruptsHandler;
};

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling

#endif
