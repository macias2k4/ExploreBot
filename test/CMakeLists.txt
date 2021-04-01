cmake_minimum_required(VERSION 3.15)
project(ExploreBotTest CXX)

enable_testing()

# dependencies
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/memsharded/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGET)
#    add_library(GTest::Main INTERFACE IMPORTED)
#    target_link_libraries(GTest::Main INTERFACE CONAN_PKG::gtest)
endif()

add_subdirectory(../exploreBot/lib/common exploreBotLib/common)
include_directories(../exploreBot/lib/peripherals/include)
add_subdirectory(../exploreBot/lib/functionality exploreBotLib/functionality)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# target definition
#add_subdirectory(mocks)
#add_subdirectory(lib)
#add_subdirectory(app)
add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    mock/functionality/appMode/AppModeMock.hpp
    mock/functionality/appModeChange/AppModeChangerMock.hpp
    lib/functionality/InterruptHandling/InterruptsHandlerCallerTest.cpp
)
target_link_libraries(${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
        Functionality
)
add_test(NAME ${CMAKE_PROJECT_NAME}
    COMMAND ${CMAKE_PROJECT_NAME}
)
