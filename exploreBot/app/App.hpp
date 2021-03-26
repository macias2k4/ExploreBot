#ifndef APP_H
#define APP_H

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"
#include "functionality/appModeChange/interface/IAppModeChanger.hpp"
#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"

namespace ExploreBot {

namespace funct = Lib::Functionalities;

class App final : public Lib::Functionalities::AppModeChange::IAppModeChangeObserver
{
public:
    explicit App(funct::AppModeChange::IAppModeChanger& appModeChanger,
        funct::InterruptHandling::InterruptsHandlerCaller& interruptsHandlerCaller);

    void exec() noexcept;

    virtual std::string name() const noexcept override { return "App"; }
    void updateAppMode(funct::AppMode::AppModePtr appMode) noexcept override;

    [[nodiscard]] bool callHandler(Lib::Common::GPIO::GPIOPin gpioPin) noexcept;

private:
    funct::AppModeChange::IAppModeChanger& _appModeChanger;
    funct::AppMode::AppModePtr _currentAppMode;
    funct::InterruptHandling::InterruptsHandlerCaller& _interruptsHandlerCaller;
};

}   // namespace ExploreBot

#endif
