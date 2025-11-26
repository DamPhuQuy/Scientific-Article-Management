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
#include <QtGui/QIcon>
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
    QVBoxLayout *verticalLayout_Other;
    QGroupBox *grpAuthors;
    QVBoxLayout *verticalLayout_Authors;
    QListWidget *listAuthors;
    QGroupBox *grpAbstract;
    QVBoxLayout *verticalLayout_Abstract;
    QTextBrowser *txtAbstract;
    QGroupBox *grpRefs;
    QVBoxLayout *verticalLayout_Refs;
    QListWidget *listRefs;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnUpdate;
    QPushButton *removeBtn;
    QPushButton *closeBtn;

    void setupUi(QDialog *ArticleDetailsDialog)
    {
        if (ArticleDetailsDialog->objectName().isEmpty())
            ArticleDetailsDialog->setObjectName("ArticleDetailsDialog");
        ArticleDetailsDialog->resize(500, 800);
        verticalLayout_Main = new QVBoxLayout(ArticleDetailsDialog);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        scrollArea = new QScrollArea(ArticleDetailsDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 476, 862));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        lblTitle = new QLabel(scrollContent);
        lblTitle->setObjectName("lblTitle");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle->sizePolicy().hasHeightForWidth());
        lblTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        lblTitle->setWordWrap(true);
        lblTitle->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse|Qt::TextInteractionFlag::TextSelectableByMouse);

        verticalLayout_Content->addWidget(lblTitle);

        lblId = new QLabel(scrollContent);
        lblId->setObjectName("lblId");
        lblId->setStyleSheet(QString::fromUtf8("color: gray;"));

        verticalLayout_Content->addWidget(lblId);

        lblVenue = new QLabel(scrollContent);
        lblVenue->setObjectName("lblVenue");

        verticalLayout_Content->addWidget(lblVenue);

        horizontalLayout_Meta = new QHBoxLayout();
        horizontalLayout_Meta->setObjectName("horizontalLayout_Meta");
        lblYear = new QLabel(scrollContent);
        lblYear->setObjectName("lblYear");
        QFont font1;
        font1.setItalic(true);
        lblYear->setFont(font1);

        horizontalLayout_Meta->addWidget(lblYear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Meta->addItem(horizontalSpacer);

        lblCitation = new QLabel(scrollContent);
        lblCitation->setObjectName("lblCitation");
        QFont font2;
        font2.setBold(true);
        lblCitation->setFont(font2);
        lblCitation->setStyleSheet(QString::fromUtf8("color: #d35400;"));

        horizontalLayout_Meta->addWidget(lblCitation);


        verticalLayout_Content->addLayout(horizontalLayout_Meta);

        horizontalLayout_Tags = new QHBoxLayout();
        horizontalLayout_Tags->setObjectName("horizontalLayout_Tags");
        lblType = new QLabel(scrollContent);
        lblType->setObjectName("lblType");
        lblType->setStyleSheet(QString::fromUtf8("background-color: #e0f7fa; color: #006064; padding: 4px; border-radius: 4px;"));
        lblType->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_Tags->addWidget(lblType);

        typeBox = new QComboBox(scrollContent);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName("typeBox");

        horizontalLayout_Tags->addWidget(typeBox);

        lblStatus = new QLabel(scrollContent);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setStyleSheet(QString::fromUtf8("background-color: #e8f5e9; color: #2e7d32; padding: 4px; border-radius: 4px;"));
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
        stackedSpecificInfo->setFrameShape(QFrame::Shape::StyledPanel);
        stackedSpecificInfo->setFrameShadow(QFrame::Shadow::Raised);
        pageSCIE = new QWidget();
        pageSCIE->setObjectName("pageSCIE");
        horizontalLayout_SCIE = new QHBoxLayout(pageSCIE);
        horizontalLayout_SCIE->setObjectName("horizontalLayout_SCIE");
        horizontalLayout_SCIE->setContentsMargins(0, -1, 0, -1);
        label_IF = new QLabel(pageSCIE);
        label_IF->setObjectName("label_IF");

        horizontalLayout_SCIE->addWidget(label_IF);

        valIF = new QLabel(pageSCIE);
        valIF->setObjectName("valIF");

        horizontalLayout_SCIE->addWidget(valIF);

        spacer_scie = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SCIE->addItem(spacer_scie);

        label_Q = new QLabel(pageSCIE);
        label_Q->setObjectName("label_Q");

        horizontalLayout_SCIE->addWidget(label_Q);

        valQRank = new QLabel(pageSCIE);
        valQRank->setObjectName("valQRank");
        valQRank->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_SCIE->addWidget(valQRank);

        stackedSpecificInfo->addWidget(pageSCIE);
        pageSCOPUS = new QWidget();
        pageSCOPUS->setObjectName("pageSCOPUS");
        horizontalLayout_SCOPUS = new QHBoxLayout(pageSCOPUS);
        horizontalLayout_SCOPUS->setObjectName("horizontalLayout_SCOPUS");
        horizontalLayout_SCOPUS->setContentsMargins(0, -1, 0, -1);
        label_SJR = new QLabel(pageSCOPUS);
        label_SJR->setObjectName("label_SJR");

        horizontalLayout_SCOPUS->addWidget(label_SJR);

        valSJR = new QLabel(pageSCOPUS);
        valSJR->setObjectName("valSJR");

        horizontalLayout_SCOPUS->addWidget(valSJR);

        spacer_scopus = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SCOPUS->addItem(spacer_scopus);

        label_H = new QLabel(pageSCOPUS);
        label_H->setObjectName("label_H");

        horizontalLayout_SCOPUS->addWidget(label_H);

        valHIndex = new QLabel(pageSCOPUS);
        valHIndex->setObjectName("valHIndex");

        horizontalLayout_SCOPUS->addWidget(valHIndex);

        stackedSpecificInfo->addWidget(pageSCOPUS);
        pageCONF = new QWidget();
        pageCONF->setObjectName("pageCONF");
        gridLayout_CONF = new QGridLayout(pageCONF);
        gridLayout_CONF->setObjectName("gridLayout_CONF");
        gridLayout_CONF->setContentsMargins(0, -1, 0, -1);
        label_ConfRank = new QLabel(pageCONF);
        label_ConfRank->setObjectName("label_ConfRank");

        gridLayout_CONF->addWidget(label_ConfRank, 0, 0, 1, 1);

        valConfRank = new QLabel(pageCONF);
        valConfRank->setObjectName("valConfRank");

        gridLayout_CONF->addWidget(valConfRank, 0, 1, 1, 1);

        label_Rate = new QLabel(pageCONF);
        label_Rate->setObjectName("label_Rate");

        gridLayout_CONF->addWidget(label_Rate, 0, 2, 1, 1);

        valAcceptRate = new QLabel(pageCONF);
        valAcceptRate->setObjectName("valAcceptRate");

        gridLayout_CONF->addWidget(valAcceptRate, 0, 3, 1, 1);

        label_Loc = new QLabel(pageCONF);
        label_Loc->setObjectName("label_Loc");

        gridLayout_CONF->addWidget(label_Loc, 1, 0, 1, 1);

        valLocation = new QLabel(pageCONF);
        valLocation->setObjectName("valLocation");
        valLocation->setWordWrap(true);

        gridLayout_CONF->addWidget(valLocation, 1, 1, 1, 3);

        stackedSpecificInfo->addWidget(pageCONF);
        pageOTHER = new QWidget();
        pageOTHER->setObjectName("pageOTHER");
        verticalLayout_Other = new QVBoxLayout(pageOTHER);
        verticalLayout_Other->setObjectName("verticalLayout_Other");
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

        widget = new QWidget(ArticleDetailsDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnUpdate = new QPushButton(widget);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setStyleSheet(QString::fromUtf8(""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-edit")));
        btnUpdate->setIcon(icon);

        horizontalLayout->addWidget(btnUpdate);

        removeBtn = new QPushButton(widget);
        removeBtn->setObjectName("removeBtn");

        horizontalLayout->addWidget(removeBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName("closeBtn");

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_Main->addWidget(widget);


        retranslateUi(ArticleDetailsDialog);

        stackedSpecificInfo->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ArticleDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleDetailsDialog)
    {
        ArticleDetailsDialog->setWindowTitle(QCoreApplication::translate("ArticleDetailsDialog", "Article Details", nullptr));
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

        label_IF->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_IF->setText(QCoreApplication::translate("ArticleDetailsDialog", "Impact Factor:", nullptr));
        valIF->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "color: #d32f2f; font-weight: bold;", nullptr));
        valIF->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        label_Q->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_Q->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q-Rank:", nullptr));
        valQRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Q1", nullptr));
        label_SJR->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_SJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "SJR:", nullptr));
        valSJR->setText(QCoreApplication::translate("ArticleDetailsDialog", "0.0", nullptr));
        label_H->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_H->setText(QCoreApplication::translate("ArticleDetailsDialog", "H-Index:", nullptr));
        valHIndex->setText(QCoreApplication::translate("ArticleDetailsDialog", "0", nullptr));
        label_ConfRank->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_ConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "Rank:", nullptr));
        valConfRank->setText(QCoreApplication::translate("ArticleDetailsDialog", "A*", nullptr));
        label_Rate->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_Rate->setText(QCoreApplication::translate("ArticleDetailsDialog", "Accept Rate:", nullptr));
        valAcceptRate->setText(QCoreApplication::translate("ArticleDetailsDialog", "20%", nullptr));
        label_Loc->setStyleSheet(QCoreApplication::translate("ArticleDetailsDialog", "font-weight: bold; color: #555;", nullptr));
        label_Loc->setText(QCoreApplication::translate("ArticleDetailsDialog", "Loc:", nullptr));
        valLocation->setText(QCoreApplication::translate("ArticleDetailsDialog", "Paris, France", nullptr));
        grpAuthors->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Authors", nullptr));
        grpAbstract->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "Abstract", nullptr));
        grpRefs->setTitle(QCoreApplication::translate("ArticleDetailsDialog", "References", nullptr));
        btnUpdate->setText(QCoreApplication::translate("ArticleDetailsDialog", "Update Article", nullptr));
        removeBtn->setText(QCoreApplication::translate("ArticleDetailsDialog", "Remove Article", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleDetailsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleDetailsDialog: public Ui_ArticleDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDETAILSDIALOG_H
