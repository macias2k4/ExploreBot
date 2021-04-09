#include "App.hpp"

#include "stm32f4xx_hal.h"

using namespace std;

namespace ExploreBot {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
App::App(funct::AppModeChange::IAppModeChanger& appModeChanger,
    funct::InterruptHandling::InterruptsHandlerCaller& interruptsHandlerCaller, Lib::Peripherals::Logger::ILogger& logger)
    : _appModeChanger { appModeChanger }
    , _interruptsHandlerCaller { interruptsHandlerCaller }
    , _logger { logger }
{}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void App::exec() noexcept
{
    _appModeChanger.addObserver(*this);
    if (!_appModeChanger.changeToStartingMode()) {
        return;
    }
    while (true) {
        _currentAppMode->executeStep();
    }
}

void App::updateAppMode(funct::AppMode::AppModePtr appMode) noexcept
{
    _currentAppMode = appMode;
    _logger.info(string { "Changed AppMode to '" }.append(_currentAppMode->modeName()).append("'"));
}

std::optional<bool> App::callHandler(Lib::Common::GPIO::GPIOPin gpioPin) noexcept
{
    return _interruptsHandlerCaller.callHandler(gpioPin);
}

}   // namespace ExploreBot
