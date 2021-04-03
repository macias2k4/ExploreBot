#ifndef MANUALCONTROLMODE_HPP
#define MANUALCONTROLMODE_HPP

#include "functionality/appMode/interface/IAppMode.hpp"

#include "peripherals/led/interface/IDebugLed.hpp"
#include "peripherals/armMcu/interface/IArmMcu.hpp"

namespace ExploreBot::Lib::Functionalities::AppMode {

class ManualControlMode final : public IAppMode
{
public:
    explicit ManualControlMode(Peripherals::Led::IDebugLed& debugLed, Peripherals::ArmMcu::IArmMcu& armMcu);

    [[nodiscard]] std::string modeName() const noexcept override { return "ManualControlMode"; }
    void executeStep() noexcept override;

private:
    Peripherals::Led::IDebugLed& _debugLed;
    Peripherals::ArmMcu::IArmMcu& _armMcu;
};

}   // namespace ExploreBot::Lib::Functionalities::AppMode

#endif   // MANUALCONTROLMODE_HPP
