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
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *container;
    QVBoxLayout *verticalLayout;
    QWidget *headerWidget;
    QVBoxLayout *verticalLayout_Header;
    QLabel *welcomeLabel;
    QLabel *logoLabel;
    QLabel *subtitleLabel;
    QWidget *bodyWidget;
    QVBoxLayout *verticalLayout_Body;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer_Input;
    QPushButton *signInButton;
    QHBoxLayout *signUpLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *signUpPromptLabel;
    QLabel *signUpLabel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(500, 600);
        LoginForm->setStyleSheet(QString::fromUtf8("\n"
"/* === GLOBAL SETTINGS === */\n"
"QWidget#LoginForm {\n"
"    background-color: #f4f7f6;\n"
"}\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"}\n"
"\n"
"/* === MAIN CONTAINER === */\n"
"QWidget#container {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"    border-radius: 12px;\n"
"}\n"
"\n"
"/* === HEADER === */\n"
"QWidget#headerWidget {\n"
"    background-color: #00264d;\n"
"    border-left: 8px solid #FFD700;\n"
"    border-bottom: 4px solid #4169E1;\n"
"    border-top-left-radius: 10px;\n"
"    border-top-right-radius: 10px;\n"
"}\n"
"\n"
"QLabel#welcomeLabel,\n"
"QLabel#logoLabel,\n"
"QLabel#subtitleLabel {\n"
"    color: #ffffff;\n"
"    background-color: transparent;\n"
"}\n"
"QLabel#welcomeLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"QLabel#subtitleLabel {\n"
"    font-size: 12px;\n"
"    font-style: italic;\n"
"    color: #dddddd;\n"
"}\n"
"\n"
"/* === INPUT LABELS === */\n"
"QLabel#usernameLabel,\n"
"QLabel#passwordLabe"
                        "l {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"/* === INPUT BOXES === */\n"
"QLineEdit {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"}\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #20B2AA;\n"
"}\n"
"\n"
"/* === SIGN IN BUTTON === */\n"
"QPushButton#signInButton {\n"
"    background-color: #20B2AA;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"    border-radius: 6px;\n"
"    border: none;\n"
"}\n"
"QPushButton#signInButton:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"QPushButton#signInButton:pressed {\n"
"    background-color: #13857e;\n"
"}\n"
"\n"
"/* === SIGN UP LINK === */\n"
"QLabel#signUpPromptLabel {\n"
"    color: #666;\n"
"}\n"
"QLabel#signUpLabel {\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* === MESSAGE BOX === */\n"
"QMessageBox {\n"
""
                        "    background-color: #ffffff;\n"
"    border: 2px solid #00264d;\n"
"    border-radius: 8px;\n"
"}\n"
"QMessageBox QLabel {\n"
"    color: #333333;\n"
"    font-size: 14px;\n"
"}\n"
"QMessageBox QPushButton {\n"
"    background-color: #20B2AA;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"    padding: 6px 20px;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"    min-width: 60px;\n"
"}\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #17a098;\n"
"}\n"
"QMessageBox QPushButton:pressed {\n"
"    background-color: #13857e;\n"
"}\n"
""));
        gridLayout = new QGridLayout(LoginForm);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        container = new QWidget(LoginForm);
        container->setObjectName("container");
        container->setMinimumSize(QSize(350, 0));
        verticalLayout = new QVBoxLayout(container);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerWidget = new QWidget(container);
        headerWidget->setObjectName("headerWidget");
        verticalLayout_Header = new QVBoxLayout(headerWidget);
        verticalLayout_Header->setSpacing(10);
        verticalLayout_Header->setObjectName("verticalLayout_Header");
        verticalLayout_Header->setContentsMargins(20, 20, 20, 20);
        welcomeLabel = new QLabel(headerWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_Header->addWidget(welcomeLabel);

        logoLabel = new QLabel(headerWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_Header->addWidget(logoLabel);

        subtitleLabel = new QLabel(headerWidget);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_Header->addWidget(subtitleLabel);


        verticalLayout->addWidget(headerWidget);

        bodyWidget = new QWidget(container);
        bodyWidget->setObjectName("bodyWidget");
        verticalLayout_Body = new QVBoxLayout(bodyWidget);
        verticalLayout_Body->setSpacing(15);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(30, 20, 30, 10);
        usernameLabel = new QLabel(bodyWidget);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout_Body->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(bodyWidget);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout_Body->addWidget(usernameEdit);

        passwordLabel = new QLabel(bodyWidget);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout_Body->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(bodyWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_Body->addWidget(passwordEdit);

        verticalSpacer_Input = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Body->addItem(verticalSpacer_Input);

        signInButton = new QPushButton(bodyWidget);
        signInButton->setObjectName("signInButton");
        signInButton->setMinimumSize(QSize(0, 45));
        signInButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Body->addWidget(signInButton);

        signUpLayout = new QHBoxLayout();
        signUpLayout->setObjectName("signUpLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_4);

        signUpPromptLabel = new QLabel(bodyWidget);
        signUpPromptLabel->setObjectName("signUpPromptLabel");

        signUpLayout->addWidget(signUpPromptLabel);

        signUpLabel = new QLabel(bodyWidget);
        signUpLabel->setObjectName("signUpLabel");
        signUpLabel->setTextFormat(Qt::RichText);
        signUpLabel->setOpenExternalLinks(false);

        signUpLayout->addWidget(signUpLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(horizontalSpacer_5);


        verticalLayout_Body->addLayout(signUpLayout);


        verticalLayout->addWidget(bodyWidget);


        gridLayout->addWidget(container, 1, 1, 1, 1);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Login System", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("LoginForm", "XIN CH\303\200O!", nullptr));
        logoLabel->setText(QCoreApplication::translate("LoginForm", "(LOGO)", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginForm", "Please enter your details to sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "Enter your username...", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginForm", "Sign in", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("LoginForm", "Don't have an account yet?", nullptr));
        signUpLabel->setText(QCoreApplication::translate("LoginForm", "<a href='#' style='color: #20B2AA; text-decoration: none;'>Sign up</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
