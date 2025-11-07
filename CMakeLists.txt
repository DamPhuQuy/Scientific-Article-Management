cmake_minimum_required(VERSION 3.16)
project(ResearchArticleSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------- Include Project Headers ----------------------
include_directories(
        ${PROJECT_SOURCE_DIR}/lib/models
        ${PROJECT_SOURCE_DIR}/lib/models/articles
        ${PROJECT_SOURCE_DIR}/lib/models/users
        ${PROJECT_SOURCE_DIR}/lib/repositories
        ${PROJECT_SOURCE_DIR}/lib/services
        ${PROJECT_SOURCE_DIR}/lib/utilities
)

# ---------------------- Collect Source Files ----------------------
file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Run
        ${SRC_FILES}
)

# target_compile_options(Run PRIVATE -fsanitize=address -g)
# target_link_options(Run PRIVATE -fsanitize=address)
