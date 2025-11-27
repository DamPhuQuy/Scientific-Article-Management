/********************************************************************************
** Form generated from reading UI file 'userdetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDETAILSDIALOG_H
#define UI_USERDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDetailsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelHeader;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QGroupBox *grpInfo;
    QFormLayout *formLayoutDetails;
    QLabel *lblUsername;
    QLabel *labelDetailUsername;
    QLabel *lblFullName;
    QLabel *labelDetailFullname;
    QLabel *lblEmail;
    QLabel *labelDetailEmail;
    QLabel *lblPhoneNumer;
    QLabel *labelDetailPhoneNumber;
    QLabel *label;
    QLabel *labelDetailKey;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;
    QPushButton *okBtn;

    void setupUi(QDialog *UserDetailsDialog)
    {
        if (UserDetailsDialog->objectName().isEmpty())
            UserDetailsDialog->setObjectName("UserDetailsDialog");
        UserDetailsDialog->resize(500, 503);
        UserDetailsDialog->setMinimumSize(QSize(500, 450));
        UserDetailsDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#UserDetailsDialog {\n"
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
"    padding-top: 20px;\n"
"    padding-bottom: 20px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
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
"/* --- LABELS --- */\n"
"QLabel {\n"
"    color: #333333;\n"
"}\n"
"/* Nh\303\243n ti\303\252u \304\221\341\273\201 field (Username, Email...) */\n"
"QLabel#lblUsername, QLabel#lblFullName, QLabel#lblEmail, QLabel#lblPhoneNumer, QLabel#label "
                        "{\n"
"    color: #555555;\n"
"    font-weight: bold;\n"
"}\n"
"/* Gi\303\241 tr\341\273\213 chi ti\341\272\277t */\n"
"QLabel#labelDetailUsername, QLabel#labelDetailFullname, QLabel#labelDetailEmail, QLabel#labelDetailPhoneNumber, QLabel#labelDetailKey {\n"
"    color: #000000;\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* --- BUTTONS --- */\n"
"QPushButton {\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    min-width: 100px;\n"
"    color: white;\n"
"}\n"
"/* N\303\272t Update (Xanh Ng\341\273\215c) */\n"
"QPushButton#btnUpdate {\n"
"    background-color: #20B2AA;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"QPushButton#btnUpdate:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"/* N\303\272t OK (\304\220\341\273\217 - \304\220\303\263ng) */\n"
"QPushButton#okBtn {\n"
"    background-color: #e74c3c;\n"
"    border: 2px solid #e74c3c;\n"
"}\n"
"QPushButton#okBtn:hover {\n"
"  "
                        "  background-color: #c0392b;\n"
"}\n"
"   "));
        UserDetailsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(UserDetailsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(UserDetailsDialog);
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

        bodyContainer = new QWidget(UserDetailsDialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 10, 20, 10);
        grpInfo = new QGroupBox(bodyContainer);
        grpInfo->setObjectName("grpInfo");
        formLayoutDetails = new QFormLayout(grpInfo);
        formLayoutDetails->setObjectName("formLayoutDetails");
        formLayoutDetails->setHorizontalSpacing(20);
        formLayoutDetails->setVerticalSpacing(15);
        formLayoutDetails->setContentsMargins(-1, 10, -1, -1);
        lblUsername = new QLabel(grpInfo);
        lblUsername->setObjectName("lblUsername");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        labelDetailUsername = new QLabel(grpInfo);
        labelDetailUsername->setObjectName("labelDetailUsername");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailUsername);

        lblFullName = new QLabel(grpInfo);
        lblFullName->setObjectName("lblFullName");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblFullName);

        labelDetailFullname = new QLabel(grpInfo);
        labelDetailFullname->setObjectName("labelDetailFullname");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailFullname);

        lblEmail = new QLabel(grpInfo);
        lblEmail->setObjectName("lblEmail");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblEmail);

        labelDetailEmail = new QLabel(grpInfo);
        labelDetailEmail->setObjectName("labelDetailEmail");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailEmail);

        lblPhoneNumer = new QLabel(grpInfo);
        lblPhoneNumer->setObjectName("lblPhoneNumer");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhoneNumer);

        labelDetailPhoneNumber = new QLabel(grpInfo);
        labelDetailPhoneNumber->setObjectName("labelDetailPhoneNumber");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPhoneNumber);

        label = new QLabel(grpInfo);
        label->setObjectName("label");

        formLayoutDetails->setWidget(4, QFormLayout::ItemRole::LabelRole, label);

        labelDetailKey = new QLabel(grpInfo);
        labelDetailKey->setObjectName("labelDetailKey");

        formLayoutDetails->setWidget(4, QFormLayout::ItemRole::FieldRole, labelDetailKey);


        verticalLayout_Body->addWidget(grpInfo);


        verticalLayout->addWidget(bodyContainer);

        footerContainer = new QWidget(UserDetailsDialog);
        footerContainer->setObjectName("footerContainer");
        horizontalLayout_2 = new QHBoxLayout(footerContainer);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(20, -1, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnUpdate = new QPushButton(footerContainer);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-edit")));
        btnUpdate->setIcon(icon);

        horizontalLayout_2->addWidget(btnUpdate);

        okBtn = new QPushButton(footerContainer);
        okBtn->setObjectName("okBtn");
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout->addWidget(footerContainer);


        retranslateUi(UserDetailsDialog);
        QObject::connect(okBtn, &QPushButton::clicked, UserDetailsDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(UserDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDetailsDialog)
    {
        UserDetailsDialog->setWindowTitle(QCoreApplication::translate("UserDetailsDialog", "User Details", nullptr));
        labelHeader->setText(QCoreApplication::translate("UserDetailsDialog", "TH\303\224NG TIN NG\306\257\341\273\234I D\303\231NG", nullptr));
        grpInfo->setTitle(QCoreApplication::translate("UserDetailsDialog", "General Information", nullptr));
        lblUsername->setText(QCoreApplication::translate("UserDetailsDialog", "Username:", nullptr));
        labelDetailUsername->setText(QCoreApplication::translate("UserDetailsDialog", "--", nullptr));
        lblFullName->setText(QCoreApplication::translate("UserDetailsDialog", "Fullname:", nullptr));
        labelDetailFullname->setText(QCoreApplication::translate("UserDetailsDialog", "--", nullptr));
        lblEmail->setText(QCoreApplication::translate("UserDetailsDialog", "Email:", nullptr));
        labelDetailEmail->setText(QCoreApplication::translate("UserDetailsDialog", "--", nullptr));
        lblPhoneNumer->setText(QCoreApplication::translate("UserDetailsDialog", "Phone Number:", nullptr));
        labelDetailPhoneNumber->setText(QCoreApplication::translate("UserDetailsDialog", "--", nullptr));
        label->setText(QCoreApplication::translate("UserDetailsDialog", "Key:", nullptr));
        labelDetailKey->setText(QCoreApplication::translate("UserDetailsDialog", "--", nullptr));
        btnUpdate->setText(QCoreApplication::translate("UserDetailsDialog", "Update Info", nullptr));
        okBtn->setText(QCoreApplication::translate("UserDetailsDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDetailsDialog: public Ui_UserDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDETAILSDIALOG_H
