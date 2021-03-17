#ifndef APPMODEINTERRUPTHANDLER_HPP
#define APPMODEINTERRUPTHANDLER_HPP

#include "functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp"
#include "functionality/appModeChange/interface/IAppModeChanger.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class AppModeInterruptHandler
{
public:
    explicit AppModeInterruptHandler(IAppModeChanger& appModeChanger);

private:
    IAppModeChanger& _appModeChanger;
};

}

#endif // APPMODEINTERRUPTHANDLER_HPP
