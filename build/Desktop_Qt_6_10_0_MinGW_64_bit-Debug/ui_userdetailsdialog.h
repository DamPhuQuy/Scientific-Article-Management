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

QT_BEGIN_NAMESPACE

class Ui_UserDetailsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelDetailName;
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *UserDetailsDialog)
    {
        if (UserDetailsDialog->objectName().isEmpty())
            UserDetailsDialog->setObjectName("UserDetailsDialog");
        UserDetailsDialog->resize(400, 300);
        UserDetailsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(UserDetailsDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelDetailName = new QLabel(UserDetailsDialog);
        labelDetailName->setObjectName("labelDetailName");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelDetailName->setFont(font);
        labelDetailName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelDetailName);

        formLayoutDetails = new QFormLayout();
        formLayoutDetails->setObjectName("formLayoutDetails");
        lblUsername = new QLabel(UserDetailsDialog);
        lblUsername->setObjectName("lblUsername");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        labelDetailUsername = new QLabel(UserDetailsDialog);
        labelDetailUsername->setObjectName("labelDetailUsername");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailUsername);

        lblFullName = new QLabel(UserDetailsDialog);
        lblFullName->setObjectName("lblFullName");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblFullName);

        labelDetailFullname = new QLabel(UserDetailsDialog);
        labelDetailFullname->setObjectName("labelDetailFullname");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailFullname);

        lblEmail = new QLabel(UserDetailsDialog);
        lblEmail->setObjectName("lblEmail");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblEmail);

        labelDetailEmail = new QLabel(UserDetailsDialog);
        labelDetailEmail->setObjectName("labelDetailEmail");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailEmail);

        lblPhoneNumer = new QLabel(UserDetailsDialog);
        lblPhoneNumer->setObjectName("lblPhoneNumer");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPhoneNumer);

        labelDetailPhoneNumber = new QLabel(UserDetailsDialog);
        labelDetailPhoneNumber->setObjectName("labelDetailPhoneNumber");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPhoneNumber);


        verticalLayout->addLayout(formLayoutDetails);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(UserDetailsDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(UserDetailsDialog);

        QMetaObject::connectSlotsByName(UserDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDetailsDialog)
    {
        UserDetailsDialog->setWindowTitle(QCoreApplication::translate("UserDetailsDialog", "Author Details", nullptr));
        labelDetailName->setText(QCoreApplication::translate("UserDetailsDialog", "User Infomation", nullptr));
        lblUsername->setText(QCoreApplication::translate("UserDetailsDialog", "Username:", nullptr));
        labelDetailUsername->setText(QString());
        lblFullName->setText(QCoreApplication::translate("UserDetailsDialog", "Fullname:", nullptr));
        labelDetailFullname->setText(QString());
        lblEmail->setText(QCoreApplication::translate("UserDetailsDialog", "Email:", nullptr));
        labelDetailEmail->setText(QString());
        lblPhoneNumer->setText(QCoreApplication::translate("UserDetailsDialog", "Phone Number:", nullptr));
        labelDetailPhoneNumber->setText(QString());
        okBtn->setText(QCoreApplication::translate("UserDetailsDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDetailsDialog: public Ui_UserDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDETAILSDIALOG_H
