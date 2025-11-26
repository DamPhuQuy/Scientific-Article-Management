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
#include <QtWidgets/QGroupBox>
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
    QVBoxLayout *verticalLayout_Main;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeaderTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QGroupBox *grpGeneral;
    QGridLayout *gridLayout;
    QLabel *label_Title;
    QPlainTextEdit *editTitle;
    QLabel *label_Venue;
    QLineEdit *editVenue;
    QLabel *label_Year;
    QSpinBox *spinYear;
    QLabel *label_Cit;
    QSpinBox *spinCitation;
    QLabel *label_Status;
    QComboBox *comboStatus;
    QLabel *label_Abstract;
    QPlainTextEdit *editAbstract;
    QGroupBox *grpSpecific;
    QVBoxLayout *verticalLayout_Specific;
    QHBoxLayout *hl_Type;
    QLabel *label_Type;
    QComboBox *comboType;
    QFrame *line;
    QStackedWidget *stackInputs;
    QWidget *pageInputSCIE;
    QGridLayout *gl_Scie;
    QLabel *lbl_IF;
    QDoubleSpinBox *spinIF;
    QLabel *lbl_Q;
    QSpinBox *spinQRank;
    QWidget *pageInputSCOPUS;
    QGridLayout *gl_Scopus;
    QLabel *lbl_SJR;
    QDoubleSpinBox *spinSJR;
    QLabel *lbl_H;
    QSpinBox *spinHIndex;
    QWidget *pageInputCONF;
    QGridLayout *gl_Conf;
    QLabel *lbl_CR;
    QLineEdit *editConfRank;
    QLabel *lbl_AR;
    QDoubleSpinBox *spinAcceptRate;
    QLabel *lbl_Loc;
    QLineEdit *editLocation;
    QWidget *pageInputOTHER;
    QVBoxLayout *vl_Other;
    QLabel *lblOther;
    QGroupBox *grpAuthorsRefs;
    QVBoxLayout *verticalLayout_AR;
    QLabel *label_Authors;
    QPlainTextEdit *editAuthors;
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
        ArticleUpdateDialog->resize(650, 850);
        ArticleUpdateDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#ArticleUpdateDialog {\n"
