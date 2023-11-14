# CMake minimum required version
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

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
if(MSVC)
	target_link_libraries(Game "msvc/raylib" winmm.lib gdi32.lib user32 shell32)
else()
	target_link_libraries(Game "mingw/libraylib" winmm.lib gdi32.lib user32 shell32)
endif()
