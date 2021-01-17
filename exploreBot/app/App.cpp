#include "App.hpp"

#include "stm32f4xx_hal.h"

namespace ExploreBot {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
App::App()
{

}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void App::exec() noexcept
{
    while(true){
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(1500);
    }
}

}
