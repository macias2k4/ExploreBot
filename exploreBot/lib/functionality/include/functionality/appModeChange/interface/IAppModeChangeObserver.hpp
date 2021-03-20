#ifndef IAPPMODECHANGEOBSERVER_HPP
#define IAPPMODECHANGEOBSERVER_HPP

#include "functionality/appMode/interface/IAppMode.hpp"

#include <memory>
#include <vector>

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class IAppModeChangeObserver
{
public:
    virtual ~IAppModeChangeObserver() = default;

    virtual std::string name() const noexcept = 0;
    virtual void updateAppMode(AppMode::IAppMode& appMode) noexcept = 0;
};

using AppModeChangeObserverPtr = std::shared_ptr<IAppModeChangeObserver>;
using AppModeChangeObserverPtrVector = std::vector<AppModeChangeObserverPtr>;

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange

#endif   // IAPPMODECHANGEOBSERVER_HPP
