/********************************************************************************
** Form generated from reading UI file 'articleinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEINPUTDIALOG_H
#define UI_ARTICLEINPUTDIALOG_H

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

class Ui_ArticleInputDialog
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *labelDialog;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QGroupBox *grpGeneral;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QPlainTextEdit *inputTitle;
    QLabel *labelAbstract;
    QPlainTextEdit *inputAbstract;
    QLabel *labelVenue;
    QLineEdit *inputVenue;
    QLabel *labelYear;
    QSpinBox *inputYear;
    QLabel *labelNCitation;
    QSpinBox *inputCitations;
    QLabel *labelStatus;
    QComboBox *inputStatus;
    QGroupBox *grpSpecific;
    QVBoxLayout *verticalLayout_Specific;
    QHBoxLayout *hl_Type;
    QLabel *labelType;
    QComboBox *inputType;
    QFrame *line;
    QStackedWidget *stackType;
    QWidget *pageScie;
    QGridLayout *gl_Scie;
    QLabel *labelIF;
    QDoubleSpinBox *inputIF;
    QLabel *labelQRank;
    QSpinBox *inputQRank;
    QWidget *pageScopus;
    QGridLayout *gl_Scopus;
    QLabel *lblSJR;
    QDoubleSpinBox *inputSJR;
    QLabel *lblHIndex;
    QSpinBox *inputHIndex;
    QWidget *pageConference;
    QGridLayout *gl_Conf;
    QLabel *lblConfRank;
    QLineEdit *inputConfRank;
    QLabel *lblRate;
    QDoubleSpinBox *inputAcceptRate;
    QLabel *lblLoc;
    QLineEdit *inputLocation;
    QWidget *pageOther;
    QVBoxLayout *vl_Other;
    QLabel *lblOther;
    QGroupBox *grpRefs;
    QVBoxLayout *verticalLayout_Refs;
    QLabel *labelRefs;
    QPlainTextEdit *inputRefs;
    QPushButton *AuthorBtn;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *ArticleInputDialog)
    {
        if (ArticleInputDialog->objectName().isEmpty())
            ArticleInputDialog->setObjectName("ArticleInputDialog");
        ArticleInputDialog->resize(850, 850);
        ArticleInputDialog->setStyleSheet(QString::fromUtf8("\n"
"/* --- C\303\200I \304\220\341\272\266T CHUNG --- */\n"
"QDialog#ArticleInputDialog {\n"
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
"    background-color: #ffff"
                        "ff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* --- T\303\231Y CH\341\273\210NH SPINBOX (N\303\272t tr\303\241i gi\341\272\243m, n\303\272t ph\341\272\243i t\304\203ng) --- */\n"
"QSpinBox, QDoubleSpinBox {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    color: #333333;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    /* Ch\341\273\253a ch\341\273\227 2 b\303\252n cho n\303\272t b\341\272\245m \304\221\341\273\203 kh\303\264ng che s\341\273\221 */\n"
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
"    subcontrol-origin: border;\n"
"    su"
                        "bcontrol-position: right;\n"
