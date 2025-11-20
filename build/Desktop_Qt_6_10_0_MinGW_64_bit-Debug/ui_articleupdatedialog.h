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
    QGridLayout *gridLayout;
    QPushButton *saveBtn;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Content;
    QHBoxLayout *horizontalLayout_ID;
    QLabel *label_Title;
    QPlainTextEdit *editTitle;
    QHBoxLayout *horizontalLayout_VenueYear;
    QVBoxLayout *verticalLayout_Venue;
    QLabel *label_Venue;
    QLineEdit *editVenue;
    QGridLayout *gridLayout_Meta;
    QLabel *label_Status;
    QLabel *label_Cit;
    QSpinBox *spinCitation;
    QComboBox *comboStatus;
    QLabel *label_Type;
    QVBoxLayout *verticalLayout_Year;
    QSpinBox *spinYear;
    QLabel *label_Year;
    QComboBox *comboType;
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
    QPushButton *closeBtn;

    void setupUi(QDialog *ArticleUpdateDialog)
    {
        if (ArticleUpdateDialog->objectName().isEmpty())
            ArticleUpdateDialog->setObjectName("ArticleUpdateDialog");
        ArticleUpdateDialog->resize(550, 800);
        gridLayout = new QGridLayout(ArticleUpdateDialog);
        gridLayout->setObjectName("gridLayout");
        saveBtn = new QPushButton(ArticleUpdateDialog);
        saveBtn->setObjectName("saveBtn");

        gridLayout->addWidget(saveBtn, 1, 1, 1, 1);

        scrollArea = new QScrollArea(ArticleUpdateDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 536, 764));
        verticalLayout_Content = new QVBoxLayout(scrollContent);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        horizontalLayout_ID = new QHBoxLayout();
        horizontalLayout_ID->setObjectName("horizontalLayout_ID");

        verticalLayout_Content->addLayout(horizontalLayout_ID);

        label_Title = new QLabel(scrollContent);
        label_Title->setObjectName("label_Title");
        QFont font;
        font.setBold(true);
        label_Title->setFont(font);

        verticalLayout_Content->addWidget(label_Title);

        editTitle = new QPlainTextEdit(scrollContent);
        editTitle->setObjectName("editTitle");
        editTitle->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));

        verticalLayout_Content->addWidget(editTitle);

        horizontalLayout_VenueYear = new QHBoxLayout();
        horizontalLayout_VenueYear->setObjectName("horizontalLayout_VenueYear");
        verticalLayout_Venue = new QVBoxLayout();
        verticalLayout_Venue->setObjectName("verticalLayout_Venue");
        label_Venue = new QLabel(scrollContent);
        label_Venue->setObjectName("label_Venue");
        label_Venue->setFont(font);

        verticalLayout_Venue->addWidget(label_Venue);

        editVenue = new QLineEdit(scrollContent);
        editVenue->setObjectName("editVenue");

        verticalLayout_Venue->addWidget(editVenue);


        horizontalLayout_VenueYear->addLayout(verticalLayout_Venue);


        verticalLayout_Content->addLayout(horizontalLayout_VenueYear);

        gridLayout_Meta = new QGridLayout();
        gridLayout_Meta->setObjectName("gridLayout_Meta");
        label_Status = new QLabel(scrollContent);
        label_Status->setObjectName("label_Status");
        label_Status->setFont(font);

        gridLayout_Meta->addWidget(label_Status, 0, 2, 1, 1);

        label_Cit = new QLabel(scrollContent);
        label_Cit->setObjectName("label_Cit");
        label_Cit->setFont(font);

        gridLayout_Meta->addWidget(label_Cit, 0, 3, 1, 1);

        spinCitation = new QSpinBox(scrollContent);
        spinCitation->setObjectName("spinCitation");
        spinCitation->setMaximum(999999);

        gridLayout_Meta->addWidget(spinCitation, 1, 3, 1, 1);

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

        label_Type = new QLabel(scrollContent);
        label_Type->setObjectName("label_Type");
        label_Type->setFont(font);

        gridLayout_Meta->addWidget(label_Type, 0, 0, 1, 1);

        verticalLayout_Year = new QVBoxLayout();
        verticalLayout_Year->setObjectName("verticalLayout_Year");
        spinYear = new QSpinBox(scrollContent);
        spinYear->setObjectName("spinYear");
        spinYear->setMinimum(1900);
        spinYear->setMaximum(2100);
        spinYear->setValue(2024);

        verticalLayout_Year->addWidget(spinYear);


        gridLayout_Meta->addLayout(verticalLayout_Year, 1, 1, 1, 1);

        label_Year = new QLabel(scrollContent);
        label_Year->setObjectName("label_Year");
        label_Year->setFont(font);

        gridLayout_Meta->addWidget(label_Year, 0, 1, 1, 1);

        comboType = new QComboBox(scrollContent);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        gridLayout_Meta->addWidget(comboType, 1, 0, 1, 1);


        verticalLayout_Content->addLayout(gridLayout_Meta);

        line1 = new QFrame(scrollContent);
        line1->setObjectName("line1");
        line1->setFrameShape(QFrame::Shape::HLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_Content->addWidget(line1);

        stackInputs = new QStackedWidget(scrollContent);
        stackInputs->setObjectName("stackInputs");
        stackInputs->setFrameShape(QFrame::Shape::StyledPanel);
        pageInputSCIE = new QWidget();
        pageInputSCIE->setObjectName("pageInputSCIE");
        hl_InputSCIE = new QHBoxLayout(pageInputSCIE);
        hl_InputSCIE->setObjectName("hl_InputSCIE");
        lbl_IF = new QLabel(pageInputSCIE);
        lbl_IF->setObjectName("lbl_IF");

        hl_InputSCIE->addWidget(lbl_IF);

        spinIF = new QDoubleSpinBox(pageInputSCIE);
        spinIF->setObjectName("spinIF");
        spinIF->setSingleStep(0.100000000000000);

        hl_InputSCIE->addWidget(spinIF);

        hs1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

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

        hs2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

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
        spinAcceptRate->setMaximum(100.000000000000000);

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
        label_Authors->setFont(font);

        verticalLayout_Content->addWidget(label_Authors);

        editAuthors = new QPlainTextEdit(scrollContent);
        editAuthors->setObjectName("editAuthors");

        verticalLayout_Content->addWidget(editAuthors);

        label_Abstract = new QLabel(scrollContent);
        label_Abstract->setObjectName("label_Abstract");
        label_Abstract->setFont(font);

        verticalLayout_Content->addWidget(label_Abstract);

        editAbstract = new QPlainTextEdit(scrollContent);
        editAbstract->setObjectName("editAbstract");

        verticalLayout_Content->addWidget(editAbstract);

        label_Refs = new QLabel(scrollContent);
        label_Refs->setObjectName("label_Refs");
        label_Refs->setFont(font);

        verticalLayout_Content->addWidget(label_Refs);

        editRefs = new QPlainTextEdit(scrollContent);
        editRefs->setObjectName("editRefs");

        verticalLayout_Content->addWidget(editRefs);

        scrollArea->setWidget(scrollContent);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 2);

        closeBtn = new QPushButton(ArticleUpdateDialog);
        closeBtn->setObjectName("closeBtn");

        gridLayout->addWidget(closeBtn, 1, 0, 1, 1);


        retranslateUi(ArticleUpdateDialog);

        stackInputs->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ArticleUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleUpdateDialog)
    {
        ArticleUpdateDialog->setWindowTitle(QCoreApplication::translate("ArticleUpdateDialog", "Update Article Information", nullptr));
        saveBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "Save", nullptr));
        label_Title->setText(QCoreApplication::translate("ArticleUpdateDialog", "Title", nullptr));
        editTitle->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Enter article title here...", nullptr));
        label_Venue->setText(QCoreApplication::translate("ArticleUpdateDialog", "Venue", nullptr));
        editVenue->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Conference or Journal Name", nullptr));
        label_Status->setText(QCoreApplication::translate("ArticleUpdateDialog", "Status", nullptr));
        label_Cit->setText(QCoreApplication::translate("ArticleUpdateDialog", "Citations", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "DRAFT", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SUBMITTED", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "UNDER_REVIEW", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "REVISIONS", nullptr));
        comboStatus->setItemText(4, QCoreApplication::translate("ArticleUpdateDialog", "ACCEPTED", nullptr));
        comboStatus->setItemText(5, QCoreApplication::translate("ArticleUpdateDialog", "REJECTED", nullptr));
        comboStatus->setItemText(6, QCoreApplication::translate("ArticleUpdateDialog", "PUBLISHED", nullptr));

        label_Type->setText(QCoreApplication::translate("ArticleUpdateDialog", "Type", nullptr));
        label_Year->setText(QCoreApplication::translate("ArticleUpdateDialog", "Year", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("ArticleUpdateDialog", "SCIE", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("ArticleUpdateDialog", "SCOPUS", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("ArticleUpdateDialog", "CONFERENCE", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("ArticleUpdateDialog", "OTHER", nullptr));
        comboType->setItemText(4, QString());

        lbl_IF->setText(QCoreApplication::translate("ArticleUpdateDialog", "Impact Factor:", nullptr));
        lbl_Q->setText(QCoreApplication::translate("ArticleUpdateDialog", "Q-Rank (1-4):", nullptr));
        lbl_SJR->setText(QCoreApplication::translate("ArticleUpdateDialog", "SJR:", nullptr));
        lbl_H->setText(QCoreApplication::translate("ArticleUpdateDialog", "H-Index:", nullptr));
        lbl_CR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Rank:", nullptr));
        editConfRank->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "e.g. A*, A", nullptr));
        lbl_AR->setText(QCoreApplication::translate("ArticleUpdateDialog", "Accept Rate (%):", nullptr));
        spinAcceptRate->setSuffix(QCoreApplication::translate("ArticleUpdateDialog", "%", nullptr));
        lbl_Loc->setText(QCoreApplication::translate("ArticleUpdateDialog", "Location:", nullptr));
        label_Authors->setText(QCoreApplication::translate("ArticleUpdateDialog", "Authors (One per line)", nullptr));
        editAuthors->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Author 1\n"
"Author 2\n"
"Author 3", nullptr));
        label_Abstract->setText(QCoreApplication::translate("ArticleUpdateDialog", "Abstract", nullptr));
        label_Refs->setText(QCoreApplication::translate("ArticleUpdateDialog", "References (One per line)", nullptr));
        editRefs->setPlaceholderText(QCoreApplication::translate("ArticleUpdateDialog", "Ref 1...\n"
"Ref 2...", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleUpdateDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleUpdateDialog: public Ui_ArticleUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEUPDATEDIALOG_H
