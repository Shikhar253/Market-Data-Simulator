cmake_minimum_required(VERSION 3.10)
project(MDSTEST CXX)

set(CMAKE_CXX_STANDARD 11)

# Add the source files to the executable
add_executable(MDSTEST
    src/main.cpp
    src/MarketData.cpp
    src/RandomGenerator.cpp
    src/TimestampGenerator.cpp
)

# Check if we are on Windows and set appropriate generator
if (WIN32)
    set(CMAKE_GENERATOR "NMake Makefiles")
endif()


# Enable testing for Windows
enable_testing()

# Set the build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Output binaries to bin directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Add compiler flags for Debug mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# Add compiler flags for Release mode
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

# Print additional information for debugging
message("CMake Build Type: ${CMAKE_BUILD_TYPE}")
message("CMake Generator : ${CMAKE_GENERATOR}")
message("C++ Compiler    : ${CMAKE_CXX_COMPILER}")

# Optionally, add tests if needed
# add_subdirectory(test)
