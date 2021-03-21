#ifndef APPMODEINTERRUPTHANDLER_HPP
#define APPMODEINTERRUPTHANDLER_HPP

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"
#include "functionality/appModeChange/interface/IAppModeChanger.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class AppModeInterruptHandler final : public InterruptHandling::IInterruptHandler
{
public:
    explicit AppModeInterruptHandler(IAppModeChanger& appModeChanger, AppMode::AppModePtrVector& appModes);

    [[nodiscard]] Common::GPIO::GPIOPin triggeringPin() const noexcept override { return Common::GPIO::userButtonD2; }
    [[nodiscard]] bool handle() noexcept override;

private:
    IAppModeChanger& _appModeChanger;
    std::vector<std::string> _appModeNames;
    std::vector<std::string>::size_type _currentAppNameIndex { 0 };
};

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange

#endif   // APPMODEINTERRUPTHANDLER_HPP
