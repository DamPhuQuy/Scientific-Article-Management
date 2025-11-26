/********************************************************************************
** Form generated from reading UI file 'authorform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORFORM_H
#define UI_AUTHORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorForm
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QHBoxLayout *bodyLayout;
    QWidget *sidebarContainer;
    QVBoxLayout *verticalLayout_Sidebar;
    QPushButton *UpdateButton_3;
    QPushButton *Statistics_3;
    QPushButton *RemoveButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *Back_3;
    QWidget *contentContainer;
    QVBoxLayout *verticalLayout_Content;
    QHBoxLayout *searchLayout;
    QLineEdit *EnterButton_3;
    QPushButton *EnterBox_3;
    QTableView *tableView_3;

    void setupUi(QWidget *AuthorForm)
    {
        if (AuthorForm->objectName().isEmpty())
            AuthorForm->setObjectName("AuthorForm");
        AuthorForm->resize(800, 600);
        AuthorForm->setStyleSheet(QString::fromUtf8("\n"
"    /* --- MAIN FORM --- */\n"
"    QWidget#AuthorForm {\n"
"        background-color: #f4f7f6;\n"
"        border: 4px solid #FFC085; /* Vi\341\273\201n cam \304\221\341\273\223ng b\341\273\231 */\n"
"    }\n"
"\n"
"    QWidget { font-family: \"Segoe UI\", Arial, sans-serif; font-size: 14px; }\n"
"\n"
"    /* --- SIDEBAR CONTAINER --- */\n"
"    QWidget#sidebarContainer {\n"
"        background-color: #ffffff;\n"
"        border-right: 1px solid #e0e0e0;\n"
"    }\n"
"\n"
"    /* --- CONTENT CONTAINER --- */\n"
"    QWidget#contentContainer {\n"
"        background-color: #f4f7f6;\n"
"    }\n"
"\n"
"    /* --- INPUT FIELDS (SEARCH) --- */\n"
"    QLineEdit { \n"
"      background-color: #ffffff; \n"
"      border: 1px solid #cccccc; \n"
"      border-radius: 6px; \n"
"      padding: 8px; \n"
"      color: #333; \n"
"    }\n"
"    QLineEdit:focus { \n"
"      border: 2px solid #20B2AA; \n"
"    }\n"
"\n"
"    /* --- TABLE VIEW --- */\n"
"    QTableView {\n"
"        background-color: #ffffff;\n"
"        "
                        "border: 1px solid #cccccc;\n"
"        border-radius: 4px;\n"
"        gridline-color: #e0e0e0;\n"
"        selection-background-color: #20B2AA;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #00264d;\n"
"        color: white;\n"
"        padding: 5px;\n"
"        border: none;\n"
"        font-weight: bold;\n"
"    }\n"
"   "));
        mainLayout = new QVBoxLayout(AuthorForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(AuthorForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("\n"
"       QWidget#headerContainer {\n"
"           background-color: #00264d;\n"
"           border-bottom: 5px solid #4169E1;\n"
"           border-left: 10px solid #FFD700; /* V\341\272\240CH V\303\200NG LOGO */\n"
"       }\n"
"      "));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setStyleSheet(QString::fromUtf8("\n"
"          color: #ffffff;\n"
"          font-weight: 900;\n"
"          font-size: 20px;\n"
"          background: transparent;\n"
"          padding-left: 10px;\n"
"         "));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(lblHeader);


        mainLayout->addWidget(headerContainer);

        bodyLayout = new QHBoxLayout();
        bodyLayout->setSpacing(0);
        bodyLayout->setObjectName("bodyLayout");
        sidebarContainer = new QWidget(AuthorForm);
        sidebarContainer->setObjectName("sidebarContainer");
        sidebarContainer->setMinimumSize(QSize(200, 0));
        sidebarContainer->setMaximumSize(QSize(220, 16777215));
        verticalLayout_Sidebar = new QVBoxLayout(sidebarContainer);
        verticalLayout_Sidebar->setSpacing(15);
        verticalLayout_Sidebar->setObjectName("verticalLayout_Sidebar");
        verticalLayout_Sidebar->setContentsMargins(15, 30, 15, 20);
        UpdateButton_3 = new QPushButton(sidebarContainer);
        UpdateButton_3->setObjectName("UpdateButton_3");
        UpdateButton_3->setMinimumSize(QSize(0, 45));
        UpdateButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        UpdateButton_3->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"             background-color: #20B2AA; \n"
"             border: 2px solid #20B2AA; \n"
"             border-radius: 6px; \n"
"             color: white; font-weight: bold;\n"
"            }\n"
"            QPushButton:hover { background-color: #17a098; }\n"
"            QPushButton:pressed { background-color: #0e6b65; }\n"
"           "));

        verticalLayout_Sidebar->addWidget(UpdateButton_3);

        Statistics_3 = new QPushButton(sidebarContainer);
        Statistics_3->setObjectName("Statistics_3");
        Statistics_3->setMinimumSize(QSize(0, 45));
        Statistics_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Statistics_3->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"             background-color: #20B2AA; \n"