"    width: 30px;\n"
"    height: 100%; \n"
"    border-left: 1px solid #cccccc;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"    background-color: #e0e0e0; \n"
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
"QSpinBox::down-button:hover, QDoubleSpinBox::down-button:hover {\n"
"    background-color: #20B2AA; \n"
"}\n"
"   "));
        verticalLayout_Main = new QVBoxLayout(ArticleInputDialog);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleInputDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        labelDialog = new QLabel(headerContainer);
        labelDialog->setObjectName("labelDialog");
        labelDialog->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;"));
        labelDialog->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(labelDialog);


        verticalLayout_Main->addWidget(headerContainer);

        scrollArea = new QScrollArea(ArticleInputDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 640, 884));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setSpacing(15);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        verticalLayout_Content->setContentsMargins(20, 20, 20, 20);
        grpGeneral = new QGroupBox(scrollContent);
        grpGeneral->setObjectName("grpGeneral");
        gridLayout = new QGridLayout(grpGeneral);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(15);
        labelTitle = new QLabel(grpGeneral);
        labelTitle->setObjectName("labelTitle");

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        inputTitle = new QPlainTextEdit(grpGeneral);
        inputTitle->setObjectName("inputTitle");
        inputTitle->setMinimumSize(QSize(0, 60));
        inputTitle->setMaximumSize(QSize(16777215, 80));

        gridLayout->addWidget(inputTitle, 0, 1, 1, 1);

        labelAbstract = new QLabel(grpGeneral);
        labelAbstract->setObjectName("labelAbstract");

        gridLayout->addWidget(labelAbstract, 1, 0, 1, 1);

        inputAbstract = new QPlainTextEdit(grpGeneral);
        inputAbstract->setObjectName("inputAbstract");
        inputAbstract->setMinimumSize(QSize(0, 80));
        inputAbstract->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(inputAbstract, 1, 1, 1, 1);

        labelVenue = new QLabel(grpGeneral);
        labelVenue->setObjectName("labelVenue");

        gridLayout->addWidget(labelVenue, 2, 0, 1, 1);

        inputVenue = new QLineEdit(grpGeneral);
        inputVenue->setObjectName("inputVenue");

        gridLayout->addWidget(inputVenue, 2, 1, 1, 1);

        labelYear = new QLabel(grpGeneral);
        labelYear->setObjectName("labelYear");

        gridLayout->addWidget(labelYear, 3, 0, 1, 1);

        inputYear = new QSpinBox(grpGeneral);
        inputYear->setObjectName("inputYear");
        inputYear->setMinimum(1900);
        inputYear->setMaximum(2100);
        inputYear->setValue(2024);

        gridLayout->addWidget(inputYear, 3, 1, 1, 1);

        labelNCitation = new QLabel(grpGeneral);
        labelNCitation->setObjectName("labelNCitation");

        gridLayout->addWidget(labelNCitation, 4, 0, 1, 1);

        inputCitations = new QSpinBox(grpGeneral);
        inputCitations->setObjectName("inputCitations");
        inputCitations->setMaximum(100000);

        gridLayout->addWidget(inputCitations, 4, 1, 1, 1);

        labelStatus = new QLabel(grpGeneral);
        labelStatus->setObjectName("labelStatus");

        gridLayout->addWidget(labelStatus, 5, 0, 1, 1);

        inputStatus = new QComboBox(grpGeneral);
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->setObjectName("inputStatus");

        gridLayout->addWidget(inputStatus, 5, 1, 1, 1);


        verticalLayout_Content->addWidget(grpGeneral);

        grpSpecific = new QGroupBox(scrollContent);
        grpSpecific->setObjectName("grpSpecific");
        verticalLayout_Specific = new QVBoxLayout(grpSpecific);
        verticalLayout_Specific->setObjectName("verticalLayout_Specific");
        hl_Type = new QHBoxLayout();
        hl_Type->setObjectName("hl_Type");
        labelType = new QLabel(grpSpecific);
        labelType->setObjectName("labelType");

        hl_Type->addWidget(labelType);

        inputType = new QComboBox(grpSpecific);
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->setObjectName("inputType");

        hl_Type->addWidget(inputType);


        verticalLayout_Specific->addLayout(hl_Type);

        line = new QFrame(grpSpecific);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Specific->addWidget(line);

        stackType = new QStackedWidget(grpSpecific);
        stackType->setObjectName("stackType");
        pageScie = new QWidget();
        pageScie->setObjectName("pageScie");
        gl_Scie = new QGridLayout(pageScie);
        gl_Scie->setObjectName("gl_Scie");
        labelIF = new QLabel(pageScie);
        labelIF->setObjectName("labelIF");

        gl_Scie->addWidget(labelIF, 0, 0, 1, 1);

        inputIF = new QDoubleSpinBox(pageScie);
        inputIF->setObjectName("inputIF");
        inputIF->setDecimals(3);

        gl_Scie->addWidget(inputIF, 0, 1, 1, 1);

        labelQRank = new QLabel(pageScie);
        labelQRank->setObjectName("labelQRank");

        gl_Scie->addWidget(labelQRank, 0, 2, 1, 1);

        inputQRank = new QSpinBox(pageScie);
        inputQRank->setObjectName("inputQRank");
        inputQRank->setMinimumSize(QSize(110, 0));
        inputQRank->setMinimum(1);
        inputQRank->setMaximum(4);

        gl_Scie->addWidget(inputQRank, 0, 3, 1, 1);

        stackType->addWidget(pageScie);
        pageScopus = new QWidget();
        pageScopus->setObjectName("pageScopus");
        gl_Scopus = new QGridLayout(pageScopus);
        gl_Scopus->setObjectName("gl_Scopus");
        lblSJR = new QLabel(pageScopus);
        lblSJR->setObjectName("lblSJR");

        gl_Scopus->addWidget(lblSJR, 0, 0, 1, 1);

        inputSJR = new QDoubleSpinBox(pageScopus);
        inputSJR->setObjectName("inputSJR");
        inputSJR->setDecimals(3);

        gl_Scopus->addWidget(inputSJR, 0, 1, 1, 1);

        lblHIndex = new QLabel(pageScopus);
        lblHIndex->setObjectName("lblHIndex");

        gl_Scopus->addWidget(lblHIndex, 0, 2, 1, 1);

        inputHIndex = new QSpinBox(pageScopus);
        inputHIndex->setObjectName("inputHIndex");
        inputHIndex->setMinimumSize(QSize(110, 0));
        inputHIndex->setMaximum(2000);

        gl_Scopus->addWidget(inputHIndex, 0, 3, 1, 1);

        stackType->addWidget(pageScopus);
        pageConference = new QWidget();
        pageConference->setObjectName("pageConference");
        gl_Conf = new QGridLayout(pageConference);
        gl_Conf->setObjectName("gl_Conf");
        lblConfRank = new QLabel(pageConference);
        lblConfRank->setObjectName("lblConfRank");

        gl_Conf->addWidget(lblConfRank, 0, 0, 1, 1);

        inputConfRank = new QLineEdit(pageConference);
        inputConfRank->setObjectName("inputConfRank");

        gl_Conf->addWidget(inputConfRank, 0, 1, 1, 1);

        lblRate = new QLabel(pageConference);
        lblRate->setObjectName("lblRate");

        gl_Conf->addWidget(lblRate, 0, 2, 1, 1);

        inputAcceptRate = new QDoubleSpinBox(pageConference);
        inputAcceptRate->setObjectName("inputAcceptRate");
        inputAcceptRate->setMinimumSize(QSize(110, 0));

        gl_Conf->addWidget(inputAcceptRate, 0, 3, 1, 1);

        lblLoc = new QLabel(pageConference);
        lblLoc->setObjectName("lblLoc");

        gl_Conf->addWidget(lblLoc, 1, 0, 1, 1);

        inputLocation = new QLineEdit(pageConference);
        inputLocation->setObjectName("inputLocation");

        gl_Conf->addWidget(inputLocation, 1, 1, 1, 3);

        stackType->addWidget(pageConference);
        pageOther = new QWidget();
        pageOther->setObjectName("pageOther");
        vl_Other = new QVBoxLayout(pageOther);
        vl_Other->setObjectName("vl_Other");
        lblOther = new QLabel(pageOther);
        lblOther->setObjectName("lblOther");
        lblOther->setStyleSheet(QString::fromUtf8("color: gray; font-style: italic;"));
        lblOther->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Other->addWidget(lblOther);

        stackType->addWidget(pageOther);

        verticalLayout_Specific->addWidget(stackType);


        verticalLayout_Content->addWidget(grpSpecific);

        grpRefs = new QGroupBox(scrollContent);
        grpRefs->setObjectName("grpRefs");
        verticalLayout_Refs = new QVBoxLayout(grpRefs);
        verticalLayout_Refs->setObjectName("verticalLayout_Refs");
        labelRefs = new QLabel(grpRefs);
        labelRefs->setObjectName("labelRefs");

        verticalLayout_Refs->addWidget(labelRefs);

        inputRefs = new QPlainTextEdit(grpRefs);
        inputRefs->setObjectName("inputRefs");
        inputRefs->setMinimumSize(QSize(0, 80));

        verticalLayout_Refs->addWidget(inputRefs);

        AuthorBtn = new QPushButton(grpRefs);
        AuthorBtn->setObjectName("AuthorBtn");
        AuthorBtn->setMinimumSize(QSize(0, 40));
        AuthorBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        AuthorBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#7f8c8d;border:2px solid #7f8c8d;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#636e72;}QPushButton:pressed{background-color:#2d3436;}"));

        verticalLayout_Refs->addWidget(AuthorBtn);


        verticalLayout_Content->addWidget(grpRefs);

        scrollArea->setWidget(scrollContent);

        verticalLayout_Main->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleInputDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setStyleSheet(QString::fromUtf8("background-color:#ffffff;border-top:1px solid #dddddd;"));
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, 10, -1, 10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        btnCancel = new QPushButton(footerContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumSize(QSize(100, 40));
        btnCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        horizontalLayout_Footer->addWidget(btnCancel);

        btnSave = new QPushButton(footerContainer);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(100, 40));
        btnSave->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        horizontalLayout_Footer->addWidget(btnSave);


        verticalLayout_Main->addWidget(footerContainer);


        retranslateUi(ArticleInputDialog);

        stackType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleInputDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleInputDialog)
    {
        ArticleInputDialog->setWindowTitle(QCoreApplication::translate("ArticleInputDialog", "Input Article", nullptr));
        labelDialog->setText(QCoreApplication::translate("ArticleInputDialog", "NH\341\272\254P TH\303\224NG TIN B\303\200I B\303\201O", nullptr));
        grpGeneral->setTitle(QCoreApplication::translate("ArticleInputDialog", "GENERAL INFORMATION", nullptr));
        labelTitle->setText(QCoreApplication::translate("ArticleInputDialog", "Title", nullptr));
        inputTitle->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Enter article title...", nullptr));
        labelAbstract->setText(QCoreApplication::translate("ArticleInputDialog", "Abstract", nullptr));
        inputAbstract->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Enter abstract...", nullptr));
        labelVenue->setText(QCoreApplication::translate("ArticleInputDialog", "Venue", nullptr));
        inputVenue->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Conference or Journal Name...", nullptr));
        labelYear->setText(QCoreApplication::translate("ArticleInputDialog", "Year", nullptr));
        labelNCitation->setText(QCoreApplication::translate("ArticleInputDialog", "Citations", nullptr));
        labelStatus->setText(QCoreApplication::translate("ArticleInputDialog", "Status", nullptr));
        inputStatus->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "DRAFT", nullptr));
        inputStatus->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SUBMITTED", nullptr));
        inputStatus->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "UNDER_REVIEW", nullptr));
        inputStatus->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "REVISIONS", nullptr));
        inputStatus->setItemText(4, QCoreApplication::translate("ArticleInputDialog", "ACCEPTED", nullptr));
        inputStatus->setItemText(5, QCoreApplication::translate("ArticleInputDialog", "REJECTED", nullptr));
        inputStatus->setItemText(6, QCoreApplication::translate("ArticleInputDialog", "PUBLISHED", nullptr));

        grpSpecific->setTitle(QCoreApplication::translate("ArticleInputDialog", "SPECIFIC DETAILS", nullptr));
        labelType->setText(QCoreApplication::translate("ArticleInputDialog", "Article Type:", nullptr));
        inputType->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "SCIE", nullptr));
        inputType->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SCOPUS", nullptr));
        inputType->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "CONFERENCE", nullptr));
        inputType->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "OTHER", nullptr));

        labelIF->setText(QCoreApplication::translate("ArticleInputDialog", "Impact Factor:", nullptr));
        labelQRank->setText(QCoreApplication::translate("ArticleInputDialog", "Q-Rank:", nullptr));
        lblSJR->setText(QCoreApplication::translate("ArticleInputDialog", "SJR:", nullptr));
        lblHIndex->setText(QCoreApplication::translate("ArticleInputDialog", "H-Index:", nullptr));
        lblConfRank->setText(QCoreApplication::translate("ArticleInputDialog", "Rank:", nullptr));
        lblRate->setText(QCoreApplication::translate("ArticleInputDialog", "Accept Rate (%):", nullptr));
        lblLoc->setText(QCoreApplication::translate("ArticleInputDialog", "Location:", nullptr));
        lblOther->setText(QCoreApplication::translate("ArticleInputDialog", "No additional fields required for OTHER type.", nullptr));
        grpRefs->setTitle(QCoreApplication::translate("ArticleInputDialog", "REFERENCES & AUTHORS", nullptr));
        labelRefs->setText(QCoreApplication::translate("ArticleInputDialog", "References (One per line)", nullptr));
        inputRefs->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Enter references...", nullptr));
        AuthorBtn->setText(QCoreApplication::translate("ArticleInputDialog", "Manage Authors (Select / Add New)", nullptr));
        btnCancel->setText(QCoreApplication::translate("ArticleInputDialog", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("ArticleInputDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleInputDialog: public Ui_ArticleInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEINPUTDIALOG_H
