QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/components/appnav.cpp \
    src/components/dialogs/article/articledetailsdialog.cpp \
    src/components/dialogs/article/articleinputdialog.cpp \
    src/components/dialogs/article/articleupdatedialog.cpp \
    src/components/dialogs/author/authordetailsdialog.cpp \
    src/components/dialogs/author/listofauthorsdialog.cpp \
    src/components/dialogs/msg/inform.cpp \
    src/components/dialogs/user/userdetailsdialog.cpp \
    src/components/mainwindow.cpp \
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
    src/components/appnav.h \
    src/components/dialogs/article/articledetailsdialog.h \
    src/components/dialogs/article/articleinputdialog.h \
    src/components/dialogs/article/articleupdatedialog.h \
    src/components/dialogs/author/authordetailsdialog.h \
    src/components/dialogs/author/listofauthorsdialog.h \
    src/components/dialogs/msg/inform.h \
    src/components/dialogs/user/userdetailsdialog.h \
    src/components/mainwindow.h \
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
    src/utils/constants.h \
    src/utils/datautils.h \
    src/utils/exception/ArticleException.h \
    src/utils/nlohmann/json.hpp \
    src/utils/usermanager.h \
    src/utils/uuid_generator.h

FORMS += \
    src/components/dialogs/article/articledetailsdialog.ui \
    src/components/dialogs/article/articleinputdialog.ui \
    src/components/dialogs/article/articleupdatedialog.ui \
    src/components/dialogs/author/authordetailsdialog.ui \
    src/components/dialogs/author/listofauthorsdialog.ui \
    src/components/dialogs/user/userdetailsdialog.ui \
    src/components/mainwindow.ui \
    src/components/widgets/article/articleform.ui \
    src/components/widgets/author/authorform.ui \
    src/components/widgets/login/loginform.ui \
    src/components/widgets/login/signupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    # data/dataset.json
    # data/author_data.json
    # data/accounts.json

RESOURCES += \
    resources.qrc
