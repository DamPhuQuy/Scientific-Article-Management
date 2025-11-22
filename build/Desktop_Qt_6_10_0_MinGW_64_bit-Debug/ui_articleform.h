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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_2;
    QPushButton *backBtn;
    QHBoxLayout *paginationLayout;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QLabel *searchLabel;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QLineEdit *searchLineEdit;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *yearFilterComboBox;
    QComboBox *typeFilterComboBox;
    QListView *articleListView;
    QSpacerItem *topBarSpacer;
    QWidget *widget_6;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *userLb;
    QLabel *label_3;
    QPushButton *newArticleBtn;
    QPushButton *RemoveArticleBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ArticleForm)
    {
        if (ArticleForm->objectName().isEmpty())
            ArticleForm->setObjectName("ArticleForm");
        ArticleForm->resize(950, 743);
        gridLayout_2 = new QGridLayout(ArticleForm);
        gridLayout_2->setObjectName("gridLayout_2");
        backBtn = new QPushButton(ArticleForm);
        backBtn->setObjectName("backBtn");

        gridLayout_2->addWidget(backBtn, 2, 3, 1, 1);

        paginationLayout = new QHBoxLayout();
        paginationLayout->setSpacing(8);
        paginationLayout->setObjectName("paginationLayout");
        paginationLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_2->addLayout(paginationLayout, 3, 0, 1, 1);

        widget_5 = new QWidget(ArticleForm);
        widget_5->setObjectName("widget_5");
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName("gridLayout_3");
        searchLabel = new QLabel(widget_5);
        searchLabel->setObjectName("searchLabel");
        searchLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(searchLabel, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName("widget_2");
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName("gridLayout_4");
        searchLineEdit = new QLineEdit(widget_2);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(250, 0));

        gridLayout_4->addWidget(searchLineEdit, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget_5, 0, 0, 1, 1);

        widget_4 = new QWidget(ArticleForm);
        widget_4->setObjectName("widget_4");
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget_4);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName("widget_3");
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        yearFilterComboBox = new QComboBox(widget_3);
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->addItem(QString());
        yearFilterComboBox->setObjectName("yearFilterComboBox");
        yearFilterComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_4->addWidget(yearFilterComboBox);

        typeFilterComboBox = new QComboBox(widget_3);
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->setObjectName("typeFilterComboBox");
        typeFilterComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_4->addWidget(typeFilterComboBox);


        verticalLayout->addWidget(widget_3);


        gridLayout_2->addWidget(widget_4, 0, 1, 1, 1);

        articleListView = new QListView(ArticleForm);
        articleListView->setObjectName("articleListView");
        articleListView->setMinimumSize(QSize(200, 0));
        articleListView->setFlow(QListView::Flow::LeftToRight);
        articleListView->setResizeMode(QListView::ResizeMode::Adjust);
        articleListView->setSpacing(16);
        articleListView->setViewMode(QListView::ViewMode::ListMode);
        articleListView->setWordWrap(true);

        gridLayout_2->addWidget(articleListView, 1, 0, 1, 4);

        topBarSpacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(topBarSpacer, 0, 2, 1, 1);

        widget_6 = new QWidget(ArticleForm);
        widget_6->setObjectName("widget_6");
        gridLayout = new QGridLayout(widget_6);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(widget_6);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        userLb = new QPushButton(widget_6);
        userLb->setObjectName("userLb");
        userLb->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(userLb, 1, 0, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        newArticleBtn = new QPushButton(widget_6);
        newArticleBtn->setObjectName("newArticleBtn");
        newArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(newArticleBtn, 3, 0, 1, 1);

        RemoveArticleBtn = new QPushButton(widget_6);
        RemoveArticleBtn->setObjectName("RemoveArticleBtn");
        RemoveArticleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(RemoveArticleBtn, 4, 0, 1, 1);


        gridLayout_2->addWidget(widget_6, 0, 3, 1, 1);

        widget = new QWidget(ArticleForm);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addWidget(widget, 2, 0, 1, 3);


        retranslateUi(ArticleForm);

        QMetaObject::connectSlotsByName(ArticleForm);
    } // setupUi

    void retranslateUi(QWidget *ArticleForm)
    {
        ArticleForm->setWindowTitle(QCoreApplication::translate("ArticleForm", "Article Menu", nullptr));
        backBtn->setText(QCoreApplication::translate("ArticleForm", "Back", nullptr));
        searchLabel->setText(QCoreApplication::translate("ArticleForm", "Search", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("ArticleForm", "Search articles by title...", nullptr));
        label->setText(QCoreApplication::translate("ArticleForm", "Filter", nullptr));
        yearFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All years", nullptr));
        yearFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "Newest first", nullptr));
        yearFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "Oldest first", nullptr));

        typeFilterComboBox->setItemText(0, QCoreApplication::translate("ArticleForm", "All types", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("ArticleForm", "SCOPUS", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("ArticleForm", "CONFERENCE", nullptr));
        typeFilterComboBox->setItemText(3, QCoreApplication::translate("ArticleForm", "OTHER", nullptr));
        typeFilterComboBox->setItemText(4, QCoreApplication::translate("ArticleForm", "SCIE", nullptr));

        label_2->setText(QCoreApplication::translate("ArticleForm", "Account", nullptr));
        userLb->setText(QCoreApplication::translate("ArticleForm", "User", nullptr));
        label_3->setText(QCoreApplication::translate("ArticleForm", "Features", nullptr));
        newArticleBtn->setText(QCoreApplication::translate("ArticleForm", "New Article", nullptr));
        RemoveArticleBtn->setText(QCoreApplication::translate("ArticleForm", "Remove Article", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleForm: public Ui_ArticleForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEFORM_H
