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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpForm
{
public:
    QVBoxLayout *mainLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QGridLayout *gridLayout_Body;
    QSpacerItem *verticalSpacer_Top;
    QSpacerItem *horizontalSpacer_Left;
    QWidget *formContainer;
    QVBoxLayout *verticalLayout_Form;
    QLabel *welcomeLabel;
    QLabel *subtitleLabel;
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
    QSpacerItem *verticalSpacer_Button;
    QPushButton *signUpButton;
    QHBoxLayout *loginLinkLayout;
    QSpacerItem *hs4;
    QLabel *signUpPromptLabel;
    QLabel *loginLabel;
    QSpacerItem *hs5;
    QSpacerItem *horizontalSpacer_Right;
    QSpacerItem *verticalSpacer_Bottom;

    void setupUi(QWidget *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName("SignUpForm");
        SignUpForm->resize(550, 750);
        SignUpForm->setStyleSheet(QString::fromUtf8("\n"
"    /* --- MAIN FORM --- */\n"
"    QWidget#SignUpForm {\n"
"        background-color: #f4f7f6;\n"
"        border: 4px solid #FFC085; /* Vi\341\273\201n cam nh\341\272\255n di\341\273\207n */\n"
"    }\n"
"\n"
"    QWidget { font-family: \"Segoe UI\", Arial, sans-serif; font-size: 14px; }\n"
"\n"
"    /* --- FORM CONTAINER (H\341\273\230P TR\341\272\256NG) --- */\n"
"    QWidget#formContainer {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 12px;\n"
"    }\n"
"\n"
"    /* --- LABELS --- */\n"
"    QLabel#welcomeLabel {\n"
"        font-size: 24px;\n"
"        font-weight: 900;\n"
"        color: #00264d; /* Xanh \304\221\341\272\255m */\n"
"        margin-bottom: 5px;\n"
"    }\n"
"    QLabel#subtitleLabel {\n"
"        color: #777;\n"
"        font-size: 13px;\n"
"        margin-bottom: 15px;\n"
"    }\n"
"    \n"
"    /* Nh\303\243n c\341\273\247a c\303\241c tr\306\260\341\273\235ng input */\n"
"    QLabel {\n"
"        font-weight: bold;\n"
"  "
                        "      color: #444;\n"
"    }\n"
"\n"
"    QLabel#signUpPromptLabel {\n"
"        color: #666;\n"
"        font-weight: normal;\n"
"        font-size: 13px;\n"
"    }\n"
"    \n"
"    /* Link Login */\n"
"    QLabel#loginLabel {\n"
"        color: #20B2AA;\n"
"        font-weight: bold;\n"
"        font-size: 13px;\n"
"    }\n"
"    QLabel#loginLabel:hover {\n"
"        color: #17a098;\n"
"        text-decoration: underline;\n"
"    }\n"
"\n"
"    /* --- INPUT FIELDS --- */\n"
"    QLineEdit { \n"
"      background-color: #f9f9f9; \n"
"      border: 1px solid #cccccc; \n"
"      border-radius: 6px; \n"
"      padding: 8px; \n"
"      color: #333; \n"
"      font-size: 14px;\n"
"    }\n"
"    QLineEdit:focus { \n"
"      background-color: #ffffff; \n"
"      border: 2px solid #20B2AA; /* Vi\341\273\201n xanh ng\341\273\215c khi focus */\n"
"    }\n"
"   "));
        mainLayout = new QVBoxLayout(SignUpForm);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(SignUpForm);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("\n"
"       QWidget#headerContainer {\n"
"           background-color: #00264d;\n"
"           border-bottom: 5px solid #4169E1;\n"
"           border-left: 10px solid #FFD700; /* V\341\272\240CH V\303\200NG LOGO */\n"
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

        scrollArea = new QScrollArea(SignUpForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setStyleSheet(QString::fromUtf8("background: transparent;"));
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 542, 750));
        gridLayout_Body = new QGridLayout(scrollContent);
        gridLayout_Body->setObjectName("gridLayout_Body");
        verticalSpacer_Top = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Body->addItem(verticalSpacer_Top, 0, 1, 1, 1);

        horizontalSpacer_Left = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Body->addItem(horizontalSpacer_Left, 1, 0, 1, 1);

        formContainer = new QWidget(scrollContent);
        formContainer->setObjectName("formContainer");
        formContainer->setMinimumSize(QSize(400, 0));
        verticalLayout_Form = new QVBoxLayout(formContainer);
        verticalLayout_Form->setSpacing(12);
        verticalLayout_Form->setObjectName("verticalLayout_Form");
        verticalLayout_Form->setContentsMargins(30, 30, 30, 40);
        welcomeLabel = new QLabel(formContainer);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Form->addWidget(welcomeLabel);

        subtitleLabel = new QLabel(formContainer);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Form->addWidget(subtitleLabel);

        usernameLabel = new QLabel(formContainer);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout_Form->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(formContainer);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout_Form->addWidget(usernameEdit);

        fullnameLabel = new QLabel(formContainer);
        fullnameLabel->setObjectName("fullnameLabel");

        verticalLayout_Form->addWidget(fullnameLabel);

        fullnameEdit = new QLineEdit(formContainer);
        fullnameEdit->setObjectName("fullnameEdit");

        verticalLayout_Form->addWidget(fullnameEdit);

        emailLabel = new QLabel(formContainer);
        emailLabel->setObjectName("emailLabel");

        verticalLayout_Form->addWidget(emailLabel);

        emailEdit = new QLineEdit(formContainer);
        emailEdit->setObjectName("emailEdit");

        verticalLayout_Form->addWidget(emailEdit);

        phoneLabel = new QLabel(formContainer);
        phoneLabel->setObjectName("phoneLabel");

        verticalLayout_Form->addWidget(phoneLabel);

        phoneEdit = new QLineEdit(formContainer);
        phoneEdit->setObjectName("phoneEdit");

        verticalLayout_Form->addWidget(phoneEdit);

        passwordLabel = new QLabel(formContainer);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout_Form->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(formContainer);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_Form->addWidget(passwordEdit);

        confirmPassLabel = new QLabel(formContainer);
        confirmPassLabel->setObjectName("confirmPassLabel");

        verticalLayout_Form->addWidget(confirmPassLabel);

        confirmPassEdit = new QLineEdit(formContainer);
        confirmPassEdit->setObjectName("confirmPassEdit");
        confirmPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_Form->addWidget(confirmPassEdit);

        verticalSpacer_Button = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Form->addItem(verticalSpacer_Button);

        signUpButton = new QPushButton(formContainer);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setMinimumSize(QSize(0, 45));
        signUpButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        signUpButton->setStyleSheet(QString::fromUtf8("\n"
"              QPushButton {\n"
"               background-color: #20B2AA; \n"
"               border: 2px solid #20B2AA; \n"
"               border-radius: 6px; \n"
"               color: white; \n"
"               font-weight: bold;\n"
"               font-size: 16px;\n"
"              }\n"
"              QPushButton:hover { background-color: #17a098; border-color: #17a098; }\n"
"              QPushButton:pressed { background-color: #0e6b65; border-color: #0e6b65; }\n"
"             "));

        verticalLayout_Form->addWidget(signUpButton);

        loginLinkLayout = new QHBoxLayout();
        loginLinkLayout->setObjectName("loginLinkLayout");
        loginLinkLayout->setContentsMargins(-1, 10, -1, -1);
        hs4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        loginLinkLayout->addItem(hs4);

        signUpPromptLabel = new QLabel(formContainer);
        signUpPromptLabel->setObjectName("signUpPromptLabel");

        loginLinkLayout->addWidget(signUpPromptLabel);

        loginLabel = new QLabel(formContainer);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        loginLinkLayout->addWidget(loginLabel);

        hs5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        loginLinkLayout->addItem(hs5);


        verticalLayout_Form->addLayout(loginLinkLayout);


        gridLayout_Body->addWidget(formContainer, 1, 1, 1, 1);

        horizontalSpacer_Right = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Body->addItem(horizontalSpacer_Right, 1, 2, 1, 1);

        verticalSpacer_Bottom = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Body->addItem(verticalSpacer_Bottom, 2, 1, 1, 1);

        scrollArea->setWidget(scrollContent);

        mainLayout->addWidget(scrollArea);


        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QWidget *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Register Account", nullptr));
        lblHeader->setText(QCoreApplication::translate("SignUpForm", "\304\220\304\202NG K\303\235 T\303\200I KHO\341\272\242N M\341\273\232I", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("SignUpForm", "Create Account", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("SignUpForm", "Please enter your detail to sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignUpForm", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your username...", nullptr));
        fullnameLabel->setText(QCoreApplication::translate("SignUpForm", "Full Name", nullptr));
        fullnameEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your full name...", nullptr));
        emailLabel->setText(QCoreApplication::translate("SignUpForm", "Email", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your email address...", nullptr));
        phoneLabel->setText(QCoreApplication::translate("SignUpForm", "Phone", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Enter your phone number...", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUpForm", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        confirmPassLabel->setText(QCoreApplication::translate("SignUpForm", "Confirm Password", nullptr));
        confirmPassEdit->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242\342\200\242", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpForm", "Register", nullptr));
        signUpPromptLabel->setText(QCoreApplication::translate("SignUpForm", "Have an account?", nullptr));
        loginLabel->setText(QCoreApplication::translate("SignUpForm", "Login here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
