#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"

namespace ExploreBot::Lib::Functionalities::InterruptsHandlerCaller {

InteruptsHandlerCaller::InteruptsHandlerCaller(IInterruptHandlerVector &interruptsHandler)
    : _interruptsHandler { interruptsHandler }
{

}

bool InteruptsHandlerCaller::callHandler(Common::GPIO::GPIOPin gpioPin) const noexcept
{
    for (const auto& handler : _interruptsHandler){
        if (handler.triggeringPin()==gpioPin) {
            return handler.handle();
        }
    }
    return false;
}

}
