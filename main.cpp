#include "mainwindow.h"
#include "loginform.h"
#include "signupform.h"
#include "ui_signupform.h"

#include <QApplication>
#include <QStackedWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStackedWidget stack;
    stack.setFixedSize(1024, 768);
    stack.setWindowTitle("My App");

    stack.setStyleSheet(
        "QStackedWidget {"
        " background: url(:/images/background.png) center center no-repeat;"
        " background-size: cover;"
        " border-radius: 20px;"
        "}"
        );

    LoginForm login;
    SignUpForm signup;

    qDebug() << "Background loaded:" << !QPixmap(":/images/background.png").isNull();

    stack.addWidget(&login);
    stack.addWidget(&signup);
    stack.setCurrentWidget(&login);  // Bắt đầu bằng Login

    // Chuyển từ Login → SignUp
    QObject::connect(&login, &LoginForm::switchToSignUp, &stack, [&stack, &signup]() {
        stack.setCurrentWidget(&signup);
    });

    // Chuyển từ SignUp → Login
    QObject::connect(&signup, &SignUpForm::backToLogin, &stack, [&]() {
        stack.setCurrentWidget(&login);
    });

    stack.show();
    return a.exec();
}
