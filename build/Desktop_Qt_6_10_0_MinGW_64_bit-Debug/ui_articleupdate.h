/********************************************************************************
** Form generated from reading UI file 'articleupdate.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEUPDATE_H
#define UI_ARTICLEUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ArticleUpdate
{
public:

    void setupUi(QDialog *ArticleUpdate)
    {
        if (ArticleUpdate->objectName().isEmpty())
            ArticleUpdate->setObjectName("ArticleUpdate");
        ArticleUpdate->resize(400, 300);

        retranslateUi(ArticleUpdate);

        QMetaObject::connectSlotsByName(ArticleUpdate);
    } // setupUi

    void retranslateUi(QDialog *ArticleUpdate)
    {
        ArticleUpdate->setWindowTitle(QCoreApplication::translate("ArticleUpdate", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleUpdate: public Ui_ArticleUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEUPDATE_H
