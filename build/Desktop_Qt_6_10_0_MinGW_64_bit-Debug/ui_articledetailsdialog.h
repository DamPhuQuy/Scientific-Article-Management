/********************************************************************************
** Form generated from reading UI file 'articledetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEDETAILSDIALOG_H
#define UI_ARTICLEDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleDetailsDialog
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblHeaderTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QGroupBox *grpGeneral;
    QGridLayout *gridLayout;
    QLabel *lblTitle;
    QLabel *lblId;
    QLabel *lblYear;
    QLabel *lblVenue;
    QLabel *lblCitation;
    QGroupBox *grpStatus;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelType;
    QComboBox *typeBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelStatus;
    QComboBox *statusBox;
    QGroupBox *grpSpecific;
    QVBoxLayout *verticalLayout_Stack;
    QStackedWidget *stackedSpecificInfo;
    QWidget *pageSCIE;
    QFormLayout *formLayout_SCIE;
    QLabel *labelIF;
    QLabel *valIF;
    QLabel *labelQRank;
    QLabel *valQRank;
    QWidget *pageSCOPUS;
    QFormLayout *formLayout_SCOPUS;
    QLabel *labelSJR;
    QLabel *valSJR;
    QLabel *labelHIndex;
    QLabel *valHIndex;
    QWidget *pageCONF;
    QFormLayout *formLayout_CONF;
    QLabel *labelConfRank;
    QLabel *valConfRank;
    QLabel *labelLocation;
    QLabel *valLocation;
    QLabel *labelAcceptRate;
    QLabel *valAcceptRate;
    QWidget *pageOTHER;
    QVBoxLayout *verticalLayout_Other;
    QLabel *labelOther;
    QGroupBox *grpAbstract;
    QVBoxLayout *verticalLayout_Abs;
    QTextEdit *txtAbstract;
    QHBoxLayout *horizontalLayout_Lists;
    QGroupBox *grpAuthors;
    QVBoxLayout *verticalLayout_Auth;
    QListWidget *listAuthors;
    QGroupBox *grpRefs;
    QVBoxLayout *verticalLayout_Ref;
    QListWidget *listRefs;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;
    QPushButton *closeBtn;

    void setupUi(QDialog *ArticleDetailsDialog)
    {
        if (ArticleDetailsDialog->objectName().isEmpty())
            ArticleDetailsDialog->setObjectName("ArticleDetailsDialog");
        ArticleDetailsDialog->resize(720, 850);
        ArticleDetailsDialog->setStyleSheet(QString::fromUtf8("QDialog#ArticleDetailsDialog { background-color: #f4f7f6; }\n"
"QWidget { font-family: \"Segoe UI\", \"Roboto\", sans-serif; }\n"
"QWidget#headerContainer { background-color: #00264d; border-left: 8px solid #FFD700; border-bottom: 4px solid #4169E1; }\n"
"QLabel#lblHeaderTitle { color: #ffffff; font-size: 20px; font-weight: 900; background-color: transparent; padding-left: 10px; }\n"
"QScrollArea { border: none; background-color: transparent; }\n"
"QWidget#scrollContent { background-color: transparent; }\n"
"QGroupBox { background-color: #ffffff; border: 1px solid #cfd8dc; border-radius: 8px; margin-top: 24px; font-weight: bold; color: #00264d; font-size: 14px; padding-top: 20px; }\n"
"QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top left; left: 20px; padding: 0 8px; background-color: #ffffff; }\n"
"QLabel { color: #546e7a; font-size: 13px; font-weight: 600; }\n"
"QLabel#lblTitle, QLabel#lblId, QLabel#lblVenue, QLabel#lblYear, QLabel#lblCitation, QLabel#valIF, QLabel#valQRank, QLabel#valS"
                        "JR, QLabel#valHIndex, QLabel#valConfRank, QLabel#valLocation, QLabel#valAcceptRate { color: #263238; font-weight: normal; font-size: 14px; }\n"
"QLabel#lblTitle { font-size: 16px; font-weight: 800; color: #0d47a1; }\n"
"QTextEdit, QListWidget, QComboBox { background-color: #fafafa; border: 1px solid #cfd8dc; border-radius: 4px; padding: 6px; font-size: 13px; color: #37474f; }\n"
"QTextEdit:focus, QListWidget:focus, QComboBox:focus { background-color: #ffffff; border: 2px solid #20B2AA; }\n"
"QComboBox::drop-down { border: 0px; }\n"
"QWidget#footerContainer { background-color: #ffffff; border-top: 1px solid #e0e0e0; }\n"
"QPushButton { border-radius: 4px; font-weight: bold; padding: 8px 24px; font-size: 13px; color: white; min-width: 80px; }\n"
"QPushButton#btnUpdate { background-color: #20B2AA; border: 1px solid #20B2AA; }\n"
"QPushButton#btnUpdate:hover { background-color: #00897b; border-color: #00897b; }\n"
"QPushButton#closeBtn { background-color: #ef5350; border: 1px solid #ef5350; }\n"
"QPushButton#close"
                        "Btn:hover { background-color: #d32f2f; border-color: #d32f2f; }"));
        mainLayout = new QVBoxLayout(ArticleDetailsDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(ArticleDetailsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        horizontalLayout = new QHBoxLayout(headerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, -1, -1, -1);
        lblHeaderTitle = new QLabel(headerContainer);
        lblHeaderTitle->setObjectName("lblHeaderTitle");

        horizontalLayout->addWidget(lblHeaderTitle);


        mainLayout->addWidget(headerContainer);

        scrollArea = new QScrollArea(ArticleDetailsDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 718, 728));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setSpacing(20);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        grpGeneral = new QGroupBox(scrollContent);
        grpGeneral->setObjectName("grpGeneral");
        gridLayout = new QGridLayout(grpGeneral);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(10);
        lblTitle = new QLabel(grpGeneral);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setWordWrap(true);

        gridLayout->addWidget(lblTitle, 0, 0, 1, 2);

        lblId = new QLabel(grpGeneral);
        lblId->setObjectName("lblId");

        gridLayout->addWidget(lblId, 1, 0, 1, 1);

        lblYear = new QLabel(grpGeneral);
        lblYear->setObjectName("lblYear");
        lblYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblYear, 1, 1, 1, 1);

        lblVenue = new QLabel(grpGeneral);
        lblVenue->setObjectName("lblVenue");

        gridLayout->addWidget(lblVenue, 2, 0, 1, 1);

        lblCitation = new QLabel(grpGeneral);
        lblCitation->setObjectName("lblCitation");
        lblCitation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCitation, 2, 1, 1, 1);


        verticalLayout_Content->addWidget(grpGeneral);

        grpStatus = new QGroupBox(scrollContent);
        grpStatus->setObjectName("grpStatus");
        horizontalLayout_3 = new QHBoxLayout(grpStatus);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelType = new QLabel(grpStatus);
        labelType->setObjectName("labelType");

        horizontalLayout_3->addWidget(labelType);

        typeBox = new QComboBox(grpStatus);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName("typeBox");
        typeBox->setEnabled(false);

        horizontalLayout_3->addWidget(typeBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        labelStatus = new QLabel(grpStatus);
        labelStatus->setObjectName("labelStatus");

        horizontalLayout_3->addWidget(labelStatus);

        statusBox = new QComboBox(grpStatus);
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->setObjectName("statusBox");
        statusBox->setEnabled(false);

        horizontalLayout_3->addWidget(statusBox);


        verticalLayout_Content->addWidget(grpStatus);

        grpSpecific = new QGroupBox(scrollContent);
        grpSpecific->setObjectName("grpSpecific");
        verticalLayout_Stack = new QVBoxLayout(grpSpecific);
        verticalLayout_Stack->setObjectName("verticalLayout_Stack");
        stackedSpecificInfo = new QStackedWidget(grpSpecific);
        stackedSpecificInfo->setObjectName("stackedSpecificInfo");
        pageSCIE = new QWidget();
        pageSCIE->setObjectName("pageSCIE");
        formLayout_SCIE = new QFormLayout(pageSCIE);
        formLayout_SCIE->setObjectName("formLayout_SCIE");
        labelIF = new QLabel(pageSCIE);
        labelIF->setObjectName("labelIF");

        formLayout_SCIE->setWidget(0, QFormLayout::ItemRole::LabelRole, labelIF);

        valIF = new QLabel(pageSCIE);
        valIF->setObjectName("valIF");

        formLayout_SCIE->setWidget(0, QFormLayout::ItemRole::FieldRole, valIF);

        labelQRank = new QLabel(pageSCIE);
        labelQRank->setObjectName("labelQRank");

        formLayout_SCIE->setWidget(1, QFormLayout::ItemRole::LabelRole, labelQRank);

        valQRank = new QLabel(pageSCIE);
        valQRank->setObjectName("valQRank");

        formLayout_SCIE->setWidget(1, QFormLayout::ItemRole::FieldRole, valQRank);

        stackedSpecificInfo->addWidget(pageSCIE);
        pageSCOPUS = new QWidget();
        pageSCOPUS->setObjectName("pageSCOPUS");
        formLayout_SCOPUS = new QFormLayout(pageSCOPUS);
        formLayout_SCOPUS->setObjectName("formLayout_SCOPUS");
        labelSJR = new QLabel(pageSCOPUS);
        labelSJR->setObjectName("labelSJR");

        formLayout_SCOPUS->setWidget(0, QFormLayout::ItemRole::LabelRole, labelSJR);

        valSJR = new QLabel(pageSCOPUS);
        valSJR->setObjectName("valSJR");

        formLayout_SCOPUS->setWidget(0, QFormLayout::ItemRole::FieldRole, valSJR);

        labelHIndex = new QLabel(pageSCOPUS);
        labelHIndex->setObjectName("labelHIndex");

        formLayout_SCOPUS->setWidget(1, QFormLayout::ItemRole::LabelRole, labelHIndex);

        valHIndex = new QLabel(pageSCOPUS);
        valHIndex->setObjectName("valHIndex");

        formLayout_SCOPUS->setWidget(1, QFormLayout::ItemRole::FieldRole, valHIndex);

        stackedSpecificInfo->addWidget(pageSCOPUS);
        pageCONF = new QWidget();
        pageCONF->setObjectName("pageCONF");
        formLayout_CONF = new QFormLayout(pageCONF);
        formLayout_CONF->setObjectName("formLayout_CONF");
        labelConfRank = new QLabel(pageCONF);
        labelConfRank->setObjectName("labelConfRank");

        formLayout_CONF->setWidget(0, QFormLayout::ItemRole::LabelRole, labelConfRank);

        valConfRank = new QLabel(pageCONF);
        valConfRank->setObjectName("valConfRank");

        formLayout_CONF->setWidget(0, QFormLayout::ItemRole::FieldRole, valConfRank);

        labelLocation = new QLabel(pageCONF);
        labelLocation->setObjectName("labelLocation");

        formLayout_CONF->setWidget(1, QFormLayout::ItemRole::LabelRole, labelLocation);

        valLocation = new QLabel(pageCONF);
        valLocation->setObjectName("valLocation");

        formLayout_CONF->setWidget(1, QFormLayout::ItemRole::FieldRole, valLocation);

        labelAcceptRate = new QLabel(pageCONF);
        labelAcceptRate->setObjectName("labelAcceptRate");

        formLayout_CONF->setWidget(2, QFormLayout::ItemRole::LabelRole, labelAcceptRate);

        valAcceptRate = new QLabel(pageCONF);
        valAcceptRate->setObjectName("valAcceptRate");

        formLayout_CONF->setWidget(2, QFormLayout::ItemRole::FieldRole, valAcceptRate);

        stackedSpecificInfo->addWidget(pageCONF);
        pageOTHER = new QWidget();
        pageOTHER->setObjectName("pageOTHER");
        verticalLayout_Other = new QVBoxLayout(pageOTHER);
        verticalLayout_Other->setObjectName("verticalLayout_Other");
        labelOther = new QLabel(pageOTHER);
        labelOther->setObjectName("labelOther");

        verticalLayout_Other->addWidget(labelOther);

        stackedSpecificInfo->addWidget(pageOTHER);

        verticalLayout_Stack->addWidget(stackedSpecificInfo);


        verticalLayout_Content->addWidget(grpSpecific);

        grpAbstract = new QGroupBox(scrollContent);
        grpAbstract->setObjectName("grpAbstract");
        verticalLayout_Abs = new QVBoxLayout(grpAbstract);
        verticalLayout_Abs->setObjectName("verticalLayout_Abs");
        txtAbstract = new QTextEdit(grpAbstract);
        txtAbstract->setObjectName("txtAbstract");
        txtAbstract->setMinimumSize(QSize(0, 100));
        txtAbstract->setReadOnly(true);

        verticalLayout_Abs->addWidget(txtAbstract);


        verticalLayout_Content->addWidget(grpAbstract);

        horizontalLayout_Lists = new QHBoxLayout();
        horizontalLayout_Lists->setSpacing(20);
        horizontalLayout_Lists->setObjectName("horizontalLayout_Lists");
        grpAuthors = new QGroupBox(scrollContent);
        grpAuthors->setObjectName("grpAuthors");
        verticalLayout_Auth = new QVBoxLayout(grpAuthors);
        verticalLayout_Auth->setObjectName("verticalLayout_Auth");
        listAuthors = new QListWidget(grpAuthors);
        listAuthors->setObjectName("listAuthors");
        listAuthors->setMinimumSize(QSize(0, 150));

        verticalLayout_Auth->addWidget(listAuthors);


        horizontalLayout_Lists->addWidget(grpAuthors);

        grpRefs = new QGroupBox(scrollContent);
        grpRefs->setObjectName("grpRefs");
        verticalLayout_Ref = new QVBoxLayout(grpRefs);
        verticalLayout_Ref->setObjectName("verticalLayout_Ref");
        listRefs = new QListWidget(grpRefs);
        listRefs->setObjectName("listRefs");
        listRefs->setMinimumSize(QSize(0, 150));

        verticalLayout_Ref->addWidget(listRefs);


        horizontalLayout_Lists->addWidget(grpRefs);


        verticalLayout_Content->addLayout(horizontalLayout_Lists);

        scrollArea->setWidget(scrollContent);

        mainLayout->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleDetailsDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setMinimumSize(QSize(0, 60));
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, -1, 30, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        btnUpdate = new QPushButton(footerContainer);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Footer->addWidget(btnUpdate);

        closeBtn = new QPushButton(footerContainer);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Footer->addWidget(closeBtn);


        mainLayout->addWidget(footerContainer);


        retranslateUi(ArticleDetailsDialog);
        QObject::connect(closeBtn, &QPushButton::clicked, ArticleDetailsDialog, qOverload<>(&QDialog::accept));

        stackedSpecificInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleDetailsDialog)
    {
        ArticleDetailsDialog->setWindowTitle(QCoreApplication::translate("ArticleDetailsDialog", "Article Details", nullptr));
        lblHeaderTitle->setText(QCoreApplication::translate("ArticleDetailsDialog", "CHI TI\341\272\276T B\303\200I B\303\201O", nullptr));
        grpGeneral->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Th\303\264ng tin chung", nullptr));
        lblTitle->setText(QCoreApplication::translate("ArticleDetailsDialog", "[Article Title Here]", nullptr));
        lblId->setText(QCoreApplication::translate("ArticleDetailsDialog", "ID: ...", nullptr));
        lblYear->setText(QCoreApplication::translate("ArticleDetailsDialog", "2025", nullptr));
        lblVenue->setText(QCoreApplication::translate("ArticleDetailsDialog", "Venue: ...", nullptr));
        lblCitation->setText(QCoreApplication::translate("ArticleDetailsDialog", "0 Citations", nullptr));
        grpStatus->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Ph\303\242n lo\341\272\241i & Tr\341\272\241ng th\303\241i", nullptr));
        labelType->setText(QCoreApplication::translate("ArticleDetailsDialog", "Lo\341\272\241i b\303\240i b\303\241o:", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("ArticleDetailsDialog", "SCIE", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("ArticleDetailsDialog", "SCOPUS", nullptr));
        typeBox->setItemText(2, QCoreApplication::translate("ArticleDetailsDialog", "CONFERENCE", nullptr));
        typeBox->setItemText(3, QCoreApplication::translate("ArticleDetailsDialog", "OTHER", nullptr));

        labelStatus->setText(QCoreApplication::translate("ArticleDetailsDialog", "Tr\341\272\241ng th\303\241i:", nullptr));
        statusBox->setItemText(0, QCoreApplication::translate("ArticleDetailsDialog", "DRAFT", nullptr));
        statusBox->setItemText(1, QCoreApplication::translate("ArticleDetailsDialog", "SUBMITTED", nullptr));
        statusBox->setItemText(2, QCoreApplication::translate("ArticleDetailsDialog", "UNDER_REVIEW", nullptr));
        statusBox->setItemText(3, QCoreApplication::translate("ArticleDetailsDialog", "REVISIONS", nullptr));
        statusBox->setItemText(4, QCoreApplication::translate("ArticleDetailsDialog", "ACCEPTED", nullptr));
        statusBox->setItemText(5, QCoreApplication::translate("ArticleDetailsDialog", "REJECTED", nullptr));
        statusBox->setItemText(6, QCoreApplication::translate("ArticleDetailsDialog", "PUBLISHED", nullptr));

        grpSpecific->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Th\303\264ng tin chi ti\341\272\277t", nullptr));
        labelIF->setText(QCoreApplication::translate("ArticleDetailsDialog", "Impact Factor:", nullptr));
        valIF->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        labelQRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q-Rank:", nullptr));
        valQRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q1", nullptr));
        labelSJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "SJR:", nullptr));
        valSJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        labelHIndex->setText(QCoreApplication::translate("ArticleDetailsDialog", "H-Index:", nullptr));
        valHIndex->setText(QCoreApplication::translate("ArticleDetailsDialog", "0", nullptr));
        labelConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Conference Rank:", nullptr));
        valConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "A", nullptr));
        labelLocation->setText(QCoreApplication::translate("ArticleDetailsDialog", "Location:", nullptr));
        valLocation->setText(QCoreApplication::translate("ArticleDetailsDialog", "...", nullptr));
        labelAcceptRate->setText(QCoreApplication::translate("ArticleDetailsDialog", "Acceptance Rate:", nullptr));
        valAcceptRate->setText(QCoreApplication::translate("ArticleDetailsDialog", "0%", nullptr));
        labelOther->setText(QCoreApplication::translate("ArticleDetailsDialog", "Kh\303\264ng c\303\263 th\303\264ng tin chi ti\341\272\277t b\341\273\225 sung.", nullptr));
        grpAbstract->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Abstract", nullptr));
        grpAuthors->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "T\303\241c gi\341\272\243", nullptr));
        grpRefs->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Tham kh\341\272\243o", nullptr));
        btnUpdate->setText(QCoreApplication::translate("ArticleDetailsDialog", "C\341\272\255p nh\341\272\255t", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleDetailsDialog", "\304\220\303\263ng", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleDetailsDialog: public Ui_ArticleDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDETAILSDIALOG_H
