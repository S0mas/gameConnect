# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.19)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget gameConnect_server gameConnect_serviceClient)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target gameConnect_server
add_library(gameConnect_server STATIC IMPORTED)

set_target_properties(gameConnect_server PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/D/Programowanie/MojeLibki/gameConnect/gameConnect_server/include/gameConnect_server"
  INTERFACE_LINK_LIBRARIES "gRPC::grpc;gRPC::grpc++;gRPC::grpc++_reflection"
)

# Create imported target gameConnect_serviceClient
add_library(gameConnect_serviceClient STATIC IMPORTED)

set_target_properties(gameConnect_serviceClient PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/D/Programowanie/MojeLibki/gameConnect/gameConnect_serviceClient/include/gameConnect_serviceClient"
  INTERFACE_LINK_LIBRARIES "gRPC::grpc;gRPC::grpc++;gRPC::grpc++_reflection"
)

# Import target "gameConnect_server" for configuration "Release"
set_property(TARGET gameConnect_server APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gameConnect_server PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/D/Programowanie/MojeLibki/build-gameConnect-Desktop_Qt_6_2_1_MSVC2019_64bit-Release/gameConnect_server/gameConnect_server.lib"
  )

# Import target "gameConnect_serviceClient" for configuration "Release"
set_property(TARGET gameConnect_serviceClient APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gameConnect_serviceClient PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/D/Programowanie/MojeLibki/build-gameConnect-Desktop_Qt_6_2_1_MSVC2019_64bit-Release/gameConnect_serviceClient/gameConnect_serviceClient.lib"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
