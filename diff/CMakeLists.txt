﻿# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (diff "main.cpp"  "factorial.cpp" "factorial.h" "gauss_method.cpp" "gauss_method.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET diff PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