"             border: 2px solid #20B2AA; \n"
"             border-radius: 6px; \n"
"             color: white; font-weight: bold;\n"
"            }\n"
"            QPushButton:hover { background-color: #17a098; }\n"
"            QPushButton:pressed { background-color: #0e6b65; }\n"
"           "));

        verticalLayout_Sidebar->addWidget(Statistics_3);

        RemoveButton_3 = new QPushButton(sidebarContainer);
        RemoveButton_3->setObjectName("RemoveButton_3");
        RemoveButton_3->setMinimumSize(QSize(0, 45));
        RemoveButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        RemoveButton_3->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"             background-color: #e74c3c; \n"
"             border: 2px solid #e74c3c; \n"
"             border-radius: 6px; \n"
"             color: white; font-weight: bold;\n"
"            }\n"
"            QPushButton:hover { background-color: #c0392b; }\n"
"            QPushButton:pressed { background-color: #922b21; }\n"
"           "));

        verticalLayout_Sidebar->addWidget(RemoveButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Sidebar->addItem(verticalSpacer);

        Back_3 = new QPushButton(sidebarContainer);
        Back_3->setObjectName("Back_3");
        Back_3->setMinimumSize(QSize(0, 45));
        Back_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Back_3->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"             background-color: #7f8c8d; \n"
"             border: 2px solid #7f8c8d; \n"
"             border-radius: 6px; \n"
"             color: white; font-weight: bold;\n"
"            }\n"
"            QPushButton:hover { background-color: #636e72; }\n"
"            QPushButton:pressed { background-color: #2d3436; }\n"
"           "));

        verticalLayout_Sidebar->addWidget(Back_3);


        bodyLayout->addWidget(sidebarContainer);

        contentContainer = new QWidget(AuthorForm);
        contentContainer->setObjectName("contentContainer");
        verticalLayout_Content = new QVBoxLayout(contentContainer);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        EnterButton_3 = new QLineEdit(contentContainer);
        EnterButton_3->setObjectName("EnterButton_3");
        EnterButton_3->setMinimumSize(QSize(0, 40));

        searchLayout->addWidget(EnterButton_3);

        EnterBox_3 = new QPushButton(contentContainer);
        EnterBox_3->setObjectName("EnterBox_3");
        EnterBox_3->setMinimumSize(QSize(100, 40));
        EnterBox_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        EnterBox_3->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"               background-color: #20B2AA; \n"
"               border: 2px solid #20B2AA; \n"
"               border-radius: 6px; \n"
"               color: white; font-weight: bold;\n"
"              }\n"
"              QPushButton:hover { background-color: #17a098; }\n"
"             "));

        searchLayout->addWidget(EnterBox_3);


        verticalLayout_Content->addLayout(searchLayout);

        tableView_3 = new QTableView(contentContainer);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setShowGrid(true);
        tableView_3->setSortingEnabled(true);
        tableView_3->horizontalHeader()->setStretchLastSection(true);
        tableView_3->verticalHeader()->setVisible(false);

        verticalLayout_Content->addWidget(tableView_3);


        bodyLayout->addWidget(contentContainer);


        mainLayout->addLayout(bodyLayout);


        retranslateUi(AuthorForm);

        QMetaObject::connectSlotsByName(AuthorForm);
    } // setupUi

    void retranslateUi(QWidget *AuthorForm)
    {
        AuthorForm->setWindowTitle(QCoreApplication::translate("AuthorForm", "Author Management", nullptr));
        lblHeader->setText(QCoreApplication::translate("AuthorForm", "QU\341\272\242N L\303\235 T\303\201C GI\341\272\242", nullptr));
        UpdateButton_3->setText(QCoreApplication::translate("AuthorForm", "Update Author", nullptr));
        Statistics_3->setText(QCoreApplication::translate("AuthorForm", "Statistics", nullptr));
        RemoveButton_3->setText(QCoreApplication::translate("AuthorForm", "Remove Author", nullptr));
        Back_3->setText(QCoreApplication::translate("AuthorForm", "Back", nullptr));
        EnterButton_3->setPlaceholderText(QCoreApplication::translate("AuthorForm", "Search author by name or ID...", nullptr));
        EnterBox_3->setText(QCoreApplication::translate("AuthorForm", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorForm: public Ui_AuthorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORFORM_H
