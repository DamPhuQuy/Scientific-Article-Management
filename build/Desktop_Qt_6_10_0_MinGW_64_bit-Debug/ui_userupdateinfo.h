/********************************************************************************
** Form generated from reading UI file 'userupdateinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERUPDATEINFO_H
#define UI_USERUPDATEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userUpdateInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelTitle;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QGroupBox *grpPersonal;
    QFormLayout *formLayout;
    QLabel *lblUsername;
    QLabel *txtUsername;
    QLabel *lblFullname;
    QLineEdit *txtFullname;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QLabel *lblPhone;
    QLineEdit *txtPhone;
    QGroupBox *grpPassword;
    QFormLayout *formLayoutPassword;
    QLabel *lblOldPass;
    QLineEdit *txtOldPass;
    QLabel *lblNewPass;
    QLineEdit *txtNewPass;
    QLabel *lblConfirmPass;
    QLineEdit *txtConfirmPass;
    QSpacerItem *verticalSpacer;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *userUpdateInfo)
    {
        if (userUpdateInfo->objectName().isEmpty())
            userUpdateInfo->setObjectName("userUpdateInfo");
        userUpdateInfo->resize(500, 671);
        userUpdateInfo->setMinimumSize(QSize(500, 600));
        userUpdateInfo->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#userUpdateInfo {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #FFC085;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- HEADER --- */\n"
"QWidget#headerContainer {\n"
"    background-color: #00264d;\n"
"    border-bottom: 5px solid #4169E1;\n"
"    border-left: 10px solid #FFD700;\n"
"}\n"
"\n"
"/* --- FOOTER CONTAINER (\304\220\303\243 chuy\341\273\203n CSS l\303\252n \304\221\303\242y \304\221\341\273\203 kh\303\264ng b\341\273\213 l\341\273\227i n\303\272t) --- */\n"
"QWidget#footerContainer {\n"
"    background-color: #ffffff;\n"
"    border-top: 1px solid #dddddd;\n"
"}\n"
"\n"
"/* --- GROUP BOX --- */\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin-top: 15px;\n"
"    padding-top: 20px;\n"
"    padding-bottom: 15px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px"
                        ";\n"
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
"    color: #333333;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    color: #333333;\n"
"}\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* Username Label (Read-only look) */\n"
"QLabel#txtUsername {\n"
"    color: #555555;\n"
"    font-weight: bold;\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* --- BUTTONS (Quan tr\341\273\215ng: Selector ph\341\272\243i r\303\265 r\303\240ng) --- */\n"
"QPushButton {\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
""
                        "    min-width: 100px;\n"
