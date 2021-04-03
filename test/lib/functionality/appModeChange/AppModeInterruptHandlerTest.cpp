#include "mock/functionality/appModeChange/AppModeChangerMock.hpp"
#include "mock/functionality/appMode/AppModeMock.hpp"

#include "functionality/appModeChange/AppModeInterruptHandler.hpp"

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

TEST(AppModeInterruptHandlerTest, noAppModes_handle_callAppModeChangeFail)
{
    AppModeChangerMock appModeChanger;
    appFunct::AppMode::AppModePtrVector appModes;
    appFunct::AppModeChange::AppModeInterruptHandler appModeInterruptHandler { appModeChanger, appModes };

    ASSERT_EQ(false, appModeInterruptHandler.handle());
}

TEST(AppModeInterruptHandlerTest, whenAtLeastTwoAppModesThenFirstCall_handle_changeToSecondAppMode)
{
    const std::string_view secondAppModeName = "SecondAppMode"sv;

    auto firstAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*firstAppMode, modeName()).Times(1).WillOnce(Return("FirstAppMode"));
    auto secondAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*secondAppMode, modeName()).Times(1).WillOnce(Return(string { secondAppModeName }));
    appFunct::AppMode::AppModePtrVector appModes { firstAppMode, secondAppMode };

    AppModeChangerMock appModeChanger;
    EXPECT_CALL(appModeChanger, changeMode(secondAppModeName)).Times(1).WillOnce(Return(true));

    appFunct::AppModeChange::AppModeInterruptHandler appModeInterruptHandler { appModeChanger, appModes };

    ASSERT_EQ(true, appModeInterruptHandler.handle());
}

TEST(AppModeInterruptHandlerTest, whenReachedLastAppModeTheNextCall_handle_changeToFirstAppMode)
{
    const std::string_view firstAppModeName = "FirstAppMode"sv;
    const std::string_view secondAppModeName = "SecondAppMode"sv;

    auto firstAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*firstAppMode, modeName()).Times(1).WillOnce(Return(string { firstAppModeName }));
    auto secondAppMode = make_shared<AppMode::AppModeMock>();
    EXPECT_CALL(*secondAppMode, modeName()).Times(1).WillOnce(Return(string { secondAppModeName }));
    appFunct::AppMode::AppModePtrVector appModes { firstAppMode, secondAppMode };

    AppModeChangerMock appModeChanger;
    EXPECT_CALL(appModeChanger, changeMode(secondAppModeName)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(appModeChanger, changeMode(firstAppModeName)).Times(1).WillOnce(Return(true));

    appFunct::AppModeChange::AppModeInterruptHandler appModeInterruptHandler { appModeChanger, appModes };

    for (appFunct::AppMode::AppModePtrVector::size_type i = 0; i < appModes.size(); i++) {
        ASSERT_EQ(true, appModeInterruptHandler.handle());
    }
}

}   // namespace AppModeChange
}   // namespace Functionalities
}   // namespace Lib
}   // namespace Test
}   // namespace ExploreBot
