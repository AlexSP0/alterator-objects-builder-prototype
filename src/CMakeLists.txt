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
    constants.h

    objects/object.h
    objects/basicobject.h
    objects/category.h
    objects/localappobject.h

    aobuilderinterface.h
    aobuilderimpl.h
)

set(SOURCES
    objects/object.cpp
    objects/basicobject.cpp
    objects/category.cpp
    objects/localappobject.cpp

    aobuilderimpl.cpp
)

add_library(dbus-object-builder ${HEADERS}  ${SOURCES})
target_link_libraries(dbus-object-builder                Qt5::Widgets Qt5::Core)
