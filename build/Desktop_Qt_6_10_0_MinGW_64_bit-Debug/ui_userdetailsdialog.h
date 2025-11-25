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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
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
    QHBoxLayout *horizontalLayout;
    QLabel *labelDetailName;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_2;
    QWidget *infoBox;
    QFormLayout *formLayoutDetails;
    QLabel *lblUsername;
    QLabel *labelDetailUsername;
    QLabel *lblFullName;
    QLabel *labelDetailFullname;
    QLabel *lblEmail;
    QLabel *labelDetailEmail;
    QLabel *lblPhoneNumer;
    QLabel *labelDetailPhoneNumber;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *UserDetailsDialog)
    {
        if (UserDetailsDialog->objectName().isEmpty())
            UserDetailsDialog->setObjectName("UserDetailsDialog");
        UserDetailsDialog->resize(450, 400);
        UserDetailsDialog->setStyleSheet(QString::fromUtf8("QDialog#UserDetailsDialog{background-color:#f4f7f6;border:4px solid #FFC085;}QWidget{font-family:\"Segoe UI\",Arial,sans-serif;font-size:14px;}"));
        verticalLayout = new QVBoxLayout(UserDetailsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(UserDetailsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout = new QHBoxLayout(headerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        labelDetailName = new QLabel(headerContainer);
        labelDetailName->setObjectName("labelDetailName");
        labelDetailName->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:18px;background:transparent;"));
        labelDetailName->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(labelDetailName);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(UserDetailsDialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_2 = new QVBoxLayout(bodyContainer);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 10);
        infoBox = new QWidget(bodyContainer);
        infoBox->setObjectName("infoBox");
        infoBox->setStyleSheet(QString::fromUtf8("QWidget#infoBox{background-color:#ffffff;border:1px solid #e0e0e0;border-radius:8px;}QLabel{padding:5px;}"));
        formLayoutDetails = new QFormLayout(infoBox);
        formLayoutDetails->setObjectName("formLayoutDetails");
        formLayoutDetails->setHorizontalSpacing(15);
        formLayoutDetails->setVerticalSpacing(15);
        formLayoutDetails->setContentsMargins(20, 20, 20, 20);
        lblUsername = new QLabel(infoBox);
        lblUsername->setObjectName("lblUsername");
        lblUsername->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        labelDetailUsername = new QLabel(infoBox);
        labelDetailUsername->setObjectName("labelDetailUsername");
        labelDetailUsername->setStyleSheet(QString::fromUtf8("color:#333333;font-weight:bold;"));

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailUsername);

        lblFullName = new QLabel(infoBox);
        lblFullName->setObjectName("lblFullName");
        lblFullName->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblFullName);

        labelDetailFullname = new QLabel(infoBox);
        labelDetailFullname->setObjectName("labelDetailFullname");
        labelDetailFullname->setStyleSheet(QString::fromUtf8("color:#333333;"));

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailFullname);

        lblEmail = new QLabel(infoBox);
        lblEmail->setObjectName("lblEmail");
        lblEmail->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblEmail);

        labelDetailEmail = new QLabel(infoBox);
        labelDetailEmail->setObjectName("labelDetailEmail");
        labelDetailEmail->setStyleSheet(QString::fromUtf8("color:#333333;"));

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailEmail);

        lblPhoneNumer = new QLabel(infoBox);
        lblPhoneNumer->setObjectName("lblPhoneNumer");
        lblPhoneNumer->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhoneNumer);

        labelDetailPhoneNumber = new QLabel(infoBox);
        labelDetailPhoneNumber->setObjectName("labelDetailPhoneNumber");
        labelDetailPhoneNumber->setStyleSheet(QString::fromUtf8("color:#333333;"));

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPhoneNumber);


        verticalLayout_2->addWidget(infoBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(bodyContainer);
        okBtn->setObjectName("okBtn");
        okBtn->setMinimumSize(QSize(100, 40));
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(bodyContainer);


        retranslateUi(UserDetailsDialog);
        QObject::connect(okBtn, &QPushButton::clicked, UserDetailsDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(UserDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDetailsDialog)
    {
        UserDetailsDialog->setWindowTitle(QCoreApplication::translate("UserDetailsDialog", "Author Details", nullptr));
        labelDetailName->setText(QCoreApplication::translate("UserDetailsDialog", "TH\303\224NG TIN NG\306\257\341\273\234I D\303\231NG", nullptr));
        lblUsername->setText(QCoreApplication::translate("UserDetailsDialog", "Username:", nullptr));
        labelDetailUsername->setText(QCoreApplication::translate("UserDetailsDialog", "N/A", nullptr));
        lblFullName->setText(QCoreApplication::translate("UserDetailsDialog", "Fullname:", nullptr));
        labelDetailFullname->setText(QCoreApplication::translate("UserDetailsDialog", "N/A", nullptr));
        lblEmail->setText(QCoreApplication::translate("UserDetailsDialog", "Email:", nullptr));
        labelDetailEmail->setText(QCoreApplication::translate("UserDetailsDialog", "N/A", nullptr));
        lblPhoneNumer->setText(QCoreApplication::translate("UserDetailsDialog", "Phone Number:", nullptr));
        labelDetailPhoneNumber->setText(QCoreApplication::translate("UserDetailsDialog", "N/A", nullptr));
        okBtn->setText(QCoreApplication::translate("UserDetailsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDetailsDialog: public Ui_UserDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDETAILSDIALOG_H
