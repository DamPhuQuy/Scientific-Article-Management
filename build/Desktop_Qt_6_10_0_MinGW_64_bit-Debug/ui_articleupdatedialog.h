/********************************************************************************
** Form generated from reading UI file 'articleupdatedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEUPDATEDIALOG_H
#define UI_ARTICLEUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleUpdateDialog
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeaderTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QLabel *label_Title;
    QPlainTextEdit *editTitle;
    QHBoxLayout *horizontalLayout_VenueYear;
    QVBoxLayout *verticalLayout_Venue;
    QLabel *label_Venue;
    QLineEdit *editVenue;
    QGridLayout *gridLayout_Meta;
    QLabel *label_Type;
    QComboBox *comboType;
    QLabel *label_Year;
    QSpinBox *spinYear;
    QLabel *label_Status;
    QComboBox *comboStatus;
    QLabel *label_Cit;
    QSpinBox *spinCitation;
    QFrame *line1;
    QStackedWidget *stackInputs;
    QWidget *pageInputSCIE;
    QHBoxLayout *hl_InputSCIE;
    QLabel *lbl_IF;
    QDoubleSpinBox *spinIF;
    QSpacerItem *hs1;
    QLabel *lbl_Q;
    QSpinBox *spinQRank;
    QWidget *pageInputSCOPUS;
    QHBoxLayout *hl_InputSCOPUS;
    QLabel *lbl_SJR;
    QDoubleSpinBox *spinSJR;
    QSpacerItem *hs2;
    QLabel *lbl_H;
    QSpinBox *spinHIndex;
    QWidget *pageInputCONF;
    QGridLayout *gl_InputCONF;
    QLabel *lbl_CR;
    QLineEdit *editConfRank;
    QLabel *lbl_AR;
    QDoubleSpinBox *spinAcceptRate;
    QLabel *lbl_Loc;
    QLineEdit *editLocation;
    QWidget *pageInputOTHER;
    QFrame *line2;
    QLabel *label_Authors;
    QPlainTextEdit *editAuthors;
    QLabel *label_Abstract;
    QPlainTextEdit *editAbstract;
    QLabel *label_Refs;
    QPlainTextEdit *editRefs;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *ArticleUpdateDialog)
    {
        if (ArticleUpdateDialog->objectName().isEmpty())
            ArticleUpdateDialog->setObjectName("ArticleUpdateDialog");
        ArticleUpdateDialog->resize(600, 800);
        ArticleUpdateDialog->setStyleSheet(QString::fromUtf8("/* --- MAIN DIALOG --- */\n"
"QDialog#ArticleUpdateDialog { \n"
"    background-color: #f4f7f6; \n"
"    border: 4px solid #FFC085; /* Vi\341\273\201n cam d\341\273\213u */\n"
"}\n"
"\n"
"QWidget { font-family: \"Segoe UI\", Arial, sans-serif; font-size: 14px; }\n"
"\n"
"/* --- HEADER --- */\n"
"QWidget#headerContainer { \n"
"    background-color: #00264d; \n"
"    border-bottom: 5px solid #4169E1; \n"
"}\n"
"QLabel#lblHeaderTitle { color: #ffffff; font-size: 22px; font-weight: 900; padding-left: 10px; background: transparent; }\n"
"\n"
"/* --- SCROLL AREA --- */\n"
"QScrollArea { border: 1px solid #20B2AA; border-radius: 8px; background-color: white; }\n"
"\n"
"/* --- INPUTS --- */\n"
"QLineEdit, QPlainTextEdit, QComboBox, QSpinBox, QDoubleSpinBox { \n"
"  background-color: #f9f9f9; \n"
"  border: 1px solid #cccccc; \n"
"  border-radius: 6px; \n"
"  padding: 8px; \n"
"  color: #333; \n"
"}\n"
"QLineEdit:focus, QPlainTextEdit:focus, QComboBox:focus, QSpinBox:focus { \n"
"  background-color: #ffffff; \n"
"  bor"
                        "der: 2px solid #20B2AA; \n"
