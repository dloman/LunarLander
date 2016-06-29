CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(LunarLander)
set(MODULE_NAME LunarLander)
add_definitions(-DMODULE_NAME=\"LunarLander\")

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
INCLUDE(LinuxHacks)
INCLUDE(OsxHacks)
INCLUDE(WindowsHacks)

# c++ 11 option
option(USE_CXX11 "Use C++11" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

include_directories(src)

set(CMAKE_DEBUG_POSTFIX d)

add_executable(
  LunarLander
  src/LunarLander.cpp
  src/Display.cpp
  src/Display.hpp
  )

target_link_libraries(
  LunarLander
  ${SDL2_LIBRARY}
  )
