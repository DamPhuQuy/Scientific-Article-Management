cmake_minimum_required(VERSION 3.16)

# Tên dự án
project(ArticleManage VERSION 1.0 LANGUAGES CXX)

# Cấu hình chuẩn C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- CẤU HÌNH QT ---
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Tìm thư viện Qt
# LƯU Ý: Bạn cần đảm bảo CMake tìm thấy phiên bản Qt dành cho MSVC (Visual Studio), không phải MinGW.
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets Charts REQUIRED)

# --- KHAI BÁO SOURCE CODE ---
include_directories(${CMAKE_SOURCE_DIR})
include_directories(src)

# Thu thập file
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS "src/*.h" "src/*.hpp")
file(GLOB_RECURSE PROJECT_UIS     CONFIGURE_DEPENDS "src/*.ui")

set(MAIN_FILE "main.cpp")
set(RESOURCES_FILE "resources.qrc")

# --- TẠO FILE THỰC THI ---
add_executable(${PROJECT_NAME} WIN32
    ${MAIN_FILE}
    ${RESOURCES_FILE}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    ${PROJECT_UIS}
)

# --- LIÊN KẾT THƯ VIỆN ---
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Charts)

# --- [SỬA LỖI 1] CẤU HÌNH RIÊNG CHO MSVC (VISUAL STUDIO) ---
if (MSVC)
    # Bắt buộc phải có cờ này để Qt nhận diện đúng C++17 trên Visual Studio
    target_compile_options(${PROJECT_NAME} PRIVATE /Zc:__cplusplus)
endif()