cmake_minimum_required(VERSION 3.0)

project(model-prototype VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set compiler options
if (CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
  if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "e2k")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -fvisibility=default -pedantic -Wall")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -fvisibility=hidden -fvisibility-inlines-hidden -pedantic -Wall\
        -Wextra -Wno-long-long -Weffc++ -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
        -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast \
        -Woverloaded-virtual -Wredundant-decls -Wshadow -Wstrict-null-sentinel -Wundef \
        -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option")
    if(CMAKE_SIZEOF_VOID_P LESS_EQUAL 4)
      CHECK_CXX_COMPILER_FLAG("-march=i586" COMPILER_SUPPORTS_MARCH_I586)
      if (${COMPILER_SUPPORTS_MARCH_I586})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=i586")
      endif()
    endif()
  endif()
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(model)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable (model-prototype ${PROJECT_SOURCES})
target_link_libraries(model-prototype Qt5::Widgets)


