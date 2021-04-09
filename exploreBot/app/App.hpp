#ifndef APP_H
#define APP_H

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"
#include "functionality/appModeChange/interface/IAppModeChanger.hpp"
#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"

#include "peripherals/logger/interface/ILogger.hpp"

namespace ExploreBot {

namespace funct = Lib::Functionalities;
namespace periph = Lib::Peripherals;

class App final : public Lib::Functionalities::AppModeChange::IAppModeChangeObserver
{
public:
    App(funct::AppModeChange::IAppModeChanger& appModeChanger,
        funct::InterruptHandling::InterruptsHandlerCaller& interruptsHandlerCaller, periph::Logger::ILogger& logger);

    void exec() noexcept;

    virtual std::string name() const noexcept override { return "App"; }
    void updateAppMode(funct::AppMode::AppModePtr appMode) noexcept override;

    [[nodiscard]] std::optional<bool> callHandler(Lib::Common::GPIO::GPIOPin gpioPin) noexcept;

private:
    funct::AppModeChange::IAppModeChanger& _appModeChanger;
    funct::AppMode::AppModePtr _currentAppMode;
    funct::InterruptHandling::InterruptsHandlerCaller& _interruptsHandlerCaller;
    periph::Logger::ILogger& _logger;
};

}   // namespace ExploreBot

#endif
