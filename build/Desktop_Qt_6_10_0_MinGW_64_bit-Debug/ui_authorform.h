/********************************************************************************
** Form generated from reading UI file 'authorform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORFORM_H
#define UI_AUTHORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorForm
{
public:

    void setupUi(QWidget *AuthorForm)
    {
        if (AuthorForm->objectName().isEmpty())
            AuthorForm->setObjectName("AuthorForm");
        AuthorForm->resize(400, 300);

        retranslateUi(AuthorForm);

        QMetaObject::connectSlotsByName(AuthorForm);
    } // setupUi

    void retranslateUi(QWidget *AuthorForm)
    {
        AuthorForm->setWindowTitle(QCoreApplication::translate("AuthorForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorForm: public Ui_AuthorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORFORM_H
