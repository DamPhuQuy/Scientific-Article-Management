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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelHeader;
    QGroupBox *groupInfo;
    QVBoxLayout *verticalLayout_Info;
    QLabel *labelDetailName;
    QFrame *line;
    QFormLayout *formLayoutDetails;
    QLabel *lblID;
    QLabel *labelDetailId;
    QLabel *lblCountry;
    QLabel *labelDetailCountry;
    QLabel *lblField;
    QLabel *labelDetailField;
    QLabel *lblPubs;
    QLabel *labelDetailPubCount;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;

    void setupUi(QDialog *AuthorDetailsDialog)
    {
        if (AuthorDetailsDialog->objectName().isEmpty())
            AuthorDetailsDialog->setObjectName("AuthorDetailsDialog");
        AuthorDetailsDialog->resize(500, 400);
        AuthorDetailsDialog->setMinimumSize(QSize(500, 400));
        AuthorDetailsDialog->setModal(true);
        AuthorDetailsDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#AuthorDetailsDialog {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #FFC085;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- GROUP BOX (TH\341\272\272 TH\303\224NG TIN) --- */\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin: 10px;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"/* --- LABELS --- */\n"
"QLabel {\n"
"    color: #333333;\n"
"}\n"
"/* Nh\303\243n ti\303\252u \304\221\341\273\201 field (ID, Country...) */\n"
"QLabel#lblID, QLabel#lblCountry, QLabel#lblField, QLabel#lblPubs {\n"
"    color: #555555;\n"
"    font-weight: bold;\n"
"}\n"
"/* T\303\252n t\303\241c gi\341\272\243 n\341\273\225i b\341\272\255t */\n"
"QLabel#labelDetailName {\n"
"    color: #20B2AA;\n"
"    font-weight: 900;\n"
"    font-size: 18px;\n"
"    margin-bottom: 10px;\n"
"}\n"
"/* Gi\303\241 tr\341\273\213"
                        " chi ti\341\272\277t */\n"
"QLabel#labelDetailId, QLabel#labelDetailCountry, QLabel#labelDetailField, QLabel#labelDetailPubCount {\n"
"    color: #000000;\n"
"    font-weight: normal;\n"
"    background-color: #f9f9f9; /* N\341\273\201n nh\341\272\271 \304\221\341\273\203 d\341\273\205 nh\303\254n */\n"
"    border: 1px solid #eeeeee;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* --- BUTTON --- */\n"
"QPushButton {\n"
"    background-color: #20B2AA;\n"
"    border: 2px solid #20B2AA;\n"
"    border-radius: 6px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    padding: 8px 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0e6b65;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(AuthorDetailsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(AuthorDetailsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        labelHeader = new QLabel(headerContainer);
        labelHeader->setObjectName("labelHeader");
        labelHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:18px;background:transparent;padding-left:10px;"));
        labelHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(labelHeader);


        verticalLayout->addWidget(headerContainer);

        groupInfo = new QGroupBox(AuthorDetailsDialog);
        groupInfo->setObjectName("groupInfo");
        verticalLayout_Info = new QVBoxLayout(groupInfo);
        verticalLayout_Info->setSpacing(15);
        verticalLayout_Info->setObjectName("verticalLayout_Info");
        labelDetailName = new QLabel(groupInfo);
        labelDetailName->setObjectName("labelDetailName");
        labelDetailName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Info->addWidget(labelDetailName);

        line = new QFrame(groupInfo);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Info->addWidget(line);

        formLayoutDetails = new QFormLayout();
        formLayoutDetails->setObjectName("formLayoutDetails");
        formLayoutDetails->setHorizontalSpacing(20);
        formLayoutDetails->setVerticalSpacing(15);
        lblID = new QLabel(groupInfo);
        lblID->setObjectName("lblID");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::LabelRole, lblID);

        labelDetailId = new QLabel(groupInfo);
        labelDetailId->setObjectName("labelDetailId");

        formLayoutDetails->setWidget(0, QFormLayout::ItemRole::FieldRole, labelDetailId);

        lblCountry = new QLabel(groupInfo);
        lblCountry->setObjectName("lblCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::LabelRole, lblCountry);

        labelDetailCountry = new QLabel(groupInfo);
        labelDetailCountry->setObjectName("labelDetailCountry");

        formLayoutDetails->setWidget(1, QFormLayout::ItemRole::FieldRole, labelDetailCountry);

        lblField = new QLabel(groupInfo);
        lblField->setObjectName("lblField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::LabelRole, lblField);

        labelDetailField = new QLabel(groupInfo);
        labelDetailField->setObjectName("labelDetailField");

        formLayoutDetails->setWidget(2, QFormLayout::ItemRole::FieldRole, labelDetailField);

        lblPubs = new QLabel(groupInfo);
        lblPubs->setObjectName("lblPubs");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::LabelRole, lblPubs);

        labelDetailPubCount = new QLabel(groupInfo);
        labelDetailPubCount->setObjectName("labelDetailPubCount");

        formLayoutDetails->setWidget(3, QFormLayout::ItemRole::FieldRole, labelDetailPubCount);


        verticalLayout_Info->addLayout(formLayoutDetails);


        verticalLayout->addWidget(groupInfo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(AuthorDetailsDialog);
        okBtn->setObjectName("okBtn");
        okBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(okBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AuthorDetailsDialog);
        QObject::connect(okBtn, &QPushButton::clicked, AuthorDetailsDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(AuthorDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthorDetailsDialog)
    {
        AuthorDetailsDialog->setWindowTitle(QCoreApplication::translate("AuthorDetailsDialog", "Author Details", nullptr));
        labelHeader->setText(QCoreApplication::translate("AuthorDetailsDialog", "TH\303\224NG TIN T\303\201C GI\341\272\242", nullptr));
        labelDetailName->setText(QCoreApplication::translate("AuthorDetailsDialog", "Author Name Placeholder", nullptr));
        lblID->setText(QCoreApplication::translate("AuthorDetailsDialog", "ID:", nullptr));
        labelDetailId->setText(QCoreApplication::translate("AuthorDetailsDialog", "--", nullptr));
        lblCountry->setText(QCoreApplication::translate("AuthorDetailsDialog", "Country:", nullptr));
        labelDetailCountry->setText(QCoreApplication::translate("AuthorDetailsDialog", "--", nullptr));
        lblField->setText(QCoreApplication::translate("AuthorDetailsDialog", "Field of Study:", nullptr));
        labelDetailField->setText(QCoreApplication::translate("AuthorDetailsDialog", "--", nullptr));
        lblPubs->setText(QCoreApplication::translate("AuthorDetailsDialog", "Total Publications:", nullptr));
        labelDetailPubCount->setText(QCoreApplication::translate("AuthorDetailsDialog", "--", nullptr));
        okBtn->setText(QCoreApplication::translate("AuthorDetailsDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorDetailsDialog: public Ui_AuthorDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORDETAILSDIALOG_H
