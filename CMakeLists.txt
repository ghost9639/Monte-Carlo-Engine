cmake_minimum_required(VERSION 3.14)
project(GeneralInsuranceRisk&CAPM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE Release)


# pybind

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG QUIET)

if (NOT pybind11_FOUND)
   message(STATUS "Couldn't find pybind, fetching from Git")
   include(FetchContent)
   FetchContent_Declare(
	pybind11
	GIT_REPOSITORY https://github.com/pybind/pybind11.git
	GIT_TAG v2.12.0
   )
   FetchContent_MakeAvailable(pybind11)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# build

set(SOURCE_FILES
    src/App.cpp
    src/GICAPM.cpp
)

add_library(core STATIC
    src/GICAPM.cpp
)

target_include_directories(core PRIVATE include)
target_link_libraries(core PRIVATE pybind11::module)

add_executable(App src/App.cpp)
target_link_libraries(App PRIVATE core)

pybind11_add_module(GICAPM src/GICAPM.cpp)
target_include_directories(GICAPM PRIVATE include)


# Xtools for Mac

if (APPLE)
   target_link_libraries(App PRIVATE edit)
else()
   find_library(READLINE_LIB readline)
   if (READLINE_LIB)
      target_link_libraries(App PRIVATE ${READLINE_LIB})
   else()
      target_link_libraries(App PRIVATE edit)
   endif()
endif()


# pyman

install(TARGETS GICAPM DESTINATION .)
