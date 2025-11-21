/********************************************************************************
** Form generated from reading UI file 'articleform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEFORM_H
#define UI_ARTICLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleForm
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
    QLabel *label;
    QComboBox *yearFilterComboBox;
    QComboBox *typeFilterComboBox;
    QFrame *lineSeparator;
    QHBoxLayout *horizontalLayout_Actions;
    QPushButton *newArticleBtn;
    QPushButton *RemoveArticleBtn;
    QSpacerItem *horizontalSpacer_Action;
    QListView *articleListView;
    QHBoxLayout *horizontalLayout_Footer;
    QHBoxLayout *paginationLayout;
    QSpacerItem *horizontalSpacer_Footer;
    QPushButton *backBtn;

    void setupUi(QWidget *ArticleForm)
    {
        if (ArticleForm->objectName().isEmpty())
            ArticleForm->setObjectName("ArticleForm");
        ArticleForm->resize(1000, 750);
        ArticleForm->setStyleSheet(QString::fromUtf8("/* \303\201p d\341\273\245ng ri\303\252ng cho menu ch\303\255nh */\n"
"QWidget#ArticleForm {\n"
"    background-color: #f4f7f6;\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"}\n"
"\n"
"/* Header Container */\n"
"QWidget#headerContainer {\n"
"    background-color: #00264d;\n"
"    border-left: 10px solid #FFD700;\n"
"    border-bottom: 5px solid #4169E1;\n"
"}\n"
"\n"
"/* Body container */\n"
"QWidget#bodyContainer {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Ch\341\273\211 style cho line edit trong ArticleForm */\n"
"QWidget#ArticleForm QLineEdit,\n"
"QWidget#ArticleForm QComboBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    /* \304\220\303\203 S\341\273\254A: \304\220\341\273\225i t\341\273\253 #fffcfcff sang #555 \304\221\341\273\203 hi\341\273\207n r\303\265 ch\341\273\257 v\303\240 \304\221\303\272ng c\303\272"
                        " ph\303\241p */\n"
"    color: #555;\n"
"    min-height: 25px;\n"
"}\n"
"\n"
"QWidget#ArticleForm QLineEdit:focus,\n"
"QWidget#ArticleForm QComboBox:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"    color: #000;\n"
"}\n"
"\n"
"/* Dropdown */\n"
"QWidget#ArticleForm QComboBox::drop-down {\n"
"    border: 0px;\n"
"}\n"
"\n"
"/* Label CHUNG (S\341\272\275 b\341\273\213 ghi \304\221\303\250 b\341\273\237i style ri\303\252ng c\341\273\247a Title) */\n"
"QWidget#ArticleForm QLabel {\n"
"    font-weight: bold;\n"
"    color: #555;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Buttons */\n"
"QWidget#ArticleForm QPushButton {\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    padding: 8px 16px;\n"
"    min-height: 25px;\n"
"    font-size: 14px;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Search + Add article buttons */\n"
"QWidget#ArticleForm QPushButton#searchBtn,\n"
"QWidget#ArticleForm QPushButton#newArticleBtn {\n"
"    background-color: #20B2AA;\n"
"    border: 2px solid #2"
                        "0B2AA;\n"
"}\n"
"QWidget#ArticleForm QPushButton#searchBtn:hover,\n"
"QWidget#ArticleForm QPushButton#newArticleBtn:hover {\n"
"    background-color: #17a098;\n"
"    border-color: #17a098;\n"
"}\n"
"\n"
"/* Delete + Back buttons */\n"
"QWidget#ArticleForm QPushButton#RemoveArticleBtn,\n"
"QWidget#ArticleForm QPushButton#backBtn {\n"
"    background-color: #da3e36;\n"
"    border: 2px solid #da3e36;\n"
"}\n"
"QWidget#ArticleForm QPushButton#RemoveArticleBtn:hover,\n"
"QWidget#ArticleForm QPushButton#backBtn:hover {\n"
"    background-color: #c0392b;\n"
"    border-color: #c0392b;\n"
"}\n"
"\n"
"/* List view */\n"
"QWidget#ArticleForm QListView {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    background-color: #fff;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QWidget#ArticleForm QListView::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #eee;\n"
"}\n"
"\n"
"QWidget#ArticleForm QListView::item:selected {\n"
"    background-color: #e0f2f1;\n"
"    color: #0"
                        "00;\n"