"}\n"
"\n"
"/* --- LABELS --- */\n"
"QLabel { font-weight: bold; color: #555; }\n"
""));
        mainLayout = new QVBoxLayout(ArticleUpdateDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleUpdateDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, -1, -1, -1);
        lblHeaderTitle = new QLabel(headerContainer);
        lblHeaderTitle->setObjectName("lblHeaderTitle");

        horizontalLayout_Header->addWidget(lblHeaderTitle);


        mainLayout->addWidget(headerContainer);

        scrollArea = new QScrollArea(ArticleUpdateDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 596, 1000));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        label_Title = new QLabel(scrollContent);
        label_Title->setObjectName("label_Title");

        verticalLayout_Content->addWidget(label_Title);

        editTitle = new QPlainTextEdit(scrollContent);
        editTitle->setObjectName("editTitle");
        editTitle->setMinimumSize(QSize(0, 60));
        editTitle->setMaximumSize(QSize(16777215, 80));

        verticalLayout_Content->addWidget(editTitle);

        horizontalLayout_VenueYear = new QHBoxLayout();
        horizontalLayout_VenueYear->setObjectName("horizontalLayout_VenueYear");
        verticalLayout_Venue = new QVBoxLayout();
        verticalLayout_Venue->setObjectName("verticalLayout_Venue");
        label_Venue = new QLabel(scrollContent);
        label_Venue->setObjectName("label_Venue");

        verticalLayout_Venue->addWidget(label_Venue);

        editVenue = new QLineEdit(scrollContent);
        editVenue->setObjectName("editVenue");

        verticalLayout_Venue->addWidget(editVenue);


        horizontalLayout_VenueYear->addLayout(verticalLayout_Venue);


        verticalLayout_Content->addLayout(horizontalLayout_VenueYear);

        gridLayout_Meta = new QGridLayout();
        gridLayout_Meta->setObjectName("gridLayout_Meta");
        gridLayout_Meta->setVerticalSpacing(15);
        label_Type = new QLabel(scrollContent);
        label_Type->setObjectName("label_Type");

        gridLayout_Meta->addWidget(label_Type, 0, 0, 1, 1);

        comboType = new QComboBox(scrollContent);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        gridLayout_Meta->addWidget(comboType, 1, 0, 1, 1);

        label_Year = new QLabel(scrollContent);
        label_Year->setObjectName("label_Year");

        gridLayout_Meta->addWidget(label_Year, 0, 1, 1, 1);

        spinYear = new QSpinBox(scrollContent);
        spinYear->setObjectName("spinYear");
        spinYear->setMinimum(1900);
        spinYear->setMaximum(2100);
        spinYear->setValue(2024);

        gridLayout_Meta->addWidget(spinYear, 1, 1, 1, 1);

        label_Status = new QLabel(scrollContent);
        label_Status->setObjectName("label_Status");

        gridLayout_Meta->addWidget(label_Status, 0, 2, 1, 1);

        comboStatus = new QComboBox(scrollContent);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        gridLayout_Meta->addWidget(comboStatus, 1, 2, 1, 1);

        label_Cit = new QLabel(scrollContent);
        label_Cit->setObjectName("label_Cit");

        gridLayout_Meta->addWidget(label_Cit, 0, 3, 1, 1);

        spinCitation = new QSpinBox(scrollContent);
        spinCitation->setObjectName("spinCitation");
        spinCitation->setMaximum(999999);

        gridLayout_Meta->addWidget(spinCitation, 1, 3, 1, 1);


        verticalLayout_Content->addLayout(gridLayout_Meta);

        line1 = new QFrame(scrollContent);
        line1->setObjectName("line1");
        line1->setFrameShape(QFrame::Shape::HLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Content->addWidget(line1);

        stackInputs = new QStackedWidget(scrollContent);
        stackInputs->setObjectName("stackInputs");
        stackInputs->setMinimumSize(QSize(0, 80));
        pageInputSCIE = new QWidget();
        pageInputSCIE->setObjectName("pageInputSCIE");
        hl_InputSCIE = new QHBoxLayout(pageInputSCIE);
        hl_InputSCIE->setObjectName("hl_InputSCIE");
        lbl_IF = new QLabel(pageInputSCIE);
        lbl_IF->setObjectName("lbl_IF");

        hl_InputSCIE->addWidget(lbl_IF);

        spinIF = new QDoubleSpinBox(pageInputSCIE);
        spinIF->setObjectName("spinIF");

        hl_InputSCIE->addWidget(spinIF);

        hs1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hl_InputSCIE->addItem(hs1);

        lbl_Q = new QLabel(pageInputSCIE);
        lbl_Q->setObjectName("lbl_Q");

        hl_InputSCIE->addWidget(lbl_Q);

        spinQRank = new QSpinBox(pageInputSCIE);
        spinQRank->setObjectName("spinQRank");
        spinQRank->setMinimum(1);
        spinQRank->setMaximum(4);

        hl_InputSCIE->addWidget(spinQRank);

        stackInputs->addWidget(pageInputSCIE);
        pageInputSCOPUS = new QWidget();
        pageInputSCOPUS->setObjectName("pageInputSCOPUS");
        hl_InputSCOPUS = new QHBoxLayout(pageInputSCOPUS);
        hl_InputSCOPUS->setObjectName("hl_InputSCOPUS");
        lbl_SJR = new QLabel(pageInputSCOPUS);
        lbl_SJR->setObjectName("lbl_SJR");

        hl_InputSCOPUS->addWidget(lbl_SJR);

        spinSJR = new QDoubleSpinBox(pageInputSCOPUS);
        spinSJR->setObjectName("spinSJR");

        hl_InputSCOPUS->addWidget(spinSJR);

        hs2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hl_InputSCOPUS->addItem(hs2);

        lbl_H = new QLabel(pageInputSCOPUS);
        lbl_H->setObjectName("lbl_H");

        hl_InputSCOPUS->addWidget(lbl_H);

        spinHIndex = new QSpinBox(pageInputSCOPUS);
        spinHIndex->setObjectName("spinHIndex");

        hl_InputSCOPUS->addWidget(spinHIndex);

        stackInputs->addWidget(pageInputSCOPUS);
        pageInputCONF = new QWidget();
        pageInputCONF->setObjectName("pageInputCONF");
        gl_InputCONF = new QGridLayout(pageInputCONF);
        gl_InputCONF->setObjectName("gl_InputCONF");
        lbl_CR = new QLabel(pageInputCONF);
        lbl_CR->setObjectName("lbl_CR");

        gl_InputCONF->addWidget(lbl_CR, 0, 0, 1, 1);

        editConfRank = new QLineEdit(pageInputCONF);
        editConfRank->setObjectName("editConfRank");

        gl_InputCONF->addWidget(editConfRank, 0, 1, 1, 1);

        lbl_AR = new QLabel(pageInputCONF);
        lbl_AR->setObjectName("lbl_AR");

        gl_InputCONF->addWidget(lbl_AR, 0, 2, 1, 1);

        spinAcceptRate = new QDoubleSpinBox(pageInputCONF);
        spinAcceptRate->setObjectName("spinAcceptRate");

        gl_InputCONF->addWidget(spinAcceptRate, 0, 3, 1, 1);

        lbl_Loc = new QLabel(pageInputCONF);
        lbl_Loc->setObjectName("lbl_Loc");

        gl_InputCONF->addWidget(lbl_Loc, 1, 0, 1, 1);

        editLocation = new QLineEdit(pageInputCONF);
        editLocation->setObjectName("editLocation");

        gl_InputCONF->addWidget(editLocation, 1, 1, 1, 3);

        stackInputs->addWidget(pageInputCONF);
        pageInputOTHER = new QWidget();
        pageInputOTHER->setObjectName("pageInputOTHER");
        stackInputs->addWidget(pageInputOTHER);

        verticalLayout_Content->addWidget(stackInputs);

        line2 = new QFrame(scrollContent);
        line2->setObjectName("line2");
        line2->setFrameShape(QFrame::Shape::HLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Content->addWidget(line2);

        label_Authors = new QLabel(scrollContent);
        label_Authors->setObjectName("label_Authors");

        verticalLayout_Content->addWidget(label_Authors);

        editAuthors = new QPlainTextEdit(scrollContent);
        editAuthors->setObjectName("editAuthors");
        editAuthors->setMinimumSize(QSize(0, 80));

        verticalLayout_Content->addWidget(editAuthors);

        label_Abstract = new QLabel(scrollContent);
        label_Abstract->setObjectName("label_Abstract");

        verticalLayout_Content->addWidget(label_Abstract);

        editAbstract = new QPlainTextEdit(scrollContent);
        editAbstract->setObjectName("editAbstract");
        editAbstract->setMinimumSize(QSize(0, 80));

        verticalLayout_Content->addWidget(editAbstract);

        label_Refs = new QLabel(scrollContent);
        label_Refs->setObjectName("label_Refs");

        verticalLayout_Content->addWidget(label_Refs);

        editRefs = new QPlainTextEdit(scrollContent);
        editRefs->setObjectName("editRefs");
        editRefs->setMinimumSize(QSize(0, 80));

        verticalLayout_Content->addWidget(editRefs);

        scrollArea->setWidget(scrollContent);

        mainLayout->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleUpdateDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setMinimumSize(QSize(0, 70));
        footerContainer->setStyleSheet(QString::fromUtf8("background-color: #ffffff; border-top: 1px solid #ddd;"));
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, -1, 30, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        closeBtn = new QPushButton(footerContainer);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMinimumSize(QSize(100, 35));
        closeBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"           background-color: #da3e36; \n"
"           border: 2px solid #da3e36; \n"
"           border-radius: 6px; \n"
"           color: white; \n"
"           font-weight: bold;\n"
"           font-size: 14px;\n"
"          }\n"
"          QPushButton:hover { background-color: #c0392b; }\n"
"          QPushButton:pressed { background-color: #922b21; }\n"
"         "));

        horizontalLayout_Footer->addWidget(closeBtn);

        saveBtn = new QPushButton(footerContainer);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setMinimumSize(QSize(100, 35));
        saveBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"           background-color: #20B2AA; \n"
