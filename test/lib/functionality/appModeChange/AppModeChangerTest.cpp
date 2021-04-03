#include "mock/functionality/appMode/AppModeMock.hpp"
#include "mock/functionality/appModeChange/AppModeChangeObserverMock.hpp"

#include "functionality/appModeChange/AppModeChanger.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;
using namespace std;

namespace ExploreBot {
namespace Test {
namespace Lib {
namespace Functionalities {
namespace AppModeChange {

namespace appFunct = ExploreBot::Lib::Functionalities;

TEST(AppModeChangerTest, noAppModes_changeToStartingMode_fail)
{
    appFunct::AppMode::AppModePtrVector appModes;
    appFunct::AppModeChange::AppModeChanger appModeChanger { appModes };

    ASSERT_EQ(false, appModeChanger.changeToStartingMode());
}

TEST(AppModeChangerTest, appModesNotEmpty_changeToStartingMode_changeToFirstMode)
{
    const std::string_view firstAppModeName = "FirstAppMode"sv;

    auto firstAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*firstAppMode, modeName()).Times(2).WillRepeatedly(Return(string { firstAppModeName }));
    appFunct::AppMode::AppModePtrVector appModes { firstAppMode };

    appFunct::AppModeChange::AppModeChanger appModeChanger { appModes };

    ASSERT_EQ(true, appModeChanger.changeToStartingMode());
}

TEST(AppModeChangerTest, noAppModes_changeMode_fail)
{
    appFunct::AppMode::AppModePtrVector appModes;
    appFunct::AppModeChange::AppModeChanger appModeChanger { appModes };

    ASSERT_EQ(false, appModeChanger.changeMode("FirstAppMode"));
}

TEST(AppModeChangerTest, incorrectAppModeName_changeMode_fail)
{
    const std::string_view firstAppModeName = "FirstAppMode"sv;

    auto firstAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*firstAppMode, modeName()).Times(1).WillRepeatedly(Return(string { firstAppModeName }));
    appFunct::AppMode::AppModePtrVector appModes { firstAppMode };

    appFunct::AppModeChange::AppModeChanger appModeChanger { appModes };

    ASSERT_EQ(false, appModeChanger.changeMode("WrongAppModeName"));
}

TEST(AppModeChangerTest, correctAppModeName_changeMode_succeedAndNotifyObserver)
{
    const std::string_view firstAppModeName = "FirstAppMode"sv;

    auto firstAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*firstAppMode, modeName()).Times(1).WillRepeatedly(Return(string { firstAppModeName }));
    appFunct::AppMode::AppModePtrVector appModes { firstAppMode };

    appFunct::AppModeChange::AppModeChanger appModeChanger { appModes };

    AppModeChange::AppModeChangeObserverMock appModeChangeObserver;
    EXPECT_CALL(appModeChangeObserver, updateAppMode(_)).Times(1);
    appModeChanger.addObserver(appModeChangeObserver);

    ASSERT_EQ(true, appModeChanger.changeMode(firstAppModeName));
}

}   // namespace AppModeChange
}   // namespace Functionalities
}   // namespace Lib
}   // namespace Test
}   // namespace ExploreBot
