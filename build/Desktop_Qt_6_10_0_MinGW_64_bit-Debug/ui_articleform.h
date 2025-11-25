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
    QLabel *label_2;
    QPushButton *userLb;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QLabel *label;
    QComboBox *yearFilterComboBox;
    QComboBox *typeFilterComboBox;
    QLabel *label_3;
    QPushButton *newArticleBtn;
    QPushButton *pushButton;
    QPushButton *RemoveArticleBtn;
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
        ArticleForm->resize(1000, 700);
        ArticleForm->setStyleSheet(QString::fromUtf8("\n"
"QWidget#ArticleForm{background-color:#f4f7f6;border:4px solid #FFC085;}\n"
"QWidget{font-family:\"Segoe UI\",Arial,sans-serif;font-size:14px;}\n"
"QWidget#sidebarContainer{background-color:#ffffff;border-right:1px solid #e0e0e0;}\n"
"QLabel{color:#555555;font-weight:bold;margin-top:10px;}\n"
"QLabel#lblHeader{margin-top:0px;}\n"
"QLineEdit,QComboBox{background-color:#f9f9f9;border:1px solid #cccccc;border-radius:6px;padding:8px;color:#333333;}\n"
"QLineEdit:focus,QComboBox:focus{background-color:#ffffff;border:2px solid #20B2AA;}\n"
"QComboBox::drop-down{border:0px;}\n"
"QListView{background-color:#ffffff;border:1px solid #cccccc;border-radius:6px;padding:10px;outline:0;}\n"
"QListView::item{padding:10px;border-bottom:1px solid #eeeeee;}\n"
"QListView::item:selected{background-color:#e0f2f1;color:#004d40;border-radius:4px;}\n"
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
        sidebarContainer->setMinimumSize(QSize(260, 0));
        sidebarContainer->setMaximumSize(QSize(280, 16777215));
        verticalLayout_Sidebar = new QVBoxLayout(sidebarContainer);
        verticalLayout_Sidebar->setSpacing(15);
        verticalLayout_Sidebar->setObjectName("verticalLayout_Sidebar");
        verticalLayout_Sidebar->setContentsMargins(20, 20, 20, 20);
        label_2 = new QLabel(sidebarContainer);
        label_2->setObjectName("label_2");

        verticalLayout_Sidebar->addWidget(label_2);

        userLb = new QPushButton(sidebarContainer);
        userLb->setObjectName("userLb");
        userLb->setMinimumSize(QSize(0, 40));
        userLb->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e0f2f1;color:#00695c;border:1px solid #b2dfdb;border-radius:6px;font-weight:bold;text-align:left;padding-left:15px;}"));

        verticalLayout_Sidebar->addWidget(userLb);

        searchLabel = new QLabel(sidebarContainer);
        searchLabel->setObjectName("searchLabel");

        verticalLayout_Sidebar->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(sidebarContainer);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(0, 40));

        verticalLayout_Sidebar->addWidget(searchLineEdit);

        label = new QLabel(sidebarContainer);
        label->setObjectName("label");

        verticalLayout_Sidebar->addWidget(label);

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

        label_3 = new QLabel(sidebarContainer);
        label_3->setObjectName("label_3");

        verticalLayout_Sidebar->addWidget(label_3);

        newArticleBtn = new QPushButton(sidebarContainer);
        newArticleBtn->setObjectName("newArticleBtn");
        newArticleBtn->setMinimumSize(QSize(0, 45));
        newArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        newArticleBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        verticalLayout_Sidebar->addWidget(newArticleBtn);

        pushButton = new QPushButton(sidebarContainer);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 45));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        verticalLayout_Sidebar->addWidget(pushButton);

        RemoveArticleBtn = new QPushButton(sidebarContainer);
        RemoveArticleBtn->setObjectName("RemoveArticleBtn");
        RemoveArticleBtn->setMinimumSize(QSize(0, 45));
        RemoveArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        RemoveArticleBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        verticalLayout_Sidebar->addWidget(RemoveArticleBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Sidebar->addItem(verticalSpacer);

        backBtn = new QPushButton(sidebarContainer);
        backBtn->setObjectName("backBtn");
        backBtn->setMinimumSize(QSize(0, 45));
        backBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#7f8c8d;border:2px solid #7f8c8d;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#636e72;}QPushButton:pressed{background-color:#2d3436;}"));

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
        label_2->setText(QCoreApplication::translate("ArticleForm", "USER ACCOUNT", nullptr));
        userLb->setText(QCoreApplication::translate("ArticleForm", "Current User", nullptr));
        searchLabel->setText(QCoreApplication::translate("ArticleForm", "SEARCH", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("ArticleForm", "Type title to search...", nullptr));
        label->setText(QCoreApplication::translate("ArticleForm", "FILTERS", nullptr));
        yearFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All Years", nullptr));
        yearFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "Newest First", nullptr));
        yearFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "Oldest First", nullptr));

        typeFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All Types", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "SCIE", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "SCOPUS", nullptr));
        typeFilterComboBox->setItemText(3, QCoreApplication::translate("ArticleForm", "CONFERENCE", nullptr));
        typeFilterComboBox->setItemText(4, QCoreApplication::translate("ArticleForm", "OTHER", nullptr));

        label_3->setText(QCoreApplication::translate("ArticleForm", "ACTIONS", nullptr));
        newArticleBtn->setText(QCoreApplication::translate("ArticleForm", "+ New Article", nullptr));
        pushButton->setText(QCoreApplication::translate("ArticleForm", "Statistics", nullptr));
        RemoveArticleBtn->setText(QCoreApplication::translate("ArticleForm", "Remove Selected", nullptr));
        backBtn->setText(QCoreApplication::translate("ArticleForm", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleForm: public Ui_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEFORM_H
