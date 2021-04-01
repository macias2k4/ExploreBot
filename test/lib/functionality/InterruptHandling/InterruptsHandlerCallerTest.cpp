#include "mock/functionality/appModeChange/AppModeChangerMock.hpp"

#include "functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp"
#include "functionality/appModeChange/AppModeInterruptHandler.hpp"

#include <gtest/gtest.h>

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

    const auto doesHandlerCalled = interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userButtonD2).has_value();
    ASSERT_EQ(false, doesHandlerCalled);
}

TEST(InterruptsHandlerCallerTest, ledD13Interrupt_callHandler_notCalledAppModeChangeInterruptHandle)
{
    AppModeChange::AppModeChangerMock appModeChanger;
    appFunct::AppMode::AppModePtrVector appModes;
    auto appModeInterruptHandler = make_shared<appFunct::AppModeChange::AppModeInterruptHandler>(appModeChanger, appModes);
    appFunct::InterruptHandling::IInterruptHandlerPtrVector handlers { appModeInterruptHandler };
    appFunct::InterruptHandling::InterruptsHandlerCaller interruptsHandlerCaller { handlers };

    const auto doesHandlerCalled = interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userLedD13).has_value();
    ASSERT_EQ(false, doesHandlerCalled);
}

TEST(InterruptsHandlerCallerTest, userButtonD2Interrupt_callHandler_calledAppModeChangeInterruptHandle)
{
    AppModeChange::AppModeChangerMock appModeChanger;
    appFunct::AppMode::AppModePtrVector appModes;
    auto appModeInterruptHandler = make_shared<appFunct::AppModeChange::AppModeInterruptHandler>(appModeChanger, appModes);
    appFunct::InterruptHandling::IInterruptHandlerPtrVector handlers { appModeInterruptHandler };
    appFunct::InterruptHandling::InterruptsHandlerCaller interruptsHandlerCaller { handlers };

    const auto doesHandlerCalled = interruptsHandlerCaller.callHandler(ExploreBot::Lib::Common::GPIO::userButtonD2).has_value();
    ASSERT_EQ(true, doesHandlerCalled);
}

}   // namespace InterruptHandling
}   // namespace Functionalities
}   // namespace Lib
}   // namespace Test
}   // namespace ExploreBot
