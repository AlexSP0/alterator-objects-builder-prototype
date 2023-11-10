cmake_minimum_required(VERSION 3.5)

project(model-prototype VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(HEADERS
    model.h
    object.h
    objectitem.h
)

set(SOURCES
    model.cpp
    object.cpp
    objectitem.cpp
)

add_library(model ${HEADERS}  ${SOURCES})
target_link_libraries(model Qt5::Widgets Qt5::Core)
