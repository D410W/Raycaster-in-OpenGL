# CMakeLists.txt
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(RaycasterOpenGL LANGUAGES CXX)

# (Optional but recommended) Set the C++ standard
# This ensures consistency across different compilers.
set(CMAKE_CXX_STANDARD 17) # For C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # CMake will error if C++17 is not available

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(OpenGL REQUIRED)

cmake_policy(SET CMP0072 NEW)

add_executable(raycasted src/main.cpp)

# (Optional) Link libraries if your executable needs them
# For example, if you were using an external library like Boost, you'd link it here.
target_link_libraries(raycasted PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    ${OPENGL_LIBRARIES}
)

# (Optional) If you have headers in a separate 'include' directory, tell CMake where to find them.
# This assumes your headers are in a directory named 'include' at the project root.
# target_include_directories(my_executable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
