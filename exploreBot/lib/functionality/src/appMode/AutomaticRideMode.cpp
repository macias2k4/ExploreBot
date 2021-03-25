#include "functionality/appMode/AutomaticRideMode.hpp"

#include "common/gpio/GPIO.hpp"

namespace ExploreBot::Lib::Functionalities::AppMode {

AutomaticRideMode::AutomaticRideMode(Peripherals::Led::IDebugLed& debugLed, Peripherals::ArmMcu::IArmMcu& armMcu)
    : _debugLed { debugLed }
    , _armMcu { armMcu }
{}

void AutomaticRideMode::executeStep() noexcept
{
    _debugLed.turnOn();
    _armMcu.delay(300);
    _debugLed.turnOff();
    _armMcu.delay(500);
}

}   // namespace ExploreBot::Lib::Functionalities::AppMode
