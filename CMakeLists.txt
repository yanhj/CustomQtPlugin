cmake_minimum_required(VERSION 3.1)
#项目名称
project(CustomQtPlugin)

#C++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SOURCE_FILES
        main.cpp
        )

if (WIN32)
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        #编译为发布模式
        add_definitions(-DQT_DEBUG)
    else()
        #编译为调试模式
        add_definitions(-DQT_NO_DEBUG)
    endif()
endif ()

add_executable(CustomQtPlugin ${SOURCE_FILES} main.cpp)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

#打印架构信息
message(STATUS "CMAKE_OSX_ARCHITECTURES: ${CMAKE_OSX_ARCHITECTURES}")

add_subdirectory(Plugins/DateEcho/)
add_subdirectory(Plugins/MessageEcho/)