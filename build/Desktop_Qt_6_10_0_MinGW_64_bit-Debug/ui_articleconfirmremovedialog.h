/********************************************************************************
** Form generated from reading UI file 'articleconfirmremovedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLECONFIRMREMOVEDIALOG_H
#define UI_ARTICLECONFIRMREMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleConfirmRemoveDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelInstruction;
    QLineEdit *editConfirm;
    QLineEdit *editKey;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnRemove;

    void setupUi(QDialog *ArticleConfirmRemoveDialog)
    {
        if (ArticleConfirmRemoveDialog->objectName().isEmpty())
            ArticleConfirmRemoveDialog->setObjectName("ArticleConfirmRemoveDialog");
        ArticleConfirmRemoveDialog->resize(450, 366);
        ArticleConfirmRemoveDialog->setMinimumSize(QSize(450, 320));
        ArticleConfirmRemoveDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#ArticleConfirmRemoveDialog {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #e74c3c; /* Vi\341\273\201n \304\221\341\273\217 c\341\272\243nh b\303\241o thay v\303\254 cam */\n"
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
"    margin-top: 10px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"/* --- LABELS --- */\n"
"QLabel {\n"
"    color: #333333;\n"
"}\n"
"QLabel#labelInstruction {\n"
"    color: #c0392b; /* M\303\240u \304\221\341\273\217 \304\221\341\272\255m cho h\306\260\341\273\233ng d\341\272\253n c\341\272\243nh b\303\241o */\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* --- INPUTS --- */\n"
"QLineEdit {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
""
                        "    padding: 8px;\n"
"    color: #333333;\n"
"}\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #e74c3c; /* Focus m\303\240u \304\221\341\273\217 \304\221\341\273\203 c\341\272\243nh b\303\241o */\n"
"}\n"
"\n"
"/* --- BUTTONS --- */\n"
"QPushButton {\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    padding: 8px 15px;\n"
"    min-width: 80px;\n"
"    color: white;\n"
"}\n"
"/* N\303\272t Remove (Nguy hi\341\273\203m - \304\220\341\273\217) */\n"
"QPushButton#btnRemove {\n"
"    background-color: #e74c3c;\n"
"    border: 2px solid #e74c3c;\n"
"}\n"
"QPushButton#btnRemove:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton#btnRemove:pressed {\n"
"    background-color: #922b21;\n"
"}\n"
"\n"
"/* N\303\272t Cancel (X\303\241m) */\n"
"QPushButton#btnCancel {\n"
"    background-color: #7f8c8d;\n"
"    border: 2px solid #7f8c8d;\n"
"}\n"
"QPushButton#btnCancel:hover {\n"
"    background-color: #636e72;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(ArticleConfirmRemoveDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleConfirmRemoveDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #e74c3c;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:18px;background:transparent;padding-left:10px;"));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(lblHeader);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(ArticleConfirmRemoveDialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 10, 20, 10);
        groupBox = new QGroupBox(bodyContainer);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelInstruction = new QLabel(groupBox);
        labelInstruction->setObjectName("labelInstruction");
        labelInstruction->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelInstruction->setWordWrap(true);

        verticalLayout_2->addWidget(labelInstruction);

        editConfirm = new QLineEdit(groupBox);
        editConfirm->setObjectName("editConfirm");
        editConfirm->setMinimumSize(QSize(0, 40));
        editConfirm->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(editConfirm);

        editKey = new QLineEdit(groupBox);
        editKey->setObjectName("editKey");
        editKey->setMinimumSize(QSize(0, 40));
        editKey->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(editKey);


        verticalLayout_Body->addWidget(groupBox);


        verticalLayout->addWidget(bodyContainer);

        footerContainer = new QWidget(ArticleConfirmRemoveDialog);
        footerContainer->setObjectName("footerContainer");
        horizontalLayout = new QHBoxLayout(footerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(footerContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumSize(QSize(114, 40));
        btnCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnCancel);

        btnRemove = new QPushButton(footerContainer);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setMinimumSize(QSize(114, 40));
        btnRemove->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnRemove);


        verticalLayout->addWidget(footerContainer);


        retranslateUi(ArticleConfirmRemoveDialog);

        QMetaObject::connectSlotsByName(ArticleConfirmRemoveDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleConfirmRemoveDialog)
    {
        ArticleConfirmRemoveDialog->setWindowTitle(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Confirm Removal", nullptr));
        lblHeader->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "X\303\201C NH\341\272\254N X\303\223A", nullptr));
        groupBox->setTitle(QString());
        labelInstruction->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "\342\232\240\357\270\217 WARNING: This action cannot be undone.\n"
"Please type \"i confirm\" and the specific key to proceed.", nullptr));
        editConfirm->setPlaceholderText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Type \"i confirm\" here...", nullptr));
        editKey->setPlaceholderText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Type the Article Key here...", nullptr));
        btnCancel->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Cancel", nullptr));
        btnRemove->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleConfirmRemoveDialog: public Ui_ArticleConfirmRemoveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLECONFIRMREMOVEDIALOG_H
