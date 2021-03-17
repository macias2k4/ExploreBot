#ifndef IINTERRUPTHANDLER_HPP
#define IINTERRUPTHANDLER_HPP

#include "common/gpio/GPIO.hpp"

#include <vector>

namespace ExploreBot::Lib::Functionalities::InterruptsHandlerCaller {

class IInterruptHandler
{
public:
    virtual ~IInterruptHandler() = default;

    [[nodiscard]] virtual Common::GPIO::GPIOPin triggeringPin() const noexcept = 0;
    [[nodiscard]] virtual bool handle() const noexcept = 0;
};

using IInterruptHandlerVector = std::vector<IInterruptHandler>;

}

#endif // IINTERRUPTHANDLER_HPP
