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
    QLabel *confirmPassLabel;
    QLineEdit *confirmPassEdit;
    QSpacerItem *verticalSpacer_Input;
    QPushButton *signUpButton;
    QHBoxLayout *footerLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *signUpPromptLabel;
    QLabel *loginLabel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName("SignUpForm");
        SignUpForm->resize(550, 650);
        SignUpForm->setStyleSheet(QString::fromUtf8("\n"
"    /* === C\303\200I \304\220\341\272\266T CHUNG === */\n"
"    QWidget#SignUpForm {\n"
"        background-color: #f4f7f6; \n"
"    }\n"
"    QWidget {\n"
"        font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    }\n"
"\n"
"    /* === KHUNG CH\341\273\250A CH\303\215NH === */\n"
"    QWidget#container {\n"
"        background-color: #ffffff;\n"
"        border: 2px solid #20B2AA; /* Vi\341\273\201n Xanh Ng\341\273\215c Nh\341\272\241t */\n"
"        border-radius: 12px;\n"
"    }\n"
"\n"
"    /* === HEADER === */\n"
"    QWidget#headerWidget {\n"
"        background-color: #00264d; /* N\341\273\201n xanh t\341\273\221i */\n"
"        border-left: 8px solid #FFD700; /* S\341\273\215c v\303\240ng */\n"
"        border-bottom: 4px solid #4169E1; /* K\341\272\273 ngang King Blue */\n"
"        border-top-left-radius: 10px; \n"
"        border-top-right-radius: 10px;\n"
"    }\n"
"    \n"
"    QLabel#welcomeLabel, QLabel#logoLabel, QLabel#subtitleLabel {\n"
"        color: #ffffff;\n"
"        backgroun"
                        "d-color: transparent;\n"
"    }\n"
"    QLabel#welcomeLabel {\n"
"        font-size: 18px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QLabel#subtitleLabel {\n"
"        font-size: 12px;\n"
"        font-style: italic;\n"
"        color: #dddddd;\n"
"    }\n"
"\n"
"    /* === INPUT FIELDS === */\n"
"    QLabel {\n"
"        color: #333;\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"    }\n"
"\n"
"    QLineEdit {\n"
"        background-color: #f9f9f9;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 6px;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"        color: #333;\n"
"    }\n"
"\n"
"    QLineEdit:focus {\n"
"        background-color: #ffffff;\n"
"        border: 2px solid #20B2AA; /* Focus m\303\240u xanh ng\341\273\215c */\n"
"    }\n"
"\n"
"    /* === BUTTON === */\n"
"    QPushButton#signUpButton {\n"
"        background-color: #20B2AA; \n"
"        color: white;\n"
"        font-weight: bold;\n"
"        font-size: 16px;\n"
"        border-radius: 6px"
                        ";\n"
"        border: none;\n"
"    }\n"
"    QPushButton#signUpButton:hover {\n"
"        background-color: #17a098;\n"
"    }\n"
"    QPushButton#signUpButton:pressed {\n"
"        background-color: #13857e;\n"
"    }\n"
"   "));
        gridLayout = new QGridLayout(SignUpForm);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        container = new QWidget(SignUpForm);
        container->setObjectName("container");
        container->setMinimumSize(QSize(380, 0));
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
        verticalLayout_Body->setSpacing(12);
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

        confirmPassLabel = new QLabel(bodyWidget);
        confirmPassLabel->setObjectName("confirmPassLabel");

        verticalLayout_Body->addWidget(confirmPassLabel);

        confirmPassEdit = new QLineEdit(bodyWidget);
        confirmPassEdit->setObjectName("confirmPassEdit");
        confirmPassEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_Body->addWidget(confirmPassEdit);

        verticalSpacer_Input = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Body->addItem(verticalSpacer_Input);

        signUpButton = new QPushButton(bodyWidget);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setMinimumSize(QSize(0, 45));
        signUpButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_Body->addWidget(signUpButton);

        footerLayout = new QHBoxLayout();
        footerLayout->setObjectName("footerLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        footerLayout->addItem(horizontalSpacer_4);

        signUpPromptLabel = new QLabel(bodyWidget);
        signUpPromptLabel->setObjectName("signUpPromptLabel");
        signUpPromptLabel->setStyleSheet(QString::fromUtf8("color: #666;"));

        footerLayout->addWidget(signUpPromptLabel);

        loginLabel = new QLabel(bodyWidget);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setTextFormat(Qt::RichText);
        loginLabel->setOpenExternalLinks(false);

        footerLayout->addWidget(loginLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        footerLayout->addItem(horizontalSpacer_5);


        verticalLayout_Body->addLayout(footerLayout);


        verticalLayout->addWidget(bodyWidget);


        gridLayout->addWidget(container, 1, 1, 1, 1);


        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QWidget *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Sign Up System", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("SignUpForm", "XIN CH\303\200O!", nullptr));
        logoLabel->setText(QCoreApplication::translate("SignUpForm", "(LOGO)", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("SignUpForm", "Create an account to get started", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignUpForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Choose a username...", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUpForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        confirmPassLabel->setText(QCoreApplication::translate("SignUpForm", "Confirm Password", nullptr));
        confirmPassEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpForm", "Sign up", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("SignUpForm", "Have an account?", nullptr));
        loginLabel->setText(QCoreApplication::translate("SignUpForm", "<a href='#' style='color: #20B2AA; text-decoration: none; font-weight: bold;'>Login</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
