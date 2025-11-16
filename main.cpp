#include "mainwindow.h"
#include "loginform.h"
#include "signupform.h"
#include "articleinput.h"
#include "articlemenu.h"

#include <QApplication>
#include <QStackedWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ArticleRepo a_repo;
    a_repo.load();
    AuthorRepo au_repo;
    au_repo.load();

    RepositoryManager repo(a_repo, au_repo);

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
    ArticleMenu articlemenu(repo);
    ArticleInput articleinput(repo);

    qDebug() << "Background loaded:" << !QPixmap(":/images/background.png").isNull();

    stack.addWidget(&login);
    stack.addWidget(&signup);
    stack.addWidget(&articlemenu);
    stack.addWidget(&articleinput);

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
