cmake_minimum_required(VERSION 3.16)
project(ResearchArticleSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------- Vcpkg Integration ----------------------
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows/share/ftxui")

# ---------------------- Find FTXUI ----------------------
find_package(ftxui CONFIG REQUIRED)

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

target_link_libraries(Run PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
