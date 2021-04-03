#ifndef IDEBUGLED_HPP
#define IDEBUGLED_HPP

#include "peripherals/led/interface/ILed.hpp"

namespace ExploreBot::Lib::Peripherals::Led {

class IDebugLed : public ILed
{
public:
    virtual ~IDebugLed() = default;
};

}   // namespace ExploreBot::Lib::Peripherals::Led

#endif   // IDEBUGLED_HPP
