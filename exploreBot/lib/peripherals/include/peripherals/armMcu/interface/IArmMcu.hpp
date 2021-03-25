#ifndef IARMMCU_H
#define IARMMCU_H

#include <stdint.h>

namespace ExploreBot::Lib::Peripherals::ArmMcu {

class IArmMcu
{
public:
    virtual ~IArmMcu() = default;

    virtual void delay(uint32_t msec) noexcept = 0;
};

}   // namespace ExploreBot::Lib::Peripherals::ArmMcu
#endif   // IARMMCU_H
