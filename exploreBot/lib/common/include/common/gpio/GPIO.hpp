#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>

namespace ExploreBot::Lib::Common::GPIO {

using GPIOPin = uint16_t;

static constexpr GPIOPin userLedD13 { 0x0020 };
static constexpr GPIOPin userButtonD2 { 0x0400 };
static constexpr GPIOPin userButtonB1 { 0x2000 };

}   // namespace ExploreBot::Lib::Common::GPIO

#endif   // GPIO_HPP
