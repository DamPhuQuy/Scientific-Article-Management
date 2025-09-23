cmake_minimum_required(VERSION 3.26)

project(ScientificArticleManagement
        VERSION 1.0
        DESCRIPTION "Manage scientific articles"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Copy data folder to build folder
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(Run
        src/main.cpp
        src/models/Article.cpp
        src/models/Author.cpp
        src/models/Journal.cpp
        src/repositories/ArticleRepository.cpp
        src/repositories/JournalRepository.cpp
        src/repositories/AuthorRepository.cpp
        src/repositories/EventListener.cpp
        src/services/DataManipulation.cpp
        src/utilities/IOHelper.cpp
        src/repositories/RepositoryManager.cpp
        lib/repositories/RepositoryManager.h
)

# Include directories (headers)
target_include_directories(Run PRIVATE src lib)
