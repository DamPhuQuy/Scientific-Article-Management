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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_userUpdateInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QFormLayout *formLayout;
    QLabel *lblFullname;
    QLineEdit *txtFullname;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QLabel *lblPhone;
    QLineEdit *txtPhone;
    QLabel *lblUsername;
    QLabel *txtUsername;
    QFrame *line;
    QLabel *labelPassword;
    QFormLayout *formLayoutPassword;
    QLabel *lblOldPass;
    QLineEdit *txtOldPass;
    QLabel *lblNewPass;
    QLineEdit *txtNewPass;
    QLabel *lblConfirmPass;
    QLineEdit *txtConfirmPass;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *userUpdateInfo)
    {
        if (userUpdateInfo->objectName().isEmpty())
            userUpdateInfo->setObjectName("userUpdateInfo");
        userUpdateInfo->resize(400, 450);
        verticalLayout = new QVBoxLayout(userUpdateInfo);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(userUpdateInfo);
        labelTitle->setObjectName("labelTitle");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        lblFullname = new QLabel(userUpdateInfo);
        lblFullname->setObjectName("lblFullname");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lblFullname);

        txtFullname = new QLineEdit(userUpdateInfo);
        txtFullname->setObjectName("txtFullname");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtFullname);

        lblEmail = new QLabel(userUpdateInfo);
        lblEmail->setObjectName("lblEmail");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, lblEmail);

        txtEmail = new QLineEdit(userUpdateInfo);
        txtEmail->setObjectName("txtEmail");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, txtEmail);

        lblPhone = new QLabel(userUpdateInfo);
        lblPhone->setObjectName("lblPhone");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhone);

        txtPhone = new QLineEdit(userUpdateInfo);
        txtPhone->setObjectName("txtPhone");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, txtPhone);

        lblUsername = new QLabel(userUpdateInfo);
        lblUsername->setObjectName("lblUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        txtUsername = new QLabel(userUpdateInfo);
        txtUsername->setObjectName("txtUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, txtUsername);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(userUpdateInfo);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        labelPassword = new QLabel(userUpdateInfo);
        labelPassword->setObjectName("labelPassword");
        QFont font1;
        font1.setBold(true);
        labelPassword->setFont(font1);

        verticalLayout->addWidget(labelPassword);

        formLayoutPassword = new QFormLayout();
        formLayoutPassword->setObjectName("formLayoutPassword");
        lblOldPass = new QLabel(userUpdateInfo);
        lblOldPass->setObjectName("lblOldPass");

        formLayoutPassword->setWidget(0, QFormLayout::ItemRole::LabelRole, lblOldPass);

        txtOldPass = new QLineEdit(userUpdateInfo);
        txtOldPass->setObjectName("txtOldPass");
        txtOldPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(0, QFormLayout::ItemRole::FieldRole, txtOldPass);

        lblNewPass = new QLabel(userUpdateInfo);
        lblNewPass->setObjectName("lblNewPass");

        formLayoutPassword->setWidget(1, QFormLayout::ItemRole::LabelRole, lblNewPass);

        txtNewPass = new QLineEdit(userUpdateInfo);
        txtNewPass->setObjectName("txtNewPass");
        txtNewPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(1, QFormLayout::ItemRole::FieldRole, txtNewPass);

        lblConfirmPass = new QLabel(userUpdateInfo);
        lblConfirmPass->setObjectName("lblConfirmPass");

        formLayoutPassword->setWidget(2, QFormLayout::ItemRole::LabelRole, lblConfirmPass);

        txtConfirmPass = new QLineEdit(userUpdateInfo);
        txtConfirmPass->setObjectName("txtConfirmPass");
        txtConfirmPass->setEchoMode(QLineEdit::EchoMode::Password);

        formLayoutPassword->setWidget(2, QFormLayout::ItemRole::FieldRole, txtConfirmPass);


        verticalLayout->addLayout(formLayoutPassword);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(userUpdateInfo);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(userUpdateInfo);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(userUpdateInfo);

        QMetaObject::connectSlotsByName(userUpdateInfo);
    } // setupUi

    void retranslateUi(QDialog *userUpdateInfo)
    {
        userUpdateInfo->setWindowTitle(QCoreApplication::translate("userUpdateInfo", "Update User Info", nullptr));
        labelTitle->setText(QCoreApplication::translate("userUpdateInfo", "Update Information", nullptr));
        lblFullname->setText(QCoreApplication::translate("userUpdateInfo", "Fullname:", nullptr));
        lblEmail->setText(QCoreApplication::translate("userUpdateInfo", "Email:", nullptr));
        lblPhone->setText(QCoreApplication::translate("userUpdateInfo", "Phone:", nullptr));
        lblUsername->setText(QCoreApplication::translate("userUpdateInfo", "Username", nullptr));
        txtUsername->setText(QCoreApplication::translate("userUpdateInfo", "TextLabel", nullptr));
        labelPassword->setText(QCoreApplication::translate("userUpdateInfo", "Change Password (Optional)", nullptr));
        lblOldPass->setText(QCoreApplication::translate("userUpdateInfo", "Old Password:", nullptr));
        lblNewPass->setText(QCoreApplication::translate("userUpdateInfo", "New Password:", nullptr));
        lblConfirmPass->setText(QCoreApplication::translate("userUpdateInfo", "Confirm Password:", nullptr));
        btnCancel->setText(QCoreApplication::translate("userUpdateInfo", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("userUpdateInfo", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userUpdateInfo: public Ui_userUpdateInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERUPDATEINFO_H
