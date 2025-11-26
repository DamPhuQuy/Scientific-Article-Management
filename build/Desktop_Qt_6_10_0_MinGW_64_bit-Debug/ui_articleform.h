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
    QLabel *lblHeader;
    QHBoxLayout *bodyLayout;
    QWidget *sidebarContainer;
    QVBoxLayout *verticalLayout_Sidebar;
    QLabel *lblAccount;
    QPushButton *userLb;
    QFrame *line_1;
    QLabel *lblSearch;
    QLineEdit *searchLineEdit;
    QLabel *lblFilters;
    QComboBox *yearFilterComboBox;
    QComboBox *typeFilterComboBox;
    QFrame *line_2;
    QLabel *lblActions;
    QPushButton *newArticleBtn;
    QPushButton *RemoveArticleBtn;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *backBtn;
    QWidget *contentContainer;
    QVBoxLayout *verticalLayout_Content;
    QListView *articleListView;
    QHBoxLayout *paginationLayout;

    void setupUi(QWidget *ArticleForm)
    {
        if (ArticleForm->objectName().isEmpty())
            ArticleForm->setObjectName("ArticleForm");
        ArticleForm->resize(1100, 750);
        ArticleForm->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QWidget#ArticleForm {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #FFC085;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- SIDEBAR --- */\n"
"QWidget#sidebarContainer {\n"
"    background-color: #ffffff;\n"
"    border-right: 1px solid #e0e0e0;\n"
"}\n"
"/* Nh\303\243n ti\303\252u \304\221\341\273\201 trong sidebar */\n"
"QLabel.sectionLabel {\n"
"    color: #20B2AA;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"    margin-top: 10px;\n"
"    margin-bottom: 5px;\n"
"}\n"
"\n"
"/* --- INPUTS & COMBOBOX --- */\n"
"QLineEdit, QComboBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    padding-right: 30px; \n"
"    color: #333333;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* Style cho ComboB"
                        "ox Dropdown */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 1px solid #cccccc;\n"
"    background-color: #e0e0e0;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"    selection-background-color: #e0f2f1;\n"
"    selection-color: #004d40;\n"
"    outline: 0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* --- BUTTONS --- */\n"
"QPushButton {\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"}\n"
"/* N\303\272t User */\n"
"QPushButton#userLb {\n"
"    background-color: #e0f2f1;\n"
"    color: #00695c;\n"
"    border: 1px solid #b2dfdb;\n"
"    text-align: left;\n"
"    padding-left: 15px;\n"
"}\n"
"/* N\303\272t H\303\240nh \304\221\341\273\231ng ch\303\255nh (Xanh Ng\341\273\215c) */\n"
"QPushButton#newArticleBtn, QPushButton#pushButton {\n"
"    b"
                        "ackground-color: #20B2AA;\n"
