#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

InterruptsHandlerCaller::InterruptsHandlerCaller(IInterruptHandlerVector& interruptsHandler)
    : _interruptsHandler { interruptsHandler }
{}

bool InterruptsHandlerCaller::callHandler(Common::GPIO::GPIOPin gpioPin) noexcept
{
    for (auto& handler : _interruptsHandler) {
        if (handler.triggeringPin() == gpioPin) {
            return handler.handle();
        }
    }
    return false;
}

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling
