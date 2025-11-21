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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
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
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Scroll;
    QGridLayout *gridLayout;
    QLabel *lblTitleInput;
    QPlainTextEdit *inputTitle;
    QLabel *lblAbstract;
    QPlainTextEdit *inputAbstract;
    QLabel *lblVenue;
    QPlainTextEdit *inputVenue;
    QLabel *lblYear;
    QSpinBox *inputYear;
    QLabel *lblCitation;
    QSpinBox *inputCitations;
    QLabel *lblStatus;
    QComboBox *inputStatus;
    QLabel *lblRefs;
    QPlainTextEdit *inputRefs;
    QLabel *lblType;
    QComboBox *inputType;
    QStackedWidget *stackType;
    QWidget *pageScie;
    QFormLayout *formLayout;
    QLabel *labelIF;
    QDoubleSpinBox *inputIF;
    QLabel *labelQ;
    QSpinBox *inputQRank;
    QWidget *pageScopus;
    QFormLayout *formLayout_2;
    QLabel *labelSJR;
    QDoubleSpinBox *inputSJR;
    QLabel *labelH;
    QSpinBox *inputHIndex;
    QWidget *pageConference;
    QFormLayout *formLayout_3;
    QLabel *labelConfRank;
    QLineEdit *inputConfRank;
    QLabel *labelLoc;
    QLineEdit *inputLocation;
    QLabel *labelAcc;
    QDoubleSpinBox *inputAcceptRate;
    QWidget *pageOther;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelOther;
    QLabel *lblAuthorsHeader;
    QListView *listAuthors;
    QPushButton *AuthorBtn;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *ArticleInputDialog)
    {
        if (ArticleInputDialog->objectName().isEmpty())
            ArticleInputDialog->setObjectName("ArticleInputDialog");
        ArticleInputDialog->resize(650, 900);
        ArticleInputDialog->setStyleSheet(QString::fromUtf8("QDialog#ArticleInputDialog{background-color:#f4f7f6;}QWidget{font-family:\"Segoe UI\",Arial,sans-serif;}QWidget#headerContainer{background-color:#00264d;border-left:10px solid #FFD700;border-bottom:5px solid #4169E1;}QLabel#lblTitle{color:#ffffff;font-size:22px;font-weight:900;background-color:transparent;padding-left:15px;}QScrollArea#scrollArea{border:2px solid #20B2AA;border-radius:8px;background-color:#ffffff;}QWidget#scrollContent{background-color:transparent;}QLineEdit,QComboBox,QSpinBox,QDoubleSpinBox,QTextEdit,QPlainTextEdit{background-color:#f9f9f9;border:1px solid #cccccc;border-radius:6px;padding:6px;font-size:14px;color:#333;min-height:40px;}QLineEdit:focus,QComboBox:focus,QSpinBox:focus,QTextEdit:focus,QPlainTextEdit:focus{background-color:#ffffff;border:2px solid #20B2AA;}QComboBox::drop-down{border:0px;}QLabel{font-weight:bold;color:#555;font-size:14px;}QLabel#lblAuthorsHeader{color:#000000;font-size:16px;margin-top:15px;font-weight:900;}QListView{background-color:#fff;border:1px solid #ccc;bord"
                        "er-radius:6px;}QPushButton{border-radius:6px;font-weight:bold;padding:8px 16px;font-size:14px;color:white;}QPushButton#btnSave,QPushButton#AuthorBtn{background-color:#20B2AA;border:2px solid #20B2AA;}QPushButton#btnSave:hover,QPushButton#AuthorBtn:hover{background-color:#17a098;border-color:#17a098;}QPushButton#btnCancel{background-color:#da3e36;border:2px solid #da3e36;}QPushButton#btnCancel:hover{background-color:#c0392b;border-color:#c0392b;}QWidget#footerContainer{background-color:#ffffff;border-top:1px solid #ddd;}"));
        mainLayout = new QVBoxLayout(ArticleInputDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(ArticleInputDialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 80));
        horizontalLayout = new QHBoxLayout(headerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblTitle = new QLabel(headerContainer);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);

        horizontalLayout->addWidget(lblTitle);


        mainLayout->addWidget(headerContainer);

        scrollArea = new QScrollArea(ArticleInputDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setStyleSheet(QString::fromUtf8("margin: 15px;"));
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 618, 1250));
        verticalLayout_Scroll = new QVBoxLayout(scrollContent);
        verticalLayout_Scroll->setSpacing(20);
        verticalLayout_Scroll->setObjectName("verticalLayout_Scroll");
        verticalLayout_Scroll->setContentsMargins(20, 20, 20, 20);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(15);
        lblTitleInput = new QLabel(scrollContent);
        lblTitleInput->setObjectName("lblTitleInput");

        gridLayout->addWidget(lblTitleInput, 0, 0, 1, 1);

        inputTitle = new QPlainTextEdit(scrollContent);
        inputTitle->setObjectName("inputTitle");
        inputTitle->setMinimumSize(QSize(0, 60));
        inputTitle->setMaximumSize(QSize(16777215, 80));

        gridLayout->addWidget(inputTitle, 0, 1, 1, 1);

        lblAbstract = new QLabel(scrollContent);
        lblAbstract->setObjectName("lblAbstract");
        lblAbstract->setAlignment(Qt::AlignTop);

        gridLayout->addWidget(lblAbstract, 1, 0, 1, 1);

        inputAbstract = new QPlainTextEdit(scrollContent);
        inputAbstract->setObjectName("inputAbstract");
        inputAbstract->setMinimumSize(QSize(0, 80));

        gridLayout->addWidget(inputAbstract, 1, 1, 1, 1);

        lblVenue = new QLabel(scrollContent);
        lblVenue->setObjectName("lblVenue");

        gridLayout->addWidget(lblVenue, 2, 0, 1, 1);

        inputVenue = new QPlainTextEdit(scrollContent);
        inputVenue->setObjectName("inputVenue");
        inputVenue->setMinimumSize(QSize(0, 60));
        inputVenue->setMaximumSize(QSize(16777215, 70));

        gridLayout->addWidget(inputVenue, 2, 1, 1, 1);

        lblYear = new QLabel(scrollContent);
        lblYear->setObjectName("lblYear");

        gridLayout->addWidget(lblYear, 3, 0, 1, 1);

        inputYear = new QSpinBox(scrollContent);
        inputYear->setObjectName("inputYear");
        inputYear->setMinimumSize(QSize(0, 40));
        inputYear->setMinimum(1900);
        inputYear->setMaximum(2100);
        inputYear->setValue(2025);

        gridLayout->addWidget(inputYear, 3, 1, 1, 1);

        lblCitation = new QLabel(scrollContent);
        lblCitation->setObjectName("lblCitation");

        gridLayout->addWidget(lblCitation, 4, 0, 1, 1);

        inputCitations = new QSpinBox(scrollContent);
        inputCitations->setObjectName("inputCitations");
        inputCitations->setMinimumSize(QSize(0, 40));
        inputCitations->setMaximum(1000000);

        gridLayout->addWidget(inputCitations, 4, 1, 1, 1);

        lblStatus = new QLabel(scrollContent);
        lblStatus->setObjectName("lblStatus");

        gridLayout->addWidget(lblStatus, 5, 0, 1, 1);

        inputStatus = new QComboBox(scrollContent);
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->setObjectName("inputStatus");
        inputStatus->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(inputStatus, 5, 1, 1, 1);

        lblRefs = new QLabel(scrollContent);
        lblRefs->setObjectName("lblRefs");
        lblRefs->setAlignment(Qt::AlignTop);

        gridLayout->addWidget(lblRefs, 6, 0, 1, 1);

        inputRefs = new QPlainTextEdit(scrollContent);
        inputRefs->setObjectName("inputRefs");
        inputRefs->setMinimumSize(QSize(0, 80));

        gridLayout->addWidget(inputRefs, 6, 1, 1, 1);

        lblType = new QLabel(scrollContent);
        lblType->setObjectName("lblType");

        gridLayout->addWidget(lblType, 7, 0, 1, 1);

        inputType = new QComboBox(scrollContent);
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->setObjectName("inputType");
        inputType->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(inputType, 7, 1, 1, 1);


        verticalLayout_Scroll->addLayout(gridLayout);

        stackType = new QStackedWidget(scrollContent);
        stackType->setObjectName("stackType");
        stackType->setMinimumSize(QSize(0, 180));
        pageScie = new QWidget();
        pageScie->setObjectName("pageScie");
        formLayout = new QFormLayout(pageScie);
        formLayout->setObjectName("formLayout");
        labelIF = new QLabel(pageScie);
        labelIF->setObjectName("labelIF");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelIF);

        inputIF = new QDoubleSpinBox(pageScie);
        inputIF->setObjectName("inputIF");
        inputIF->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, inputIF);

        labelQ = new QLabel(pageScie);
        labelQ->setObjectName("labelQ");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelQ);

        inputQRank = new QSpinBox(pageScie);
        inputQRank->setObjectName("inputQRank");
        inputQRank->setMinimum(1);
        inputQRank->setMaximum(4);
        inputQRank->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, inputQRank);

        stackType->addWidget(pageScie);
        pageScopus = new QWidget();
        pageScopus->setObjectName("pageScopus");
        formLayout_2 = new QFormLayout(pageScopus);
        formLayout_2->setObjectName("formLayout_2");
        labelSJR = new QLabel(pageScopus);
        labelSJR->setObjectName("labelSJR");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, labelSJR);

        inputSJR = new QDoubleSpinBox(pageScopus);
        inputSJR->setObjectName("inputSJR");
        inputSJR->setMinimumSize(QSize(0, 40));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, inputSJR);

        labelH = new QLabel(pageScopus);
        labelH->setObjectName("labelH");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, labelH);

        inputHIndex = new QSpinBox(pageScopus);
        inputHIndex->setObjectName("inputHIndex");
        inputHIndex->setMinimumSize(QSize(0, 40));

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, inputHIndex);

        stackType->addWidget(pageScopus);
        pageConference = new QWidget();
        pageConference->setObjectName("pageConference");
        formLayout_3 = new QFormLayout(pageConference);
        formLayout_3->setObjectName("formLayout_3");
        labelConfRank = new QLabel(pageConference);
        labelConfRank->setObjectName("labelConfRank");

        formLayout_3->setWidget(0, QFormLayout::ItemRole::LabelRole, labelConfRank);

        inputConfRank = new QLineEdit(pageConference);
        inputConfRank->setObjectName("inputConfRank");
        inputConfRank->setMinimumSize(QSize(0, 40));

        formLayout_3->setWidget(0, QFormLayout::ItemRole::FieldRole, inputConfRank);

        labelLoc = new QLabel(pageConference);
        labelLoc->setObjectName("labelLoc");

        formLayout_3->setWidget(1, QFormLayout::ItemRole::LabelRole, labelLoc);

        inputLocation = new QLineEdit(pageConference);
        inputLocation->setObjectName("inputLocation");
        inputLocation->setMinimumSize(QSize(0, 40));

        formLayout_3->setWidget(1, QFormLayout::ItemRole::FieldRole, inputLocation);

        labelAcc = new QLabel(pageConference);
        labelAcc->setObjectName("labelAcc");

        formLayout_3->setWidget(2, QFormLayout::ItemRole::LabelRole, labelAcc);

        inputAcceptRate = new QDoubleSpinBox(pageConference);
        inputAcceptRate->setObjectName("inputAcceptRate");
        inputAcceptRate->setMinimumSize(QSize(0, 40));

        formLayout_3->setWidget(2, QFormLayout::ItemRole::FieldRole, inputAcceptRate);

        stackType->addWidget(pageConference);
        pageOther = new QWidget();
        pageOther->setObjectName("pageOther");
        verticalLayout_3 = new QVBoxLayout(pageOther);
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelOther = new QLabel(pageOther);
        labelOther->setObjectName("labelOther");

        verticalLayout_3->addWidget(labelOther);

        stackType->addWidget(pageOther);

        verticalLayout_Scroll->addWidget(stackType);

        lblAuthorsHeader = new QLabel(scrollContent);
        lblAuthorsHeader->setObjectName("lblAuthorsHeader");

        verticalLayout_Scroll->addWidget(lblAuthorsHeader);

        listAuthors = new QListView(scrollContent);
        listAuthors->setObjectName("listAuthors");
        listAuthors->setMinimumSize(QSize(0, 150));

        verticalLayout_Scroll->addWidget(listAuthors);

        AuthorBtn = new QPushButton(scrollContent);
        AuthorBtn->setObjectName("AuthorBtn");
        AuthorBtn->setMinimumSize(QSize(0, 45));
        AuthorBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Scroll->addWidget(AuthorBtn);

        scrollArea->setWidget(scrollContent);

        mainLayout->addWidget(scrollArea);

        footerContainer = new QWidget(ArticleInputDialog);
        footerContainer->setObjectName("footerContainer");
        footerContainer->setMinimumSize(QSize(0, 80));
        horizontalLayout_Buttons = new QHBoxLayout(footerContainer);
        horizontalLayout_Buttons->setObjectName("horizontalLayout_Buttons");
        horizontalLayout_Buttons->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer);

        btnCancel = new QPushButton(footerContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumSize(QSize(120, 45));
        btnCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnCancel);

        btnSave = new QPushButton(footerContainer);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(120, 45));
        btnSave->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnSave);


        mainLayout->addWidget(footerContainer);


        retranslateUi(ArticleInputDialog);

        stackType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleInputDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleInputDialog)
    {
        ArticleInputDialog->setWindowTitle(QCoreApplication::translate("ArticleInputDialog", "Article Input", nullptr));
        lblTitle->setText(QCoreApplication::translate("ArticleInputDialog", "NH\341\272\254P LI\341\273\206U B\303\200I B\303\201O", nullptr));
        lblTitleInput->setText(QCoreApplication::translate("ArticleInputDialog", "Title", nullptr));
        inputTitle->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p ti\303\252u \304\221\341\273\201 c\341\273\247a b\303\240i b\303\241o...", nullptr));
        lblAbstract->setText(QCoreApplication::translate("ArticleInputDialog", "Abstract", nullptr));
        inputAbstract->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p m\303\264 t\341\272\243 c\306\241 b\341\272\243n...", nullptr));
        lblVenue->setText(QCoreApplication::translate("ArticleInputDialog", "Venue", nullptr));
        inputVenue->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p n\306\241i t\341\273\225 ch\341\273\251c...", nullptr));
        lblYear->setText(QCoreApplication::translate("ArticleInputDialog", "Publication Year", nullptr));
        lblCitation->setText(QCoreApplication::translate("ArticleInputDialog", "Citation Count", nullptr));
        lblStatus->setText(QCoreApplication::translate("ArticleInputDialog", "Article Status", nullptr));
        inputStatus->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "DRAFT", nullptr));
        inputStatus->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SUBMITTED", nullptr));
        inputStatus->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "UNDER_REVIEW", nullptr));
        inputStatus->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "REVISIONS", nullptr));
        inputStatus->setItemText(4, QCoreApplication::translate("ArticleInputDialog", "ACCEPTED", nullptr));
        inputStatus->setItemText(5, QCoreApplication::translate("ArticleInputDialog", "REJECTED", nullptr));
        inputStatus->setItemText(6, QCoreApplication::translate("ArticleInputDialog", "PUBLISHED", nullptr));

        lblRefs->setText(QCoreApplication::translate("ArticleInputDialog", "References", nullptr));
        inputRefs->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p t\303\252n b\303\240i b\303\241o tham kh\341\272\243o...", nullptr));
        lblType->setText(QCoreApplication::translate("ArticleInputDialog", "Type", nullptr));
        inputType->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "SCIE", nullptr));
        inputType->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SCOPUS", nullptr));
        inputType->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "CONFERENCE", nullptr));
        inputType->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "OTHER", nullptr));

        labelIF->setText(QCoreApplication::translate("ArticleInputDialog", "Impact Factor", nullptr));
        labelQ->setText(QCoreApplication::translate("ArticleInputDialog", "Q-Rank", nullptr));
        labelSJR->setText(QCoreApplication::translate("ArticleInputDialog", "SJR", nullptr));
        labelH->setText(QCoreApplication::translate("ArticleInputDialog", "H-Index", nullptr));
        labelConfRank->setText(QCoreApplication::translate("ArticleInputDialog", "Conference Rank", nullptr));
        labelLoc->setText(QCoreApplication::translate("ArticleInputDialog", "Location", nullptr));
        labelAcc->setText(QCoreApplication::translate("ArticleInputDialog", "Acceptance Rate (%)", nullptr));
        labelOther->setText(QCoreApplication::translate("ArticleInputDialog", "No extra fields for OTHER type.", nullptr));
        lblAuthorsHeader->setText(QCoreApplication::translate("ArticleInputDialog", "Danh s\303\241ch t\303\241c gi\341\272\243:", nullptr));
        AuthorBtn->setText(QCoreApplication::translate("ArticleInputDialog", "Ch\341\273\215n t\303\241c gi\341\272\243 c\303\263 s\341\272\265n ho\341\272\267c th\303\252m m\341\273\233i t\303\241c gi\341\272\243", nullptr));
        btnCancel->setText(QCoreApplication::translate("ArticleInputDialog", "Quay l\341\272\241i", nullptr));
        btnSave->setText(QCoreApplication::translate("ArticleInputDialog", "L\306\260u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleInputDialog: public Ui_ArticleInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEINPUTDIALOG_H
