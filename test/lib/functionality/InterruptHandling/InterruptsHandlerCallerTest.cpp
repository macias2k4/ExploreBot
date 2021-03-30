#include "mock/functionality/appModeChange/AppModeChangerMock.hpp"

#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"
#include "functionality/appModeChange/AppModeInterruptHandler.hpp"
#include "functionality/appMode/ManualControlMode.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;
using namespace std;

namespace ExploreBot {
namespace Test {
namespace Lib {
namespace Functionalities {
namespace InterruptHandling {

namespace appFunct = ExploreBot::Lib::Functionalities;

TEST(InterruptsHandlerCallerTest, noHandlers_callHandler_noInterruptHandleCalled)
{
    appFunct::InterruptHandling::IInterruptHandlerPtrVector handlers;
    appFunct::InterruptHandling::InterruptsHandlerCaller interruptsHandlerCaller { handlers };

    ASSERT_EQ(false, interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userButtonD2));
}

TEST(InterruptsHandlerCallerTest, ledD13Interrupt_callHandler_notCalledAppModeChangeInterruptHandle)
{
    AppModeChange::AppModeChangerMock appModeChanger;
    appFunct::AppMode::AppModePtrVector appModes;
    auto appModeInterruptHandler = make_shared<appFunct::AppModeChange::AppModeInterruptHandler>(appModeChanger, appModes);
    appFunct::InterruptHandling::IInterruptHandlerPtrVector handlers { appModeInterruptHandler };
    appFunct::InterruptHandling::InterruptsHandlerCaller interruptsHandlerCaller { handlers };

    ASSERT_EQ(false, interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userLedD13));
}

TEST(InterruptsHandlerCallerTest, buttonD2InterruptAndNoAppModes_callHandler_calledAppModeChangeInterruptHandleWithFail)
{
    AppModeChange::AppModeChangerMock appModeChanger;
    appFunct::AppMode::AppModePtrVector appModes;
    auto appModeInterruptHandler = make_shared<appFunct::AppModeChange::AppModeInterruptHandler>(appModeChanger, appModes);
    appFunct::InterruptHandling::IInterruptHandlerPtrVector handlers { appModeInterruptHandler };
    appFunct::InterruptHandling::InterruptsHandlerCaller interruptsHandlerCaller { handlers };

    ASSERT_EQ(false, interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userButtonD2));
}

TEST(InterruptsHandlerCallerTest, buttonD2InterruptWithAppModes_callHandler_calledAppModeChangeInterruptHandleWithSucceed)
{
    ASSERT_EQ(false, true);
}

}   // namespace InterruptHandling
}   // namespace Functionalities
}   // namespace Lib
}   // namespace Test
}   // namespace ExploreBot
