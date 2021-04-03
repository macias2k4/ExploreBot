#ifndef IINTERRUPTHANDLER_HPP
#define IINTERRUPTHANDLER_HPP

#include "common/gpio/GPIO.hpp"

#include <memory>
#include <vector>

namespace ExploreBot::Lib::Functionalities::InterruptHandling {

class IInterruptHandler
{
public:
    virtual ~IInterruptHandler() = default;

    [[nodiscard]] virtual Common::GPIO::GPIOPin triggeringPin() const noexcept = 0;
    [[nodiscard]] virtual bool handle() noexcept = 0;
};

using IInterruptHandlerPtr = std::shared_ptr<IInterruptHandler>;
using IInterruptHandlerPtrVector = std::vector<IInterruptHandlerPtr>;

}   // namespace ExploreBot::Lib::Functionalities::InterruptHandling

#endif   // IINTERRUPTHANDLER_HPP
