cmake_minimum_required(VERSION 3.15)
 
project(ExploreBotTest CXX)

enable_testing()

include(FetchContent)

# GTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
FetchContent_MakeAvailable(googletest)

#add_subdirectory(include)
#add_subdirectory(src)
add_executable(${CMAKE_PROJECT_NAME}
    Test.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    gtest_main
)

add_test(
    NAME ${CMAKE_PROJECT_NAME}
    COMMAND ${CMAKE_PROJECT_NAME}
)
