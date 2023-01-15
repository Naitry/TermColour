cmake_minimum_required(VERSION 3.11)
project(TCExample)

set(CMAKE_CXX_STANDARD 23)

# Define sources and executable
set(EXECUTABLE_NAME "TCExample")

set(project_sources TermColourExample.cpp
                    TermColour.hpp
                    termcolor.hpp)

add_executable(${EXECUTABLE_NAME}
               ${project_sources})
