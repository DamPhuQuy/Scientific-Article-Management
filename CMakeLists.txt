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
    src/models/Article.cpp
    lib/models/Article.h 
    src/models/Author.cpp
    lib/models/Author.h
    src/models/Journal.cpp
    lib/models/Journal.h
    src/repositories/ArticleRepository.cpp
    lib/repositories/ArticleRepository.h
    src/repositories/AuthorRepository.cpp
    lib/repositories/AuthorRepository.h
    src/repositories/JournalRepository.cpp
    lib/repositories/JournalRepository.h
    src/services/DataManipulation.cpp
    lib/services/DataManipulation.h
    lib/utilities/Constants.h)
)

# Create executable
add_executable(RunArticleManagement ${SOURCES})

# Enable C++20
target_compile_features(RunArticleManage PRIVATE cxx_std_20)