#ifndef ARMMCU_HPP
#define ARMMCU_HPP

#include "peripherals/armMcu/interface/IArmMcu.hpp"

namespace ExploreBot::Lib::Peripherals::ArmMcu {

class ArmMcu final : public IArmMcu
{
public:
    ArmMcu();

    void delay(uint32_t msec) noexcept override;
};

}   // namespace ExploreBot::Lib::Peripherals::ArmMcu

#endif   // ARMMCU_HPP
