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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleDetailsDialog
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeaderTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QLabel *lblTitle;
    QLabel *lblId;
    QLabel *lblVenue;
    QHBoxLayout *horizontalLayout_Meta;
    QLabel *lblYear;
    QSpacerItem *horizontalSpacer;
    QLabel *lblCitation;
    QHBoxLayout *horizontalLayout_Tags;
    QLabel *lblType;
    QComboBox *typeBox;
    QLabel *lblStatus;
    QComboBox *statusBox;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QStackedWidget *stackedSpecificInfo;
    QWidget *pageSCIE;
    QHBoxLayout *horizontalLayout_SCIE;
    QLabel *label_IF;
    QLabel *valIF;
    QSpacerItem *spacer_scie;
    QLabel *label_Q;
    QLabel *valQRank;
    QWidget *pageSCOPUS;
    QHBoxLayout *horizontalLayout_SCOPUS;
    QLabel *label_SJR;
    QLabel *valSJR;
    QSpacerItem *spacer_scopus;
    QLabel *label_H;
    QLabel *valHIndex;
    QWidget *pageCONF;
    QGridLayout *gridLayout_CONF;
    QLabel *label_ConfRank;
    QLabel *valConfRank;
    QLabel *label_Rate;
    QLabel *valAcceptRate;
    QLabel *label_Loc;
    QLabel *valLocation;
    QWidget *pageOTHER;
    QGroupBox *grpAuthors;
    QVBoxLayout *verticalLayout_Authors;
    QListWidget *listAuthors;
    QGroupBox *grpAbstract;
    QVBoxLayout *verticalLayout_Abstract;
    QTextBrowser *txtAbstract;
    QGroupBox *grpRefs;
    QVBoxLayout *verticalLayout_Refs;
    QListWidget *listRefs;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *footerSpacer;
    QPushButton *btnUpdate;
    QPushButton *closeBtn;

    void setupUi(QDialog *ArticleDetailsDialog)
    {
        if (ArticleDetailsDialog->objectName().isEmpty())
            ArticleDetailsDialog->setObjectName("ArticleDetailsDialog");
        ArticleDetailsDialog->resize(600, 850);
        ArticleDetailsDialog->setStyleSheet(QString::fromUtf8("QDialog#ArticleDetailsDialog{background-color:#f4f7f6;border:4px solid #FFC085;}QWidget{font-family:\"Segoe UI\",Arial,sans-serif;font-size:14px;}QScrollArea{border:none;background-color:transparent;}QGroupBox{background-color:#ffffff;border:1px solid #e0e0e0;border-radius:8px;margin-top:20px;font-size:14px;}QGroupBox::title{subcontrol-origin:margin;subcontrol-position:top left;padding:0 5px;color:#20B2AA;font-weight:bold;left:10px;}QListWidget,QTextBrowser{border:none;background-color:transparent;}"));
        verticalLayout_Main = new QVBoxLayout(ArticleDetailsDialog);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleDetailsDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeaderTitle = new QLabel(headerContainer);
        lblHeaderTitle->setObjectName("lblHeaderTitle");
        lblHeaderTitle->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;"));
        lblHeaderTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(lblHeaderTitle);


        verticalLayout_Main->addWidget(headerContainer);

        scrollArea = new QScrollArea(ArticleDetailsDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 592, 798));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        lblTitle = new QLabel(scrollContent);
        lblTitle->setObjectName("lblTitle");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle->sizePolicy().hasHeightForWidth());
        lblTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(18);
        font.setBold(true);
        lblTitle->setFont(font);
        lblTitle->setStyleSheet(QString::fromUtf8("color:#00264d;"));
        lblTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        lblTitle->setWordWrap(true);

        verticalLayout_Content->addWidget(lblTitle);

        lblId = new QLabel(scrollContent);
        lblId->setObjectName("lblId");
        lblId->setStyleSheet(QString::fromUtf8("color:gray;font-style:italic;"));

        verticalLayout_Content->addWidget(lblId);

        lblVenue = new QLabel(scrollContent);
        lblVenue->setObjectName("lblVenue");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        font1.setBold(true);
        lblVenue->setFont(font1);
        lblVenue->setStyleSheet(QString::fromUtf8("color:#333333;"));

        verticalLayout_Content->addWidget(lblVenue);

        horizontalLayout_Meta = new QHBoxLayout();
        horizontalLayout_Meta->setObjectName("horizontalLayout_Meta");
        lblYear = new QLabel(scrollContent);
        lblYear->setObjectName("lblYear");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        lblYear->setFont(font2);
        lblYear->setStyleSheet(QString::fromUtf8("color:#555555;"));

        horizontalLayout_Meta->addWidget(lblYear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Meta->addItem(horizontalSpacer);

        lblCitation = new QLabel(scrollContent);
        lblCitation->setObjectName("lblCitation");
        lblCitation->setFont(font1);
        lblCitation->setStyleSheet(QString::fromUtf8("color:#d35400;"));

        horizontalLayout_Meta->addWidget(lblCitation);


        verticalLayout_Content->addLayout(horizontalLayout_Meta);

        horizontalLayout_Tags = new QHBoxLayout();
        horizontalLayout_Tags->setObjectName("horizontalLayout_Tags");
        lblType = new QLabel(scrollContent);
        lblType->setObjectName("lblType");
        lblType->setStyleSheet(QString::fromUtf8("background-color:#e0f7fa;color:#006064;padding:6px;border-radius:4px;font-weight:bold;"));
        lblType->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_Tags->addWidget(lblType);

        typeBox = new QComboBox(scrollContent);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName("typeBox");
        typeBox->setStyleSheet(QString::fromUtf8("background-color:#ffffff;border:1px solid #cccccc;border-radius:4px;padding:4px;"));

        horizontalLayout_Tags->addWidget(typeBox);

        lblStatus = new QLabel(scrollContent);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setStyleSheet(QString::fromUtf8("background-color:#e8f5e9;color:#2e7d32;padding:6px;border-radius:4px;font-weight:bold;"));
        lblStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_Tags->addWidget(lblStatus);

        statusBox = new QComboBox(scrollContent);
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->setObjectName("statusBox");
        statusBox->setStyleSheet(QString::fromUtf8("background-color:#ffffff;border:1px solid #cccccc;border-radius:4px;padding:4px;"));

        horizontalLayout_Tags->addWidget(statusBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Tags->addItem(horizontalSpacer_2);


        verticalLayout_Content->addLayout(horizontalLayout_Tags);

        line = new QFrame(scrollContent);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Content->addWidget(line);

        stackedSpecificInfo = new QStackedWidget(scrollContent);
        stackedSpecificInfo->setObjectName("stackedSpecificInfo");
        pageSCIE = new QWidget();
        pageSCIE->setObjectName("pageSCIE");
        horizontalLayout_SCIE = new QHBoxLayout(pageSCIE);
        horizontalLayout_SCIE->setObjectName("horizontalLayout_SCIE");
        label_IF = new QLabel(pageSCIE);
        label_IF->setObjectName("label_IF");
        label_IF->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        horizontalLayout_SCIE->addWidget(label_IF);

        valIF = new QLabel(pageSCIE);
        valIF->setObjectName("valIF");
        valIF->setStyleSheet(QString::fromUtf8("color:#d32f2f;font-weight:bold;"));

        horizontalLayout_SCIE->addWidget(valIF);

        spacer_scie = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SCIE->addItem(spacer_scie);

        label_Q = new QLabel(pageSCIE);
        label_Q->setObjectName("label_Q");
        label_Q->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        horizontalLayout_SCIE->addWidget(label_Q);

        valQRank = new QLabel(pageSCIE);
        valQRank->setObjectName("valQRank");
        valQRank->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayout_SCIE->addWidget(valQRank);

        stackedSpecificInfo->addWidget(pageSCIE);
        pageSCOPUS = new QWidget();
        pageSCOPUS->setObjectName("pageSCOPUS");
        horizontalLayout_SCOPUS = new QHBoxLayout(pageSCOPUS);
        horizontalLayout_SCOPUS->setObjectName("horizontalLayout_SCOPUS");
        label_SJR = new QLabel(pageSCOPUS);
        label_SJR->setObjectName("label_SJR");
        label_SJR->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        horizontalLayout_SCOPUS->addWidget(label_SJR);

        valSJR = new QLabel(pageSCOPUS);
        valSJR->setObjectName("valSJR");
        valSJR->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayout_SCOPUS->addWidget(valSJR);

        spacer_scopus = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SCOPUS->addItem(spacer_scopus);

        label_H = new QLabel(pageSCOPUS);
        label_H->setObjectName("label_H");
        label_H->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        horizontalLayout_SCOPUS->addWidget(label_H);

        valHIndex = new QLabel(pageSCOPUS);
        valHIndex->setObjectName("valHIndex");
        valHIndex->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayout_SCOPUS->addWidget(valHIndex);

        stackedSpecificInfo->addWidget(pageSCOPUS);
        pageCONF = new QWidget();
        pageCONF->setObjectName("pageCONF");
        gridLayout_CONF = new QGridLayout(pageCONF);
        gridLayout_CONF->setObjectName("gridLayout_CONF");
        label_ConfRank = new QLabel(pageCONF);
        label_ConfRank->setObjectName("label_ConfRank");
        label_ConfRank->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        gridLayout_CONF->addWidget(label_ConfRank, 0, 0, 1, 1);

        valConfRank = new QLabel(pageCONF);
        valConfRank->setObjectName("valConfRank");
        valConfRank->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        gridLayout_CONF->addWidget(valConfRank, 0, 1, 1, 1);

        label_Rate = new QLabel(pageCONF);
        label_Rate->setObjectName("label_Rate");
        label_Rate->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        gridLayout_CONF->addWidget(label_Rate, 0, 2, 1, 1);

        valAcceptRate = new QLabel(pageCONF);
        valAcceptRate->setObjectName("valAcceptRate");
        valAcceptRate->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        gridLayout_CONF->addWidget(valAcceptRate, 0, 3, 1, 1);

        label_Loc = new QLabel(pageCONF);
        label_Loc->setObjectName("label_Loc");
        label_Loc->setStyleSheet(QString::fromUtf8("font-weight:bold;color:#555555;"));

        gridLayout_CONF->addWidget(label_Loc, 1, 0, 1, 1);

        valLocation = new QLabel(pageCONF);
        valLocation->setObjectName("valLocation");
        valLocation->setWordWrap(true);

        gridLayout_CONF->addWidget(valLocation, 1, 1, 1, 3);

        stackedSpecificInfo->addWidget(pageCONF);
        pageOTHER = new QWidget();
        pageOTHER->setObjectName("pageOTHER");
        stackedSpecificInfo->addWidget(pageOTHER);

        verticalLayout_Content->addWidget(stackedSpecificInfo);

        grpAuthors = new QGroupBox(scrollContent);
        grpAuthors->setObjectName("grpAuthors");
        verticalLayout_Authors = new QVBoxLayout(grpAuthors);
        verticalLayout_Authors->setObjectName("verticalLayout_Authors");
        listAuthors = new QListWidget(grpAuthors);
        listAuthors->setObjectName("listAuthors");

        verticalLayout_Authors->addWidget(listAuthors);


        verticalLayout_Content->addWidget(grpAuthors);

        grpAbstract = new QGroupBox(scrollContent);
        grpAbstract->setObjectName("grpAbstract");
        verticalLayout_Abstract = new QVBoxLayout(grpAbstract);
        verticalLayout_Abstract->setObjectName("verticalLayout_Abstract");
        txtAbstract = new QTextBrowser(grpAbstract);
        txtAbstract->setObjectName("txtAbstract");

        verticalLayout_Abstract->addWidget(txtAbstract);


        verticalLayout_Content->addWidget(grpAbstract);

        grpRefs = new QGroupBox(scrollContent);
        grpRefs->setObjectName("grpRefs");
        verticalLayout_Refs = new QVBoxLayout(grpRefs);
        verticalLayout_Refs->setObjectName("verticalLayout_Refs");
        listRefs = new QListWidget(grpRefs);
        listRefs->setObjectName("listRefs");

        verticalLayout_Refs->addWidget(listRefs);


        verticalLayout_Content->addWidget(grpRefs);

        scrollArea->setWidget(scrollContent);

        verticalLayout_Main->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleDetailsDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setStyleSheet(QString::fromUtf8("background-color:#ffffff;border-top:1px solid #dddddd;"));
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, 10, -1, 10);
        footerSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(footerSpacer);

        btnUpdate = new QPushButton(footerContainer);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setMinimumSize(QSize(120, 40));
        btnUpdate->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnUpdate->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        horizontalLayout_Footer->addWidget(btnUpdate);

        closeBtn = new QPushButton(footerContainer);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMinimumSize(QSize(100, 40));
        closeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        horizontalLayout_Footer->addWidget(closeBtn);


        verticalLayout_Main->addWidget(footerContainer);


        retranslateUi(ArticleDetailsDialog);
        QObject::connect(closeBtn, &QPushButton::clicked, ArticleDetailsDialog, qOverload<>(&QDialog::accept));

        stackedSpecificInfo->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ArticleDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleDetailsDialog)
    {
        ArticleDetailsDialog->setWindowTitle(QCoreApplication::translate("ArticleDetailsDialog", "Article Details", nullptr));
        lblHeaderTitle->setText(QCoreApplication::translate("ArticleDetailsDialog", "CHI TI\341\272\276T B\303\200I B\303\201O", nullptr));
        lblTitle->setText(QCoreApplication::translate("ArticleDetailsDialog", "Article Title Placeholder", nullptr));
        lblId->setText(QCoreApplication::translate("ArticleDetailsDialog", "ID: 00000", nullptr));
        lblVenue->setText(QCoreApplication::translate("ArticleDetailsDialog", "Venue Name", nullptr));
        lblYear->setText(QCoreApplication::translate("ArticleDetailsDialog", "2024", nullptr));
        lblCitation->setText(QCoreApplication::translate("ArticleDetailsDialog", "0 Citations", nullptr));
        lblType->setText(QCoreApplication::translate("ArticleDetailsDialog", "Type", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("ArticleDetailsDialog", "SCIE", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("ArticleDetailsDialog", "SCOPUS", nullptr));
        typeBox->setItemText(2, QCoreApplication::translate("ArticleDetailsDialog", "CONFERENCE", nullptr));
        typeBox->setItemText(3, QCoreApplication::translate("ArticleDetailsDialog", "OTHER", nullptr));

        lblStatus->setText(QCoreApplication::translate("ArticleDetailsDialog", "Status", nullptr));
        statusBox->setItemText(0, QCoreApplication::translate("ArticleDetailsDialog", "DRAFT", nullptr));
        statusBox->setItemText(1, QCoreApplication::translate("ArticleDetailsDialog", "SUBMITTED", nullptr));
        statusBox->setItemText(2, QCoreApplication::translate("ArticleDetailsDialog", "UNDER_REVIEW", nullptr));
        statusBox->setItemText(3, QCoreApplication::translate("ArticleDetailsDialog", "REVISIONS", nullptr));
        statusBox->setItemText(4, QCoreApplication::translate("ArticleDetailsDialog", "ACCEPTED", nullptr));
        statusBox->setItemText(5, QCoreApplication::translate("ArticleDetailsDialog", "REJECTED", nullptr));
        statusBox->setItemText(6, QCoreApplication::translate("ArticleDetailsDialog", "PUBLISHED", nullptr));

        label_IF->setText(QCoreApplication::translate("ArticleDetailsDialog", "Impact Factor:", nullptr));
        valIF->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        label_Q->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q-Rank:", nullptr));
        valQRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q1", nullptr));
        label_SJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "SJR:", nullptr));
        valSJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        label_H->setText(QCoreApplication::translate("ArticleDetailsDialog", "H-Index:", nullptr));
        valHIndex->setText(QCoreApplication::translate("ArticleDetailsDialog", "0", nullptr));
        label_ConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Rank:", nullptr));
        valConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "A*", nullptr));
        label_Rate->setText(QCoreApplication::translate("ArticleDetailsDialog", "Accept Rate:", nullptr));
        valAcceptRate->setText(QCoreApplication::translate("ArticleDetailsDialog", "20%", nullptr));
        label_Loc->setText(QCoreApplication::translate("ArticleDetailsDialog", "Loc:", nullptr));
        valLocation->setText(QCoreApplication::translate("ArticleDetailsDialog", "Paris, France", nullptr));
        grpAuthors->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "AUTHORS", nullptr));
        grpAbstract->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "ABSTRACT", nullptr));
        grpRefs->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "REFERENCES", nullptr));
        btnUpdate->setText(QCoreApplication::translate("ArticleDetailsDialog", "Update Article", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleDetailsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleDetailsDialog: public Ui_ArticleDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDETAILSDIALOG_H
