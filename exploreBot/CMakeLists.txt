cmake_minimum_required(VERSION 3.15)
 
project(ExploreBot LANGUAGES C CXX ASM)

# for startup code written by ST in assembly
enable_language(ASM-ATT)
 
# Resonator used in this project. Stm32F4-DISCO uses 8MHz crystal. I left this definition here
# in the CMakeLists.txt rather than the toolchain file, because it's project dependent, not
# "platform" dependent, where by platform I mean STM32F4.
add_definitions(-DHSE_VALUE=8000000)

#include(FetchContent)

## DI
#FetchContent_Declare(
#  di
#  GIT_REPOSITORY https://github.com/boost-ext/di.git
#  GIT_TAG        1.2.0
#)
#FetchContent_MakeAvailable(di)

include_directories("app")

add_subdirectory(extern)
add_subdirectory(lib)
#add_subdirectory(include)
#add_subdirectory(src)
add_subdirectory(app)

#FIND_PROGRAM (OPENOCD openocd)
#ADD_CUSTOM_TARGET("upload" DEPENDS ${CMAKE_PROJECT_NAME}.elf COMMAND ${OPENOCD} -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg -c 'program ${CMAKE_PROJECT_NAME}.elf verify reset exit')

