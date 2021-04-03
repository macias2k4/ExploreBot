#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

InterruptsHandlerCaller::InterruptsHandlerCaller(IInterruptHandlerPtrVector& interruptsHandler)
    : _interruptsHandler { interruptsHandler }
{}

std::optional<bool> InterruptsHandlerCaller::callHandler(Common::GPIO::GPIOPin gpioPin) noexcept
{
    for (auto& handler : _interruptsHandler) {
        if (handler->triggeringPin() == gpioPin) {
            return handler->handle();
        }
    }
    return {};
}

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling
