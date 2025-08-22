# Minimum required CMake version
cmake_minimum_required(VERSION 3.26)

# Project name
project(ScientificArticleManagement 
    VERSION 1.0
    DESCRIPTION "Manage scientific articles"
    LANGUAGES CXX)

# Set requirement for CXX
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Copy data folder (chứa CSV) sang build
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

# Collect all .cpp files automatically
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Create executable
add_executable(RunArticleManagement ${SOURCES})

# Add include directories so #include "models/Article.h" works
target_include_directories(RunArticleManagement PRIVATE lib)

# Enable C++20
target_compile_features(RunArticleManagement PRIVATE cxx_std_20)
