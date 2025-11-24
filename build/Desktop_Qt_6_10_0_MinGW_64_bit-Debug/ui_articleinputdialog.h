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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleInputDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelDialog;
    QGridLayout *gridLayout;
    QLabel *labelYear;
    QLabel *labelVenue;
    QLabel *labelStatus;
    QSpinBox *inputCitations;
    QLabel *labelTitle;
    QLabel *labelRefs;
    QLabel *labelType;
    QComboBox *inputStatus;
    QComboBox *inputType;
    QTextEdit *inputVenue;
    QLabel *labelNCitation;
    QTextEdit *inputRefs;
    QTextEdit *inputAbstract;
    QLabel *labelAbstract;
    QTextEdit *inputTitle;
    QSpinBox *inputYear;
    QStackedWidget *stackType;
    QWidget *pageScie;
    QFormLayout *formLayoutScie;
    QLabel *labelIF;
    QDoubleSpinBox *inputIF;
    QLabel *labelQRank;
    QSpinBox *inputQRank;
    QWidget *pageScopus;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *inputSJR;
    QLabel *label1;
    QSpinBox *inputHIndex;
    QWidget *pageConference;
    QFormLayout *formLayout1;
    QLabel *label2;
    QLabel *label3;
    QLineEdit *inputLocation;
    QLabel *label4;
    QDoubleSpinBox *inputAcceptRate;
    QLineEdit *inputConfRank;
    QWidget *pageOther;
    QVBoxLayout *vboxLayout;
    QLabel *label5;
    QPushButton *AuthorBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hboxLayout;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *ArticleInputDialog)
    {
        if (ArticleInputDialog->objectName().isEmpty())
            ArticleInputDialog->setObjectName("ArticleInputDialog");
        ArticleInputDialog->resize(576, 639);
        verticalLayout = new QVBoxLayout(ArticleInputDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelDialog = new QLabel(ArticleInputDialog);
        labelDialog->setObjectName("labelDialog");
        labelDialog->setAutoFillBackground(false);
        labelDialog->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelDialog);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelYear = new QLabel(ArticleInputDialog);
        labelYear->setObjectName("labelYear");

        gridLayout->addWidget(labelYear, 3, 0, 1, 1);

        labelVenue = new QLabel(ArticleInputDialog);
        labelVenue->setObjectName("labelVenue");

        gridLayout->addWidget(labelVenue, 2, 0, 1, 1);

        labelStatus = new QLabel(ArticleInputDialog);
        labelStatus->setObjectName("labelStatus");

        gridLayout->addWidget(labelStatus, 5, 0, 1, 1);

        inputCitations = new QSpinBox(ArticleInputDialog);
        inputCitations->setObjectName("inputCitations");

        gridLayout->addWidget(inputCitations, 4, 1, 1, 1);

        labelTitle = new QLabel(ArticleInputDialog);
        labelTitle->setObjectName("labelTitle");

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        labelRefs = new QLabel(ArticleInputDialog);
        labelRefs->setObjectName("labelRefs");

        gridLayout->addWidget(labelRefs, 6, 0, 1, 1);

        labelType = new QLabel(ArticleInputDialog);
        labelType->setObjectName("labelType");

        gridLayout->addWidget(labelType, 7, 0, 1, 1);

        inputStatus = new QComboBox(ArticleInputDialog);
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->addItem(QString());
        inputStatus->setObjectName("inputStatus");

        gridLayout->addWidget(inputStatus, 5, 1, 1, 1);

        inputType = new QComboBox(ArticleInputDialog);
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->addItem(QString());
        inputType->setObjectName("inputType");

        gridLayout->addWidget(inputType, 7, 1, 1, 1);

        inputVenue = new QTextEdit(ArticleInputDialog);
        inputVenue->setObjectName("inputVenue");

        gridLayout->addWidget(inputVenue, 2, 1, 1, 1);

        labelNCitation = new QLabel(ArticleInputDialog);
        labelNCitation->setObjectName("labelNCitation");

        gridLayout->addWidget(labelNCitation, 4, 0, 1, 1);

        inputRefs = new QTextEdit(ArticleInputDialog);
        inputRefs->setObjectName("inputRefs");

        gridLayout->addWidget(inputRefs, 6, 1, 1, 1);

        inputAbstract = new QTextEdit(ArticleInputDialog);
        inputAbstract->setObjectName("inputAbstract");

        gridLayout->addWidget(inputAbstract, 1, 1, 1, 1);

        labelAbstract = new QLabel(ArticleInputDialog);
        labelAbstract->setObjectName("labelAbstract");

        gridLayout->addWidget(labelAbstract, 1, 0, 1, 1);

        inputTitle = new QTextEdit(ArticleInputDialog);
        inputTitle->setObjectName("inputTitle");

        gridLayout->addWidget(inputTitle, 0, 1, 1, 1);

        inputYear = new QSpinBox(ArticleInputDialog);
        inputYear->setObjectName("inputYear");
        inputYear->setMinimum(1900);
        inputYear->setMaximum(2100);

        gridLayout->addWidget(inputYear, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        stackType = new QStackedWidget(ArticleInputDialog);
        stackType->setObjectName("stackType");
        pageScie = new QWidget();
        pageScie->setObjectName("pageScie");
        formLayoutScie = new QFormLayout(pageScie);
        formLayoutScie->setObjectName("formLayoutScie");
        labelIF = new QLabel(pageScie);
        labelIF->setObjectName("labelIF");

        formLayoutScie->setWidget(0, QFormLayout::ItemRole::LabelRole, labelIF);

        inputIF = new QDoubleSpinBox(pageScie);
        inputIF->setObjectName("inputIF");
        inputIF->setDecimals(3);
        inputIF->setMaximum(100.000000000000000);

        formLayoutScie->setWidget(0, QFormLayout::ItemRole::FieldRole, inputIF);

        labelQRank = new QLabel(pageScie);
        labelQRank->setObjectName("labelQRank");

        formLayoutScie->setWidget(1, QFormLayout::ItemRole::LabelRole, labelQRank);

        inputQRank = new QSpinBox(pageScie);
        inputQRank->setObjectName("inputQRank");
        inputQRank->setMinimum(1);
        inputQRank->setMaximum(4);

        formLayoutScie->setWidget(1, QFormLayout::ItemRole::FieldRole, inputQRank);

        stackType->addWidget(pageScie);
        pageScopus = new QWidget();
        pageScopus->setObjectName("pageScopus");
        formLayout = new QFormLayout(pageScopus);
        formLayout->setObjectName("formLayout");
        label = new QLabel(pageScopus);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        inputSJR = new QDoubleSpinBox(pageScopus);
        inputSJR->setObjectName("inputSJR");
        inputSJR->setDecimals(3);
        inputSJR->setMaximum(100.000000000000000);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, inputSJR);

        label1 = new QLabel(pageScopus);
        label1->setObjectName("label1");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label1);

        inputHIndex = new QSpinBox(pageScopus);
        inputHIndex->setObjectName("inputHIndex");
        inputHIndex->setMaximum(2000);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, inputHIndex);

        stackType->addWidget(pageScopus);
        pageConference = new QWidget();
        pageConference->setObjectName("pageConference");
        formLayout1 = new QFormLayout(pageConference);
        formLayout1->setObjectName("formLayout1");
        label2 = new QLabel(pageConference);
        label2->setObjectName("label2");

        formLayout1->setWidget(0, QFormLayout::ItemRole::LabelRole, label2);

        label3 = new QLabel(pageConference);
        label3->setObjectName("label3");

        formLayout1->setWidget(1, QFormLayout::ItemRole::LabelRole, label3);

        inputLocation = new QLineEdit(pageConference);
        inputLocation->setObjectName("inputLocation");

        formLayout1->setWidget(1, QFormLayout::ItemRole::FieldRole, inputLocation);

        label4 = new QLabel(pageConference);
        label4->setObjectName("label4");

        formLayout1->setWidget(2, QFormLayout::ItemRole::LabelRole, label4);

        inputAcceptRate = new QDoubleSpinBox(pageConference);
        inputAcceptRate->setObjectName("inputAcceptRate");
        inputAcceptRate->setMinimum(0.000000000000000);
        inputAcceptRate->setMaximum(100.000000000000000);

        formLayout1->setWidget(2, QFormLayout::ItemRole::FieldRole, inputAcceptRate);

        inputConfRank = new QLineEdit(pageConference);
        inputConfRank->setObjectName("inputConfRank");

        formLayout1->setWidget(0, QFormLayout::ItemRole::FieldRole, inputConfRank);

        stackType->addWidget(pageConference);
        pageOther = new QWidget();
        pageOther->setObjectName("pageOther");
        vboxLayout = new QVBoxLayout(pageOther);
        vboxLayout->setObjectName("vboxLayout");
        label5 = new QLabel(pageOther);
        label5->setObjectName("label5");

        vboxLayout->addWidget(label5);

        stackType->addWidget(pageOther);

        verticalLayout->addWidget(stackType);

        AuthorBtn = new QPushButton(ArticleInputDialog);
        AuthorBtn->setObjectName("AuthorBtn");

        verticalLayout->addWidget(AuthorBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        btnCancel = new QPushButton(ArticleInputDialog);
        btnCancel->setObjectName("btnCancel");

        hboxLayout->addWidget(btnCancel);

        btnSave = new QPushButton(ArticleInputDialog);
        btnSave->setObjectName("btnSave");

        hboxLayout->addWidget(btnSave);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(ArticleInputDialog);

        stackType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ArticleInputDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleInputDialog)
    {
        ArticleInputDialog->setWindowTitle(QCoreApplication::translate("ArticleInputDialog", "Article Input", nullptr));
        labelDialog->setText(QCoreApplication::translate("ArticleInputDialog", "Article Information", nullptr));
        labelYear->setText(QCoreApplication::translate("ArticleInputDialog", "Publication Year", nullptr));
        labelVenue->setText(QCoreApplication::translate("ArticleInputDialog", "Venue", nullptr));
        labelStatus->setText(QCoreApplication::translate("ArticleInputDialog", "Article Status", nullptr));
        labelTitle->setText(QCoreApplication::translate("ArticleInputDialog", "Title", nullptr));
        labelRefs->setText(QCoreApplication::translate("ArticleInputDialog", "References", nullptr));
        labelType->setText(QCoreApplication::translate("ArticleInputDialog", "Type", nullptr));
        inputStatus->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "DRAFT", nullptr));
        inputStatus->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SUBMITTED", nullptr));
        inputStatus->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "UNDER_REVIEW", nullptr));
        inputStatus->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "REVISIONS", nullptr));
        inputStatus->setItemText(4, QCoreApplication::translate("ArticleInputDialog", "ACCEPTED", nullptr));
        inputStatus->setItemText(5, QCoreApplication::translate("ArticleInputDialog", "REJECTED", nullptr));
        inputStatus->setItemText(6, QCoreApplication::translate("ArticleInputDialog", "PUBLISHED", nullptr));

        inputType->setItemText(0, QCoreApplication::translate("ArticleInputDialog", "SCIE", nullptr));
        inputType->setItemText(1, QCoreApplication::translate("ArticleInputDialog", "SCOPUS", nullptr));
        inputType->setItemText(2, QCoreApplication::translate("ArticleInputDialog", "CONFERENCE", nullptr));
        inputType->setItemText(3, QCoreApplication::translate("ArticleInputDialog", "OTHER", nullptr));

        inputVenue->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p n\306\241i t\341\273\225 ch\341\273\251c c\341\273\247a b\303\240i b\303\241o...", nullptr));
        labelNCitation->setText(QCoreApplication::translate("ArticleInputDialog", "Citation Count", nullptr));
        inputRefs->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p t\303\252n b\303\240i b\303\241o tham kh\341\272\243o (m\341\273\227i b\303\240i b\303\241o m\341\273\231t d\303\262ng)", nullptr));
        inputAbstract->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p m\303\264 t\341\272\243 c\306\241 b\341\272\243n c\341\273\247a b\303\240i b\303\241o...", nullptr));
        labelAbstract->setText(QCoreApplication::translate("ArticleInputDialog", "Abstract", nullptr));
        inputTitle->setPlaceholderText(QCoreApplication::translate("ArticleInputDialog", "Nh\341\272\255p ti\303\252u \304\221\341\273\201 c\341\273\247a b\303\240i b\303\241o...", nullptr));
        labelIF->setText(QCoreApplication::translate("ArticleInputDialog", "Impact Factor", nullptr));
        labelQRank->setText(QCoreApplication::translate("ArticleInputDialog", "Q-Rank", nullptr));
        label->setText(QCoreApplication::translate("ArticleInputDialog", "SJR", nullptr));
        label1->setText(QCoreApplication::translate("ArticleInputDialog", "H-Index", nullptr));
        label2->setText(QCoreApplication::translate("ArticleInputDialog", "Conference Rank", nullptr));
        label3->setText(QCoreApplication::translate("ArticleInputDialog", "Location", nullptr));
        label4->setText(QCoreApplication::translate("ArticleInputDialog", "Acceptance Rate (%)", nullptr));
        inputAcceptRate->setSuffix(QCoreApplication::translate("ArticleInputDialog", "%", nullptr));
        label5->setText(QCoreApplication::translate("ArticleInputDialog", "No extra fields for OTHER type.", nullptr));
        AuthorBtn->setText(QCoreApplication::translate("ArticleInputDialog", "Ch\341\273\215n t\303\241c gi\341\272\243 c\303\263 s\341\272\265n ho\341\272\267c th\303\252m m\341\273\233i t\303\241c gi\341\272\243", nullptr));
        btnCancel->setText(QCoreApplication::translate("ArticleInputDialog", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("ArticleInputDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleInputDialog: public Ui_ArticleInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEINPUTDIALOG_H
