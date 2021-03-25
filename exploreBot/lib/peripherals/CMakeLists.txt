cmake_minimum_required(VERSION 3.15)
project(Peripherals VERSION 0.0.1)

add_library(Peripherals
    include/peripherals/armMcu/interface/IArmMcu.hpp
    include/peripherals/armMcu/ArmMcu.hpp
    src/armMcu/ArmMcu.cpp
    include/peripherals/led/interface/ILed.hpp
    include/peripherals/led/interface/IDebugLed.hpp
    include/peripherals/led/DebugLed.hpp
    src/led/DebugLed.cpp
)

target_compile_features(Peripherals PUBLIC cxx_std_17)
target_include_directories(Peripherals PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(Peripherals Common)