"    border-left: 4px solid #20B2AA;\n"
"}\n"
"\n"
"/* Separator */\n"
"QWidget#ArticleForm QFrame#lineSeparator {\n"
"    min-height: 3px;\n"
"    max-height: 3px;\n"
"    background-color: #20B2AA;\n"
"    border: none;\n"
"}\n"
""));
        mainLayout = new QVBoxLayout(ArticleForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 80));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, -1, -1, -1);
        lblPageTitle = new QLabel(headerContainer);
        lblPageTitle->setObjectName("lblPageTitle");

        horizontalLayout_Header->addWidget(lblPageTitle);


        mainLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(ArticleForm);
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

        label = new QLabel(bodyContainer);
        label->setObjectName("label");

        horizontalLayout_Tools->addWidget(label);

        yearFilterComboBox = new QComboBox(bodyContainer);
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->setObjectName("yearFilterComboBox");
        yearFilterComboBox->setMinimumSize(QSize(150, 40));
        yearFilterComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Tools->addWidget(yearFilterComboBox);

        typeFilterComboBox = new QComboBox(bodyContainer);
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->setObjectName("typeFilterComboBox");
        typeFilterComboBox->setMinimumSize(QSize(150, 40));
        typeFilterComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Tools->addWidget(typeFilterComboBox);


        verticalLayout_Body->addLayout(horizontalLayout_Tools);

        lineSeparator = new QFrame(bodyContainer);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::HLine);
        lineSeparator->setFrameShadow(QFrame::Plain);

        verticalLayout_Body->addWidget(lineSeparator);

        horizontalLayout_Actions = new QHBoxLayout();
        horizontalLayout_Actions->setObjectName("horizontalLayout_Actions");
        newArticleBtn = new QPushButton(bodyContainer);
        newArticleBtn->setObjectName("newArticleBtn");
        newArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        newArticleBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(newArticleBtn);

        RemoveArticleBtn = new QPushButton(bodyContainer);
        RemoveArticleBtn->setObjectName("RemoveArticleBtn");
        RemoveArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        RemoveArticleBtn->setMinimumSize(QSize(0, 40));

        horizontalLayout_Actions->addWidget(RemoveArticleBtn);

        horizontalSpacer_Action = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_Action);


        verticalLayout_Body->addLayout(horizontalLayout_Actions);

        articleListView = new QListView(bodyContainer);
        articleListView->setObjectName("articleListView");
        articleListView->setAlternatingRowColors(true);

        verticalLayout_Body->addWidget(articleListView);

        horizontalLayout_Footer = new QHBoxLayout();
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        paginationLayout = new QHBoxLayout();
        paginationLayout->setObjectName("paginationLayout");

        horizontalLayout_Footer->addLayout(paginationLayout);

        horizontalSpacer_Footer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer_Footer);

        backBtn = new QPushButton(bodyContainer);
        backBtn->setObjectName("backBtn");
        backBtn->setMinimumSize(QSize(100, 40));

        horizontalLayout_Footer->addWidget(backBtn);


        verticalLayout_Body->addLayout(horizontalLayout_Footer);


        mainLayout->addWidget(bodyContainer);


        retranslateUi(ArticleForm);

        QMetaObject::connectSlotsByName(ArticleForm);
    } // setupUi

    void retranslateUi(QWidget *ArticleForm)
    {
        ArticleForm->setWindowTitle(QCoreApplication::translate("ArticleForm", "Article Management", nullptr));
        lblPageTitle->setStyleSheet(QCoreApplication::translate("ArticleForm", "color: #ffffff; font-size: 26px; font-weight: 900; background-color: transparent;", nullptr));
        lblPageTitle->setText(QCoreApplication::translate("ArticleForm", "QU\341\272\242N L\303\235 B\303\200I B\303\201O KHOA H\341\273\214C", nullptr));
        searchLabel->setText(QCoreApplication::translate("ArticleForm", "T\303\254m ki\341\272\277m:", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("ArticleForm", "Nh\341\272\255p ti\303\252u \304\221\341\273\201 b\303\240i b\303\241o...", nullptr));
        searchBtn->setText(QCoreApplication::translate("ArticleForm", "T\303\254m", nullptr));
        label->setText(QCoreApplication::translate("ArticleForm", "L\341\273\215c theo:", nullptr));
        yearFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "-- T\341\272\245t c\341\272\243 n\304\203m --", nullptr));
        yearFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "M\341\273\233i nh\341\272\245t", nullptr));
        yearFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "C\305\251 nh\341\272\245t", nullptr));

        typeFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "-- Lo\341\272\241i b\303\240i b\303\241o --", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "SCOPUS", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "CONFERENCE", nullptr));

        newArticleBtn->setText(QCoreApplication::translate("ArticleForm", "+ Th\303\252m m\341\273\233i", nullptr));
        RemoveArticleBtn->setText(QCoreApplication::translate("ArticleForm", "X\303\263a b\303\240i b\303\241o", nullptr));
        backBtn->setText(QCoreApplication::translate("ArticleForm", "Quay l\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleForm: public Ui_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEFORM_H
