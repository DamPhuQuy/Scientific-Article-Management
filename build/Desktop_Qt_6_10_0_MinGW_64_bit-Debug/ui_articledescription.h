/********************************************************************************
** Form generated from reading UI file 'articledescription.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEDESCRIPTION_H
#define UI_ARTICLEDESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ArticleDescription
{
public:

    void setupUi(QDialog *ArticleDescription)
    {
        if (ArticleDescription->objectName().isEmpty())
            ArticleDescription->setObjectName("ArticleDescription");
        ArticleDescription->resize(400, 300);

        retranslateUi(ArticleDescription);

        QMetaObject::connectSlotsByName(ArticleDescription);
    } // setupUi

    void retranslateUi(QDialog *ArticleDescription)
    {
        ArticleDescription->setWindowTitle(QCoreApplication::translate("ArticleDescription", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleDescription: public Ui_ArticleDescription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDESCRIPTION_H
