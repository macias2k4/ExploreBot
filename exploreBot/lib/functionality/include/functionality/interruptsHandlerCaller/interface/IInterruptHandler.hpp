#ifndef IINTERRUPTHANDLER_HPP
#define IINTERRUPTHANDLER_HPP

#include "common/gpio/GPIO.hpp"

#include <vector>

namespace ExploreBot::Lib::Functionalities::InterruptsHandlerCaller {

class IInterruptHandler
{
public:
    virtual ~IInterruptHandler() = default;

    [[nodiscard]] virtual bool handle(Common::GPIO::GPIOPin gpioPin) const noexcept = 0;
};

using IInterruptHandlerVector = std::vector<IInterruptHandler>;

}

#endif // IINTERRUPTHANDLER_HPP
