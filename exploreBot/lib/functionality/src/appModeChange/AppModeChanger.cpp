#include "functionality/appModeChange/AppModeChanger.hpp"

#include <algorithm>

using namespace std;

namespace ExploreBot::Lib::Functionalities::AppModeChange {

AppModeChanger::AppModeChanger(AppMode::AppModePtrVector& appModes)
    : _appModes { appModes }
{}

bool AppModeChanger::addObserver(AppModeChangeObserverPtr newObserver) noexcept
{
    const auto it = find_if(begin(_observers), end(_observers),
        [&newObserver](const AppModeChangeObserverPtr& observer) { return newObserver->name() == observer->name(); });
    if (it != end(_observers)) {
        return false;
    }
    _observers.push_back(newObserver);
    return true;
}

bool AppModeChanger::changeMode(std::string_view modeName) noexcept
{
    auto it = find_if(begin(_appModes), end(_appModes),
        [&modeName](const AppMode::AppModePtr& appMode) { return appMode->modeName() == modeName; });
    if (it == end(_appModes)) {
        return false;
    }
    notifyAllObservers(*(*it));
    return true;
}

void AppModeChanger::notifyAllObservers(AppMode::IAppMode& appMode) noexcept
{
    for (auto& observer : _observers) {
        observer->updateAppMode(appMode);
    }
}

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange
