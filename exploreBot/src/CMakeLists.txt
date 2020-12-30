#add_library("src" STATIC
#    stm32f4xx_hal_msp.c
#    stm32f4xx_it.c
#    system_stm32f4xx
#    )

#target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#add_executable(${CMAKE_PROJECT_NAME}.elf main.cpp)

#add_library(src
#    stm32f4xx_hal_msp.c
#    stm32f4xx_it.c
#    system_stm32f4xx
#    )

#add_executable(${CMAKE_PROJECT_NAME}.elf
#    stm32f4xx_hal_msp.c
#    stm32f4xx_it.c
#    system_stm32f4xx
#)

##target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries(src PRIVATE include)
