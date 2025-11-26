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
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QGridLayout *gridLayout_Body;
    QSpacerItem *verticalSpacer_Top;
    QSpacerItem *horizontalSpacer_Left;
    QWidget *container;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer_Internal;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *horizontalSpacer_Buttons;
    QPushButton *signInButton;
    QHBoxLayout *signUpLayout;
    QSpacerItem *hs4;
    QLabel *signUpPromptLabel;
    QLabel *signUpLabel;
    QSpacerItem *hs5;
    QSpacerItem *horizontalSpacer_Right;
    QSpacerItem *verticalSpacer_Bottom;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(500, 600);
        LoginForm->setStyleSheet(QString::fromUtf8("\n"
"    /* --- MAIN FORM --- */\n"
"    QWidget#LoginForm {\n"
"        background-color: #f4f7f6;\n"
"        border: 4px solid #FFC085; /* Vi\341\273\201n cam nh\341\272\255n di\341\273\207n */\n"
"    }\n"
"\n"
"    QWidget { font-family: \"Segoe UI\", Arial, sans-serif; font-size: 14px; }\n"
"\n"
"    /* --- CONTAINER (H\341\273\230P \304\220\304\202NG NH\341\272\254P) --- */\n"
"    QWidget#container {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 12px;\n"
"    }\n"
"\n"
"    /* --- LABELS --- */\n"
"    QLabel#welcomeLabel {\n"
"        font-size: 26px;\n"
"        font-weight: 900;\n"
"        color: #00264d; /* Xanh \304\221\341\272\255m */\n"
"    }\n"
"    QLabel#subtitleLabel {\n"
"        color: #777;\n"
"        font-size: 13px;\n"
"        margin-bottom: 10px;\n"
"    }\n"
"    QLabel#usernameLabel, QLabel#passwordLabel {\n"
"        font-weight: bold;\n"
"        color: #333;\n"
"        margin-top: 5px;\n"
"    }\n"
"    QLabel#signUpP"
                        "romptLabel {\n"
"        color: #666;\n"
"        font-size: 13px;\n"
"    }\n"
"    QLabel#signUpLabel {\n"
"        color: #20B2AA;\n"
"        font-weight: bold;\n"
"        font-size: 13px;\n"
"    }\n"
"    QLabel#signUpLabel:hover {\n"
"        color: #17a098;\n"
"        text-decoration: underline;\n"
"    }\n"
"\n"
"    /* --- INPUT FIELDS --- */\n"
"    QLineEdit { \n"
"      background-color: #f9f9f9; \n"
"      border: 1px solid #cccccc; \n"
"      border-radius: 6px; \n"
"      padding: 10px; \n"
"      color: #333; \n"
"      font-size: 14px;\n"
"    }\n"
"    QLineEdit:focus { \n"
"      background-color: #ffffff; \n"
"      border: 2px solid #20B2AA; /* Vi\341\273\201n xanh ng\341\273\215c khi focus */\n"
"    }\n"
"   "));
        mainLayout = new QVBoxLayout(LoginForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(LoginForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("\n"
"       QWidget#headerContainer {\n"
"           background-color: #00264d;\n"
"           border-bottom: 5px solid #4169E1;\n"
"           border-left: 10px solid #FFD700; /* V\341\272\240CH V\303\200NG LOGO DUT */\n"
"       }\n"
"      "));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblHeader->setStyleSheet(QString::fromUtf8("\n"
"          color: #ffffff;\n"
"          font-weight: 900;\n"
"          font-size: 18px;\n"
"          background: transparent;\n"
"         "));

        horizontalLayout_Header->addWidget(lblHeader);


        mainLayout->addWidget(headerContainer);

        gridLayout_Body = new QGridLayout();
        gridLayout_Body->setObjectName("gridLayout_Body");
        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Body->addItem(verticalSpacer_Top, 0, 1, 1, 1);

        horizontalSpacer_Left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Body->addItem(horizontalSpacer_Left, 1, 0, 1, 1);

        container = new QWidget(LoginForm);
        container->setObjectName("container");
        container->setMinimumSize(QSize(350, 0));
        verticalLayout = new QVBoxLayout(container);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 40);
        welcomeLabel = new QLabel(container);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(welcomeLabel);

        subtitleLabel = new QLabel(container);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        verticalSpacer_Internal = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_Internal);

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

        horizontalSpacer_Buttons = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_Buttons);

        signInButton = new QPushButton(container);
        signInButton->setObjectName("signInButton");
        signInButton->setMinimumSize(QSize(0, 45));
        signInButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        signInButton->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"             background-color: #20B2AA; \n"
"             border: 2px solid #20B2AA; \n"
"             border-radius: 6px; \n"
"             color: white; \n"
"             font-weight: bold;\n"
"             font-size: 16px;\n"
"            }\n"
"            QPushButton:hover { background-color: #17a098; border-color: #17a098; }\n"
"            QPushButton:pressed { background-color: #0e6b65; border-color: #0e6b65; }\n"
"           "));

        verticalLayout->addWidget(signInButton);

        signUpLayout = new QHBoxLayout();
        signUpLayout->setObjectName("signUpLayout");
        signUpLayout->setContentsMargins(-1, 10, -1, -1);
        hs4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(hs4);

        signUpPromptLabel = new QLabel(container);
        signUpPromptLabel->setObjectName("signUpPromptLabel");

        signUpLayout->addWidget(signUpPromptLabel);

        signUpLabel = new QLabel(container);
        signUpLabel->setObjectName("signUpLabel");
        signUpLabel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        signUpLayout->addWidget(signUpLabel);

        hs5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        signUpLayout->addItem(hs5);


        verticalLayout->addLayout(signUpLayout);


        gridLayout_Body->addWidget(container, 1, 1, 1, 1);

        horizontalSpacer_Right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Body->addItem(horizontalSpacer_Right, 1, 2, 1, 1);

        verticalSpacer_Bottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Body->addItem(verticalSpacer_Bottom, 2, 1, 1, 1);


        mainLayout->addLayout(gridLayout_Body);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Login System", nullptr));
        lblHeader->setText(QCoreApplication::translate("LoginForm", "\304\220\304\202NG NH\341\272\254P H\341\273\206 TH\341\273\220NG QU\341\272\242N L\303\235", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("LoginForm", "Welcome Back!", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginForm", "Please enter your details to sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "Enter your username...", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        signInButton->setText(QCoreApplication::translate("LoginForm", "Sign in", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("LoginForm", "Don't have an account yet?", nullptr));
        signUpLabel->setText(QCoreApplication::translate("LoginForm", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