"           border: 2px solid #20B2AA; \n"
"           border-radius: 6px; \n"
"           color: white; \n"
"           font-weight: bold;\n"
"           font-size: 14px;\n"
"          }\n"
"          QPushButton:hover { background-color: #17a098; }\n"
"          QPushButton:pressed { background-color: #0e6b65; }\n"
"         "));

        horizontalLayout_Footer->addWidget(saveBtn);


        mainLayout->addWidget(footerContainer);


        retranslateUi(ArticleUpdateDialog);

        stackInputs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleUpdateDialog)
    {
        ArticleUpdateDialog->setWindowTitle(QCoreApplication::translate("ArticleUpdateDialog", "Update Article Information", nullptr));
        lblHeaderTitle->setText(QCoreApplication::translate("ArticleUpdateDialog", "C\341\272\254P NH\341\272\254T B\303\200I B\303\201O", nullptr));
        label_Title->setText(QCoreApplication::translate("ArticleUpdateDialog", "Title", nullptr));
        editTitle->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Enter article title here...", nullptr));
        label_Venue->setText(QCoreApplication::translate("ArticleUpdateDialog", "Venue", nullptr));
        editVenue->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Conference or Journal Name", nullptr));
        label_Type->setText(QCoreApplication::translate("ArticleUpdateDialog", "Type", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "SCIE", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SCOPUS", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "CONFERENCE", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "OTHER", nullptr));

        label_Year->setText(QCoreApplication::translate("ArticleUpdateDialog", "Year", nullptr));
        label_Status->setText(QCoreApplication::translate("ArticleUpdateDialog", "Status", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "DRAFT", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SUBMITTED", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "UNDER_REVIEW", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "REVISIONS", nullptr));
        comboStatus->setItemText(4, QCoreApplication::translate("ArticleUpdateDialog", "ACCEPTED", nullptr));
        comboStatus->setItemText(5, QCoreApplication::translate("ArticleUpdateDialog", "REJECTED", nullptr));
        comboStatus->setItemText(6, QCoreApplication::translate("ArticleUpdateDialog", "PUBLISHED", nullptr));

        label_Cit->setText(QCoreApplication::translate("ArticleUpdateDialog", "Citations", nullptr));
        lbl_IF->setText(QCoreApplication::translate("ArticleUpdateDialog", "Impact Factor:", nullptr));
        lbl_Q->setText(QCoreApplication::translate("ArticleUpdateDialog", "Q-Rank:", nullptr));
        lbl_SJR->setText(QCoreApplication::translate("ArticleUpdateDialog", "SJR:", nullptr));
        lbl_H->setText(QCoreApplication::translate("ArticleUpdateDialog", "H-Index:", nullptr));
        lbl_CR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Rank:", nullptr));
        lbl_AR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Accept Rate (%):", nullptr));
        lbl_Loc->setText(QCoreApplication::translate("ArticleUpdateDialog", "Location:", nullptr));
        label_Authors->setText(QCoreApplication::translate("ArticleUpdateDialog", "Authors (One per line)", nullptr));
        editAuthors->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Enter authors here...", nullptr));
        label_Abstract->setText(QCoreApplication::translate("ArticleUpdateDialog", "Abstract", nullptr));
        label_Refs->setText(QCoreApplication::translate("ArticleUpdateDialog", "References (One per line)", nullptr));
        editRefs->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Ref 1...\n"
"Ref 2...", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "H\341\273\247y", nullptr));
        saveBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "L\306\260u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleUpdateDialog: public Ui_ArticleUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEUPDATEDIALOG_H
