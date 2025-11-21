/********************************************************************************
** Form generated from reading UI file 'authordetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORDETAILSDIALOG_H
#define UI_AUTHORDETAILSDIALOG_H

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

class Ui_AuthorDetailsDialog
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelDetailName;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QFormLayout *formLayoutDetails;
    QLabel *lblID;
    QLabel *labelDetailId;
    QLabel *lblCountry;
    QLabel *labelDetailCountry;
    QLabel *lblField;
    QLabel *labelDetailField;
    QLabel *lblPubs;
    QLabel *labelDetailPubCount;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *AuthorDetailsDialog)
    {
        if (AuthorDetailsDialog->objectName().isEmpty())
            AuthorDetailsDialog->setObjectName("AuthorDetailsDialog");
        AuthorDetailsDialog->resize(450, 380);
        AuthorDetailsDialog->setModal(true);
        AuthorDetailsDialog->setStyleSheet(QString::fromUtf8("QDialog#AuthorDetailsDialog { background-color: #f4f7f6; }\n"
"QWidget { font-family: \"Segoe UI\", Arial, sans-serif; }\n"
"\n"
"/* HEADER */\n"
"QWidget#headerContainer { background-color: #00264d; border-left: 10px solid #FFD700; border-bottom: 5px solid #4169E1; }\n"
"QLabel#labelDetailName { color: #ffffff; font-size: 18px; font-weight: 900; background-color: transparent; padding-left: 10px; }\n"
"\n"
"/* BODY */\n"
"QWidget#bodyContainer { background-color: #ffffff; border: 2px solid #20B2AA; border-radius: 8px; }\n"
"\n"
"/* LABELS */\n"
"QLabel { font-size: 14px; color: #555; font-weight: bold; }\n"
"/* C\303\241c label hi\341\273\203n th\341\273\213 d\341\273\257 li\341\273\207u (ID, Country...) th\303\254 \304\221\341\273\203 ch\341\273\257 th\306\260\341\273\235ng, m\303\240u \304\221\341\272\255m */\n"
"QLabel#labelDetailId, QLabel#labelDetailCountry, QLabel#labelDetailField, QLabel#labelDetailPubCount { color: #00264d; font-weight: normal; }\n"
"\n"
"/* BUTTON OK (XANH NG\341\273\214C) */\n"
"QPus"
                        "hButton#okBtn { background-color: #20B2AA; border: 2px solid #20B2AA; border-radius: 6px; font-weight: bold; padding: 8px 20px; color: white; min-width: 80px; }\n"
"QPushButton#okBtn:hover { background-color: #17a098; border-color: #17a098; }"));
        mainLayout = new QVBoxLayout(AuthorDetailsDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(AuthorDetailsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, -1, -1, -1);
        labelDetailName = new QLabel(headerContainer);
        labelDetailName->setObjectName("labelDetailName");
        labelDetailName->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);

        horizontalLayout_Header->addWidget(labelDetailName);


        mainLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(AuthorDetailsDialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(20);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(30, 30, 30, 20);
        formLayoutDetails = new QFormLayout();
        formLayoutDetails->setObjectName("formLayoutDetails");
        formLayoutDetails->setHorizontalSpacing(20);
        formLayoutDetails->setVerticalSpacing(15);
        lblID = new QLabel(bodyContainer);
        lblID->setObjectName("lblID");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblID);

        labelDetailId = new QLabel(bodyContainer);
        labelDetailId->setObjectName("labelDetailId");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailId);

        lblCountry = new QLabel(bodyContainer);
        lblCountry->setObjectName("lblCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblCountry);

        labelDetailCountry = new QLabel(bodyContainer);
        labelDetailCountry->setObjectName("labelDetailCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailCountry);

        lblField = new QLabel(bodyContainer);
        lblField->setObjectName("lblField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblField);

        labelDetailField = new QLabel(bodyContainer);
        labelDetailField->setObjectName("labelDetailField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailField);

        lblPubs = new QLabel(bodyContainer);
        lblPubs->setObjectName("lblPubs");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPubs);

        labelDetailPubCount = new QLabel(bodyContainer);
        labelDetailPubCount->setObjectName("labelDetailPubCount");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPubCount);


        verticalLayout_Body->addLayout(formLayoutDetails);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Body->addItem(verticalSpacer);

        horizontalLayout_Footer = new QHBoxLayout();
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        okBtn = new QPushButton(bodyContainer);
        okBtn->setObjectName("okBtn");
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Footer->addWidget(okBtn);


        verticalLayout_Body->addLayout(horizontalLayout_Footer);


        mainLayout->addWidget(bodyContainer);


        retranslateUi(AuthorDetailsDialog);

        QMetaObject::connectSlotsByName(AuthorDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthorDetailsDialog)
    {
        AuthorDetailsDialog->setWindowTitle(QCoreApplication::translate("AuthorDetailsDialog", "Author Details", nullptr));
        labelDetailName->setText(QCoreApplication::translate("AuthorDetailsDialog", "[Author Name Here]", nullptr));
        lblID->setText(QCoreApplication::translate("AuthorDetailsDialog", "ID:", nullptr));
        labelDetailId->setText(QCoreApplication::translate("AuthorDetailsDialog", "...", nullptr));
        lblCountry->setText(QCoreApplication::translate("AuthorDetailsDialog", "Country:", nullptr));
        labelDetailCountry->setText(QCoreApplication::translate("AuthorDetailsDialog", "...", nullptr));
        lblField->setText(QCoreApplication::translate("AuthorDetailsDialog", "Field of Study:", nullptr));
        labelDetailField->setText(QCoreApplication::translate("AuthorDetailsDialog", "...", nullptr));
        lblPubs->setText(QCoreApplication::translate("AuthorDetailsDialog", "Total Publications:", nullptr));
        labelDetailPubCount->setText(QCoreApplication::translate("AuthorDetailsDialog", "0", nullptr));
        okBtn->setText(QCoreApplication::translate("AuthorDetailsDialog", "\304\220\303\263ng", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorDetailsDialog: public Ui_AuthorDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORDETAILSDIALOG_H
