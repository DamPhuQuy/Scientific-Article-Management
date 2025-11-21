/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

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

class Ui_LoginForm
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QWidget *container;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QLabel *logoLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer_3;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *signInButton;
    QHBoxLayout *signUpLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *signUpPromptLabel;
    QLabel *signUpLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(483, 454);
        gridLayout = new QGridLayout(LoginForm);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 85, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(106, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        container = new QWidget(LoginForm);
        container->setObjectName("container");
        verticalLayout = new QVBoxLayout(container);
        verticalLayout->setObjectName("verticalLayout");
        welcomeLabel = new QLabel(container);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(welcomeLabel);

        logoLabel = new QLabel(container);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        subtitleLabel = new QLabel(container);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        usernameLabel = new QLabel(container);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(container);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordLabel = new QLabel(container);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(container);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        signInButton = new QPushButton(container);
        signInButton->setObjectName("signInButton");
        signInButton->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(signInButton);

        signUpLayout = new QHBoxLayout();
        signUpLayout->setObjectName("signUpLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_4);

        signUpPromptLabel = new QLabel(container);
        signUpPromptLabel->setObjectName("signUpPromptLabel");

        signUpLayout->addWidget(signUpPromptLabel);

        signUpLabel = new QLabel(container);
        signUpLabel->setObjectName("signUpLabel");
        signUpLabel->setTextFormat(Qt::TextFormat::RichText);

        signUpLayout->addWidget(signUpLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(signUpLayout);


        gridLayout->addWidget(container, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(106, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 84, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Form", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("LoginForm", "Welcome!", nullptr));
        logoLabel->setText(QCoreApplication::translate("LoginForm", "(Logo here)", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginForm", "Please enter your detail to sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "Enter your username...", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "Password@123", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginForm", "Sign in", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("LoginForm", "Don't have an account yet?", nullptr));
        signUpLabel->setText(QCoreApplication::translate("LoginForm", "<a href='#'>Sign up</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
