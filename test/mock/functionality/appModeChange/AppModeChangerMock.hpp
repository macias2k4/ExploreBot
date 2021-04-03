#ifndef APPMODECHANGERMOCK_H
#define APPMODECHANGERMOCK_H

#include "functionality/appModeChange/interface/IAppModeChanger.hpp"

#include <gmock/gmock.h>

namespace ExploreBot::Test::Lib::Functionalities::AppModeChange {

namespace appFunct = ExploreBot::Lib::Functionalities;

class AppModeChangerMock final : public appFunct::AppModeChange::IAppModeChanger
{
public:
        MOCK_METHOD(bool, addObserver, (appFunct::AppModeChange::IAppModeChangeObserver&), (noexcept, override));

        MOCK_METHOD(bool, changeToStartingMode, (), (noexcept, override));
        MOCK_METHOD(bool, changeMode, (std::string_view), (noexcept, override));
};

}   // namespace ExploreBot::Test::Lib::Functionalities::AppModeChange

#endif   // APPMODECHANGERMOCK_H
