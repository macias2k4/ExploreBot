#ifndef IINTERRUPTHANDLER_HPP
#define IINTERRUPTHANDLER_HPP

#include "common/gpio/GPIO.hpp"

#include <vector>

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

class IInterruptHandler
{
public:
    virtual ~IInterruptHandler() = default;

    [[nodiscard]] virtual Common::GPIO::GPIOPin triggeringPin() const noexcept = 0;
    [[nodiscard]] virtual bool handle() noexcept = 0;
};

using IInterruptHandlerVector = std::vector<IInterruptHandler>;

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling

#endif   // IINTERRUPTHANDLER_HPP
