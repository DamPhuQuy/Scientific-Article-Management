cmake_minimum_required(VERSION 3.19)
project(DigitalLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------- Qt ----------------------
set(CMAKE_PREFIX_PATH "C:/Qt/6.10.0/mingw_64/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
qt_standard_project_setup()

# ============================================================
#                          MODELS
# ============================================================
add_library(models
    src/models/articles/Article.cpp
    src/models/articles/Author.cpp
    src/models/articles/CONFERENCE_Article.cpp
    src/models/articles/OTHER_Article.cpp
    src/models/articles/SCIE_Article.cpp
    src/models/articles/SCOPUS_Article.cpp

    src/models/users/Admin.cpp
    src/models/users/Reviewer.cpp
    src/models/users/User.cpp
)

target_include_directories(models PUBLIC src/models)

# ============================================================
#                        REPOSITORIES
# ============================================================
add_library(repositories
    src/repositories/ArticleRepo.cpp
    src/repositories/AuthorRepo.cpp
    src/repositories/AuthorArticleRepo.cpp
    src/repositories/RepositoryManager.cpp
)

target_include_directories(repositories PUBLIC src/repositories)
target_link_libraries(repositories PUBLIC models)

# ============================================================
#                          SERVICES
# ============================================================
add_library(services
    src/services/ArticleService.cpp
    src/services/AuthorService.cpp
    src/services/UserService.cpp
    src/services/DataManipulation.cpp
)

target_include_directories(services PUBLIC src/services)
target_link_libraries(services PUBLIC repositories models)

# ============================================================
#                          UTILITIES
# ============================================================
add_library(utilities
    src/utilities/MenuUtilities.cpp
    src/utilities/Statistics.cpp
    src/utilities/UUID_Generator.cpp
)

target_include_directories(utilities PUBLIC src/utilities)
target_link_libraries(utilities PUBLIC models)

# ============================================================
#                       GUI WIDGETS (Qt)
# ============================================================
add_library(widgets
    src/gui/widgets/MainMenuWidget.cpp
    src/gui/widgets/MainMenuWidget.h
    src/gui/widgets/MainMenuWidget.ui

    src/gui/widgets/ArticleManagementWidget.cpp
    src/gui/widgets/ArticleManagementWidget.h
    src/gui/widgets/ArticleManagementWidget.ui

    src/gui/widgets/AuthorManagementWidget.cpp
    src/gui/widgets/AuthorManagementWidget.h
    src/gui/widgets/AuthorManagementWidget.ui

    src/gui/widgets/ArticleStatisticsWidget.cpp
    src/gui/widgets/ArticleStatisticsWidget.h
    src/gui/widgets/ArticleStatisticsWidget.ui

    src/gui/widgets/ViewAllArticlesWidget.cpp
    src/gui/widgets/ViewAllArticlesWidget.h
    src/gui/widgets/ViewAllArticlesWidget.ui

    src/gui/widgets/ViewAllAuthorsWidget.cpp
    src/gui/widgets/ViewAllAuthorsWidget.h
    src/gui/widgets/ViewAllAuthorsWidget.ui
)

target_link_libraries(widgets
    PUBLIC Qt::Core Qt::Widgets Qt::Gui
    PUBLIC models services repositories utilities
)

target_include_directories(widgets PUBLIC src/gui/widgets)

# ============================================================
#                     MAIN APPLICATION
# ============================================================
qt_add_executable(DigitalLibrary
    WIN32 MACOSX_BUNDLE

    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
)

target_link_libraries(DigitalLibrary
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Gui
        widgets
        models
        repositories
        services
        utilities
)

# ---------------------- Install ----------------------
include(GNUInstallDirs)

install(TARGETS DigitalLibrary
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET DigitalLibrary
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
