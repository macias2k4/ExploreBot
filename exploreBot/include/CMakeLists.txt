add_library("include" STATIC
    main.h
    stm32f4xx_hal_conf.h
    stm32f4xx_it.h
)

target_include_directories(include PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
