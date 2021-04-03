#ifndef AUTOMATICRIDEMODE_HPP
#define AUTOMATICRIDEMODE_HPP

#include "functionality/appMode/interface/IAppMode.hpp"

#include "peripherals/led/interface/IDebugLed.hpp"
#include "peripherals/armMcu/interface/IArmMcu.hpp"

namespace ExploreBot::Lib::Functionalities::AppMode {

class AutomaticRideMode final : public IAppMode
{
public:
    explicit AutomaticRideMode(Peripherals::Led::IDebugLed& debugLed, Peripherals::ArmMcu::IArmMcu& armMcu);

    [[nodiscard]] std::string modeName() const noexcept override { return "AutomaticRideMode"; }
    void executeStep() noexcept override;

private:
    Peripherals::Led::IDebugLed& _debugLed;
    Peripherals::ArmMcu::IArmMcu& _armMcu;
};

}   // namespace ExploreBot::Lib::Functionalities::AppMode

#endif   // AUTOMATICRIDEMODE_HPP
