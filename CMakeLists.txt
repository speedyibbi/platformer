# CMake minimum required version
cmake_minimum_required (VERSION 3.8)

# Set C++ version
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

# Setup project name
project ("Platformer")

# Add include directory to header search path
include_directories(include/)

# Add lib directory to library search path
link_directories(lib/)

# Search for source files
file(GLOB_RECURSE sourcefiles "src/*.cpp")

# Compile and link source files into the executable
add_executable (Game ${sourcefiles})

# Link to library
target_link_libraries(Game raylib winmm.lib gdi32.lib user32 shell32)
