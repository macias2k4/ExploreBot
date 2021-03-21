#ifndef APP_H
#define APP_H

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"

namespace ExploreBot {

namespace funct = Lib::Functionalities;

class App final : public Lib::Functionalities::AppModeChange::IAppModeChangeObserver
{
public:
    explicit App(funct::AppMode::IAppMode& startAppMode);

    void exec() noexcept;

    virtual std::string name() const noexcept override { return "App"; }
    void updateAppMode(funct::AppMode::IAppMode& appMode) noexcept override;

private:
    funct::AppMode::IAppMode& _currentAppMode;
};

}   // namespace ExploreBot

#endif
