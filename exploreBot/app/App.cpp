#include "App.hpp"

#include "stm32f4xx_hal.h"

namespace ExploreBot {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
App::App(Lib::Functionalities::AppMode::IAppMode& appMode)
    : _appMode { appMode }
{}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void App::exec() noexcept
{
    while (true) {
        _appMode.exec();
    }
}

void App::updateAppMode(Lib::Functionalities::AppMode::IAppMode& appMode) noexcept { _appMode = appMode; }

}   // namespace ExploreBot
