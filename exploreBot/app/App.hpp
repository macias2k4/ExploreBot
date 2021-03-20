#ifndef APP_H
#define APP_H

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"

namespace ExploreBot {

class App final : public Lib::Functionalities::AppModeChange::IAppModeChangeObserver
{
public:
    explicit App(Lib::Functionalities::AppMode::IAppMode& appMode);

    void exec() noexcept;

    virtual std::string name() const noexcept override { return "App"; }
    void updateAppMode(Lib::Functionalities::AppMode::IAppMode& appMode) noexcept override;

private:
    Lib::Functionalities::AppMode::IAppMode& _appMode;
};

}   // namespace ExploreBot

#endif
