cmake_minimum_required(VERSION 3.1)
#项目名称
project(DateEcho)

#C++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        *.ui
        **/*.cpp
        **/*.h
        **/*.hpp
        **/*.ui
        )

include_directories(../Interface)

if (WIN32)
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        #编译为发布模式
        add_definitions(-DQT_DEBUG)
    else()
        #编译为调试模式
        add_definitions(-DQT_NO_DEBUG)
    endif()
endif ()

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

#debug模式下的库，增加后缀'd'
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

#打印架构信息
message(STATUS "CMAKE_OSX_ARCHITECTURES: ${CMAKE_OSX_ARCHITECTURES}")

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
#安装插件
install(PROGRAMS ${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}d.dylib DESTINATION ${PROJECT_BINARY_DIR}/../../plugins/)
unset(CMAKE_INSTALL_PREFIX)