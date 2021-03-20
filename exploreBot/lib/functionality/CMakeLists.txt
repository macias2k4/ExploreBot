cmake_minimum_required(VERSION 3.15)
project(Functionality VERSION 0.0.1)

#dependencies
#find_package

#library definition
add_library(Functionality
    include/functionality/interruptsHandlerCaller/interface/IInterruptHandler.hpp
    include/functionality/interruptsHandlerCaller/InterruptsHandlerCaller.hpp
    src/interruptsHandlerCaller/InterruptsHandlerCaller.cpp
    include/functionality/appModeChange/interface/IAppModeChanger.hpp
    include/functionality/appModeChange/interface/IAppModeChangeObserver.hpp
    include/functionality/appModeChange/AppModeChanger.hpp
    include/functionality/appMode/interface/IAppMode.hpp
    src/appModeChange/AppModeChanger.cpp
    include/functionality/appModeChange/AppModeInterruptHandler.hpp
    src/appModeChange/AppModeInterruptHandler.cpp
)
target_compile_features(Functionality PUBLIC cxx_std_17)
target_include_directories(Functionality PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(Functionality Common)
