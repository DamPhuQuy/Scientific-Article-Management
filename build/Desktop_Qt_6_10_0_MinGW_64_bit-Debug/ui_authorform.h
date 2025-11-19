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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorForm
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *UpdateButton_3;
    QPushButton *RemoveButton_3;
    QPushButton *Statistics_3;
    QPushButton *Back_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *EnterButton_3;
    QPushButton *EnterBox_3;
    QTableView *tableView_3;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *AuthorForm)
    {
        if (AuthorForm->objectName().isEmpty())
            AuthorForm->setObjectName("AuthorForm");
        AuthorForm->resize(400, 300);
        gridLayout_4 = new QGridLayout(AuthorForm);
        gridLayout_4->setObjectName("gridLayout_4");
        widget_2 = new QWidget(AuthorForm);
        widget_2->setObjectName("widget_2");
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        UpdateButton_3 = new QPushButton(widget_2);
        UpdateButton_3->setObjectName("UpdateButton_3");

        verticalLayout_3->addWidget(UpdateButton_3);

        RemoveButton_3 = new QPushButton(widget_2);
        RemoveButton_3->setObjectName("RemoveButton_3");

        verticalLayout_3->addWidget(RemoveButton_3);

        Statistics_3 = new QPushButton(widget_2);
        Statistics_3->setObjectName("Statistics_3");

        verticalLayout_3->addWidget(Statistics_3);

        Back_3 = new QPushButton(widget_2);
        Back_3->setObjectName("Back_3");

        verticalLayout_3->addWidget(Back_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout_4->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(AuthorForm);
        widget->setObjectName("widget");
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        EnterButton_3 = new QLineEdit(widget_5);
        EnterButton_3->setObjectName("EnterButton_3");

        horizontalLayout_4->addWidget(EnterButton_3);

        EnterBox_3 = new QPushButton(widget_5);
        EnterBox_3->setObjectName("EnterBox_3");

        horizontalLayout_4->addWidget(EnterBox_3);


        gridLayout_3->addWidget(widget_5, 0, 0, 1, 1);

        tableView_3 = new QTableView(widget);
        tableView_3->setObjectName("tableView_3");

        gridLayout_3->addWidget(tableView_3, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget, 0, 1, 1, 1);

        verticalScrollBar = new QScrollBar(AuthorForm);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);

        gridLayout_4->addWidget(verticalScrollBar, 0, 2, 1, 1);


        retranslateUi(AuthorForm);

        QMetaObject::connectSlotsByName(AuthorForm);
    } // setupUi

    void retranslateUi(QWidget *AuthorForm)
    {
        AuthorForm->setWindowTitle(QCoreApplication::translate("AuthorForm", "Form", nullptr));
        UpdateButton_3->setText(QCoreApplication::translate("AuthorForm", "Update Article", nullptr));
        RemoveButton_3->setText(QCoreApplication::translate("AuthorForm", "Remove Article", nullptr));
        Statistics_3->setText(QCoreApplication::translate("AuthorForm", "Statistics", nullptr));
        Back_3->setText(QCoreApplication::translate("AuthorForm", "Back", nullptr));
        EnterBox_3->setText(QCoreApplication::translate("AuthorForm", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorForm: public Ui_AuthorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORFORM_H
