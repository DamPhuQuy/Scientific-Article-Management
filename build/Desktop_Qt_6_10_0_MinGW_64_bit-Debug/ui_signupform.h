/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QLabel *logoLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer_3;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *fullnameLabel;
    QLineEdit *fullnameEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *confirmPassLabel;
    QLineEdit *confirmPassEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *signUpButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *signUpLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *signUpPromptLabel;
    QLabel *loginLabel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName("SignUpForm");
        SignUpForm->resize(634, 538);
        gridLayout = new QGridLayout(SignUpForm);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 66, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(172, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(172, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 66, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        widget = new QWidget(SignUpForm);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        welcomeLabel = new QLabel(widget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(welcomeLabel);

        logoLabel = new QLabel(widget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        subtitleLabel = new QLabel(widget);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        usernameLabel = new QLabel(widget);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        fullnameLabel = new QLabel(widget);
        fullnameLabel->setObjectName("fullnameLabel");

        verticalLayout->addWidget(fullnameLabel);

        fullnameEdit = new QLineEdit(widget);
        fullnameEdit->setObjectName("fullnameEdit");

        verticalLayout->addWidget(fullnameEdit);

        emailLabel = new QLabel(widget);
        emailLabel->setObjectName("emailLabel");

        verticalLayout->addWidget(emailLabel);

        emailEdit = new QLineEdit(widget);
        emailEdit->setObjectName("emailEdit");

        verticalLayout->addWidget(emailEdit);

        phoneLabel = new QLabel(widget);
        phoneLabel->setObjectName("phoneLabel");

        verticalLayout->addWidget(phoneLabel);

        phoneEdit = new QLineEdit(widget);
        phoneEdit->setObjectName("phoneEdit");

        verticalLayout->addWidget(phoneEdit);

        passwordLabel = new QLabel(widget);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordEdit);

        confirmPassLabel = new QLabel(widget);
        confirmPassLabel->setObjectName("confirmPassLabel");

        verticalLayout->addWidget(confirmPassLabel);

        confirmPassEdit = new QLineEdit(widget);
        confirmPassEdit->setObjectName("confirmPassEdit");
        confirmPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(confirmPassEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        signUpButton = new QPushButton(widget);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(signUpButton);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        signUpLayout = new QHBoxLayout();
        signUpLayout->setObjectName("signUpLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_4);

        signUpPromptLabel = new QLabel(widget_2);
        signUpPromptLabel->setObjectName("signUpPromptLabel");

        signUpLayout->addWidget(signUpPromptLabel);

        loginLabel = new QLabel(widget_2);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setTextFormat(Qt::TextFormat::RichText);

        signUpLayout->addWidget(loginLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_5);


        horizontalLayout->addLayout(signUpLayout);


        verticalLayout->addWidget(widget_2);


        gridLayout->addWidget(widget, 2, 1, 1, 1);


        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QWidget *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Form", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("SignUpForm", "Welcome!", nullptr));
        logoLabel->setText(QCoreApplication::translate("SignUpForm", "(Logo here)", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("SignUpForm", "Please enter your detail to sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignUpForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your username...", nullptr));
        fullnameLabel->setText(QCoreApplication::translate("SignUpForm", "Full Name", nullptr));
        fullnameEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your Full Name", nullptr));
        emailLabel->setText(QCoreApplication::translate("SignUpForm", "Email", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your email", nullptr));
        phoneLabel->setText(QCoreApplication::translate("SignUpForm", "Phone", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your phone", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUpForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Password@123", nullptr));
        confirmPassLabel->setText(QCoreApplication::translate("SignUpForm", "Password again", nullptr));
        confirmPassEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Password@123", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpForm", "Sign up", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("SignUpForm", "Have an account?", nullptr));
        loginLabel->setText(QCoreApplication::translate("SignUpForm", "<html><head/><body><p><a href=\"#\"><span style=\" text-decoration: underline; color:#27bf73;\">Login</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
