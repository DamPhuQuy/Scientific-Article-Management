/********************************************************************************
** Form generated from reading UI file 'articlestatistics.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLESTATISTICS_H
#define UI_ARTICLESTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ArticleStatistics
{
public:

    void setupUi(QDialog *ArticleStatistics)
    {
        if (ArticleStatistics->objectName().isEmpty())
            ArticleStatistics->setObjectName("ArticleStatistics");
        ArticleStatistics->resize(400, 300);

        retranslateUi(ArticleStatistics);

        QMetaObject::connectSlotsByName(ArticleStatistics);
    } // setupUi

    void retranslateUi(QDialog *ArticleStatistics)
    {
        ArticleStatistics->setWindowTitle(QCoreApplication::translate("ArticleStatistics", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleStatistics: public Ui_ArticleStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLESTATISTICS_H
