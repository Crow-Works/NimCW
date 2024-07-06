cmake_minimum_required(VERSION 3.27)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_GENERATOR Ninja)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/")

find_program(NIM nim)
if(NIM)
  message("Found nim!")
else()
  message("Failed to find nim...")
endif()

# ######################### NimCW -- Managed #############################
set(NIM_SOURCE_DIR "${CMAKE_SOURCE_DIR}/NimCWManaged")
set(NIM_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build/")

file(GLOB_RECURSE NIM_SOURCES "${NIM_SOURCE_DIR}/*.nim")

if(WIN32)
  set(NIM_LIB_EXT "dll")
else()
  set(NIM_LIB_EXT "so")
endif()

add_custom_command(
  OUTPUT ${NIM_OUTPUT_DIR}/NimScripts.${NIM_LIB_EXT}
  COMMAND ${NIM} c -d:release --app:lib
          -o:${NIM_OUTPUT_DIR}/NimScripts.${NIM_LIB_EXT} ${NIM_SOURCES}
  WORKING_DIRECTORY ${NIM_SOURCE_DIR}
  COMMENT "Compiling Nim
sources")

add_custom_target(
  NimCWManaged ALL
  DEPENDS ${NIM_OUTPUT_DIR}/NimScripts.${NIM_LIB_EXT}
  COMMENT
    "Compiling Nim scripts into ${NIM_OUTPUT_DIR}/NimScripts.${NIM_LIB_EXT}")

# ######################### NimCW -- Native ###############################

project(NimCWNative)
set(NATIVE_DIR "${CMAKE_SOURCE_DIR}/NimCWNative")
set(NATIVE_INCLUDE_DIR "${NATIVE_DIR}/include")
set(NATIVE_SOURCE_DIR "${NATIVE_DIR}/src")

file(GLOB_RECURSE NATIVE_SRC "${NATIVE_SOURCE_DIR}/*.cpp")

add_library(NimCWNative SHARED ${NATIVE_SRC})
target_include_directories(NimCWNative PRIVATE ${NATIVE_INCLUDE_DIR})
if(WIN32)
  target_compile_definitions(NimCWNative PRIVATE EXAMPLE_EXPORTS)
endif()

set_target_properties(
  NimCWNative
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
             PREFIX ""
             OUTPUT_NAME NimCW)

# ######################### NimCW -- Example ###############################

project(NimCWExample)
add_executable(NimCWExample "${CMAKE_SOURCE_DIR}/Example/example.cpp")
target_include_directories(NimCWExample PRIVATE ${NATIVE_INCLUDE_DIR})
target_link_libraries(NimCWExample NimCWNative)