"    background-color: #f4f7f6;\n"
"    border: 4px solid #FFC085;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"QScrollArea {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"QGroupBox {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    padding-top: 15px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 5px;\n"
"    color: #20B2AA;\n"
"    font-weight: bold;\n"
"    left: 10px;\n"
"    top: 0px;\n"
"}\n"
"QLineEdit, QPlainTextEdit, QComboBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    color: #333333;\n"
"}\n"
"QLineEdit:focus, QPlainTextEdit:focus, QComboBox:focus {\n"
"    background-color: #fff"
                        "fff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* --- T\303\231Y CH\341\273\210NH SPINBOX (YEAR, CITATION, ETC) --- */\n"
"/* T\341\272\241o giao di\341\273\207n n\303\272t Tr\303\241i/Ph\341\272\243i */\n"
"QSpinBox, QDoubleSpinBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    color: #333333;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    /* Quan tr\341\273\215ng: Ch\341\273\253a ch\341\273\227 tr\341\273\221ng 2 b\303\252n cho n\303\272t b\341\272\245m */\n"
"    padding-left: 35px;  \n"
"    padding-right: 35px;\n"
"    /* C\304\203n gi\341\273\257a s\341\273\221 */\n"
"    qproperty-alignment: AlignCenter; \n"
"}\n"
"QSpinBox:focus, QDoubleSpinBox:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* N\303\272t T\304\203ng (Up-Button) -> \304\220\306\260a v\341\273\201 b\303\252n PH\341\272\242I */\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: bor"
                        "der;\n"
"    subcontrol-position: right;\n"
"    width: 30px;\n"
"    height: 100%; /* Chi\341\273\201u cao b\341\272\261ng parent */\n"
"    border-left: 1px solid #cccccc;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background-color: #e0e0e0; /* M\303\240u n\341\273\201n n\303\272t */\n"
"}\n"
"\n"
"/* N\303\272t Gi\341\272\243m (Down-Button) -> \304\220\306\260a v\341\273\201 b\303\252n TR\303\201I */\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: left;\n"
"    width: 30px;\n"
"    height: 100%;\n"
"    border-right: 1px solid #cccccc;\n"
"    border-top-left-radius: 6px;\n"
"    border-bottom-left-radius: 6px;\n"
"    background-color: #e0e0e0;\n"
"}\n"
"\n"
"/* Hi\341\273\207u \341\273\251ng khi di chu\341\273\231t v\303\240o n\303\272t t\304\203ng/gi\341\272\243m */\n"
"QSpinBox::up-button:hover, QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover, QDoubleSpinBox::down-button:"
                        "hover {\n"
"    background-color: #20B2AA; /* \304\220\341\273\225i m\303\240u xanh ng\341\273\215c */\n"
"}\n"
"\n"
"/* T\303\271y ch\341\273\211nh m\305\251i t\303\252n (Opsional: \304\221\341\273\203 m\341\272\267c \304\221\341\273\213nh Qt s\341\272\275 t\341\273\261 v\341\272\275 m\305\251i t\303\252n l\303\252n/xu\341\273\221ng) */\n"
"/* N\341\272\277u mu\341\273\221n \304\221\341\272\271p h\306\241n, b\341\272\241n c\303\263 th\341\273\203 thay b\341\272\261ng icon h\303\254nh d\341\272\245u + v\303\240 - */\n"
"   "));
        verticalLayout_Main = new QVBoxLayout(ArticleUpdateDialog);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleUpdateDialog);
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

        scrollArea = new QScrollArea(ArticleUpdateDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 640, 927));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        grpGeneral = new QGroupBox(scrollContent);
        grpGeneral->setObjectName("grpGeneral");
        gridLayout = new QGridLayout(grpGeneral);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(15);
        label_Title = new QLabel(grpGeneral);
        label_Title->setObjectName("label_Title");

        gridLayout->addWidget(label_Title, 0, 0, 1, 1);

        editTitle = new QPlainTextEdit(grpGeneral);
        editTitle->setObjectName("editTitle");
        editTitle->setMinimumSize(QSize(0, 60));
        editTitle->setMaximumSize(QSize(16777215, 80));

        gridLayout->addWidget(editTitle, 0, 1, 1, 1);

        label_Venue = new QLabel(grpGeneral);
        label_Venue->setObjectName("label_Venue");

        gridLayout->addWidget(label_Venue, 1, 0, 1, 1);

        editVenue = new QLineEdit(grpGeneral);
        editVenue->setObjectName("editVenue");

        gridLayout->addWidget(editVenue, 1, 1, 1, 1);

        label_Year = new QLabel(grpGeneral);
        label_Year->setObjectName("label_Year");

        gridLayout->addWidget(label_Year, 2, 0, 1, 1);

        spinYear = new QSpinBox(grpGeneral);
        spinYear->setObjectName("spinYear");
        spinYear->setMinimum(1900);
        spinYear->setMaximum(2100);
        spinYear->setValue(2024);

        gridLayout->addWidget(spinYear, 2, 1, 1, 1);

        label_Cit = new QLabel(grpGeneral);
        label_Cit->setObjectName("label_Cit");

        gridLayout->addWidget(label_Cit, 3, 0, 1, 1);

        spinCitation = new QSpinBox(grpGeneral);
        spinCitation->setObjectName("spinCitation");
        spinCitation->setMaximum(100000);

        gridLayout->addWidget(spinCitation, 3, 1, 1, 1);

        label_Status = new QLabel(grpGeneral);
        label_Status->setObjectName("label_Status");

        gridLayout->addWidget(label_Status, 4, 0, 1, 1);

        comboStatus = new QComboBox(grpGeneral);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        gridLayout->addWidget(comboStatus, 4, 1, 1, 1);

        label_Abstract = new QLabel(grpGeneral);
        label_Abstract->setObjectName("label_Abstract");

        gridLayout->addWidget(label_Abstract, 5, 0, 1, 1);

        editAbstract = new QPlainTextEdit(grpGeneral);
        editAbstract->setObjectName("editAbstract");
        editAbstract->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(editAbstract, 5, 1, 1, 1);


        verticalLayout_Content->addWidget(grpGeneral);

        grpSpecific = new QGroupBox(scrollContent);
        grpSpecific->setObjectName("grpSpecific");
        verticalLayout_Specific = new QVBoxLayout(grpSpecific);
        verticalLayout_Specific->setObjectName("verticalLayout_Specific");
        hl_Type = new QHBoxLayout();
        hl_Type->setObjectName("hl_Type");
        label_Type = new QLabel(grpSpecific);
        label_Type->setObjectName("label_Type");

        hl_Type->addWidget(label_Type);

        comboType = new QComboBox(grpSpecific);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        hl_Type->addWidget(comboType);


        verticalLayout_Specific->addLayout(hl_Type);

        line = new QFrame(grpSpecific);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Specific->addWidget(line);

        stackInputs = new QStackedWidget(grpSpecific);
        stackInputs->setObjectName("stackInputs");
        pageInputSCIE = new QWidget();
        pageInputSCIE->setObjectName("pageInputSCIE");
        gl_Scie = new QGridLayout(pageInputSCIE);
        gl_Scie->setObjectName("gl_Scie");
        lbl_IF = new QLabel(pageInputSCIE);
        lbl_IF->setObjectName("lbl_IF");

        gl_Scie->addWidget(lbl_IF, 0, 0, 1, 1);

        spinIF = new QDoubleSpinBox(pageInputSCIE);
        spinIF->setObjectName("spinIF");
        spinIF->setDecimals(3);

        gl_Scie->addWidget(spinIF, 0, 1, 1, 1);

        lbl_Q = new QLabel(pageInputSCIE);
        lbl_Q->setObjectName("lbl_Q");

        gl_Scie->addWidget(lbl_Q, 0, 2, 1, 1);

        spinQRank = new QSpinBox(pageInputSCIE);
        spinQRank->setObjectName("spinQRank");
        spinQRank->setMinimum(1);
        spinQRank->setMaximum(4);

        gl_Scie->addWidget(spinQRank, 0, 3, 1, 1);

        stackInputs->addWidget(pageInputSCIE);
        pageInputSCOPUS = new QWidget();
        pageInputSCOPUS->setObjectName("pageInputSCOPUS");
        gl_Scopus = new QGridLayout(pageInputSCOPUS);
        gl_Scopus->setObjectName("gl_Scopus");
        lbl_SJR = new QLabel(pageInputSCOPUS);
        lbl_SJR->setObjectName("lbl_SJR");

        gl_Scopus->addWidget(lbl_SJR, 0, 0, 1, 1);

        spinSJR = new QDoubleSpinBox(pageInputSCOPUS);
        spinSJR->setObjectName("spinSJR");
        spinSJR->setDecimals(3);

        gl_Scopus->addWidget(spinSJR, 0, 1, 1, 1);

        lbl_H = new QLabel(pageInputSCOPUS);
        lbl_H->setObjectName("lbl_H");

        gl_Scopus->addWidget(lbl_H, 0, 2, 1, 1);

        spinHIndex = new QSpinBox(pageInputSCOPUS);
        spinHIndex->setObjectName("spinHIndex");
        spinHIndex->setMaximum(2000);

        gl_Scopus->addWidget(spinHIndex, 0, 3, 1, 1);

        stackInputs->addWidget(pageInputSCOPUS);
        pageInputCONF = new QWidget();
        pageInputCONF->setObjectName("pageInputCONF");
        gl_Conf = new QGridLayout(pageInputCONF);
        gl_Conf->setObjectName("gl_Conf");
        lbl_CR = new QLabel(pageInputCONF);
        lbl_CR->setObjectName("lbl_CR");

        gl_Conf->addWidget(lbl_CR, 0, 0, 1, 1);

        editConfRank = new QLineEdit(pageInputCONF);
        editConfRank->setObjectName("editConfRank");

        gl_Conf->addWidget(editConfRank, 0, 1, 1, 1);

        lbl_AR = new QLabel(pageInputCONF);
        lbl_AR->setObjectName("lbl_AR");

        gl_Conf->addWidget(lbl_AR, 0, 2, 1, 1);

        spinAcceptRate = new QDoubleSpinBox(pageInputCONF);
        spinAcceptRate->setObjectName("spinAcceptRate");

        gl_Conf->addWidget(spinAcceptRate, 0, 3, 1, 1);

        lbl_Loc = new QLabel(pageInputCONF);
        lbl_Loc->setObjectName("lbl_Loc");

        gl_Conf->addWidget(lbl_Loc, 1, 0, 1, 1);

        editLocation = new QLineEdit(pageInputCONF);
        editLocation->setObjectName("editLocation");

        gl_Conf->addWidget(editLocation, 1, 1, 1, 3);

        stackInputs->addWidget(pageInputCONF);
        pageInputOTHER = new QWidget();
        pageInputOTHER->setObjectName("pageInputOTHER");
        vl_Other = new QVBoxLayout(pageInputOTHER);
        vl_Other->setObjectName("vl_Other");
        lblOther = new QLabel(pageInputOTHER);
        lblOther->setObjectName("lblOther");
        lblOther->setStyleSheet(QString::fromUtf8("color: gray; font-style: italic;"));
        lblOther->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Other->addWidget(lblOther);

        stackInputs->addWidget(pageInputOTHER);

        verticalLayout_Specific->addWidget(stackInputs);


        verticalLayout_Content->addWidget(grpSpecific);

        grpAuthorsRefs = new QGroupBox(scrollContent);
        grpAuthorsRefs->setObjectName("grpAuthorsRefs");
        verticalLayout_AR = new QVBoxLayout(grpAuthorsRefs);
        verticalLayout_AR->setObjectName("verticalLayout_AR");
        label_Authors = new QLabel(grpAuthorsRefs);
        label_Authors->setObjectName("label_Authors");

        verticalLayout_AR->addWidget(label_Authors);

        editAuthors = new QPlainTextEdit(grpAuthorsRefs);
        editAuthors->setObjectName("editAuthors");
        editAuthors->setMinimumSize(QSize(0, 60));

        verticalLayout_AR->addWidget(editAuthors);

        label_Refs = new QLabel(grpAuthorsRefs);
        label_Refs->setObjectName("label_Refs");

        verticalLayout_AR->addWidget(label_Refs);

        editRefs = new QPlainTextEdit(grpAuthorsRefs);
        editRefs->setObjectName("editRefs");
        editRefs->setMinimumSize(QSize(0, 60));

        verticalLayout_AR->addWidget(editRefs);


        verticalLayout_Content->addWidget(grpAuthorsRefs);

        scrollArea->setWidget(scrollContent);

        verticalLayout_Main->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleUpdateDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setStyleSheet(QString::fromUtf8("background-color:#ffffff;border-top:1px solid #dddddd;"));
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, 10, -1, 10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        closeBtn = new QPushButton(footerContainer);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMinimumSize(QSize(100, 0));
        closeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        horizontalLayout_Footer->addWidget(closeBtn);

        saveBtn = new QPushButton(footerContainer);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setMinimumSize(QSize(100, 40));
        saveBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        saveBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        horizontalLayout_Footer->addWidget(saveBtn);


        verticalLayout_Main->addWidget(footerContainer);


        retranslateUi(ArticleUpdateDialog);
        QObject::connect(closeBtn, &QPushButton::clicked, ArticleUpdateDialog, qOverload<>(&QDialog::reject));

        stackInputs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleUpdateDialog)
    {
        ArticleUpdateDialog->setWindowTitle(QCoreApplication::translate("ArticleUpdateDialog", "Update Article", nullptr));
        lblHeaderTitle->setText(QCoreApplication::translate("ArticleUpdateDialog", "C\341\272\254P NH\341\272\254T B\303\200I B\303\201O", nullptr));
        grpGeneral->setTitle(QCoreApplication::translate("ArticleUpdateDialog", "GENERAL INFORMATION", nullptr));
        label_Title->setText(QCoreApplication::translate("ArticleUpdateDialog", "Title", nullptr));
        editTitle->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Update article title...", nullptr));
        label_Venue->setText(QCoreApplication::translate("ArticleUpdateDialog", "Venue", nullptr));
        editVenue->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Conference or Journal Name...", nullptr));
        label_Year->setText(QCoreApplication::translate("ArticleUpdateDialog", "Year", nullptr));
        label_Cit->setText(QCoreApplication::translate("ArticleUpdateDialog", "Citations", nullptr));
        label_Status->setText(QCoreApplication::translate("ArticleUpdateDialog", "Status", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "DRAFT", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SUBMITTED", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "UNDER_REVIEW", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "REVISIONS", nullptr));
        comboStatus->setItemText(4, QCoreApplication::translate("ArticleUpdateDialog", "ACCEPTED", nullptr));
        comboStatus->setItemText(5, QCoreApplication::translate("ArticleUpdateDialog", "REJECTED", nullptr));
        comboStatus->setItemText(6, QCoreApplication::translate("ArticleUpdateDialog", "PUBLISHED", nullptr));

        label_Abstract->setText(QCoreApplication::translate("ArticleUpdateDialog", "Abstract", nullptr));
        editAbstract->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Update abstract...", nullptr));
        grpSpecific->setTitle(QCoreApplication::translate("ArticleUpdateDialog", "SPECIFIC DETAILS", nullptr));
        label_Type->setText(QCoreApplication::translate("ArticleUpdateDialog", "Article Type:", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "SCIE", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SCOPUS", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "CONFERENCE", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "OTHER", nullptr));

        lbl_IF->setText(QCoreApplication::translate("ArticleUpdateDialog", "Impact Factor:", nullptr));
        lbl_Q->setText(QCoreApplication::translate("ArticleUpdateDialog", "Q-Rank:", nullptr));
        lbl_SJR->setText(QCoreApplication::translate("ArticleUpdateDialog", "SJR:", nullptr));
        lbl_H->setText(QCoreApplication::translate("ArticleUpdateDialog", "H-Index:", nullptr));
        lbl_CR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Rank:", nullptr));
        lbl_AR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Accept Rate (%):", nullptr));
        lbl_Loc->setText(QCoreApplication::translate("ArticleUpdateDialog", "Location:", nullptr));
        lblOther->setText(QCoreApplication::translate("ArticleUpdateDialog", "No additional fields required for OTHER type.", nullptr));
        grpAuthorsRefs->setTitle(QCoreApplication::translate("ArticleUpdateDialog", "AUTHORS & REFERENCES", nullptr));
        label_Authors->setText(QCoreApplication::translate("ArticleUpdateDialog", "Authors (One per line)", nullptr));
        editAuthors->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Update authors...", nullptr));
        label_Refs->setText(QCoreApplication::translate("ArticleUpdateDialog", "References (One per line)", nullptr));
        editRefs->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Update references...", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "Close", nullptr));
        saveBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleUpdateDialog: public Ui_ArticleUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEUPDATEDIALOG_H
