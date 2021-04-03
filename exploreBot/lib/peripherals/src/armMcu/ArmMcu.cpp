#include "peripherals/armMcu/ArmMcu.hpp"

#include "stm32f4xx_hal.h"

namespace ExploreBot::Lib::Peripherals::ArmMcu {

ArmMcu::ArmMcu() {}

void ArmMcu::delay(uint32_t msec) noexcept { HAL_Delay(msec); }

}   // namespace ExploreBot::Lib::Peripherals::ArmMcu
