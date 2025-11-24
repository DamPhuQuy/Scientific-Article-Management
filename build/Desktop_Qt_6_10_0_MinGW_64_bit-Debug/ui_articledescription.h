/********************************************************************************
** Form generated from reading UI file 'articledescription.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEDESCRIPTION_H
#define UI_ARTICLEDESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleDescriptionDialog
{
public:
    QVBoxLayout *verticalLayoutMain;
    QLabel *lblHeader;
    QGroupBox *groupCommon;
    QFormLayout *formLayoutCommon;
    QLabel *lblTitle;
    QLabel *lblAuthors;
    QLabel *lblAbstract;
    QPlainTextEdit *inputAbstract;
    QLabel *lblVenue;
    QHBoxLayout *layoutVenueYear;
    QLineEdit *inputVenue;
    QLabel *lblYear;
    QSpinBox *inputYear;
    QLabel *lblStatus;
    QComboBox *comboStatus;
    QLabel *lblCitation;
    QSpinBox *inputCitation;
    QLabel *label;
    QListView *refsList;
    QListView *authorsList;
    QPlainTextEdit *titleText;
    QHBoxLayout *layoutTypeSelect;
    QLabel *lblTypeSelect;
    QComboBox *comboType;
    QStackedWidget *stackSpecifics;
    QWidget *pageSCIE;
    QFormLayout *formLayoutSCIE;
    QLabel *lblIF;
    QDoubleSpinBox *inputIF;
    QLabel *lblQRank;
    QSpinBox *inputQRank;
    QWidget *pageSCOPUS;
    QFormLayout *formLayoutSCOPUS;
    QLabel *lblSJR;
    QDoubleSpinBox *inputSJR;
    QLabel *lblHIndex;
    QSpinBox *inputHIndex;
    QWidget *pageCONFERENCE;
    QFormLayout *formLayoutCONF;
    QLabel *lblConfRank;
    QLineEdit *inputConfRank;
    QLabel *lblLocation;
    QLineEdit *inputLocation;
    QLabel *lblRate;
    QDoubleSpinBox *inputAcceptRate;
    QWidget *pageOTHER;
    QVBoxLayout *verticalOther;
    QLabel *lblOtherMsg;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *layoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;

    void setupUi(QDialog *ArticleDescriptionDialog)
    {
        if (ArticleDescriptionDialog->objectName().isEmpty())
            ArticleDescriptionDialog->setObjectName("ArticleDescriptionDialog");
        ArticleDescriptionDialog->resize(500, 700);
        verticalLayoutMain = new QVBoxLayout(ArticleDescriptionDialog);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        lblHeader = new QLabel(ArticleDescriptionDialog);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutMain->addWidget(lblHeader);

        groupCommon = new QGroupBox(ArticleDescriptionDialog);
        groupCommon->setObjectName("groupCommon");
        formLayoutCommon = new QFormLayout(groupCommon);
        formLayoutCommon->setObjectName("formLayoutCommon");
        lblTitle = new QLabel(groupCommon);
        lblTitle->setObjectName("lblTitle");

        formLayoutCommon->setWidget(0, QFormLayout::ItemRole::LabelRole, lblTitle);

        lblAuthors = new QLabel(groupCommon);
        lblAuthors->setObjectName("lblAuthors");

        formLayoutCommon->setWidget(1, QFormLayout::ItemRole::LabelRole, lblAuthors);

        lblAbstract = new QLabel(groupCommon);
        lblAbstract->setObjectName("lblAbstract");

        formLayoutCommon->setWidget(2, QFormLayout::ItemRole::LabelRole, lblAbstract);

        inputAbstract = new QPlainTextEdit(groupCommon);
        inputAbstract->setObjectName("inputAbstract");

        formLayoutCommon->setWidget(2, QFormLayout::ItemRole::FieldRole, inputAbstract);

        lblVenue = new QLabel(groupCommon);
        lblVenue->setObjectName("lblVenue");

        formLayoutCommon->setWidget(3, QFormLayout::ItemRole::LabelRole, lblVenue);

        layoutVenueYear = new QHBoxLayout();
        layoutVenueYear->setObjectName("layoutVenueYear");
        inputVenue = new QLineEdit(groupCommon);
        inputVenue->setObjectName("inputVenue");

        layoutVenueYear->addWidget(inputVenue);

        lblYear = new QLabel(groupCommon);
        lblYear->setObjectName("lblYear");

        layoutVenueYear->addWidget(lblYear);

        inputYear = new QSpinBox(groupCommon);
        inputYear->setObjectName("inputYear");
        inputYear->setMinimum(1900);
        inputYear->setMaximum(2100);
        inputYear->setValue(2024);

        layoutVenueYear->addWidget(inputYear);


        formLayoutCommon->setLayout(3, QFormLayout::ItemRole::FieldRole, layoutVenueYear);

        lblStatus = new QLabel(groupCommon);
        lblStatus->setObjectName("lblStatus");

        formLayoutCommon->setWidget(4, QFormLayout::ItemRole::LabelRole, lblStatus);

        comboStatus = new QComboBox(groupCommon);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        formLayoutCommon->setWidget(4, QFormLayout::ItemRole::FieldRole, comboStatus);

        lblCitation = new QLabel(groupCommon);
        lblCitation->setObjectName("lblCitation");

        formLayoutCommon->setWidget(5, QFormLayout::ItemRole::LabelRole, lblCitation);

        inputCitation = new QSpinBox(groupCommon);
        inputCitation->setObjectName("inputCitation");
        inputCitation->setMaximum(999999);

        formLayoutCommon->setWidget(5, QFormLayout::ItemRole::FieldRole, inputCitation);

        label = new QLabel(groupCommon);
        label->setObjectName("label");

        formLayoutCommon->setWidget(6, QFormLayout::ItemRole::LabelRole, label);

        refsList = new QListView(groupCommon);
        refsList->setObjectName("refsList");

        formLayoutCommon->setWidget(6, QFormLayout::ItemRole::FieldRole, refsList);

        authorsList = new QListView(groupCommon);
        authorsList->setObjectName("authorsList");

        formLayoutCommon->setWidget(1, QFormLayout::ItemRole::FieldRole, authorsList);

        titleText = new QPlainTextEdit(groupCommon);
        titleText->setObjectName("titleText");

        formLayoutCommon->setWidget(0, QFormLayout::ItemRole::FieldRole, titleText);


        verticalLayoutMain->addWidget(groupCommon);

        layoutTypeSelect = new QHBoxLayout();
        layoutTypeSelect->setObjectName("layoutTypeSelect");
        lblTypeSelect = new QLabel(ArticleDescriptionDialog);
        lblTypeSelect->setObjectName("lblTypeSelect");

        layoutTypeSelect->addWidget(lblTypeSelect);

        comboType = new QComboBox(ArticleDescriptionDialog);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        layoutTypeSelect->addWidget(comboType);


        verticalLayoutMain->addLayout(layoutTypeSelect);

        stackSpecifics = new QStackedWidget(ArticleDescriptionDialog);
        stackSpecifics->setObjectName("stackSpecifics");
        stackSpecifics->setFrameShape(QFrame::Shape::StyledPanel);
        pageSCIE = new QWidget();
        pageSCIE->setObjectName("pageSCIE");
        formLayoutSCIE = new QFormLayout(pageSCIE);
        formLayoutSCIE->setObjectName("formLayoutSCIE");
        lblIF = new QLabel(pageSCIE);
        lblIF->setObjectName("lblIF");

        formLayoutSCIE->setWidget(0, QFormLayout::ItemRole::LabelRole, lblIF);

        inputIF = new QDoubleSpinBox(pageSCIE);
        inputIF->setObjectName("inputIF");
        inputIF->setDecimals(3);

        formLayoutSCIE->setWidget(0, QFormLayout::ItemRole::FieldRole, inputIF);

        lblQRank = new QLabel(pageSCIE);
        lblQRank->setObjectName("lblQRank");

        formLayoutSCIE->setWidget(1, QFormLayout::ItemRole::LabelRole, lblQRank);

        inputQRank = new QSpinBox(pageSCIE);
        inputQRank->setObjectName("inputQRank");
        inputQRank->setMinimum(1);
        inputQRank->setMaximum(4);

        formLayoutSCIE->setWidget(1, QFormLayout::ItemRole::FieldRole, inputQRank);

        stackSpecifics->addWidget(pageSCIE);
        pageSCOPUS = new QWidget();
        pageSCOPUS->setObjectName("pageSCOPUS");
        formLayoutSCOPUS = new QFormLayout(pageSCOPUS);
        formLayoutSCOPUS->setObjectName("formLayoutSCOPUS");
        lblSJR = new QLabel(pageSCOPUS);
        lblSJR->setObjectName("lblSJR");

        formLayoutSCOPUS->setWidget(0, QFormLayout::ItemRole::LabelRole, lblSJR);

        inputSJR = new QDoubleSpinBox(pageSCOPUS);
        inputSJR->setObjectName("inputSJR");
        inputSJR->setDecimals(3);

        formLayoutSCOPUS->setWidget(0, QFormLayout::ItemRole::FieldRole, inputSJR);

        lblHIndex = new QLabel(pageSCOPUS);
        lblHIndex->setObjectName("lblHIndex");

        formLayoutSCOPUS->setWidget(1, QFormLayout::ItemRole::LabelRole, lblHIndex);

        inputHIndex = new QSpinBox(pageSCOPUS);
        inputHIndex->setObjectName("inputHIndex");

        formLayoutSCOPUS->setWidget(1, QFormLayout::ItemRole::FieldRole, inputHIndex);

        stackSpecifics->addWidget(pageSCOPUS);
        pageCONFERENCE = new QWidget();
        pageCONFERENCE->setObjectName("pageCONFERENCE");
        formLayoutCONF = new QFormLayout(pageCONFERENCE);
        formLayoutCONF->setObjectName("formLayoutCONF");
        lblConfRank = new QLabel(pageCONFERENCE);
        lblConfRank->setObjectName("lblConfRank");

        formLayoutCONF->setWidget(0, QFormLayout::ItemRole::LabelRole, lblConfRank);

        inputConfRank = new QLineEdit(pageCONFERENCE);
        inputConfRank->setObjectName("inputConfRank");

        formLayoutCONF->setWidget(0, QFormLayout::ItemRole::FieldRole, inputConfRank);

        lblLocation = new QLabel(pageCONFERENCE);
        lblLocation->setObjectName("lblLocation");

        formLayoutCONF->setWidget(1, QFormLayout::ItemRole::LabelRole, lblLocation);

        inputLocation = new QLineEdit(pageCONFERENCE);
        inputLocation->setObjectName("inputLocation");

        formLayoutCONF->setWidget(1, QFormLayout::ItemRole::FieldRole, inputLocation);

        lblRate = new QLabel(pageCONFERENCE);
        lblRate->setObjectName("lblRate");

        formLayoutCONF->setWidget(2, QFormLayout::ItemRole::LabelRole, lblRate);

        inputAcceptRate = new QDoubleSpinBox(pageCONFERENCE);
        inputAcceptRate->setObjectName("inputAcceptRate");
        inputAcceptRate->setMaximum(100.000000000000000);

        formLayoutCONF->setWidget(2, QFormLayout::ItemRole::FieldRole, inputAcceptRate);

        stackSpecifics->addWidget(pageCONFERENCE);
        pageOTHER = new QWidget();
        pageOTHER->setObjectName("pageOTHER");
        verticalOther = new QVBoxLayout(pageOTHER);
        verticalOther->setObjectName("verticalOther");
        lblOtherMsg = new QLabel(pageOTHER);
        lblOtherMsg->setObjectName("lblOtherMsg");
        lblOtherMsg->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalOther->addWidget(lblOtherMsg);

        stackSpecifics->addWidget(pageOTHER);

        verticalLayoutMain->addWidget(stackSpecifics);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutMain->addItem(verticalSpacer);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName("layoutButtons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        btnClose = new QPushButton(ArticleDescriptionDialog);
        btnClose->setObjectName("btnClose");

        layoutButtons->addWidget(btnClose);


        verticalLayoutMain->addLayout(layoutButtons);


        retranslateUi(ArticleDescriptionDialog);
        QObject::connect(comboType, &QComboBox::currentIndexChanged, stackSpecifics, &QStackedWidget::setCurrentIndex);

        stackSpecifics->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleDescriptionDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleDescriptionDialog)
    {
        ArticleDescriptionDialog->setWindowTitle(QCoreApplication::translate("ArticleDescriptionDialog", "Article Details", nullptr));
        lblHeader->setStyleSheet(QCoreApplication::translate("ArticleDescriptionDialog", "font-size: 18px; font-weight: bold; color: #2c3e50;", nullptr));
        lblHeader->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Article Details Information", nullptr));
        groupCommon->setTitle(QCoreApplication::translate("ArticleDescriptionDialog", "General Information", nullptr));
        lblTitle->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Title", nullptr));
        lblAuthors->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Authors", nullptr));
        lblAbstract->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Abstract", nullptr));
        lblVenue->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Venue", nullptr));
        lblYear->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Year:", nullptr));
        lblStatus->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Status", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("ArticleDescriptionDialog", "DRAFT", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("ArticleDescriptionDialog", "SUBMITTED", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("ArticleDescriptionDialog", "UNDER_REVIEW", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("ArticleDescriptionDialog", "REVISIONS", nullptr));
        comboStatus->setItemText(4, QCoreApplication::translate("ArticleDescriptionDialog", "ACCEPTED", nullptr));
        comboStatus->setItemText(5, QCoreApplication::translate("ArticleDescriptionDialog", "REJECTED", nullptr));
        comboStatus->setItemText(6, QCoreApplication::translate("ArticleDescriptionDialog", "PUBLISHED", nullptr));

        lblCitation->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Citations", nullptr));
        label->setText(QCoreApplication::translate("ArticleDescriptionDialog", "References", nullptr));
        lblTypeSelect->setStyleSheet(QCoreApplication::translate("ArticleDescriptionDialog", "font-weight: bold;", nullptr));
        lblTypeSelect->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Article Type:", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("ArticleDescriptionDialog", "SCIE", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("ArticleDescriptionDialog", "SCOPUS", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("ArticleDescriptionDialog", "CONFERENCE", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("ArticleDescriptionDialog", "OTHER", nullptr));

        lblIF->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Impact Factor (IF)", nullptr));
        lblQRank->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Q-Rank (1-4)", nullptr));
        lblSJR->setText(QCoreApplication::translate("ArticleDescriptionDialog", "SJR", nullptr));
        lblHIndex->setText(QCoreApplication::translate("ArticleDescriptionDialog", "H-Index", nullptr));
        lblConfRank->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Conference Rank", nullptr));
        lblLocation->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Location", nullptr));
        lblRate->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Acceptance Rate", nullptr));
        inputAcceptRate->setSuffix(QCoreApplication::translate("ArticleDescriptionDialog", " %", nullptr));
        lblOtherMsg->setStyleSheet(QCoreApplication::translate("ArticleDescriptionDialog", "color: gray; font-style: italic;", nullptr));
        lblOtherMsg->setText(QCoreApplication::translate("ArticleDescriptionDialog", "No specific details for this type.", nullptr));
        btnClose->setText(QCoreApplication::translate("ArticleDescriptionDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleDescriptionDialog: public Ui_ArticleDescriptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDESCRIPTION_H
