QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/components/dialogs/article/articlestatistics.cpp \
    src/components/mainwindow.cpp \
    src/components/appnav.cpp \
    # src/components/dialogs/article/articledescription.cpp \
    # src/components/dialogs/articleinput.cpp \
    # src/components/dialogs/articleremove.cpp \
    # src/components/dialogs/articleupdate.cpp \
    # src/components/dialogs/author/authordescription.cpp \
    # src/components/dialogs/author/authorinput.cpp \
    # src/components/dialogs/author/authorremove.cpp \
    # src/components/dialogs/author/authorupdate.cpp \
    src/components/dialogs/msg/inform.cpp \
    src/components/widgets/article/articleform.cpp \
    src/components/widgets/author/authorform.cpp \
    src/components/widgets/login/loginform.cpp \
    src/components/widgets/login/signupform.cpp \
    src/models/article.cpp \
    src/models/author.cpp \
    src/models/conference_article.cpp \
    src/models/other_article.cpp \
    src/models/scie_article.cpp \
    src/models/scopus_article.cpp \
    src/repos/articlerepo.cpp \
    src/repos/authorrepo.cpp \
    src/repos/repomanager.cpp \
    src/utils/usermanager.cpp \
    src/utils/uuid_generator.cpp

HEADERS += \
    src/components/dialogs/article/articlestatistics.h \
    src/components/mainwindow.h \
    src/components/appnav.h \
    # src/components/dialogs/article/articledescription.h \
    # src/components/dialogs/articleinput.h \
    # src/components/dialogs/articleremove.h \
    # src/components/dialogs/articleupdate.h \
    # src/components/dialogs/author/authordescription.h \
    # src/components/dialogs/author/authorinput.h \
    # src/components/dialogs/author/authorremove.h \
    # src/components/dialogs/author/authorupdate.h \
    src/components/dialogs/msg/inform.h \
    src/components/widgets/article/articleform.h \
    src/components/widgets/author/authorform.h \
    src/components/widgets/login/loginform.h \
    src/components/widgets/login/signupform.h \
    src/lib/hashmap.h \
    src/models/article.h \
    src/models/author.h \
    src/models/conference_article.h \
    src/models/other_article.h \
    src/models/scie_article.h \
    src/models/scopus_article.h \
    src/repos/articlerepo.h \
    src/repos/authorrepo.h \
    src/repos/repomanager.h \
    src/utils/datautils.h \
    src/utils/constants.h \
    src/utils/exception/ArticleException.h \
    src/utils/nlohmann/json.hpp \
    src/utils/usermanager.h \
    src/utils/uuid_generator.h

FORMS += \
    src/components/dialogs/article/articlestatistics.ui \
    src/components/mainwindow.ui \
    # src/components/dialogs/article/articledescription.ui \
    # src/components/dialogs/articleinput.ui \
    # src/components/dialogs/articleremove.ui \
    # src/components/dialogs/articlestatistics.ui \
    # src/components/dialogs/articleupdate.ui \
    # src/components/dialogs/author/authordescription.ui \
    # src/components/dialogs/author/authorinput.ui \
    # src/components/dialogs/author/authorremove.ui \
    # src/components/dialogs/author/authorupdate.ui \
    src/components/widgets/article/articleform.ui \
    src/components/widgets/author/authorform.ui \
    src/components/widgets/login/loginform.ui \
    src/components/widgets/login/signupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/dataset.json
    data/author_data.json
    data/accounts.json

RESOURCES += \
    resources.qrc
