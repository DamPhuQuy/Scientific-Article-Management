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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListOfAuthorsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelHeader;
    QVBoxLayout *bodyLayout;
    QGroupBox *groupFilter;
    QGridLayout *gridLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QLabel *labelCountry;
    QComboBox *comboCountry;
    QLabel *labelField;
    QComboBox *comboField;
    QHBoxLayout *filterBtnLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnApplyFilter;
    QListView *listViewAuthors;
    QHBoxLayout *actionLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QPushButton *okBtn;

    void setupUi(QDialog *ListOfAuthorsDialog)
    {
        if (ListOfAuthorsDialog->objectName().isEmpty())
            ListOfAuthorsDialog->setObjectName("ListOfAuthorsDialog");
        ListOfAuthorsDialog->resize(900, 600);
        ListOfAuthorsDialog->setMinimumSize(QSize(900, 600));
        ListOfAuthorsDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#ListOfAuthorsDialog {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #FFC085;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- GROUP BOX --- */\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    padding-top: 25px;\n"
"    padding-bottom: 10px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 5px;\n"
"    color: #20B2AA;\n"
"    font-weight: bold;\n"
"    left: 10px;\n"
"    top: 0px;\n"
"}\n"
"\n"
"/* --- INPUTS & LABELS --- */\n"
"QLabel {\n"
"    color: #555555;\n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
""
                        "    color: #333333;\n"
"}\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* --- COMBOBOX (T\303\271y ch\341\273\211nh \304\221\341\273\203 n\341\273\225i b\341\272\255t danh s\303\241ch) --- */\n"
"QComboBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    padding-right: 30px; /* Ch\341\273\253a ch\341\273\227 cho m\305\251i t\303\252n */\n"
"    color: #333333;\n"
"}\n"
"QComboBox:focus, QComboBox:on { /* Khi click v\303\240o */\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* T\341\272\241o n\303\272t m\305\251i t\303\252n b\303\252n ph\341\272\243i n\341\273\225i b\341\272\255t */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #cccccc;\n"
"    border-left-style: solid;\n"
"    border-top-right-rad"
                        "ius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background-color: #e0e0e0; /* N\341\273\201n x\303\241m cho n\303\272t m\305\251i t\303\252n */\n"
"}\n"
"QComboBox::drop-down:hover {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 10px; \n"
"    height: 10px;\n"
"    /* Qt t\341\273\261 v\341\272\275 m\305\251i t\303\252n \304\221en, ho\341\272\267c b\341\272\241n c\303\263 th\341\273\203 ch\303\250n \341\272\243nh v\303\240o \304\221\303\242y */\n"
"}\n"
"\n"
"/* Ph\341\272\247n danh s\303\241ch x\341\273\225 xu\341\273\221ng (Popup List) */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA; /* Vi\341\273\201n xanh ng\341\273\215c bao quanh list */\n"
"    selection-background-color: #e0f2f1; /* N\341\273\201n xanh nh\341\272\241t khi hover item */\n"
"    selection-color: #004d40; /* Ch\341\273\257 \304\221\341\272\255m khi hover item */\n"
"    outline: 0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* --- LIST VIEW"
                        " CH\303\215NH --- */\n"
"QListView {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    outline: 0;\n"
"}\n"
"QListView::item {\n"
"    padding: 8px;\n"
"    border-bottom: 1px solid #eeeeee;\n"
"}\n"
"QListView::item:selected {\n"
"    background-color: #e0f2f1;\n"
"    color: #004d40;\n"
"    border-radius: 4px;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(ListOfAuthorsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ListOfAuthorsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        labelHeader = new QLabel(headerContainer);
        labelHeader->setObjectName("labelHeader");
        labelHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;"));
        labelHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(labelHeader);


        verticalLayout->addWidget(headerContainer);

        bodyLayout = new QVBoxLayout();
        bodyLayout->setSpacing(15);
        bodyLayout->setObjectName("bodyLayout");
        bodyLayout->setContentsMargins(20, 20, 20, -1);
        groupFilter = new QGroupBox(ListOfAuthorsDialog);
        groupFilter->setObjectName("groupFilter");
        gridLayout = new QGridLayout(groupFilter);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(15);
        gridLayout->setHorizontalSpacing(15);
        labelSearch = new QLabel(groupFilter);
        labelSearch->setObjectName("labelSearch");

        gridLayout->addWidget(labelSearch, 0, 0, 1, 1);

        lineEditSearch = new QLineEdit(groupFilter);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setMinimumSize(QSize(0, 40));
        lineEditSearch->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEditSearch, 0, 1, 1, 1);

        labelCountry = new QLabel(groupFilter);
        labelCountry->setObjectName("labelCountry");

        gridLayout->addWidget(labelCountry, 1, 0, 1, 1);

        comboCountry = new QComboBox(groupFilter);
        comboCountry->addItem(QString());
        comboCountry->setObjectName("comboCountry");
        comboCountry->setMinimumSize(QSize(0, 40));
        comboCountry->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comboCountry->setEditable(true);
        comboCountry->setInsertPolicy(QComboBox::InsertPolicy::NoInsert);

        gridLayout->addWidget(comboCountry, 1, 1, 1, 1);

        labelField = new QLabel(groupFilter);
        labelField->setObjectName("labelField");

        gridLayout->addWidget(labelField, 2, 0, 1, 1);

        comboField = new QComboBox(groupFilter);
        comboField->addItem(QString());
        comboField->setObjectName("comboField");
        comboField->setMinimumSize(QSize(0, 40));
        comboField->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        comboField->setEditable(true);

        gridLayout->addWidget(comboField, 2, 1, 1, 1);

        filterBtnLayout = new QHBoxLayout();
        filterBtnLayout->setObjectName("filterBtnLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        filterBtnLayout->addItem(horizontalSpacer_2);

        btnApplyFilter = new QPushButton(groupFilter);
        btnApplyFilter->setObjectName("btnApplyFilter");
        btnApplyFilter->setMinimumSize(QSize(120, 35));
        btnApplyFilter->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnApplyFilter->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        filterBtnLayout->addWidget(btnApplyFilter);


        gridLayout->addLayout(filterBtnLayout, 3, 1, 1, 1);


        bodyLayout->addWidget(groupFilter);

        listViewAuthors = new QListView(ListOfAuthorsDialog);
        listViewAuthors->setObjectName("listViewAuthors");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(11);
        listViewAuthors->setFont(font);
        listViewAuthors->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        listViewAuthors->setAlternatingRowColors(true);
        listViewAuthors->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        listViewAuthors->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        listViewAuthors->setSpacing(2);

        bodyLayout->addWidget(listViewAuthors);

        actionLayout = new QHBoxLayout();
        actionLayout->setObjectName("actionLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(ListOfAuthorsDialog);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(100, 40));
        btnClose->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        actionLayout->addWidget(btnClose);

        okBtn = new QPushButton(ListOfAuthorsDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setMinimumSize(QSize(100, 40));
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        actionLayout->addWidget(okBtn);


        bodyLayout->addLayout(actionLayout);


        verticalLayout->addLayout(bodyLayout);


        retranslateUi(ListOfAuthorsDialog);
        QObject::connect(btnClose, &QPushButton::clicked, ListOfAuthorsDialog, qOverload<>(&QDialog::reject));

        btnApplyFilter->setDefault(true);


        QMetaObject::connectSlotsByName(ListOfAuthorsDialog);
    } // setupUi

    void retranslateUi(QDialog *ListOfAuthorsDialog)
    {
        ListOfAuthorsDialog->setWindowTitle(QCoreApplication::translate("ListOfAuthorsDialog", "Author Browser", nullptr));
        labelHeader->setText(QCoreApplication::translate("ListOfAuthorsDialog", "DANH S\303\201CH T\303\201C GI\341\272\242", nullptr));
        groupFilter->setTitle(QCoreApplication::translate("ListOfAuthorsDialog", "Search & Filter", nullptr));
        labelSearch->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Search by name:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("ListOfAuthorsDialog", "Type author name...", nullptr));
        labelCountry->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Country:", nullptr));
        comboCountry->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Countries", nullptr));

        labelField->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Field of Study:", nullptr));
        comboField->setItemText(0, QCoreApplication::translate("ListOfAuthorsDialog", "All Fields", nullptr));

        btnApplyFilter->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Apply Filter", nullptr));
        btnClose->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Close", nullptr));
        okBtn->setText(QCoreApplication::translate("ListOfAuthorsDialog", "Select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListOfAuthorsDialog: public Ui_ListOfAuthorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTOFAUTHORSDIALOG_H
