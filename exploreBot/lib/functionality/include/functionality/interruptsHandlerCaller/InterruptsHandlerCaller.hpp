#ifndef INTERUPOTSHANDLERCALLER_H
#define INTERUPOTSHANDLERCALLER_H

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

class InterruptsHandlerCaller
{
public:
    explicit InterruptsHandlerCaller(IInterruptHandlerPtrVector& interruptsHandler);

    [[nodiscard]] bool callHandler(Common::GPIO::GPIOPin gpioPin) noexcept;

private:
    IInterruptHandlerPtrVector& _interruptsHandler;
};

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling

#endif
