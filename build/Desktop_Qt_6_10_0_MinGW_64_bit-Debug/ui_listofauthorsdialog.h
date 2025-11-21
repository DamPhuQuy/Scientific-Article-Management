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

class Ui_ListOfAuthorsDialog
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblTitle;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QHBoxLayout *horizontalLayout_Search;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QPushButton *btnApplyFilter;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_Filters;
    QLabel *labelCountry;
    QComboBox *comboCountry;
    QLabel *labelField;
    QComboBox *comboField;
    QSpacerItem *horizontalSpacer_Filters;
    QFrame *lineSeparator;
    QListView *listViewAuthors;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QPushButton *okBtn;

    void setupUi(QDialog *ListOfAuthorsDialog)
    {
        if (ListOfAuthorsDialog->objectName().isEmpty())
            ListOfAuthorsDialog->setObjectName("ListOfAuthorsDialog");
        ListOfAuthorsDialog->resize(900, 600);
        ListOfAuthorsDialog->setMinimumSize(QSize(900, 600));
        ListOfAuthorsDialog->setStyleSheet(QString::fromUtf8("QDialog#ListOfAuthorsDialog { background-color: #f4f7f6; font-family: \"Segoe UI\", Arial, sans-serif; }\n"
"QWidget#headerContainer { background-color: #00264d; border-left: 10px solid #FFD700; border-bottom: 5px solid #4169E1; }\n"
"QLabel#lblTitle { color: #ffffff; font-size: 24px; font-weight: 900; background-color: transparent; padding-left: 10px; }\n"
"QWidget#bodyContainer { background-color: #ffffff; border: 2px solid #20B2AA; border-radius: 8px; }\n"
"QLineEdit, QComboBox { background-color: #f9f9f9; border: 1px solid #cccccc; border-radius: 6px; padding: 8px 12px; font-size: 14px; color: #555; min-height: 25px; }\n"
"QLineEdit:focus, QComboBox:focus { background-color: #ffffff; border: 2px solid #20B2AA; color: #000; }\n"
"QComboBox::drop-down { border: 0px; }\n"
"QLabel { font-weight: bold; color: #555; font-size: 14px; }\n"
"QPushButton { border-radius: 6px; font-weight: bold; padding: 8px 16px; min-height: 25px; font-size: 14px; color: white; }\n"
"QPushButton#btnApplyFilter, QPushButton#okBtn { b"
                        "ackground-color: #20B2AA; border: 2px solid #20B2AA; }\n"
"QPushButton#btnApplyFilter:hover, QPushButton#okBtn:hover { background-color: #17a098; border-color: #17a098; }\n"
"QPushButton#btnClose { background-color: #da3e36; border: 2px solid #da3e36; }\n"
"QPushButton#btnClose:hover { background-color: #c0392b; border-color: #c0392b; }\n"
"QListView { border: 1px solid #e0e0e0; border-radius: 6px; padding: 5px; background-color: #fff; font-size: 14px; }\n"
"QListView::item { padding: 10px; border-bottom: 1px solid #eee; }\n"
"QListView::item:selected { background-color: #e0f2f1; color: #000; border-left: 4px solid #20B2AA; }\n"
"QFrame#lineSeparator { min-height: 3px; max-height: 3px; background-color: #20B2AA; border: none; }"));
        mainLayout = new QVBoxLayout(ListOfAuthorsDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ListOfAuthorsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 80));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, -1, -1, -1);
        lblTitle = new QLabel(headerContainer);
        lblTitle->setObjectName("lblTitle");

        horizontalLayout_Header->addWidget(lblTitle);


        mainLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(ListOfAuthorsDialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(20);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_Search = new QHBoxLayout();
        horizontalLayout_Search->setSpacing(15);
        horizontalLayout_Search->setObjectName("horizontalLayout_Search");
        labelSearch = new QLabel(bodyContainer);
        labelSearch->setObjectName("labelSearch");

        horizontalLayout_Search->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(bodyContainer);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setMinimumSize(QSize(250, 40));
        lineEditSearch->setClearButtonEnabled(true);

        horizontalLayout_Search->addWidget(lineEditSearch);

        btnApplyFilter = new QPushButton(bodyContainer);
        btnApplyFilter->setObjectName("btnApplyFilter");
        btnApplyFilter->setMinimumSize(QSize(100, 40));
        btnApplyFilter->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Search->addWidget(btnApplyFilter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Search->addItem(horizontalSpacer_2);


        verticalLayout_Body->addLayout(horizontalLayout_Search);

        horizontalLayout_Filters = new QHBoxLayout();
        horizontalLayout_Filters->setSpacing(15);
        horizontalLayout_Filters->setObjectName("horizontalLayout_Filters");
        labelCountry = new QLabel(bodyContainer);
        labelCountry->setObjectName("labelCountry");

        horizontalLayout_Filters->addWidget(labelCountry);

        comboCountry = new QComboBox(bodyContainer);
        comboCountry->addItem(QString());
        comboCountry->setObjectName("comboCountry");
        comboCountry->setMinimumSize(QSize(150, 40));
        comboCountry->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comboCountry->setEditable(true);

        horizontalLayout_Filters->addWidget(comboCountry);

        labelField = new QLabel(bodyContainer);
        labelField->setObjectName("labelField");

        horizontalLayout_Filters->addWidget(labelField);

        comboField = new QComboBox(bodyContainer);
        comboField->addItem(QString());
        comboField->setObjectName("comboField");
        comboField->setMinimumSize(QSize(150, 40));
        comboField->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comboField->setEditable(true);

        horizontalLayout_Filters->addWidget(comboField);

        horizontalSpacer_Filters = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Filters->addItem(horizontalSpacer_Filters);


        verticalLayout_Body->addLayout(horizontalLayout_Filters);

        lineSeparator = new QFrame(bodyContainer);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::HLine);
        lineSeparator->setFrameShadow(QFrame::Plain);

        verticalLayout_Body->addWidget(lineSeparator);

        listViewAuthors = new QListView(bodyContainer);
        listViewAuthors->setObjectName("listViewAuthors");
        listViewAuthors->setAlternatingRowColors(true);
        listViewAuthors->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listViewAuthors->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Body->addWidget(listViewAuthors);

        horizontalLayout_Footer = new QHBoxLayout();
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        btnClose = new QPushButton(bodyContainer);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(100, 40));

        horizontalLayout_Footer->addWidget(btnClose);

        okBtn = new QPushButton(bodyContainer);
        okBtn->setObjectName("okBtn");
        okBtn->setMinimumSize(QSize(100, 40));

        horizontalLayout_Footer->addWidget(okBtn);


        verticalLayout_Body->addLayout(horizontalLayout_Footer);


        mainLayout->addWidget(bodyContainer);


        retranslateUi(ListOfAuthorsDialog);
        QObject::connect(btnClose, &QPushButton::clicked, ListOfAuthorsDialog, qOverload<>(&QDialog::reject));

        btnApplyFilter->setDefault(true);


        QMetaObject::connectSlotsByName(ListOfAuthorsDialog);
    } // setupUi

    void retranslateUi(QDialog *ListOfAuthorsDialog)
    {
        ListOfAuthorsDialog->setWindowTitle(QCoreApplication::translate("ListOfAuthorsDialog", "Author Browser", nullptr));
        lblTitle->setText(QCoreApplication::translate("ListOfAuthorsDialog", "DANH S\303\201CH T\303\201C GI\341\272\242", nullptr));
        labelSearch->setText(QCoreApplication::translate("ListOfAuthorsDialog", "T\303\254m ki\341\272\277m t\303\252n:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("ListOfAuthorsDialog", "Nh\341\272\255p t\303\252n t\303\241c gi\341\272\243...", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("ListOfAuthorsDialog", "\303\201p d\341\273\245ng l\341\273\215c", nullptr));
        labelCountry->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Qu\341\273\221c gia:", nullptr));
        comboCountry->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Countries", nullptr));

        labelField->setText(QCoreApplication::translate("ListOfAuthorsDialog", "L\304\251nh v\341\273\261c:", nullptr));
        comboField->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Fields", nullptr));

        btnClose->setText(QCoreApplication::translate("ListOfAuthorsDialog", "\304\220\303\263ng", nullptr));
        okBtn->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Ch\341\273\215n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListOfAuthorsDialog: public Ui_ListOfAuthorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTOFAUTHORSDIALOG_H
