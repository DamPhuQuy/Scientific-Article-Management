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

QT_BEGIN_NAMESPACE

class Ui_AuthorDetailsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelDetailName;
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *AuthorDetailsDialog)
    {
        if (AuthorDetailsDialog->objectName().isEmpty())
            AuthorDetailsDialog->setObjectName("AuthorDetailsDialog");
        AuthorDetailsDialog->resize(400, 300);
        AuthorDetailsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AuthorDetailsDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelDetailName = new QLabel(AuthorDetailsDialog);
        labelDetailName->setObjectName("labelDetailName");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        labelDetailName->setFont(font);
        labelDetailName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelDetailName);

        formLayoutDetails = new QFormLayout();
        formLayoutDetails->setObjectName("formLayoutDetails");
        lblID = new QLabel(AuthorDetailsDialog);
        lblID->setObjectName("lblID");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblID);

        labelDetailId = new QLabel(AuthorDetailsDialog);
        labelDetailId->setObjectName("labelDetailId");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailId);

        lblCountry = new QLabel(AuthorDetailsDialog);
        lblCountry->setObjectName("lblCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblCountry);

        labelDetailCountry = new QLabel(AuthorDetailsDialog);
        labelDetailCountry->setObjectName("labelDetailCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailCountry);

        lblField = new QLabel(AuthorDetailsDialog);
        lblField->setObjectName("lblField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblField);

        labelDetailField = new QLabel(AuthorDetailsDialog);
        labelDetailField->setObjectName("labelDetailField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailField);

        lblPubs = new QLabel(AuthorDetailsDialog);
        lblPubs->setObjectName("lblPubs");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPubs);

        labelDetailPubCount = new QLabel(AuthorDetailsDialog);
        labelDetailPubCount->setObjectName("labelDetailPubCount");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPubCount);


        verticalLayout->addLayout(formLayoutDetails);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(AuthorDetailsDialog);
        okBtn->setObjectName("okBtn");

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(AuthorDetailsDialog);

        QMetaObject::connectSlotsByName(AuthorDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthorDetailsDialog)
    {
        AuthorDetailsDialog->setWindowTitle(QCoreApplication::translate("AuthorDetailsDialog", "Author Details", nullptr));
        labelDetailName->setText(QCoreApplication::translate("AuthorDetailsDialog", "Author Name", nullptr));
        lblID->setText(QCoreApplication::translate("AuthorDetailsDialog", "ID:", nullptr));
        labelDetailId->setText(QString());
        lblCountry->setText(QCoreApplication::translate("AuthorDetailsDialog", "Country:", nullptr));
        labelDetailCountry->setText(QString());
        lblField->setText(QCoreApplication::translate("AuthorDetailsDialog", "Field of Study:", nullptr));
        labelDetailField->setText(QString());
        lblPubs->setText(QCoreApplication::translate("AuthorDetailsDialog", "Total Publications:", nullptr));
        labelDetailPubCount->setText(QString());
        okBtn->setText(QCoreApplication::translate("AuthorDetailsDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorDetailsDialog: public Ui_AuthorDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORDETAILSDIALOG_H
