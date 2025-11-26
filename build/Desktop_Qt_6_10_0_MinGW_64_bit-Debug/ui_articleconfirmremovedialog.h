/********************************************************************************
** Form generated from reading UI file 'articleconfirmremovedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLECONFIRMREMOVEDIALOG_H
#define UI_ARTICLECONFIRMREMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArticleConfirmRemoveDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelInstruction;
    QLineEdit *editConfirm;
    QLineEdit *editKey;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRemove;
    QPushButton *btnCancel;

    void setupUi(QDialog *ArticleConfirmRemoveDialog)
    {
        if (ArticleConfirmRemoveDialog->objectName().isEmpty())
            ArticleConfirmRemoveDialog->setObjectName("ArticleConfirmRemoveDialog");
        ArticleConfirmRemoveDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(ArticleConfirmRemoveDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelInstruction = new QLabel(ArticleConfirmRemoveDialog);
        labelInstruction->setObjectName("labelInstruction");
        labelInstruction->setWordWrap(true);

        verticalLayout->addWidget(labelInstruction);

        editConfirm = new QLineEdit(ArticleConfirmRemoveDialog);
        editConfirm->setObjectName("editConfirm");

        verticalLayout->addWidget(editConfirm);

        editKey = new QLineEdit(ArticleConfirmRemoveDialog);
        editKey->setObjectName("editKey");

        verticalLayout->addWidget(editKey);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRemove = new QPushButton(ArticleConfirmRemoveDialog);
        btnRemove->setObjectName("btnRemove");

        horizontalLayout->addWidget(btnRemove);

        btnCancel = new QPushButton(ArticleConfirmRemoveDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ArticleConfirmRemoveDialog);

        QMetaObject::connectSlotsByName(ArticleConfirmRemoveDialog);
    } // setupUi

    void retranslateUi(QDialog *ArticleConfirmRemoveDialog)
    {
        ArticleConfirmRemoveDialog->setWindowTitle(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Confirm Removal", nullptr));
        labelInstruction->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Please type \"i confirm\" and the key to remove the article.", nullptr));
        editConfirm->setPlaceholderText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Type \"i confirm\"", nullptr));
        editKey->setPlaceholderText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Type key to remove", nullptr));
        btnRemove->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Remove", nullptr));
        btnCancel->setText(QCoreApplication::translate("ArticleConfirmRemoveDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleConfirmRemoveDialog: public Ui_ArticleConfirmRemoveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLECONFIRMREMOVEDIALOG_H
