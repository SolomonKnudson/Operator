cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
#Stop module flags from being passed
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

project(Inserter LANGUAGES CXX)

add_library(Inserter INTERFACE)

target_include_directories(Inserter INTERFACE 
  $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/>
)

target_compile_features(Inserter INTERFACE
  cxx_std_17
)

set_target_properties(Inserter PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
)

  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/app)
