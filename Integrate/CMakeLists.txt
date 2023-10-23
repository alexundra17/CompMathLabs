# CMakeList.txt : CMake project for Integrate, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Integrate "Integrate.cpp" "Integrate.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Integrate PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
