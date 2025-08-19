# Minimum required CMake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(ScientificArticleManagement 
	VERSION 1.0
	DESCRIPTION "Manage scientific article"
	LANGUAGES CXX)

# Add an executable target
add_executable(article
               main.cpp)