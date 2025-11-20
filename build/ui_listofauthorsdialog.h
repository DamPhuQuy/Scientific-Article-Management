/********************************************************************************
** Form generated from reading UI file 'listofauthorsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTOFAUTHORSDIALOG_H
#define UI_LISTOFAUTHORSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListOfAuthorsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupFilter;
    QGridLayout *gridLayout;
    QLabel *labelField;
    QHBoxLayout *hboxLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnApplyFilter;
    QLineEdit *lineEditSearch;
    QLabel *labelCountry;
    QLabel *labelSearch;
    QComboBox *comboCountry;
    QComboBox *comboField;
    QListView *listViewAuthors;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QPushButton *okBtn;

    void setupUi(QDialog *ListOfAuthorsDialog)
    {
        if (ListOfAuthorsDialog->objectName().isEmpty())
            ListOfAuthorsDialog->setObjectName("ListOfAuthorsDialog");
        ListOfAuthorsDialog->resize(900, 600);
        ListOfAuthorsDialog->setMinimumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(ListOfAuthorsDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupFilter = new QGroupBox(ListOfAuthorsDialog);
        groupFilter->setObjectName("groupFilter");
        gridLayout = new QGridLayout(groupFilter);
        gridLayout->setObjectName("gridLayout");
        labelField = new QLabel(groupFilter);
        labelField->setObjectName("labelField");

        gridLayout->addWidget(labelField, 2, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(horizontalSpacer_2);

        btnApplyFilter = new QPushButton(groupFilter);
        btnApplyFilter->setObjectName("btnApplyFilter");

        hboxLayout->addWidget(btnApplyFilter);


        gridLayout->addLayout(hboxLayout, 3, 1, 1, 1);

        lineEditSearch = new QLineEdit(groupFilter);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEditSearch, 0, 1, 1, 1);

        labelCountry = new QLabel(groupFilter);
        labelCountry->setObjectName("labelCountry");

        gridLayout->addWidget(labelCountry, 1, 0, 1, 1);

        labelSearch = new QLabel(groupFilter);
        labelSearch->setObjectName("labelSearch");

        gridLayout->addWidget(labelSearch, 0, 0, 1, 1);

        comboCountry = new QComboBox(groupFilter);
        comboCountry->addItem(QString());
        comboCountry->setObjectName("comboCountry");
        comboCountry->setEditable(true);
        comboCountry->setInsertPolicy(QComboBox::InsertPolicy::NoInsert);

        gridLayout->addWidget(comboCountry, 1, 1, 1, 1);

        comboField = new QComboBox(groupFilter);
        comboField->addItem(QString());
        comboField->setObjectName("comboField");
        comboField->setEditable(true);

        gridLayout->addWidget(comboField, 2, 1, 1, 1);


        verticalLayout->addWidget(groupFilter);

        listViewAuthors = new QListView(ListOfAuthorsDialog);
        listViewAuthors->setObjectName("listViewAuthors");
        QFont font;
        font.setPointSize(10);
        listViewAuthors->setFont(font);
        listViewAuthors->setAlternatingRowColors(true);
        listViewAuthors->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        listViewAuthors->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        listViewAuthors->setSpacing(2);

        verticalLayout->addWidget(listViewAuthors);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout1->addItem(horizontalSpacer);

        btnClose = new QPushButton(ListOfAuthorsDialog);
        btnClose->setObjectName("btnClose");

        hboxLayout1->addWidget(btnClose);

        okBtn = new QPushButton(ListOfAuthorsDialog);
        okBtn->setObjectName("okBtn");

        hboxLayout1->addWidget(okBtn);


        verticalLayout->addLayout(hboxLayout1);


        retranslateUi(ListOfAuthorsDialog);
        QObject::connect(btnClose, &QPushButton::clicked, ListOfAuthorsDialog, qOverload<>(&QDialog::reject));

        btnApplyFilter->setDefault(true);


        QMetaObject::connectSlotsByName(ListOfAuthorsDialog);
    } // setupUi

    void retranslateUi(QDialog *ListOfAuthorsDialog)
    {
        ListOfAuthorsDialog->setWindowTitle(QCoreApplication::translate("ListOfAuthorsDialog", "Author Browser", nullptr));
        groupFilter->setTitle(QCoreApplication::translate("ListOfAuthorsDialog", "Search && Filter", nullptr));
        labelField->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Field of Study:", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Apply Filter", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("ListOfAuthorsDialog", "Type author name...", nullptr));
        labelCountry->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Country:", nullptr));
        labelSearch->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Search by name:", nullptr));
        comboCountry->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Countries", nullptr));

        comboField->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Fields", nullptr));

        btnClose->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Close", nullptr));
        okBtn->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListOfAuthorsDialog: public Ui_ListOfAuthorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTOFAUTHORSDIALOG_H
