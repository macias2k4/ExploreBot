#include "peripherals/led/DebugLed.hpp"

#include "main.h"

namespace ExploreBot::Lib::Peripherals::Led {

void DebugLed::turnOn() noexcept { HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PinState::GPIO_PIN_SET); }

void DebugLed::turnOff() noexcept { HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PinState::GPIO_PIN_RESET); }

}   // namespace ExploreBot::Lib::Peripherals::Led
