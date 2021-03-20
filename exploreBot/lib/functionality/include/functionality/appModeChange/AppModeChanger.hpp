#ifndef APPMODECHANGER_HPP
#define APPMODECHANGER_HPP

#include "functionality/appModeChange/interface/IAppModeChanger.hpp"
#include "functionality/appMode/interface/IAppMode.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class AppModeChanger final : public IAppModeChanger
{
public:
    explicit AppModeChanger(AppMode::AppModePtrVector& appModes);

    bool addObserver(AppModeChangeObserverPtr newObserver) noexcept override;
    [[nodiscard]] bool changeMode(std::string_view modeName) noexcept override;

private:
    AppMode::AppModePtrVector& _appModes;
    AppModeChangeObserverPtrVector _observers;

    void notifyAllObservers(AppMode::IAppMode& appMode) noexcept;
};

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange

#endif   // APPMODECHANGER_HPP
