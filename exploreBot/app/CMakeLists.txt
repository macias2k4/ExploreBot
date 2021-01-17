include_directories("../extern/dependencyInjection")

add_executable(${CMAKE_PROJECT_NAME}.elf
    App.cpp
    main.cpp
    stm32f4xx_hal_msp.c
    stm32f4xx_it.c
    system_stm32f4xx
)

#target_link_libraries(${CMAKE_PROJECT_NAME}.elf PRIVATE -Wl,--whole-archive stm -Wl,--no-whole-archive)# motorsController)
target_link_libraries (${CMAKE_PROJECT_NAME}.elf -Wl,--whole-archive stm -Wl,--no-whole-archive)
