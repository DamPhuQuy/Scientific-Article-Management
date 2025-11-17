/********************************************************************************
** Form generated from reading UI file 'articleremove.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEREMOVE_H
#define UI_ARTICLEREMOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ArticleRemove
{
public:

    void setupUi(QDialog *ArticleRemove)
    {
        if (ArticleRemove->objectName().isEmpty())
            ArticleRemove->setObjectName("ArticleRemove");
        ArticleRemove->resize(400, 300);

        retranslateUi(ArticleRemove);

        QMetaObject::connectSlotsByName(ArticleRemove);
    } // setupUi

    void retranslateUi(QDialog *ArticleRemove)
    {
        ArticleRemove->setWindowTitle(QCoreApplication::translate("ArticleRemove", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleRemove: public Ui_ArticleRemove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEREMOVE_H
