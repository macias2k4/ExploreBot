#include "functionality/appModeChange/AppModeInterruptHandler.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

AppModeInterruptHandler::AppModeInterruptHandler(IAppModeChanger& appModeChanger)
    : _appModeChanger{appModeChanger}
{

}

}
