
add_library ("stm" STATIC
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_cortex.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_gpio.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_rcc.h"
 "${CUBE_ROOT}/Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_system.h"
 "${STARTUP_CODE}"
)

