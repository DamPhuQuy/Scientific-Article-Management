# 1. Minimum required CMake version
cmake_minimum_required(VERSION 3.26)

# 2. Project name and version
project(ScientificArticleManagement 
    VERSION 1.0
    DESCRIPTION "Manage scientific articles"
    LANGUAGES CXX)

# 3. Set requirement for CXX
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Copy data folder to build folder
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

# 4. Collect all .cpp files with GLOB_RECURSE
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# 5. Create executable
add_executable(RunArticleManagement ${SOURCES})

# 6. Add include directories
target_include_directories(RunArticleManagement PRIVATE lib)
