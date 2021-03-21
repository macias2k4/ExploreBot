#include "App.hpp"

#include "stm32f4xx_hal.h"

namespace ExploreBot {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
App::App(Lib::Functionalities::AppMode::IAppMode& startAppMode)
    : _currentAppMode { startAppMode }
{}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void App::exec() noexcept
{
    while (true) {
        _currentAppMode.executeStep();
    }
}

void App::updateAppMode(Lib::Functionalities::AppMode::IAppMode& appMode) noexcept { _currentAppMode = appMode; }

}   // namespace ExploreBot
