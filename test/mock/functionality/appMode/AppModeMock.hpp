#ifndef APPMODEMOCK_HPP
#define APPMODEMOCK_HPP

#include "functionality/appMode/interface/IAppMode.hpp"

#include <gmock/gmock.h>

namespace ExploreBot::Test::Lib::Functionalities::AppMode {

namespace appFunct = ExploreBot::Lib::Functionalities;

class AppModeMock final : public appFunct::AppMode::IAppMode
{
    MOCK_METHOD(std::string, modeName, (), (const, noexcept));
    MOCK_METHOD(void, executeStep, (), (noexcept, override));
};

}   // namespace ExploreBot::Test::Lib::Functionalities::AppMode

#endif   // APPMODEMOCK_HPP