"    border: 2px solid #20B2AA;\n"
"    color: white;\n"
"}\n"
"QPushButton#newArticleBtn:hover, QPushButton#pushButton:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"\n"
"/* N\303\272t Back (X\303\241m) */\n"
"QPushButton#backBtn {\n"
"    background-color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"    color: white;\n"
"}\n"
"QPushButton#backBtn:hover {\n"
"    background-color: #636e72;\n"
"}\n"
"\n"
"/* --- LIST VIEW --- */\n"
"QListView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    outline: 0;\n"
"}\n"
"QListView::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #eeeeee;\n"
"}\n"
"QListView::item:selected {\n"
"    background-color: #e0f2f1;\n"
"    color: #004d40;\n"
"    border-radius: 4px;\n"
"}\n"
"   "));
        mainLayout = new QVBoxLayout(ArticleForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(ArticleForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;margin-top:0px;"));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(lblHeader);


        mainLayout->addWidget(headerContainer);

        bodyLayout = new QHBoxLayout();
        bodyLayout->setSpacing(0);
        bodyLayout->setObjectName("bodyLayout");
        sidebarContainer = new QWidget(ArticleForm);
        sidebarContainer->setObjectName("sidebarContainer");
        sidebarContainer->setMinimumSize(QSize(280, 0));
        sidebarContainer->setMaximumSize(QSize(300, 16777215));
        verticalLayout_Sidebar = new QVBoxLayout(sidebarContainer);
        verticalLayout_Sidebar->setSpacing(10);
        verticalLayout_Sidebar->setObjectName("verticalLayout_Sidebar");
        verticalLayout_Sidebar->setContentsMargins(20, 20, 20, 20);
        lblAccount = new QLabel(sidebarContainer);
        lblAccount->setObjectName("lblAccount");

        verticalLayout_Sidebar->addWidget(lblAccount);

        userLb = new QPushButton(sidebarContainer);
        userLb->setObjectName("userLb");
        userLb->setMinimumSize(QSize(0, 40));

        verticalLayout_Sidebar->addWidget(userLb);

        line_1 = new QFrame(sidebarContainer);
        line_1->setObjectName("line_1");
        line_1->setFrameShape(QFrame::Shape::HLine);
        line_1->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Sidebar->addWidget(line_1);

        lblSearch = new QLabel(sidebarContainer);
        lblSearch->setObjectName("lblSearch");

        verticalLayout_Sidebar->addWidget(lblSearch);

        searchLineEdit = new QLineEdit(sidebarContainer);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(0, 40));

        verticalLayout_Sidebar->addWidget(searchLineEdit);

        lblFilters = new QLabel(sidebarContainer);
        lblFilters->setObjectName("lblFilters");

        verticalLayout_Sidebar->addWidget(lblFilters);

        yearFilterComboBox = new QComboBox(sidebarContainer);
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->setObjectName("yearFilterComboBox");
        yearFilterComboBox->setMinimumSize(QSize(0, 40));

        verticalLayout_Sidebar->addWidget(yearFilterComboBox);

        typeFilterComboBox = new QComboBox(sidebarContainer);
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->setObjectName("typeFilterComboBox");
        typeFilterComboBox->setMinimumSize(QSize(0, 40));

        verticalLayout_Sidebar->addWidget(typeFilterComboBox);

        line_2 = new QFrame(sidebarContainer);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Sidebar->addWidget(line_2);

        lblActions = new QLabel(sidebarContainer);
        lblActions->setObjectName("lblActions");

        verticalLayout_Sidebar->addWidget(lblActions);

        newArticleBtn = new QPushButton(sidebarContainer);
        newArticleBtn->setObjectName("newArticleBtn");
        newArticleBtn->setMinimumSize(QSize(0, 45));
        newArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Sidebar->addWidget(newArticleBtn);

        RemoveArticleBtn = new QPushButton(sidebarContainer);
        RemoveArticleBtn->setObjectName("RemoveArticleBtn");
        RemoveArticleBtn->setMinimumSize(QSize(0, 45));
        RemoveArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        RemoveArticleBtn->setStyleSheet(QString::fromUtf8("background-color: #e74c3c; border: 2px solid #e74c3c; color: white;"));

        verticalLayout_Sidebar->addWidget(RemoveArticleBtn);

        pushButton = new QPushButton(sidebarContainer);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 45));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Sidebar->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Sidebar->addItem(verticalSpacer);

        backBtn = new QPushButton(sidebarContainer);
        backBtn->setObjectName("backBtn");
        backBtn->setMinimumSize(QSize(0, 45));
        backBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Sidebar->addWidget(backBtn);


        bodyLayout->addWidget(sidebarContainer);

        contentContainer = new QWidget(ArticleForm);
        contentContainer->setObjectName("contentContainer");
        verticalLayout_Content = new QVBoxLayout(contentContainer);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        articleListView = new QListView(contentContainer);
        articleListView->setObjectName("articleListView");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(11);
        articleListView->setFont(font);
        articleListView->setAlternatingRowColors(true);
        articleListView->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        articleListView->setSpacing(5);

        verticalLayout_Content->addWidget(articleListView);

        paginationLayout = new QHBoxLayout();
        paginationLayout->setObjectName("paginationLayout");

        verticalLayout_Content->addLayout(paginationLayout);


        bodyLayout->addWidget(contentContainer);


        mainLayout->addLayout(bodyLayout);


        retranslateUi(ArticleForm);

        QMetaObject::connectSlotsByName(ArticleForm);
    } // setupUi

    void retranslateUi(QWidget *ArticleForm)
    {
        ArticleForm->setWindowTitle(QCoreApplication::translate("ArticleForm", "Article Menu", nullptr));
        lblHeader->setText(QCoreApplication::translate("ArticleForm", "DANH S\303\201CH B\303\200I B\303\201O KHOA H\341\273\214C", nullptr));
        lblAccount->setText(QCoreApplication::translate("ArticleForm", "ACCOUNT", nullptr));
        userLb->setText(QCoreApplication::translate("ArticleForm", "Current User", nullptr));
        lblSearch->setText(QCoreApplication::translate("ArticleForm", "SEARCH", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("ArticleForm", "Type title to search...", nullptr));
        lblFilters->setText(QCoreApplication::translate("ArticleForm", "FILTERS", nullptr));
        yearFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All Years", nullptr));
        yearFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "Newest First", nullptr));
        yearFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "Oldest First", nullptr));

        typeFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All Types", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "SCIE", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "SCOPUS", nullptr));
        typeFilterComboBox->setItemText(3, QCoreApplication::translate("ArticleForm", "CONFERENCE", nullptr));
        typeFilterComboBox->setItemText(4, QCoreApplication::translate("ArticleForm", "OTHER", nullptr));

        lblActions->setText(QCoreApplication::translate("ArticleForm", "ACTIONS", nullptr));
        newArticleBtn->setText(QCoreApplication::translate("ArticleForm", "+ New Article", nullptr));
        RemoveArticleBtn->setText(QCoreApplication::translate("ArticleForm", "Remove Selected", nullptr));
        pushButton->setText(QCoreApplication::translate("ArticleForm", "Statistics", nullptr));
        backBtn->setText(QCoreApplication::translate("ArticleForm", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleForm: public Ui_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEFORM_H