"    color: white;\n"
"}\n"
"\n"
"/* N\303\272t Save (Xanh Ng\341\273\215c) */\n"
"QPushButton#btnSave {\n"
"    background-color: #20B2AA;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"QPushButton#btnSave:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"QPushButton#btnSave:pressed {\n"
"    background-color: #0e6b65;\n"
"}\n"
"\n"
"/* N\303\272t Cancel (\304\220\341\273\217) */\n"
"QPushButton#btnCancel {\n"
"    background-color: #e74c3c;\n"
"    border: 2px solid #e74c3c;\n"
"}\n"
"QPushButton#btnCancel:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton#btnCancel:pressed {\n"
"    background-color: #922b21;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(userUpdateInfo);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(userUpdateInfo);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        labelTitle = new QLabel(headerContainer);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;"));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(labelTitle);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(userUpdateInfo);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(15);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 10, 20, 10);
        grpPersonal = new QGroupBox(bodyContainer);
        grpPersonal->setObjectName("grpPersonal");
        formLayout = new QFormLayout(grpPersonal);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        lblUsername = new QLabel(grpPersonal);
        lblUsername->setObjectName("lblUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        txtUsername = new QLabel(grpPersonal);
        txtUsername->setObjectName("txtUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, txtUsername);

        lblFullname = new QLabel(grpPersonal);
        lblFullname->setObjectName("lblFullname");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lblFullname);

        txtFullname = new QLineEdit(grpPersonal);
        txtFullname->setObjectName("txtFullname");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtFullname);

        lblEmail = new QLabel(grpPersonal);
        lblEmail->setObjectName("lblEmail");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, lblEmail);

        txtEmail = new QLineEdit(grpPersonal);
        txtEmail->setObjectName("txtEmail");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, txtEmail);

        lblPhone = new QLabel(grpPersonal);
        lblPhone->setObjectName("lblPhone");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhone);

        txtPhone = new QLineEdit(grpPersonal);
        txtPhone->setObjectName("txtPhone");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, txtPhone);


        verticalLayout_Body->addWidget(grpPersonal);

        grpPassword = new QGroupBox(bodyContainer);
        grpPassword->setObjectName("grpPassword");
        grpPassword->setCheckable(true);
        grpPassword->setChecked(false);
        formLayoutPassword = new QFormLayout(grpPassword);
        formLayoutPassword->setObjectName("formLayoutPassword");
        formLayoutPassword->setHorizontalSpacing(15);
        formLayoutPassword->setVerticalSpacing(15);
        lblOldPass = new QLabel(grpPassword);
        lblOldPass->setObjectName("lblOldPass");

        formLayoutPassword->setWidget(0, QFormLayout::ItemRole::LabelRole, lblOldPass);

        txtOldPass = new QLineEdit(grpPassword);
        txtOldPass->setObjectName("txtOldPass");
        txtOldPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(0, QFormLayout::ItemRole::FieldRole, txtOldPass);

        lblNewPass = new QLabel(grpPassword);
        lblNewPass->setObjectName("lblNewPass");

        formLayoutPassword->setWidget(1, QFormLayout::ItemRole::LabelRole, lblNewPass);

        txtNewPass = new QLineEdit(grpPassword);
        txtNewPass->setObjectName("txtNewPass");
        txtNewPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(1, QFormLayout::ItemRole::FieldRole, txtNewPass);

        lblConfirmPass = new QLabel(grpPassword);
        lblConfirmPass->setObjectName("lblConfirmPass");

        formLayoutPassword->setWidget(2, QFormLayout::ItemRole::LabelRole, lblConfirmPass);

        txtConfirmPass = new QLineEdit(grpPassword);
        txtConfirmPass->setObjectName("txtConfirmPass");
        txtConfirmPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(2, QFormLayout::ItemRole::FieldRole, txtConfirmPass);


        verticalLayout_Body->addWidget(grpPassword);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Body->addItem(verticalSpacer);


        verticalLayout->addWidget(bodyContainer);

        footerContainer = new QWidget(userUpdateInfo);
        footerContainer->setObjectName("footerContainer");
        horizontalLayout = new QHBoxLayout(footerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 10, -1, 10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(footerContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(footerContainer);
        btnSave->setObjectName("btnSave");
        btnSave->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addWidget(footerContainer);


        retranslateUi(userUpdateInfo);

        QMetaObject::connectSlotsByName(userUpdateInfo);
    } // setupUi

    void retranslateUi(QDialog *userUpdateInfo)
    {
        userUpdateInfo->setWindowTitle(QCoreApplication::translate("userUpdateInfo", "Update User Info", nullptr));
        labelTitle->setText(QCoreApplication::translate("userUpdateInfo", "C\341\272\254P NH\341\272\254T TH\303\224NG TIN", nullptr));
        grpPersonal->setTitle(QCoreApplication::translate("userUpdateInfo", "Personal Information", nullptr));
        lblUsername->setText(QCoreApplication::translate("userUpdateInfo", "Username:", nullptr));
        txtUsername->setText(QCoreApplication::translate("userUpdateInfo", "User123", nullptr));
        lblFullname->setText(QCoreApplication::translate("userUpdateInfo", "Fullname:", nullptr));
        txtFullname->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Enter your full name", nullptr));
        lblEmail->setText(QCoreApplication::translate("userUpdateInfo", "Email:", nullptr));
        txtEmail->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Enter your email", nullptr));
        lblPhone->setText(QCoreApplication::translate("userUpdateInfo", "Phone:", nullptr));
        txtPhone->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Enter phone number", nullptr));
        grpPassword->setTitle(QCoreApplication::translate("userUpdateInfo", "Change Password (Optional)", nullptr));
        lblOldPass->setText(QCoreApplication::translate("userUpdateInfo", "Old Password:", nullptr));
        txtOldPass->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Enter current password", nullptr));
        lblNewPass->setText(QCoreApplication::translate("userUpdateInfo", "New Password:", nullptr));
        txtNewPass->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Enter new password", nullptr));
        lblConfirmPass->setText(QCoreApplication::translate("userUpdateInfo", "Confirm:", nullptr));
        txtConfirmPass->setPlaceholderText(QCoreApplication::translate("userUpdateInfo", "Repeat new password", nullptr));
        btnCancel->setText(QCoreApplication::translate("userUpdateInfo", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("userUpdateInfo", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userUpdateInfo: public Ui_userUpdateInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERUPDATEINFO_H
