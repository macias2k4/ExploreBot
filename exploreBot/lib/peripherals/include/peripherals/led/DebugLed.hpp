#ifndef DEBUGLED_HPP
#define DEBUGLED_HPP

#include "peripherals/led/interface/IDebugLed.hpp"

namespace ExploreBot::Lib::Peripherals::Led {

class DebugLed final : public IDebugLed
{
public:
    void turnOn() noexcept override;
    void turnOff() noexcept override;
};

}   // namespace ExploreBot::Lib::Peripherals::Led

#endif   // DEBUGLED_HPP
