/********************************************************************************
** Form generated from reading UI file 'articleinput.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEINPUT_H
#define UI_ARTICLEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ArticleInput
{
public:

    void setupUi(QDialog *ArticleInput)
    {
        if (ArticleInput->objectName().isEmpty())
            ArticleInput->setObjectName("ArticleInput");
        ArticleInput->resize(400, 300);

        retranslateUi(ArticleInput);

        QMetaObject::connectSlotsByName(ArticleInput);
    } // setupUi

    void retranslateUi(QDialog *ArticleInput)
    {
        ArticleInput->setWindowTitle(QCoreApplication::translate("ArticleInput", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleInput: public Ui_ArticleInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEINPUT_H
