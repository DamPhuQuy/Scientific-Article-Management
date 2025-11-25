/********************************************************************************
** Form generated from reading UI file 'articleremovedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEREMOVEDIALOG_H
#define UI_ARTICLEREMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_articleremovedialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblHeader;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblWarningIcon;
    QLabel *lblMessage;
    QLabel *lblSubMessage;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnConfirmRemove;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *articleremovedialog)
    {
        if (articleremovedialog->objectName().isEmpty())
            articleremovedialog->setObjectName("articleremovedialog");
        articleremovedialog->resize(400, 250);
        articleremovedialog->setStyleSheet(QString::fromUtf8("QDialog#articleremovedialog{background-color:#f4f7f6;border:4px solid #FFC085;}QWidget{font-family:\"Segoe UI\",Arial,sans-serif;font-size:14px;}"));
        verticalLayout = new QVBoxLayout(articleremovedialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(articleremovedialog);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout = new QHBoxLayout(headerContainer);
        horizontalLayout->setObjectName("horizontalLayout");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:18px;background:transparent;"));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(lblHeader);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(articleremovedialog);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_2 = new QVBoxLayout(bodyContainer);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 10);
        lblWarningIcon = new QLabel(bodyContainer);
        lblWarningIcon->setObjectName("lblWarningIcon");
        lblWarningIcon->setStyleSheet(QString::fromUtf8("color:#e74c3c;font-size:40px;font-weight:bold;"));
        lblWarningIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(lblWarningIcon);

        lblMessage = new QLabel(bodyContainer);
        lblMessage->setObjectName("lblMessage");
        lblMessage->setStyleSheet(QString::fromUtf8("color:#333333;font-weight:bold;font-size:15px;"));
        lblMessage->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblMessage->setWordWrap(true);

        verticalLayout_2->addWidget(lblMessage);

        lblSubMessage = new QLabel(bodyContainer);
        lblSubMessage->setObjectName("lblSubMessage");
        lblSubMessage->setStyleSheet(QString::fromUtf8("color:#555555;font-size:13px;"));
        lblSubMessage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(lblSubMessage);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnCancel = new QPushButton(bodyContainer);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumSize(QSize(100, 40));
        btnCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#20B2AA;border:2px solid #20B2AA;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#17a098;}QPushButton:pressed{background-color:#0e6b65;}"));

        horizontalLayout_2->addWidget(btnCancel);

        btnConfirmRemove = new QPushButton(bodyContainer);
        btnConfirmRemove->setObjectName("btnConfirmRemove");
        btnConfirmRemove->setMinimumSize(QSize(100, 40));
        btnConfirmRemove->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnConfirmRemove->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        horizontalLayout_2->addWidget(btnConfirmRemove);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(bodyContainer);


        retranslateUi(articleremovedialog);
        QObject::connect(btnCancel, &QPushButton::clicked, articleremovedialog, qOverload<>(&QDialog::reject));
        QObject::connect(btnConfirmRemove, &QPushButton::clicked, articleremovedialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(articleremovedialog);
    } // setupUi

    void retranslateUi(QDialog *articleremovedialog)
    {
        articleremovedialog->setWindowTitle(QCoreApplication::translate("articleremovedialog", "Confirm Delete", nullptr));
        lblHeader->setText(QCoreApplication::translate("articleremovedialog", "X\303\201C NH\341\272\254N X\303\223A B\303\200I B\303\201O", nullptr));
        lblWarningIcon->setText(QCoreApplication::translate("articleremovedialog", "!", nullptr));
        lblMessage->setText(QCoreApplication::translate("articleremovedialog", "B\341\272\241n c\303\263 ch\341\272\257c ch\341\272\257n mu\341\273\221n x\303\263a b\303\240i b\303\241o n\303\240y?", nullptr));
        lblSubMessage->setText(QCoreApplication::translate("articleremovedialog", "H\303\240nh \304\221\341\273\231ng n\303\240y kh\303\264ng th\341\273\203 ho\303\240n t\303\241c.", nullptr));
        btnCancel->setText(QCoreApplication::translate("articleremovedialog", "H\341\273\247y b\341\273\217", nullptr));
        btnConfirmRemove->setText(QCoreApplication::translate("articleremovedialog", "X\303\263a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class articleremovedialog: public Ui_articleremovedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEREMOVEDIALOG_H
