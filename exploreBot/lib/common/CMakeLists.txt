add_library(Common INTERFACE)

target_include_directories(Common INTERFACE include/)

target_sources(Common INTERFACE include/common/gpio/GPIO.hpp)
