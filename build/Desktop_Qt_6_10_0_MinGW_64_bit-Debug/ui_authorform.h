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
#include <QtWidgets/QFrame>
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
    QLabel *lblPageTitle;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QHBoxLayout *horizontalLayout_Tools;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *searchBtn;
    QSpacerItem *horizontalSpacer_Tool;
    QFrame *lineSeparator;
    QHBoxLayout *horizontalLayout_Actions;
    QPushButton *newAuthorBtn;
    QPushButton *updateAuthorBtn;
    QPushButton *statsBtn;
    QPushButton *removeAuthorBtn;
    QSpacerItem *horizontalSpacer_Action;
    QTableView *authorTableView;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer_Footer;
    QPushButton *backBtn;

    void setupUi(QWidget *AuthorForm)
    {
        if (AuthorForm->objectName().isEmpty())
            AuthorForm->setObjectName("AuthorForm");
        AuthorForm->resize(1000, 750);
        AuthorForm->setStyleSheet(QString::fromUtf8("QWidget#AuthorForm { background-color: #f4f7f6; }\n"
"QWidget { font-family: \"Segoe UI\", Arial, sans-serif; }\n"
"\n"
"/* HEADER */\n"
"QWidget#headerContainer { background-color: #00264d; border-left: 10px solid #FFD700; border-bottom: 5px solid #4169E1; }\n"
"QLabel#lblPageTitle { color: #ffffff; font-size: 24px; font-weight: 900; background-color: transparent; padding-left: 10px; }\n"
"\n"
"/* BODY */\n"
"QWidget#bodyContainer { background-color: #ffffff; border: 2px solid #20B2AA; border-radius: 8px; }\n"
"\n"
"/* INPUTS */\n"
"QLineEdit { background-color: #f9f9f9; border: 1px solid #cccccc; border-radius: 6px; padding: 8px 12px; font-size: 14px; color: #333; min-height: 25px; }\n"
"QLineEdit:focus { background-color: #ffffff; border: 2px solid #20B2AA; color: #000; }\n"
"\n"
"QLabel { font-weight: bold; color: #555; font-size: 14px; }\n"
"\n"
"/* BUTTONS CHUNG */\n"
"QPushButton { border-radius: 6px; font-weight: bold; padding: 8px 16px; min-height: 25px; font-size: 14px; color: white; }\n"
"\n"
"/* =="
                        "= NH\303\223M M\303\200U XANH NG\341\273\214C (T\303\215CH C\341\273\260C) === */\n"
"QPushButton#searchBtn, QPushButton#newAuthorBtn, QPushButton#updateAuthorBtn, QPushButton#statsBtn { background-color: #20B2AA; border: 2px solid #20B2AA; }\n"
"QPushButton#searchBtn:hover, QPushButton#newAuthorBtn:hover, QPushButton#updateAuthorBtn:hover, QPushButton#statsBtn:hover { background-color: #17a098; border-color: #17a098; }\n"
"\n"
"/* === NH\303\223M M\303\200U \304\220\341\273\216 (TI\303\212U C\341\273\260C/THO\303\201T) === */\n"
"QPushButton#removeAuthorBtn, QPushButton#backBtn { background-color: #da3e36; border: 2px solid #da3e36; }\n"
"QPushButton#removeAuthorBtn:hover, QPushButton#backBtn:hover { background-color: #c0392b; border-color: #c0392b; }\n"
"\n"
"/* TABLE VIEW */\n"
"QTableView { border: 1px solid #e0e0e0; border-radius: 6px; padding: 5px; background-color: #fff; font-size: 14px; gridline-color: #eee; }\n"
"QTableView::item { padding: 5px; }\n"
"QTableView::item:selected { background-color: #e0f"
                        "2f1; color: #000; }\n"
"QHeaderView::section { background-color: #f0f0f0; padding: 5px; border: none; border-bottom: 1px solid #ccc; font-weight: bold; }\n"
"\n"
"/* LINE SEPARATOR */\n"
"QFrame#lineSeparator { min-height: 3px; max-height: 3px; background-color: #20B2AA; border: none; }"));
        mainLayout = new QVBoxLayout(AuthorForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(AuthorForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 80));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, -1, -1, -1);
        lblPageTitle = new QLabel(headerContainer);
        lblPageTitle->setObjectName("lblPageTitle");

        horizontalLayout_Header->addWidget(lblPageTitle);


        mainLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(AuthorForm);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(20);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_Tools = new QHBoxLayout();
        horizontalLayout_Tools->setSpacing(15);
        horizontalLayout_Tools->setObjectName("horizontalLayout_Tools");
        searchLabel = new QLabel(bodyContainer);
        searchLabel->setObjectName("searchLabel");

        horizontalLayout_Tools->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(bodyContainer);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(250, 40));

        horizontalLayout_Tools->addWidget(searchLineEdit);

        searchBtn = new QPushButton(bodyContainer);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchBtn->setMinimumSize(QSize(80, 40));

        horizontalLayout_Tools->addWidget(searchBtn);

        horizontalSpacer_Tool = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Tools->addItem(horizontalSpacer_Tool);


        verticalLayout_Body->addLayout(horizontalLayout_Tools);

        lineSeparator = new QFrame(bodyContainer);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::HLine);
        lineSeparator->setFrameShadow(QFrame::Plain);

        verticalLayout_Body->addWidget(lineSeparator);

        horizontalLayout_Actions = new QHBoxLayout();
        horizontalLayout_Actions->setSpacing(10);
        horizontalLayout_Actions->setObjectName("horizontalLayout_Actions");
        newAuthorBtn = new QPushButton(bodyContainer);
        newAuthorBtn->setObjectName("newAuthorBtn");
        newAuthorBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        newAuthorBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(newAuthorBtn);

        updateAuthorBtn = new QPushButton(bodyContainer);
        updateAuthorBtn->setObjectName("updateAuthorBtn");
        updateAuthorBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updateAuthorBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(updateAuthorBtn);

        statsBtn = new QPushButton(bodyContainer);
        statsBtn->setObjectName("statsBtn");
        statsBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statsBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(statsBtn);

        removeAuthorBtn = new QPushButton(bodyContainer);
        removeAuthorBtn->setObjectName("removeAuthorBtn");
        removeAuthorBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        removeAuthorBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(removeAuthorBtn);

        horizontalSpacer_Action = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_Action);


        verticalLayout_Body->addLayout(horizontalLayout_Actions);

        authorTableView = new QTableView(bodyContainer);
        authorTableView->setObjectName("authorTableView");
        authorTableView->setAlternatingRowColors(true);
        authorTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Body->addWidget(authorTableView);

        horizontalLayout_Footer = new QHBoxLayout();
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalSpacer_Footer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer_Footer);

        backBtn = new QPushButton(bodyContainer);
        backBtn->setObjectName("backBtn");
        backBtn->setMinimumSize(QSize(100, 40));

        horizontalLayout_Footer->addWidget(backBtn);


        verticalLayout_Body->addLayout(horizontalLayout_Footer);


        mainLayout->addWidget(bodyContainer);


        retranslateUi(AuthorForm);

        QMetaObject::connectSlotsByName(AuthorForm);
    } // setupUi

    void retranslateUi(QWidget *AuthorForm)
    {
        AuthorForm->setWindowTitle(QCoreApplication::translate("AuthorForm", "Author Management", nullptr));
        lblPageTitle->setText(QCoreApplication::translate("AuthorForm", "QU\341\272\242N L\303\235 T\303\201C GI\341\272\242", nullptr));
        searchLabel->setText(QCoreApplication::translate("AuthorForm", "T\303\254m ki\341\272\277m:", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("AuthorForm", "Nh\341\272\255p t\303\252n t\303\241c gi\341\272\243...", nullptr));
        searchBtn->setText(QCoreApplication::translate("AuthorForm", "T\303\254m", nullptr));
        newAuthorBtn->setText(QCoreApplication::translate("AuthorForm", "+ Th\303\252m m\341\273\233i", nullptr));
        updateAuthorBtn->setText(QCoreApplication::translate("AuthorForm", "C\341\272\255p nh\341\272\255t", nullptr));
        statsBtn->setText(QCoreApplication::translate("AuthorForm", "Th\341\273\221ng k\303\252", nullptr));
        removeAuthorBtn->setText(QCoreApplication::translate("AuthorForm", "X\303\263a", nullptr));
        backBtn->setText(QCoreApplication::translate("AuthorForm", "Quay l\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorForm: public Ui_AuthorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORFORM_H
