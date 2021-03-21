#include "functionality/appModeChange/AppModeInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

AppModeInterruptHandler::AppModeInterruptHandler(IAppModeChanger& appModeChanger, AppMode::AppModePtrVector& appModes)
    : _appModeChanger { appModeChanger }
{
    for (const auto& appMode : appModes) {
        _appModeNames.emplace_back(appMode->modeName());
    }
}

bool AppModeInterruptHandler::handle() noexcept
{
    _currentAppNameIndex++;
    if (_currentAppNameIndex >= _appModeNames.size()) {
        _currentAppNameIndex = 0;
    }
    return _appModeChanger.changeMode(_appModeNames.at(_currentAppNameIndex));
}

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange
