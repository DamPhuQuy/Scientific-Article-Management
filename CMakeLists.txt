# Minimum required CMake version
cmake_minimum_required(VERSION 3.26)

# Project name
project(ScientificArticleManagement 
	VERSION 1.0
	DESCRIPTION "Manage scientific article"
	LANGUAGES CXX)

# Set requirement for CXX
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List all sources
set(SOURCES
    main.cpp 
    models/Article.cpp
    models/Article.h 
    models/Author.cpp
    models/Author.h
    models/Journal.cpp
    models/Journal.h)
)

# Create executable
add_executable(RunArticleManagement ${SOURCES})

# Enable C++20
target_compile_features(RunArticleManage PRIVATE cxx_std_20)