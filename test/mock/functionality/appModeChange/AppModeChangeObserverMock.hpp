#ifndef APPMODECHANGEOBSERVERMOCK_HPP
#define APPMODECHANGEOBSERVERMOCK_HPP

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"

#include <gmock/gmock.h>

namespace ExploreBot::Test::Lib::Functionalities::AppModeChange {

namespace appFunct = ExploreBot::Lib::Functionalities;

class AppModeChangeObserverMock final : public appFunct::AppModeChange::IAppModeChangeObserver
{
public:
    MOCK_METHOD(std::string, name, (), (const, noexcept, override));
    MOCK_METHOD(void, updateAppMode, (appFunct::AppMode::AppModePtr appMode), (noexcept, override));
};

}   // namespace ExploreBot::Test::Lib::Functionalities::AppModeChange
#endif   // APPMODECHANGEOBSERVERMOCK_HPP
