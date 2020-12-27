cmake_minimum_required(VERSION 3.15)
 
project(ExploreBot C CXX ASM)

#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 17)

# for startup code written by ST in assembly
enable_language(ASM-ATT)
 
#set(CMAKE_C_COMPILER /home/macias/opt/xPacks/arm-none-eabi-gcc/xpack-arm-none-eabi-gcc-9.2.1-1.1/bin/arm-none-eabi-gcc)
#set(CMAKE_CXX_COMPILER /home/macias/opt/xPacks/arm-none-eabi-gcc/xpack-arm-none-eabi-gcc-9.2.1-1.1/bin/arm-none-eabi-g++)

# conan section
# ...

enable_testing()

set(CMAKE_CXX_FLAGS " -DGTEST_HAS_PTHREAD=0 -DGTEST_HAS_POSIX_RE=0 -DGTEST_HAS_CLONE=0 -DGTEST_HAS_EXCEPTIONS=0 -DGTEST_HAS_TR1_TUPLE=0 -DGTEST_HAS_STREAM_REDIRECTION=0 -DGTEST_HAS_RTTI=0")
#set(CMAKE_CXX_EXTENSIONS OFF)

# Resonator used in this project. Stm32F4-DISCO uses 8MHz crystal. I left this definition here
# in the CMakeLists.txt rather than the toolchain file, because it's project dependent, not
# "platform" dependent, where by platform I mean STM32F4.
add_definitions(-DHSE_VALUE=8000000)

include(FetchContent)

################################ packet manager? ################################
# - GTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
#FetchContent_GetProperties(googletest)
#if(NOT googletest_POPULATED)
#  FetchContent_Populate(googletest)
#  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
#endif()
FetchContent_MakeAvailable(googletest)

include_directories("app")

#add_subdirectory(googletest)
add_subdirectory(extern)
#add_subdirectory(include)
#add_subdirectory(src)
add_subdirectory(app)
#add_subdirectory(test)

#FIND_PROGRAM (OPENOCD openocd)
#ADD_CUSTOM_TARGET("upload" DEPENDS ${CMAKE_PROJECT_NAME}.elf COMMAND ${OPENOCD} -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg -c 'program ${CMAKE_PROJECT_NAME}.elf verify reset exit')

