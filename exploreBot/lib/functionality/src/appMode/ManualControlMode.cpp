#include "functionality/appMode/ManualControlMode.hpp"

#include "common/gpio/GPIO.hpp"

namespace ExploreBot::Lib::Functionalities::AppMode {

ManualControlMode::ManualControlMode(Peripherals::Led::IDebugLed& debugLed, Peripherals::ArmMcu::IArmMcu& armMcu)
    : _debugLed { debugLed }
    , _armMcu { armMcu }
{}

void ManualControlMode::executeStep() noexcept
{
    _debugLed.turnOn();
    _armMcu.delay(2000);
    _debugLed.turnOff();
    _armMcu.delay(2000);
}

}   // namespace ExploreBot::Lib::Functionalities::AppMode
